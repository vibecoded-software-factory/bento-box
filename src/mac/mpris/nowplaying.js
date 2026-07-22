// Now-playing bridge for macOS, run through osascript.
//
// Since macOS 15.4 the mediaremoted daemon refuses NowPlaying access to
// processes without a private entitlement - but Apple's own signed binaries
// (bundle id com.apple.*) are allowed, and /usr/bin/osascript is one. So this
// script, loaded by osascript, can read the system now-playing (from ANY app,
// including a browser) and send transport commands, and bento drives it over a
// plain Process. No private entitlement on bento, no compiled helper.
//
// Two modes:
//   osascript -l JavaScript nowplaying.js               -> stream JSON lines
//   osascript -l JavaScript nowplaying.js command <n>   -> send command n, exit
// where n is a MediaRemote command: 0 play, 1 pause, 2 toggle, 3 stop,
// 4 next, 5 previous.

ObjC.import('Foundation');

function loadMediaRemote() {
	const bundle = $.NSBundle.bundleWithPath(
		'/System/Library/PrivateFrameworks/MediaRemote.framework/'
	);
	bundle.load;
	return bundle;
}

function run(argv) {
	loadMediaRemote();

	if (argv[0] === 'command') {
		ObjC.bindFunction('MRMediaRemoteSendCommand', ['bool', ['int', 'id']]);
		$.MRMediaRemoteSendCommand(parseInt(argv[1], 10), $());
		// The command is delivered to mediaremoted asynchronously (over XPC). If
		// this process exits immediately after the call the message is dropped
		// and nothing happens - so pump the runloop briefly to let the delivery
		// flush before returning. Without this, commands silently no-op.
		$.NSRunLoop.currentRunLoop.runUntilDate(
			$.NSDate.dateWithTimeIntervalSinceNow(1.0)
		);
		return;
	}

	const MRNowPlayingRequest = $.NSClassFromString('MRNowPlayingRequest');

	// Write to real stdout: JXA's console.log goes to STDERR, which the parser
	// on the other end does not read (and which osascript also uses for its own
	// diagnostics). A raw NSFileHandle write keeps the JSON stream clean.
	const stdout = $.NSFileHandle.fileHandleWithStandardOutput;
	function emit(s) {
		stdout.writeData($(s + '\n').dataUsingEncoding($.NSUTF8StringEncoding));
	}

	// Album art is binary NSData, too heavy to stream inline. Instead it is
	// written to a temp file ONCE per track and the file URL is emitted, so a
	// bar's Image binds to a path and only reloads when the track changes. A
	// sequence number in the name forces a new URL each time so the Image
	// actually reloads rather than caching the old path.
	let artUrl = null;
	let artTitle = null;
	let artSeq = 0;
	function updateArt(title, info) {
		if (title === artTitle) return;
		artTitle = title;
		const data = info.valueForKey('kMRMediaRemoteNowPlayingInfoArtworkData');
		if (data.js && data.length && data.length > 0) {
			artSeq += 1;
			const path = $.NSTemporaryDirectory().js + 'bento-art-' + artSeq + '.jpg';
			data.writeToFileAtomically($(path), false);
			artUrl = 'file://' + path;
		} else {
			artUrl = null;
		}
	}

	function snapshot() {
		const item = MRNowPlayingRequest.localNowPlayingItem;
		if (!item.js) return JSON.stringify({ hasPlayer: false });
		const info = item.nowPlayingInfo;
		const path = MRNowPlayingRequest.localNowPlayingPlayerPath;
		const client = path && path.client ? path.client : null;
		const g = k => {
			const v = info.valueForKey(k);
			return v && v.js !== undefined ? v.js : null;
		};
		const title = g('kMRMediaRemoteNowPlayingInfoTitle');
		updateArt(title, info);
		// The Timestamp is WHEN the elapsed value was true. Some apps (a
		// browser) report elapsed=0 with a fresh timestamp instead of a live
		// position, so the real position is elapsed + (now - timestamp) - the
		// consumer needs the timestamp to compute it. Emitted as epoch seconds.
		const ts = info.valueForKey('kMRMediaRemoteNowPlayingInfoTimestamp');
		return JSON.stringify({
			hasPlayer: true,
			app: client ? client.displayName.js : null,
			bundleId: client ? client.bundleIdentifier.js : null,
			title: title,
			artist: g('kMRMediaRemoteNowPlayingInfoArtist'),
			album: g('kMRMediaRemoteNowPlayingInfoAlbum'),
			art: artUrl,
			duration: g('kMRMediaRemoteNowPlayingInfoDuration'),
			elapsed: g('kMRMediaRemoteNowPlayingInfoElapsedTime'),
			timestamp: ts.js ? ts.timeIntervalSince1970 : null,
			playing: g('kMRMediaRemoteNowPlayingInfoPlaybackRate') == 1
		});
	}

	// Poll and emit only on change - the system has no public change
	// notification reachable from here, so a short poll is the honest option;
	// emitting only diffs keeps bento's parser idle when nothing moves.
	let last = null;
	// eslint-disable-next-line no-constant-condition
	while (true) {
		const s = snapshot();
		if (s !== last) {
			emit(s);
			last = s;
		}
		delay(0.5);
	}
}

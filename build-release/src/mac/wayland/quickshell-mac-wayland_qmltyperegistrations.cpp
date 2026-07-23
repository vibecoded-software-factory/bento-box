/****************************************************************************
** Generated QML type registration code
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <QtQml/qqml.h>
#include <QtQml/qqmlmoduleregistration.h>

#if __has_include(<screencopy.hpp>)
#  include <screencopy.hpp>
#endif
#if __has_include(<toplevel.hpp>)
#  include <toplevel.hpp>
#endif
#if __has_include(<wayland.hpp>)
#  include <wayland.hpp>
#endif


#if !defined(QT_STATIC)
#define Q_QMLTYPE_EXPORT Q_DECL_EXPORT
#else
#define Q_QMLTYPE_EXPORT
#endif
Q_QMLTYPE_EXPORT void qml_register_types_Quickshell_Wayland()
{
    qmlRegisterModule("Quickshell.Wayland", 0, 0);
    QT_WARNING_PUSH QT_WARNING_DISABLE_DEPRECATED
    qmlRegisterTypesAndRevisions<qs::mac::wayland::IdleInhibitor>("Quickshell.Wayland", 0);
    qmlRegisterTypesAndRevisions<qs::mac::wayland::IdleMonitor>("Quickshell.Wayland", 0);
    qmlRegisterTypesAndRevisions<qs::mac::wayland::ScreencopyView>("Quickshell.Wayland", 0);
    qmlRegisterAnonymousType<QQuickItem, 254>("Quickshell.Wayland", 0);
    qmlRegisterTypesAndRevisions<qs::mac::wayland::ShortcutInhibitor>("Quickshell.Wayland", 0);
    qmlRegisterTypesAndRevisions<qs::mac::wayland::Toplevel>("Quickshell.Wayland", 0);
    qmlRegisterTypesAndRevisions<qs::mac::wayland::ToplevelManager>("Quickshell.Wayland", 0);
    qmlRegisterTypesAndRevisions<qs::mac::wayland::WlSessionLock>("Quickshell.Wayland", 0);
    qmlRegisterTypesAndRevisions<qs::mac::wayland::WlSessionLockSurface>("Quickshell.Wayland", 0);
    {
        Q_CONSTINIT static auto metaType = QQmlPrivate::metaTypeForNamespace(
            [](const QtPrivate::QMetaTypeInterface *) {return &qs::mac::wayland::WlrKeyboardFocus::staticMetaObject;},
            "qs::mac::wayland::WlrKeyboardFocus");
        QMetaType(&metaType).id();
    }
    qmlRegisterNamespaceAndRevisions(&qs::mac::wayland::WlrKeyboardFocus::staticMetaObject, "Quickshell.Wayland", 0, nullptr, &qs::mac::wayland::WlrKeyboardFocus::staticMetaObject, nullptr);
    qmlRegisterEnum<qs::mac::wayland::WlrKeyboardFocus::Enum>("qs::mac::wayland::WlrKeyboardFocus::Enum");
    {
        Q_CONSTINIT static auto metaType = QQmlPrivate::metaTypeForNamespace(
            [](const QtPrivate::QMetaTypeInterface *) {return &qs::mac::wayland::WlrLayer::staticMetaObject;},
            "qs::mac::wayland::WlrLayer");
        QMetaType(&metaType).id();
    }
    qmlRegisterNamespaceAndRevisions(&qs::mac::wayland::WlrLayer::staticMetaObject, "Quickshell.Wayland", 0, nullptr, &qs::mac::wayland::WlrLayer::staticMetaObject, nullptr);
    qmlRegisterEnum<qs::mac::wayland::WlrLayer::Enum>("qs::mac::wayland::WlrLayer::Enum");
    qmlRegisterTypesAndRevisions<qs::mac::wayland::WlrLayershell>("Quickshell.Wayland", 0);
    qmlRegisterEnum<qs::mac::wayland::WlrLayershell::Layer>("qs::mac::wayland::WlrLayershell::Layer");
    QT_WARNING_POP
    qmlRegisterModule("Quickshell.Wayland", 0, 1);
}

static const QQmlModuleRegistration quickshellWaylandRegistration("Quickshell.Wayland", qml_register_types_Quickshell_Wayland);

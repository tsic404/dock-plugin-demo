// Copyright (C) 2017 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#include <QGuiApplication>
#include <QWindow>

#include <QtGui/QGuiApplication>
#include <QtGui/QWindow>
#include <QtGui/QPlatformSurfaceEvent>
#include <QtGui/qpa/qplatformnativeinterface.h>

#include <qwayland-dock-plugin-shell-v1.h>

int main (int argc, char **argv)
{
    QGuiApplication app(argc, argv);
    QWindow window;
    auto surf = static_cast<struct ::wl_surface *>(QGuiApplication::platformNativeInterface()->nativeResourceForWindow("surface", &window));
    qDebug() << surf;
    auto tmp = QtWayland::dock_plugin_shell_v1().surface_create("test", 1, surf);
    window.show();
    return app.exec();
}

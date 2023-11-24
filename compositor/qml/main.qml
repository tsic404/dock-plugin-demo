// Copyright (C) 2017 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

import QtQuick
import QtQuick.Controls
import QtWayland.Compositor
import QtWayland.Compositor.IviApplication
import QtWayland.Compositor.XdgShell
import org.deepin.dde.dock

Window {
    id: root
    visible: true
    height: 400
    width: 400

    Item {
        WaylandCompositor {
            id: waylandCompositor

            WaylandOutput {
                window: surfaceHandler.window
            }


            IviApplication {
                onIviSurfaceCreated: (iviSurface) => {
                    console.log(iviSurface.surface.client)
                }
            }

            DockPluginShell {
                onDockPluginSurfaceCreated: (dockPluginSurface) => {
                    console.log(dockPluginSurface.surface)
                }
            }
        }

        Item {
            id: surfaceHandler
            property ListModel shellSurfaces: ListModel {}
            property var window: Window.window

            function handleShellSurface(shellSurface) {
                shellSurfaces.append({shellSurface: shellSurface})
            }

            Row {
                Rectangle { height: 20; width: 20; color: "red"}
                Rectangle { height: 20; width: 20; color: "red"}

                Repeater {
                    model: surfaceHandler.shellSurfaces
                    delegate: ShellSurfaceItem {
                        shellSurface: modelData
                        onSurfaceDestroyed: {
                            surfaceHandler.shellSurfaces.remove(index)
                            console.log("destroyed")
                        }
                        Component.onCompleted: {
                            console.log("created")
                        }
                    }
                }
            }
        }
    }
}

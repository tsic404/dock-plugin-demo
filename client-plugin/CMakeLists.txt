# Copyright (C) 2022 The Qt Company Ltd.
# SPDX-License-Identifier: BSD-3-Clause

cmake_minimum_required(VERSION 3.16)
project(dockpluginshell-client)

set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui WaylandClient)

qt_add_executable(dockpluginshell-client
    dockpluginshellintegration_p.h
    dockpluginshellintegration.cpp
    dockpluginsurface_p.h
    dockpluginsurface.cpp
    main.cpp
)

qt6_generate_wayland_protocol_client_sources(dockpluginshell-client
    FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/../protocol/dock-plugin-shell-v1.xml
)

target_link_libraries(dockpluginshell-client PUBLIC
    Qt::Core
    Qt::Gui
    Qt::GuiPrivate
    Qt::WaylandClient
    Qt::WaylandClientPrivate
)

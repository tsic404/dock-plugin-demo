cmake_minimum_required(VERSION 3.16)
project(dock-plugin-demo-compositor)

set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Qml WaylandCompositor)

qt6_policy(SET QTP0001 NEW)
qt_add_executable(dock-plugin-demo-compositor
    dockpluginshellextension.cpp dockpluginshellextension.h
    main.cpp
)

qt6_generate_wayland_protocol_server_sources(dock-plugin-demo-compositor
    FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/../protocol/dock-plugin-shell-v1.xml
)

target_link_libraries(dock-plugin-demo-compositor PUBLIC
    Qt::Core
    Qt::Gui
    Qt::Qml
    Qt::WaylandCompositor
)

# Resources:
set(compositor_resource_files
    "qml/main.qml"
)

qt6_add_resources(dock-plugin-demo-compositor "compositor"
    PREFIX
        "/"
    FILES
        ${compositor_resource_files}
)

qt6_add_qml_module(dock-plugin-demo-compositor
  URI org.deepin.dde.dock
  VERSION 1.0
)

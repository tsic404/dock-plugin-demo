# Copyright (C) 2022 The Qt Company Ltd.
# SPDX-License-Identifier: BSD-3-Clause

cmake_minimum_required(VERSION 3.16)
project(dock-plugin-demo LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_AUTOMOC ON)

if(NOT DEFINED INSTALL_EXAMPLESDIR)
    set(INSTALL_EXAMPLESDIR "examples")
endif()

set(INSTALL_EXAMPLEDIR "${INSTALL_EXAMPLESDIR}/wayland/dock-plugin-demo")

find_package(Qt6 REQUIRED COMPONENTS Core Gui Qml)

qt_add_executable(dock-plugin-demo
    main.cpp
)

set_target_properties(dock-plugin-demo PROPERTIES
    WIN32_EXECUTABLE TRUE
    MACOSX_BUNDLE TRUE
)

target_link_libraries(dock-plugin-demo PUBLIC
    Qt::Core
    Qt::Gui
    Qt::Qml
)

# Resources:
set(dock-plugin-demo_resource_files
    "qml/main.qml"
)

qt6_add_resources(dock-plugin-demo "dock-plugin-demo"
    PREFIX
        "/"
    FILES
        ${dock-plugin-demo_resource_files}
)

install(TARGETS dock-plugin-demo
    RUNTIME DESTINATION "${INSTALL_EXAMPLEDIR}"
    BUNDLE DESTINATION "${INSTALL_EXAMPLEDIR}"
    LIBRARY DESTINATION "${INSTALL_EXAMPLEDIR}"
)

// SPDX-FileCopyrightText: 2023 UnionTech Software Technology Co., Ltd.
//
// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#include <qwayland-dock-plugin-shell-v1.h>

#include <QtWaylandClient/private/qwaylandclientshellapi_p.h>

class DockPluginShellIntegration : public QtWaylandClient::QWaylandShellIntegrationTemplate<DockPluginShellIntegration>, public QtWayland::dock_plugin_shell_v1
{

public:
    DockPluginShellIntegration();
    ~DockPluginShellIntegration() override;

    QtWaylandClient::QWaylandShellSurface *createShellSurface(QtWaylandClient::QWaylandWindow *window) override;
};


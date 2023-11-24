// SPDX-FileCopyrightText: 2023 UnionTech Software Technology Co., Ltd.
//
// SPDX-License-Identifier: GPL-3.0-or-later

#include "dockpluginshellintegration_p.h"
#include "dockpluginsurface_p.h"


DockPluginShellIntegration::DockPluginShellIntegration()
    : QWaylandShellIntegrationTemplate<DockPluginShellIntegration>(4)
{
}

DockPluginShellIntegration::~DockPluginShellIntegration()
{
}

QtWaylandClient::QWaylandShellSurface *DockPluginShellIntegration::createShellSurface(QtWaylandClient::QWaylandWindow *window)
{
    return new DockPluginSurface(this, window);
}

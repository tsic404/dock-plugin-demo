#pragma once

#include "qwayland-dock-plugin-shell-v1.h"

#include <private/qwaylandwindow_p.h>
#include <QtWaylandClient/private/qwaylandshellsurface_p.h>

class DockPluginSurface : public QtWaylandClient::QWaylandShellSurface, public QtWayland::dock_plugin_surface
{
    Q_OBJECT

public:
    DockPluginSurface(QtWayland::dock_plugin_shell_v1 *shell, QtWaylandClient::QWaylandWindow *window);
    ~DockPluginSurface() override;

protected:
    void dock_plugin_surface_configure(int32_t width, int32_t height) override;
};
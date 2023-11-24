#include "dockpluginsurface_p.h"
#include "qwayland-dock-plugin-shell-v1.h"
#include <qsize.h>

DockPluginSurface::DockPluginSurface(QtWayland::dock_plugin_shell_v1 *shell, QtWaylandClient::QWaylandWindow *window)
    : QtWaylandClient::QWaylandShellSurface(window)
    , QtWayland::dock_plugin_surface()
{

}

DockPluginSurface::~DockPluginSurface()
{
}

void DockPluginSurface::dock_plugin_surface_configure(int32_t width, int32_t height)
{
    QSize pendingSize = QSize(width, height);
    window()->resizeFromApplyConfigure(pendingSize);
    window()->handleExpose(QRect(QPoint(), pendingSize));
}

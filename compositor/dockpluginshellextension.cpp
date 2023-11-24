#include "dockpluginshellextension.h"

#include <QtWaylandCompositor/QWaylandCompositor>
#include <QtWaylandCompositor/QWaylandSurface>
#include <QtWaylandCompositor/QWaylandResource>

DockPluginShell::DockPluginShell(QWaylandCompositor *compositor)
    : QWaylandCompositorExtensionTemplate(compositor)
{
}

void DockPluginShell::initialize()
{
    QWaylandCompositorExtensionTemplate::initialize();
    QWaylandCompositor *compositor = static_cast<QWaylandCompositor *>(extensionContainer());
    init(compositor->display(), 1);
}

void DockPluginShell::dock_plugin_shell_v1_surface_create(Resource *resource, const QString &plugin_id, uint32_t plugin_surface_type, struct ::wl_resource *surfaceResource, uint32_t id)
{
    qDebug() << "created";
    Q_UNUSED(resource);
    QWaylandSurface *surface = QWaylandSurface::fromResource(surfaceResource);

    QWaylandResource shellSurfaceResource(wl_resource_create(resource->client(), &::dock_plugin_surface_interface,
                                                           wl_resource_get_version(resource->handle), id));

    auto *shellSurface = new DockPluginSurface(this, plugin_id, plugin_surface_type, surface, shellSurfaceResource);
    emit dockPluginSurfaceCreated(shellSurface);
}

DockPluginSurface::DockPluginSurface(DockPluginShell* shell, const QString& plugin_id, uint32_t plugin_surface_type, QWaylandSurface *surface, const QWaylandResource &resource)
{
    m_shell = shell;
    m_surface = surface;
    m_pluginId = plugin_id;
    m_surfaceType = plugin_surface_type;
    init(resource.resource());
    setExtensionContainer(surface);
    QWaylandCompositorExtension::initialize();
}

QWaylandSurface* DockPluginSurface::surface() const
{
    return m_surface;
}

QString DockPluginSurface::pluginId() const
{
    return m_pluginId;
}

uint DockPluginSurface::surfaceType() const
{
    return m_surfaceType;
}


#pragma once

#include <QtWaylandCompositor/QWaylandCompositorExtensionTemplate>
#include <QtWaylandCompositor/QWaylandQuickExtension>
#include <QtWaylandCompositor/QWaylandCompositor>
#include <QtWaylandCompositor/QWaylandSurface>

#include <QtWaylandCompositor/QWaylandCompositorExtension>
#include <QtWaylandCompositor/QWaylandQuickExtension>
#include <QtWaylandCompositor/QWaylandSurface>
#include <QtWaylandCompositor/QWaylandResource>

#include "qwayland-server-dock-plugin-shell-v1.h"

class DockPluginSurface;

class DockPluginShell  : public QWaylandCompositorExtensionTemplate<DockPluginShell>
        , public QtWaylandServer::dock_plugin_shell_v1
{
    Q_OBJECT
    QML_ELEMENT
public:
    DockPluginShell(QWaylandCompositor *compositor = nullptr);
    void initialize() override;

protected:
    void dock_plugin_shell_v1_surface_create(Resource *resource, const QString &plugin_id, uint32_t plugin_surface_type, struct ::wl_resource *surfaceResource, uint32_t id) override;

Q_SIGNALS:
    void dockPluginSurfaceCreated(DockPluginSurface *surface);
};


class DockPluginSurface : public QWaylandCompositorExtensionTemplate<DockPluginSurface>
        , public QtWaylandServer::dock_plugin_surface
{
    Q_OBJECT

    Q_PROPERTY(QString pluginId READ pluginId)
    Q_PROPERTY(uint surfaceType READ surfaceType)

public:
    DockPluginSurface(DockPluginShell* shell, const QString& plugin_id, uint32_t plugin_surface_type, QWaylandSurface *surface, const QWaylandResource &resource);

    QWaylandSurface *surface() const;

    QString pluginId() const;
    uint surfaceType() const;

private:
    static QWaylandSurfaceRole s_role;
    DockPluginShell* m_shell;
    QWaylandSurface* m_surface;

    QString m_pluginId;
    uint m_surfaceType;

};

Q_COMPOSITOR_DECLARE_QUICK_EXTENSION_CLASS(DockPluginShell)


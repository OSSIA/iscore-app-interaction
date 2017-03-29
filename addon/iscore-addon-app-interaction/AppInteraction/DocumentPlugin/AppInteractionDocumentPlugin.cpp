#include "AppInteractionDocumentPlugin.hpp"

namespace AppInteraction
{

DocumentPlugin::DocumentPlugin(
        const iscore::DocumentContext& ctx,
        Id<iscore::DocumentPlugin> id,
        QObject* parent):
    iscore::DocumentPlugin{ctx, std::move(id), "DocumentPlugin", parent}
{
}

DocumentPlugin::~DocumentPlugin()
{
}

connectionFaussaire::ConnectionManagerFaussaire* DocumentPlugin::connectionManager(){

    return m_connectionManager;
}

}

#include "AppInteractionDocumentPlugin.hpp"

namespace AppInteraction
{

DocumentPlugin::DocumentPlugin(
        const iscore::DocumentContext& ctx,
        Id<iscore::DocumentPlugin> id,
        QObject* parent):
    iscore::SerializableDocumentPlugin{ctx, std::move(id), "DocumentPlugin", parent}
{
}
connectionFaussaire::ConnectionManagerFaussaire& DocumentPlugin::connectionManager(){

        return m_connectionManager;
           }
}



template <>
void DataStreamReader::read(
        const AppInteraction::DocumentPlugin& dev)
{
    insertDelimiter();
}

template <>
void DataStreamWriter::write(
        AppInteraction::DocumentPlugin& plug)
{
    checkDelimiter();
}

template <>
void JSONObjectReader::read(
        const AppInteraction::DocumentPlugin& plug)
{

}

template <>
void JSONObjectWriter::write(
        AppInteraction::DocumentPlugin& plug)
{
}

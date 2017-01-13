#include "TutorialDocumentPlugin.hpp"

namespace Tutorial
{

DocumentPlugin::DocumentPlugin(
        const iscore::DocumentContext& ctx,
        Id<iscore::DocumentPlugin> id,
        QObject* parent):
    iscore::SerializableDocumentPlugin{ctx, std::move(id), "DocumentPlugin", parent}
{
}

}

template <>
void DataStreamReader::read(
        const Tutorial::DocumentPlugin& dev)
{
    insertDelimiter();
}

template <>
void DataStreamWriter::write(
        Tutorial::DocumentPlugin& plug)
{
    checkDelimiter();
}

template <>
void JSONObjectReader::read(
        const Tutorial::DocumentPlugin& plug)
{

}

template <>
void JSONObjectWriter::write(
        Tutorial::DocumentPlugin& plug)
{
}

#include "SimpleElement.hpp"
#include <iscore/serialization/DataStreamVisitor.hpp>
#include <iscore/serialization/JSONVisitor.hpp>
namespace AppInteraction
{

SimpleElement::SimpleElement(const Id<SimpleElement>& id, QObject* parent):
    IdentifiedObject{
      id, // Has to be passed here, will be accessible with id().
      "SimpleElement", // The name of the object.
      parent} // Don't forget to pass the parent so that the hierarchy works.
{

}

SimpleElement::~SimpleElement()
{

}

}

//Here is some serialization / deserialization prototypes.
// See AppInteraction::ProcessModel for a complete example.
template <>
void DataStreamReader::read(const AppInteraction::SimpleElement& e)
{
    insertDelimiter();
}

template <>
void DataStreamWriter::write(AppInteraction::SimpleElement& e)
{
    checkDelimiter();
}

template <>
void JSONObjectReader::read(const AppInteraction::SimpleElement& e)
{
}

template <>
void JSONObjectWriter::write(AppInteraction::SimpleElement& e)
{

}

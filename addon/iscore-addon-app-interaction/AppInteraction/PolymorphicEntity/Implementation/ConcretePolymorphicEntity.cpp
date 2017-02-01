#include "ConcretePolymorphicEntity.hpp"

namespace AppInteraction
{

ConcretePolymorphicEntity::ConcretePolymorphicEntity(
        const Id<PolymorphicEntity>& id,
        QObject* parent):
    PolymorphicEntity{id, parent}
{

}

ConcretePolymorphicEntity::ConcretePolymorphicEntity(
        const ConcretePolymorphicEntity& source,
        const Id<PolymorphicEntity>& id,
        QObject* parent):
    PolymorphicEntity{source, id, parent}
{

}

int ConcretePolymorphicEntity::someVirtualMethod() const
{
  return 1234;
}

}

// Here we do not need to save the parent class.
// This is because the serialization mechanism will
// be called from the point of view of the PolymorphicElement class.
template <>
void DataStreamReader::read(
        const AppInteraction::ConcretePolymorphicEntity& p)
{
    insertDelimiter();
}

template <>
void DataStreamWriter::write(
        AppInteraction::ConcretePolymorphicEntity& p)
{
    checkDelimiter();
}

template <>
void JSONObjectReader::read(
        const AppInteraction::ConcretePolymorphicEntity& p)
{
}

template <>
void JSONObjectWriter::write(
        AppInteraction::ConcretePolymorphicEntity& p)
{
}

#include "ConcretePolymorphicEntity.hpp"

namespace Tutorial
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
        const Tutorial::ConcretePolymorphicEntity& p)
{
    insertDelimiter();
}

template <>
void DataStreamWriter::write(
        Tutorial::ConcretePolymorphicEntity& p)
{
    checkDelimiter();
}

template <>
void JSONObjectReader::read(
        const Tutorial::ConcretePolymorphicEntity& p)
{
}

template <>
void JSONObjectWriter::write(
        Tutorial::ConcretePolymorphicEntity& p)
{
}

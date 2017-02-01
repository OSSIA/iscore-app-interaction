#include "PolymorphicEntity.hpp"

namespace Tutorial
{

PolymorphicEntity::PolymorphicEntity(
        const Id<PolymorphicEntity>& id,
        QObject* parent):
    Entity{id, "PolymorphicElement", parent}
{

}

PolymorphicEntity::PolymorphicEntity(
        const PolymorphicEntity& source,
        const Id<PolymorphicEntity>& id,
        QObject* parent):
    Entity{id, "PolymorphicElement", parent}
{

}

PolymorphicEntity::~PolymorphicEntity()
{

}

}

template <>
void DataStreamReader::read(
        const Tutorial::PolymorphicEntity& p)
{
}

template <>
void DataStreamWriter::write(
        Tutorial::PolymorphicEntity& p)
{
}

template <>
void JSONObjectReader::read(
        const Tutorial::PolymorphicEntity& p)
{;
}

template <>
void JSONObjectWriter::write(
        Tutorial::PolymorphicEntity& p)
{
}

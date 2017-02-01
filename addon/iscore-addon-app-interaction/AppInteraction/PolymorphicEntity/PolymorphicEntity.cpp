#include "PolymorphicEntity.hpp"

namespace AppInteraction
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
        const AppInteraction::PolymorphicEntity& p)
{
}

template <>
void DataStreamWriter::write(
        AppInteraction::PolymorphicEntity& p)
{
}

template <>
void JSONObjectReader::read(
        const AppInteraction::PolymorphicEntity& p)
{;
}

template <>
void JSONObjectWriter::write(
        AppInteraction::PolymorphicEntity& p)
{
}

#include "SimpleEntity.hpp"

namespace AppInteraction
{

SimpleEntity::SimpleEntity(const Id<SimpleEntity>& id, QObject* parent):
    Entity{id, "SimpleEntity", parent}
{

}

SimpleEntity::~SimpleEntity()
{

}

}

template <>
void DataStreamReader::read(const AppInteraction::SimpleEntity& e)
{
    insertDelimiter();
}

template <>
void DataStreamWriter::write(AppInteraction::SimpleEntity& e)
{
    checkDelimiter();
}

template <>
void JSONObjectReader::read(const AppInteraction::SimpleEntity& e)
{
}

template <>
void JSONObjectWriter::write(AppInteraction::SimpleEntity& e)
{

}

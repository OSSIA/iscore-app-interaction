#include "PolymorphicEntityFactory.hpp"

namespace AppInteraction
{

PolymorphicElementFactory::~PolymorphicElementFactory()
{

}

PolymorphicEntity* PolymorphicElementFactoryList::loadMissing(
        const VisitorVariant& vis,
        QObject* parent) const
{
    return nullptr;
}

}

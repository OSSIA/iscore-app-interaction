#pragma once
#include <Tutorial/PolymorphicEntity/PolymorphicEntity.hpp>

namespace Tutorial
{
class ConcretePolymorphicEntity;
}

//! This is used to provide some metadata used for serialization.
POLYMORPHIC_ENTITY_METADATA(
        ,
        Tutorial::ConcretePolymorphicEntity,
        "e1c02c4c-a4c4-4779-9204-8a00f35e7985",
        "Concrete",
        "Concrete")

namespace Tutorial
{
// A concrete class that will be used for instance in Tutorial::ProcessModel
class ConcretePolymorphicEntity final : public PolymorphicEntity
{
        // Necessary for signals / slots, so not strictly necessary here.
        Q_OBJECT

        // Necessary to allow the JSONReader, etc. functions to access private members.
        ISCORE_SERIALIZE_FRIENDS

        // Default implementations for the functions defined in iscore::SerializableInterface.
        MODEL_METADATA_IMPL(ConcretePolymorphicEntity)

    public:
        // Standard constructor
        ConcretePolymorphicEntity(
                const Id<PolymorphicEntity>& id,
                QObject* parent);

        // Clone constructor
        ConcretePolymorphicEntity(
                const ConcretePolymorphicEntity& source,
                const Id<PolymorphicEntity>&,
                QObject* parent);

        // Load constructor
        template<typename Impl>
        ConcretePolymorphicEntity(
                Impl& vis,
                QObject* parent) :
            PolymorphicEntity{vis, parent}
        {
            vis.writeTo(*this);
        }


        int someVirtualMethod() const override;
};

// Thanks to the generic factory we wrote earlier, the definition
// for this particular class's factory is a single line.
using ConcretePolymorphicElementFactory =
    PolymorphicElementFactory_T<ConcretePolymorphicEntity>;
}

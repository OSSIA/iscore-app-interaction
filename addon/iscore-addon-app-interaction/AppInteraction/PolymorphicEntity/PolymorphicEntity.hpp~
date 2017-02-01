#pragma once
#include <Tutorial/PolymorphicEntity/PolymorphicEntityFactory.hpp>
#include <iscore/plugins/customfactory/SerializableInterface.hpp>
#include <iscore/model/Entity.hpp>

namespace Tutorial
{
class PolymorphicEntity :
        public iscore::Entity<PolymorphicEntity>,
        public iscore::SerializableInterface<PolymorphicElementFactory>
{
        Q_OBJECT
        ISCORE_SERIALIZE_FRIENDS

    public:
        PolymorphicEntity(
                const Id<PolymorphicEntity>& id,
                QObject* parent);

        PolymorphicEntity(
                const PolymorphicEntity& source,
                const Id<PolymorphicEntity>&,
                QObject* parent);

        template<typename Impl>
        PolymorphicEntity(
                Impl& vis,
                QObject* parent) :
            iscore::Entity<PolymorphicEntity>{vis, parent}
        {
            vis.writeTo(*this);
        }


        ~PolymorphicEntity();

        virtual int someVirtualMethod() const = 0;

        virtual PolymorphicEntity* clone(
                const Id<PolymorphicEntity>& newId,
                QObject* parent) const = 0;

};
}

#define POLYMORPHIC_ENTITY_METADATA(Export, Model, Uuid, ObjectKey, PrettyName) \
    MODEL_METADATA(Export, Tutorial::PolymorphicElementFactory, Model, Uuid, ObjectKey, PrettyName)

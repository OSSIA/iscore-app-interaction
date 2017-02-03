#pragma once
#include <iscore/command/Command.hpp>
#include <AppInteraction/Process/AppInteractionProcessModel.hpp>
#include <AppInteraction/Commands/AppInteractionCommandFactory.hpp>
#include <AppInteraction/PolymorphicEntity/PolymorphicEntityFactory.hpp>

namespace AppInteraction
{
class AddEntity: public iscore::Command
{
        ISCORE_COMMAND_DECL(AppInteraction::CommandFactoryName(), AddEntity, "Add a polymorphic entity")

    public:
        AddEntity(
            const AppInteraction::ProcessModel& model,
            PolymorphicElementFactory::ConcreteKey key);

        void undo() const override;
        void redo() const override;

    protected:
        void serializeImpl(DataStreamInput & s) const override;
        void deserializeImpl(DataStreamOutput & s) override;

    private:
        Path<ProcessModel> m_model;

        //! Key to identify the instance we want to create
        PolymorphicElementFactory::ConcreteKey m_key;

        //! The identifier of the object to be created
        Id<PolymorphicEntity> m_id;
};
}

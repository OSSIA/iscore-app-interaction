#pragma once
#include <iscore/command/Command.hpp>
#include <Tutorial/Process/TutorialProcessModel.hpp>
#include <Tutorial/Commands/TutorialCommandFactory.hpp>

namespace Tutorial
{
/**
 * @brief The RemoveBanana class
 */
class RemoveBanana : public iscore::Command
{
        // The following macro is used to allow CMake to parseall the commands in a plug-in,
        // and to provide some metadata (e.g. the name that will be shown to the user)
        ISCORE_COMMAND_DECL(Tutorial::CommandFactoryName(), RemoveBanana, "Rm a banana")

    public:
        RemoveBanana(const Tutorial::ProcessModel& model);

        void undo() const override;
        void redo() const override;

    protected:
        void serializeImpl(DataStreamInput & s) const override;
        void deserializeImpl(DataStreamOutput & s) override;

    private:
        Path<ProcessModel> m_model;
};
}

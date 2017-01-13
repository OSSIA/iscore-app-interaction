#pragma once
#include <iscore/command/Command.hpp>
#include <Tutorial/Process/TutorialProcessModel.hpp>
#include <Tutorial/Commands/TutorialCommandFactory.hpp>

namespace Tutorial
{
/**
 * @brief The AddBanana class
 *
 * This is an example of a command.
 * The command patterns enables undo-redo.
 *
 * The command classes also must be able to serialize themselves.
 * This is used :
 * - For google-docs like edition with iscore-addon-network.
 * - For restoring the application if there is a crash.
 *
 * It is *extremely* important not to save pointers to anything in the commands.
 * This is because if all commands were undone, and then redone, the pointer
 * in the command may now be invalid since the pointed-to object has certainly been deleted
 * and recreated in previous commands.
 *
 * Instead, we save paths to objects in the object tree with \ref Path.
 */
class AddBanana : public iscore::Command
{
        // The following macro is used to allow CMake to parseall the commands in a plug-in,
        // and to provide some metadata (e.g. the name that will be shown to the user)
        ISCORE_COMMAND_DECL(Tutorial::CommandFactoryName(), AddBanana, "Add a banana")

    public:
        AddBanana(const Tutorial::ProcessModel& model);

        void undo() const override;
        void redo() const override;

    protected:
        void serializeImpl(DataStreamInput & s) const override;
        void deserializeImpl(DataStreamOutput & s) override;

    private:
        Path<ProcessModel> m_model;
};
}

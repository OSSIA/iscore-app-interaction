#include "AddBanana.hpp"
#include <iscore/model/path/PathSerialization.hpp>

namespace Tutorial
{
AddBanana::AddBanana(
        const Tutorial::ProcessModel& model):
    m_model{model}
{
}

void AddBanana::undo() const
{
    Tutorial::ProcessModel& proc = m_model.find();
    proc.setBananas(proc.bananas() - 1);
}

void AddBanana::redo() const
{
    Tutorial::ProcessModel& proc = m_model.find();
    proc.setBananas(proc.bananas() + 1);
}

void AddBanana::serializeImpl(DataStreamInput& s) const
{
    s << m_model;
}

void AddBanana::deserializeImpl(DataStreamOutput& s)
{
    s >> m_model;
}
}

#include "removebanana.hpp"
#include <iscore/model/path/PathSerialization.hpp>

namespace Tutorial
{
RemoveBanana::RemoveBanana(
        const Tutorial::ProcessModel& model):
    m_model{model}
{
}

void RemoveBanana::undo() const
{
    Tutorial::ProcessModel& proc = m_model.find();
    proc.setBananas(proc.bananas() + 1);
}

void RemoveBanana::redo() const
{
    Tutorial::ProcessModel& proc = m_model.find();
    proc.setBananas(proc.bananas() - 1);
}

void RemoveBanana::serializeImpl(DataStreamInput& s) const
{
    s << m_model;
}

void RemoveBanana::deserializeImpl(DataStreamOutput& s)
{
    s >> m_model;
}
}


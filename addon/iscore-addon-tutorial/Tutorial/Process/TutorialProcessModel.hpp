#pragma once
#include <Process/Process.hpp>
#include <Tutorial/Process/TutorialProcessMetadata.hpp>

#include <Tutorial/SimpleElement/SimpleElement.hpp>
#include <Tutorial/PolymorphicEntity/PolymorphicEntity.hpp>

#include <iscore/model/EntityMap.hpp>

namespace Tutorial
{
class ProcessModel final : public Process::ProcessModel
{
        ISCORE_SERIALIZE_FRIENDS
        MODEL_METADATA_IMPL(Tutorial::ProcessModel)

        Q_PROPERTY(int bananas READ bananas WRITE setBananas NOTIFY bananasChanged)

        Q_OBJECT

    public:
        ProcessModel(const TimeValue& duration,
                     const Id<Process::ProcessModel>& id,
                     QObject* parent);

        template<typename Impl>
        ProcessModel(Impl& vis, QObject* parent) :
            Process::ProcessModel{vis, parent}
        {
            vis.writeTo(*this);
        }

        iscore::EntityMap<SimpleElement> simpleElements;
        iscore::EntityMap<PolymorphicEntity> polymorphicEntities;

        int bananas() const;
        void setBananas(int bananas);

    signals:
        void bananasChanged(int bananas);

    private:
        ProcessModel(const ProcessModel& source,
                     const Id<Process::ProcessModel>& id,
                     QObject* parent);

        QString prettyName() const override;
        void startExecution() override;
        void stopExecution() override;
        void reset() override;
        ProcessStateDataInterface*startStateData() const override;
        ProcessStateDataInterface*endStateData() const override;
        Selection selectableChildren() const override;
        Selection selectedChildren() const override;
        void setSelection(const Selection& s) const override;

        void setDurationAndScale(const TimeValue& newDuration) override;
        void setDurationAndGrow(const TimeValue& newDuration) override;
        void setDurationAndShrink(const TimeValue& newDuration) override;

        int m_bananas{};
};
}

#pragma once
#include <Process/Process.hpp>
#include <AppInteraction/Process/AppInteractionProcessMetadata.hpp>

#include <AppInteraction/SimpleElement/SimpleElement.hpp>
#include <AppInteraction/PolymorphicEntity/PolymorphicEntity.hpp>

#include <State/Address.hpp>

#include <iscore/model/EntityMap.hpp>
#include "AppInteraction/Connection/ConnectionManagerFaussaire.hpp"

namespace AppInteraction
{
class ProcessModel final : public Process::ProcessModel
{
        ISCORE_SERIALIZE_FRIENDS
        MODEL_METADATA_IMPL(AppInteraction::ProcessModel)

        Q_OBJECT
        Q_PROPERTY(::State::AddressAccessor address READ address WRITE setAddress
                       NOTIFY addressChanged)
        Q_PROPERTY(double min READ min WRITE setMin NOTIFY minChanged)
        Q_PROPERTY(double max READ max WRITE setMax NOTIFY maxChanged)
    public:
        ProcessModel(const TimeVal& duration,
                     const Id<Process::ProcessModel>& id,
                     QObject* parent);

        template<typename Impl>
        ProcessModel(Impl& vis, QObject* parent) :
            Process::ProcessModel{vis, parent}
        {
            vis.writeTo(*this);
        }

        //Getters:
        ::State::AddressAccessor address() const;
        int interactionType() const;
        int mobileDevice() const;
        double min() const;
        double max() const;

        //Setters:
        void setAddress(const ::State::AddressAccessor& arg);
        void setInteractionType(int);
        void setMobileDevice(int);
        void setMin(double);
        void setMax(double);

        iscore::EntityMap<SimpleElement> simpleElements;
        iscore::EntityMap<PolymorphicEntity> polymorphicEntities;

        QString prettyName() const override;

    signals:
        void addressChanged(const ::State::AddressAccessor&);
        void interactionTypeChanged(int);
        void mobileDeviceChanged(int);
        void minChanged(double);
        void maxChanged(double);

    private:
        ProcessModel(const ProcessModel& source,
                     const Id<Process::ProcessModel>& id,
                     QObject* parent);

        void startExecution() override;
        void stopExecution() override;
        void reset() override;
        ProcessStateDataInterface*startStateData() const override;
        ProcessStateDataInterface*endStateData() const override;
        Selection selectableChildren() const override;
        Selection selectedChildren() const override;
        void setSelection(const Selection& s) const override;

        void setDurationAndScale(const TimeVal& newDuration) override;
        void setDurationAndGrow(const TimeVal& newDuration) override;
        void setDurationAndShrink(const TimeVal& newDuration) override;

    //Attributes :
     ::State::AddressAccessor m_address; //device/parameter address (where to send the value received from app)
     int m_interactionType; //index of chosen interaction type
     int m_mobileDevice; //index of chosen connected mobile device
     double m_min; //min value to send to m_address
     double m_max; //max value to send to m_address

};
}

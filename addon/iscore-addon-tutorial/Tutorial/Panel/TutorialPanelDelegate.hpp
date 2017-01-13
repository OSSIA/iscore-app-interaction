#pragma once
#include <iscore/plugins/panel/PanelDelegate.hpp>
#include <iscore/plugins/panel/PanelDelegateFactory.hpp>

namespace Tutorial
{

class PanelDelegate final :
        public QObject,
        public iscore::PanelDelegate
{
    public:
        PanelDelegate(
                const iscore::GUIApplicationContext& ctx);

    private:
        QWidget *widget() override;

        const iscore::PanelStatus& defaultPanelStatus() const override;

        void on_modelChanged(
                iscore::MaybeDocument oldm,
                iscore::MaybeDocument newm) override;

        void setNewSelection(const Selection& s) override;

        QWidget* m_widget{};
};

class PanelDelegateFactory final :
        public iscore::PanelDelegateFactory
{
        ISCORE_CONCRETE("11114a3b-f123-42f6-84d0-b3af124d5689")

        std::unique_ptr<iscore::PanelDelegate> make(
                const iscore::GUIApplicationContext& ctx) override;
};

}

#pragma once
#include <iscore/plugins/application/GUIApplicationPlugin.hpp>

namespace Tutorial
{
/**
 * @brief The ApplicationPlugin class
 *
 * The ApplicationPlugin is a class that will be instantiated only once.
 * It is accessible in the whole application, by using an \ref iscore::ApplicationContext instance.
 *
 * For instance:
 *
 * \code
 * auto& ctx = iscore::AppContext();
 * auto& my_plugin = ctx.applicationPlugin<Tutorial::ApplicationPlugin>();
 * \endcode
 *
 * Most of the time this is used to have ownership on some global data,
 * without enforcing the existence of a singleton at the type level.
 *
 * It is also used to add document plug-ins to a newly created or loaded document.
 */
class ApplicationPlugin final :
        public iscore::GUIApplicationPlugin
{
    public:
        ApplicationPlugin(
                const iscore::GUIApplicationContext& app);

    protected:
        void on_newDocument(iscore::Document& doc) override;

        void on_documentChanged(
                iscore::Document* olddoc,
                iscore::Document* newdoc) override;

        void initialize() override;

        iscore::GUIElements makeGUIElements() override;

        bool handleStartup() override;

        void on_initDocument(iscore::Document& doc) override;

        void on_loadedDocument(iscore::Document& doc) override;

        void on_createdDocument(iscore::Document& doc) override;

        void prepareNewDocument() override;

        void on_activeWindowChanged() override;
};
}

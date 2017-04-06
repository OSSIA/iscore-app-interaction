#pragma once
#include <iscore/plugins/documentdelegate/plugin/DocumentPlugin.hpp>
#include <AppInteraction/Connection/ConnectionManagerFaussaire.hpp>

namespace AppInteraction
{
class DocumentPlugin;
}

UUID_METADATA(,
    iscore::DocumentPluginFactory,
    AppInteraction::DocumentPlugin,
    "3de9703e-0394-497b-8522-b64fc9e07d0c")


namespace AppInteraction
{
/**
 * @brief The DocumentPlugin class
 *
 * The DocumentPlugin is a class that will be instantiated once per document.
 * It is accessible through a \ref iscore::DocumentContext.
 *
 * For instance:
 *
 * \code
 * iscore::DocumentContext& ctx = ...;
 * auto& my_plugin = ctx.plugin<AppInteraction::DocumentPlugin>();
 * \endcode
 *
 * If (and only if) there is no easy access to a \ref iscore::DocumentContext instance,
 * one can get it from an object that is part of the i-score object tree :
 *
 * \code
 * iscore::DocumentContext& ctx = iscore::IDocument::documentContext(some_object);
 * \endcode
 *
 * But this should seldom be used, and especially not in resource-intensive parts of
 * the application. If it is going to be reused, the context should be cached somewhere.
 *
 */
class DocumentPlugin final :
        public iscore::DocumentPlugin
{
        Q_OBJECT

        private:
            /**
             * @brief m_connectionManager : instance of ConnectionManager used in this AppInteraction Process
             */
            connectionFaussaire::ConnectionManagerFaussaire* m_connectionManager = new connectionFaussaire::ConnectionManagerFaussaire();
        public:
            /**
             * @brief connectionManager
             * @return getter for attribute m_connectionManager
             */
            connectionFaussaire::ConnectionManagerFaussaire* connectionManager();

            explicit DocumentPlugin(
                    const iscore::DocumentContext& ctx,
                    Id<iscore::DocumentPlugin> id,
                    QObject* parent);

            virtual ~DocumentPlugin();

};
}

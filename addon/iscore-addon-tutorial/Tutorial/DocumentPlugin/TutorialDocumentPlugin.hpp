#pragma once
#include <iscore/plugins/documentdelegate/plugin/DocumentPlugin.hpp>

namespace Tutorial
{
class DocumentPlugin;
}

UUID_METADATA(,
    iscore::DocumentPluginFactory,
    Tutorial::DocumentPlugin,
    "164843db-345f-4e31-b614-f8de5ca7e94f")

namespace Tutorial
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
 * auto& my_plugin = ctx.plugin<Tutorial::DocumentPlugin>();
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
        public iscore::SerializableDocumentPlugin
{
        Q_OBJECT
        ISCORE_SERIALIZE_FRIENDS

        SERIALIZABLE_MODEL_METADATA_IMPL(DocumentPlugin)

        public:
            explicit DocumentPlugin(
                    const iscore::DocumentContext& ctx,
                    Id<iscore::DocumentPlugin> id,
                    QObject* parent);

        template<typename Impl>
        DocumentPlugin(
                const iscore::DocumentContext& ctx,
                Impl& vis,
                QObject* parent):
            iscore::SerializableDocumentPlugin{ctx, vis, parent}
        {
            vis.writeTo(*this);
        }
};

using DocumentPluginFactory = iscore::DocumentPluginFactory_T<DocumentPlugin>;
}

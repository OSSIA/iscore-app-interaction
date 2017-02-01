#include "iscore_addon_app_interaction.hpp"
#include <iscore_addon_app_interaction_commands_files.hpp>

#include <AppInteraction/Process/AppInteractionProcessFactory.hpp>
#include <AppInteraction/Process/Executor/AppInteractionProcessExecutor.hpp>
#include <AppInteraction/Process/Inspector/AppInteractionProcessInspector.hpp>
#include <AppInteraction/Process/LocalTree/AppInteractionProcessLocalTree.hpp>
#include <AppInteraction/Process/Layer/AppInteractionProcessLayerFactory.hpp>
#include <AppInteraction/ApplicationPlugin/AppInteractionApplicationPlugin.hpp>
#include <AppInteraction/DocumentPlugin/AppInteractionDocumentPlugin.hpp>
#include <AppInteraction/PolymorphicEntity/PolymorphicEntityFactory.hpp>
#include <AppInteraction/PolymorphicEntity/Implementation/ConcretePolymorphicEntity.hpp>
#include <AppInteraction/Panel/AppInteractionPanelDelegate.hpp>

#include <iscore/plugins/customfactory/FactorySetup.hpp>

iscore_addon_app_interaction::iscore_addon_app_interaction()
{

}

iscore_addon_app_interaction::~iscore_addon_app_interaction()
{

}

/**
 * @brief iscore_addon_app_interaction::required
 * @return Features that this plug-in requires.
 *
 * If a feature is listed here, i-score will load the
 * plug-in providing this feature (through \ref iscore::Plugin_QtInterface::offered)
 * before this one.
 */
auto iscore_addon_app_interaction::required() const
  -> std::vector<iscore::PluginKey>
{
    return {};
}

/**
 * @brief iscore_addon_app_interaction::updateSaveFile
 * This function is called if someone tries to load
 * a save file that was created with a previous version
 * of this plug-in.
 * This allows to update the JSON data in order to load
 * it in the current version.
 */
void iscore_addon_app_interaction::updateSaveFile(
        QJsonObject& obj,
        iscore::Version obj_version,
        iscore::Version current_version)
{

}

/**
 * @brief iscore_addon_app_interaction::factoryFamilies
 * This function allows the plug-in to provide new factory types.
 * All plug-ins will be scanned for factories of the provided type.
 *
 * For instance, a new interface to display some elements in a toolbar.
 *
 * Elements registered here can then be used through an \ref iscore::ApplicationContext
 * instance :
 *
 * \code
 * auto& ctx = iscore::AppContext();
 * auto& my_factories = ctx.interfaces<AppInteraction::PolymorphicElementFactoryList>();
 * \endcode
 */
std::vector<std::unique_ptr<iscore::InterfaceListBase> >
iscore_addon_app_interaction::factoryFamilies()
{
    return make_ptr_vector<iscore::InterfaceListBase,
            AppInteraction::PolymorphicElementFactoryList>();
}


/**
 * @brief iscore_addon_app_interaction::factories
 *
 * This function allows the plug-in to provide implementations for the
 * factory types provided earlier.
 *
 * For instance, factories for the elements that will go in the toolbar.
 *
 * An helper function is provided : \ref instantiate_factories .
 *
 * The factories registered here are then accessible like this :
 *
 * \code
 * // Get a context or use an existing one
 * auto& ctx = iscore::AppContext();
 *
 * // Get the list of factories that we are looking for
 * auto& my_factories = ctx.interfaces<Process::ProcessList>();
 *
 * // Get the key for the actual factory we want;
 * // Instead of doing this, it could already be saved somewhere for instance.
 * auto process_key = Metadata<ConcreteKey_k, AppInteraction::ProcessFactory>::get();
 *
 * // Get the actual factory
 * auto my_process_factory = my_factories.get(process_key);
 * \endcode
 *
 * However, it should rarely be necessary to access a particular factory.
 * The general case should be getting a factory according to an user input.
 */
std::vector<std::unique_ptr<iscore::InterfaceBase> >
iscore_addon_app_interaction::factories(
        const iscore::ApplicationContext& ctx,
        const iscore::InterfaceKey& key) const
{
    return instantiate_factories<
            iscore::ApplicationContext,
        FW<
           Process::ProcessModelFactory, // An abstract factory
           AppInteraction::ProcessFactory // followed by all the matching concrete factories
          >,
        FW<
           Process::LayerFactory, // Another abstract factory
           AppInteraction::LayerFactory // etc...
          >,
        FW<Process::InspectorWidgetDelegateFactory,
           AppInteraction::InspectorFactory>,
        FW<Engine::Execution::ProcessComponentFactory,
           AppInteraction::ProcessExecutorComponentFactory>,
        FW<Engine::LocalTree::ProcessComponentFactory,
           AppInteraction::LocalTreeProcessComponentFactory>,
        FW<iscore::DocumentPluginFactory,
           AppInteraction::DocumentPluginFactory>,
        FW<iscore::PanelDelegateFactory,
           AppInteraction::PanelDelegateFactory>,
        FW<

           AppInteraction::PolymorphicElementFactory,
           AppInteraction::ConcretePolymorphicElementFactory
          >
    >(ctx, key);
}

/**
 * @brief iscore_addon_app_interaction::make_applicationPlugin
 *
 * This function allows to instantiate an application-wide object.
 * These objects are instantiated before any factory.
 */
iscore::GUIApplicationPlugin*
iscore_addon_app_interaction::make_applicationPlugin(
        const iscore::GUIApplicationContext& app)
{
    return new AppInteraction::ApplicationPlugin{app};
}

/**
 * @brief iscore_addon_app_interaction::make_commands
 * This function provides the list of commands available with this
 * plug-in.
 */
std::pair<const CommandGroupKey, CommandGeneratorMap>
iscore_addon_app_interaction::make_commands()
{
    using namespace AppInteraction;
    std::pair<const CommandGroupKey, CommandGeneratorMap> cmds{
        CommandFactoryName(),
        CommandGeneratorMap{}};

    // CMake generates the "addon_commands.hpp" and "addon_commands_file.hpp"
    // by scanning the source files for \ref ISCORE_COMMAND_DECL or \ref ISCORE_COMMAND_DECL_T.
    using Types = TypeList<
#include <iscore_addon_app_interaction_commands.hpp>
      >;

    for_each_type<Types>(iscore::commands::FactoryInserter{cmds.second});

    return cmds;
}

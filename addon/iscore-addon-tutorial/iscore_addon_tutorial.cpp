#include "iscore_addon_tutorial.hpp"
#include <iscore_addon_tutorial_commands_files.hpp>

#include <Tutorial/Process/TutorialProcessFactory.hpp>
#include <Tutorial/Process/Executor/TutorialProcessExecutor.hpp>
#include <Tutorial/Process/Inspector/TutorialProcessInspector.hpp>
#include <Tutorial/Process/LocalTree/TutorialProcessLocalTree.hpp>
#include <Tutorial/Process/Layer/TutorialProcessLayerFactory.hpp>
#include <Tutorial/ApplicationPlugin/TutorialApplicationPlugin.hpp>
#include <Tutorial/DocumentPlugin/TutorialDocumentPlugin.hpp>
#include <Tutorial/PolymorphicEntity/PolymorphicEntityFactory.hpp>
#include <Tutorial/PolymorphicEntity/Implementation/ConcretePolymorphicEntity.hpp>
#include <Tutorial/Panel/TutorialPanelDelegate.hpp>

#include <iscore/plugins/customfactory/FactorySetup.hpp>

iscore_addon_tutorial::iscore_addon_tutorial()
{

}

iscore_addon_tutorial::~iscore_addon_tutorial()
{

}

/**
 * @brief iscore_addon_tutorial::required
 * @return Features that this plug-in requires.
 *
 * If a feature is listed here, i-score will load the
 * plug-in providing this feature (through \ref iscore::Plugin_QtInterface::offered)
 * before this one.
 */
auto iscore_addon_tutorial::required() const
  -> std::vector<iscore::PluginKey>
{
    return {};
}

/**
 * @brief iscore_addon_tutorial::updateSaveFile
 * This function is called if someone tries to load
 * a save file that was created with a previous version
 * of this plug-in.
 * This allows to update the JSON data in order to load
 * it in the current version.
 */
void iscore_addon_tutorial::updateSaveFile(
        QJsonObject& obj,
        iscore::Version obj_version,
        iscore::Version current_version)
{

}

/**
 * @brief iscore_addon_tutorial::factoryFamilies
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
 * auto& my_factories = ctx.interfaces<Tutorial::PolymorphicElementFactoryList>();
 * \endcode
 */
std::vector<std::unique_ptr<iscore::InterfaceListBase> >
iscore_addon_tutorial::factoryFamilies()
{
    return make_ptr_vector<iscore::InterfaceListBase,
            Tutorial::PolymorphicElementFactoryList>();
}


/**
 * @brief iscore_addon_tutorial::factories
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
 * auto process_key = Metadata<ConcreteKey_k, Tutorial::ProcessFactory>::get();
 *
 * // Get the actual factory
 * auto my_process_factory = my_factories.get(process_key);
 * \endcode
 *
 * However, it should rarely be necessary to access a particular factory.
 * The general case should be getting a factory according to an user input.
 */
std::vector<std::unique_ptr<iscore::InterfaceBase> >
iscore_addon_tutorial::factories(
        const iscore::ApplicationContext& ctx,
        const iscore::InterfaceKey& key) const
{
    return instantiate_factories<
            iscore::ApplicationContext,
        FW<
           Process::ProcessModelFactory, // An abstract factory
           Tutorial::ProcessFactory // followed by all the matching concrete factories
          >,
        FW<
           Process::LayerFactory, // Another abstract factory
           Tutorial::LayerFactory // etc...
          >,
        FW<Process::InspectorWidgetDelegateFactory,
           Tutorial::InspectorFactory>,
        FW<Engine::Execution::ProcessComponentFactory,
           Tutorial::ProcessExecutorComponentFactory>,
        FW<Engine::LocalTree::ProcessComponentFactory,
           Tutorial::LocalTreeProcessComponentFactory>,
        FW<iscore::DocumentPluginFactory,
           Tutorial::DocumentPluginFactory>,
        FW<iscore::PanelDelegateFactory,
           Tutorial::PanelDelegateFactory>,
        FW<
           // This abstract factory was defined inside the tutorial plug-in :
           Tutorial::PolymorphicElementFactory,
           Tutorial::ConcretePolymorphicElementFactory
          >
    >(ctx, key);
}

/**
 * @brief iscore_addon_tutorial::make_applicationPlugin
 *
 * This function allows to instantiate an application-wide object.
 * These objects are instantiated before any factory.
 */
iscore::GUIApplicationPlugin*
iscore_addon_tutorial::make_applicationPlugin(
        const iscore::GUIApplicationContext& app)
{
    return new Tutorial::ApplicationPlugin{app};
}

/**
 * @brief iscore_addon_tutorial::make_commands
 * This function provides the list of commands available with this
 * plug-in.
 */
std::pair<const CommandGroupKey, CommandGeneratorMap>
iscore_addon_tutorial::make_commands()
{
    using namespace Tutorial;
    std::pair<const CommandGroupKey, CommandGeneratorMap> cmds{
        CommandFactoryName(),
        CommandGeneratorMap{}};

    // CMake generates the "addon_commands.hpp" and "addon_commands_file.hpp"
    // by scanning the source files for \ref ISCORE_COMMAND_DECL or \ref ISCORE_COMMAND_DECL_T.
    using Types = TypeList<
#include <iscore_addon_tutorial_commands.hpp>
      >;

    for_each_type<Types>(iscore::commands::FactoryInserter{cmds.second});

    return cmds;
}

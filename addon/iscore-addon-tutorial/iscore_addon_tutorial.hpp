#pragma once
#include <iscore/plugins/qt_interfaces/PluginRequirements_QtInterface.hpp>
#include <iscore/plugins/qt_interfaces/FactoryInterface_QtInterface.hpp>
#include <iscore/plugins/qt_interfaces/FactoryFamily_QtInterface.hpp>
#include <iscore/plugins/qt_interfaces/GUIApplicationPlugin_QtInterface.hpp>
#include <iscore/plugins/qt_interfaces/CommandFactory_QtInterface.hpp>

#include <iscore/application/ApplicationContext.hpp>
#include <iscore/command/CommandGeneratorMap.hpp>
#include <iscore/command/Command.hpp>
#include <iscore/plugins/customfactory/FactoryFamily.hpp>

#include <QObject>
#include <utility>
#include <vector>

/**
 * @brief The iscore_addon_tutorial class
 *
 * This class is the entry-point of the i-score plugin.
 *
 * \ref iscore::PluginLoader::loadPlugins contains the plug-in loading code.
 * \ref iscore::ApplicationInterface::loadPluginData contains plug-in setup code.
 *
 * The loaded plug-in data can always be accessed through \ref iscore::AppContext
 * but it is better practice to have the objects depend on their requirements
 * through constructor injection, and provide these requirements in the object
 * factories which have access to the same context without requiring a singleton function.
 *
 * When making a plug-in, not all the interfaces used here may be necessary; this
 * one aims to give an overview of all the possibilities.
 */
class iscore_addon_tutorial final :
        public QObject,
        public iscore::Plugin_QtInterface,
        public iscore::FactoryInterface_QtInterface,
        public iscore::FactoryList_QtInterface,
        public iscore::GUIApplicationPlugin_QtInterface,
        public iscore::CommandFactory_QtInterface
{
        Q_OBJECT
        Q_PLUGIN_METADATA(IID FactoryInterface_QtInterface_iid)
        Q_INTERFACES(
                iscore::Plugin_QtInterface
                iscore::FactoryInterface_QtInterface
                iscore::FactoryList_QtInterface
                iscore::GUIApplicationPlugin_QtInterface
                iscore::CommandFactory_QtInterface
                )

  // Version, and unique identifier for the plug-in.
  // The uuid can be generated with "uuidgen" on linux or OS X.
  ISCORE_PLUGIN_METADATA(1, "e8601d50-e29e-4437-8c65-fcee42655a0b")

    public:
        iscore_addon_tutorial();
        virtual ~iscore_addon_tutorial();

    private:
        // Defined in Plugin_QtInterface
        std::vector<iscore::PluginKey> required() const override;

        void updateSaveFile(
                QJsonObject& obj,
                iscore::Version obj_version,
                iscore::Version current_version) override;

        // Defined in FactoryList_QtInterface
        std::vector<std::unique_ptr<iscore::InterfaceListBase>> factoryFamilies() override;

        // Defined in FactoryInterface_QtInterface
        std::vector<std::unique_ptr<iscore::InterfaceBase>> factories(
                const iscore::ApplicationContext& ctx,
                const iscore::InterfaceKey& key) const override;

        // Defined in GUIApplicationPlugin_QtInterface
        iscore::GUIApplicationPlugin* make_applicationPlugin(
                const iscore::GUIApplicationContext& app) override;

        // Defined in CommandFactory_QtInterface
        std::pair<const CommandGroupKey, CommandGeneratorMap> make_commands() override;

};

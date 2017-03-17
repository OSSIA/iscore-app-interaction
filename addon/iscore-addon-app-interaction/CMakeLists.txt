cmake_minimum_required(VERSION 3.1)
project(iscore_addon_app_interaction LANGUAGES CXX)

# General initialization
iscore_common_setup()

# Source files
set(HDRS
    AppInteraction/Process/Executor/AppInteractionProcessExecutor.hpp
    AppInteraction/Process/Layer/AppInteractionProcessPresenter.hpp
    AppInteraction/Process/Layer/AppInteractionProcessView.hpp
    AppInteraction/Process/Layer/AppInteractionProcessLayerFactory.hpp
    AppInteraction/Process/Layer/AppInteractionProcessLayer.hpp
    AppInteraction/Process/LocalTree/AppInteractionProcessLocalTree.hpp
    AppInteraction/Process/Inspector/AppInteractionProcessInspector.hpp
    AppInteraction/Process/State/AppInteractionProcessState.hpp
    AppInteraction/Process/State/Widgets/InteractionTypeWidget.hpp
    AppInteraction/Process/State/Widgets/MobileDevicesWidget.hpp
    AppInteraction/Process/AppInteractionProcessModel.hpp
    AppInteraction/Process/AppInteractionProcessMetadata.hpp
    AppInteraction/Process/AppInteractionProcessFactory.hpp
    AppInteraction/ApplicationPlugin/AppInteractionApplicationPlugin.hpp
    AppInteraction/Panel/AppInteractionPanelDelegate.hpp
    AppInteraction/Panel/AppInteractionPanelDelegateFactory.hpp
    AppInteraction/StateProcess/AppInteractionStateProcess.hpp
    AppInteraction/StateProcess/AppInteractionStateProcessFactory.hpp
    AppInteraction/Settings/AppInteractionSettingsModel.hpp
    AppInteraction/Settings/AppInteractionSettingsView.hpp
    AppInteraction/Settings/AppInteractionSettingsPresenter.hpp
    AppInteraction/Settings/AppInteractionSettingsFactory.hpp
    AppInteraction/DocumentPlugin/AppInteractionDocumentPlugin.hpp
    AppInteraction/Commands/AddEntity.hpp
    AppInteraction/Commands/AppInteractionCommandFactory.hpp
    AppInteraction/Commands/ChangeAddress.hpp
    AppInteraction/Commands/ChangeInteractionType.hpp
    AppInteraction/Commands/ChangeMobileDevice.hpp
    AppInteraction/Commands/SetAppInteractionMax.hpp
    AppInteraction/Commands/SetAppInteractionMin.hpp	
    AppInteraction/SimpleElement/SimpleElement.hpp
    AppInteraction/SimpleElement/SimpleEntity.hpp
    AppInteraction/PolymorphicEntity/PolymorphicEntity.hpp
    AppInteraction/PolymorphicEntity/PolymorphicEntityFactory.hpp
    AppInteraction/PolymorphicEntity/Implementation/ConcretePolymorphicEntity.hpp
    AppInteraction/Connection/Connection.hpp
    AppInteraction/Connection/ConnectionFaussaire.hpp
    AppInteraction/Connection/ConnectionManager.hpp
    AppInteraction/Connection/ConnectionManagerFaussaire.hpp

    iscore_addon_app_interaction.hpp

)
set(SRCS
    AppInteraction/SimpleElement/SimpleElement.cpp
    AppInteraction/Process/Executor/AppInteractionProcessExecutor.cpp
    AppInteraction/Process/Layer/AppInteractionProcessPresenter.cpp
    AppInteraction/Process/Layer/AppInteractionProcessView.cpp
    AppInteraction/Process/LocalTree/AppInteractionProcessLocalTree.cpp
    AppInteraction/Process/Inspector/AppInteractionProcessInspector.cpp
    AppInteraction/Process/State/AppInteractionProcessState.cpp
    AppInteraction/Process/State/Widgets/InteractionTypeWidget.cpp
    AppInteraction/Process/State/Widgets/MobileDevicesWidget.cpp
    AppInteraction/Process/AppInteractionProcessModel.cpp
    AppInteraction/ApplicationPlugin/AppInteractionApplicationPlugin.cpp
    AppInteraction/Panel/AppInteractionPanelDelegate.cpp
    AppInteraction/StateProcess/AppInteractionStateProcess.cpp
    AppInteraction/Settings/AppInteractionSettingsModel.cpp
    AppInteraction/Settings/AppInteractionSettingsView.cpp
    AppInteraction/Settings/AppInteractionSettingsPresenter.cpp
    AppInteraction/DocumentPlugin/AppInteractionDocumentPlugin.cpp
    AppInteraction/Commands/AddEntity.cpp
    AppInteraction/Commands/ChangeAddress.cpp
    AppInteraction/Commands/ChangeInteractionType.cpp
    AppInteraction/Commands/ChangeMobileDevice.cpp
    AppInteraction/SimpleElement/SimpleEntity.cpp
    AppInteraction/PolymorphicEntity/PolymorphicEntity.cpp
    AppInteraction/PolymorphicEntity/PolymorphicEntityFactory.cpp
    AppInteraction/PolymorphicEntity/Implementation/ConcretePolymorphicEntity.cpp
    AppInteraction/Connection/Connection.cpp
    AppInteraction/Connection/ConnectionFaussaire.cpp
    AppInteraction/Connection/ConnectionManager.cpp
    AppInteraction/Connection/ConnectionManagerFaussaire.cpp
    
    iscore_addon_app_interaction.cpp
)

# Creation of the library
add_library(${PROJECT_NAME} ${SRCS} ${HDRS} ${QRCS})

# Code generation
iscore_generate_command_list_file(${PROJECT_NAME} "${HDRS}")

# Link
target_link_libraries(${PROJECT_NAME} PUBLIC iscore_plugin_engine)

# Target-specific options
setup_iscore_plugin(${PROJECT_NAME})

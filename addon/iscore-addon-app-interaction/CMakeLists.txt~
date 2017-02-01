cmake_minimum_required(VERSION 3.1)
project(iscore_addon_tutorial LANGUAGES CXX)

# General initialization
iscore_common_setup()

# Source files
set(HDRS
    Tutorial/Process/Executor/TutorialProcessExecutor.hpp
    Tutorial/Process/Layer/TutorialProcessPresenter.hpp
    Tutorial/Process/Layer/TutorialProcessView.hpp
    Tutorial/Process/Layer/TutorialProcessLayerFactory.hpp
    Tutorial/Process/Layer/TutorialProcessLayer.hpp
    Tutorial/Process/LocalTree/TutorialProcessLocalTree.hpp
    Tutorial/Process/Inspector/TutorialProcessInspector.hpp
    Tutorial/Process/State/TutorialProcessState.hpp
    Tutorial/Process/TutorialProcessModel.hpp
    Tutorial/Process/TutorialProcessMetadata.hpp
    Tutorial/Process/TutorialProcessFactory.hpp
    Tutorial/ApplicationPlugin/TutorialApplicationPlugin.hpp
    Tutorial/Panel/TutorialPanelDelegate.hpp
    Tutorial/Panel/TutorialPanelDelegateFactory.hpp
    Tutorial/StateProcess/TutorialStateProcess.hpp
    Tutorial/StateProcess/TutorialStateProcessFactory.hpp
    Tutorial/Settings/TutorialSettingsModel.hpp
    Tutorial/Settings/TutorialSettingsView.hpp
    Tutorial/Settings/TutorialSettingsPresenter.hpp
    Tutorial/Settings/TutorialSettingsFactory.hpp
    Tutorial/DocumentPlugin/TutorialDocumentPlugin.hpp
    Tutorial/Commands/AddBanana.hpp
    Tutorial/Commands/removebanana.hpp
    Tutorial/Commands/AddEntity.hpp
    Tutorial/Commands/TutorialCommandFactory.hpp
    Tutorial/SimpleElement/SimpleElement.hpp
    Tutorial/SimpleElement/SimpleEntity.hpp
    Tutorial/PolymorphicEntity/PolymorphicEntity.hpp
    Tutorial/PolymorphicEntity/PolymorphicEntityFactory.hpp
    Tutorial/PolymorphicEntity/Implementation/ConcretePolymorphicEntity.hpp

    iscore_addon_tutorial.hpp

)
set(SRCS
    Tutorial/SimpleElement/SimpleElement.cpp
    Tutorial/Process/Executor/TutorialProcessExecutor.cpp
    Tutorial/Process/Layer/TutorialProcessPresenter.cpp
    Tutorial/Process/Layer/TutorialProcessView.cpp
    Tutorial/Process/LocalTree/TutorialProcessLocalTree.cpp
    Tutorial/Process/Inspector/TutorialProcessInspector.cpp
    Tutorial/Process/State/TutorialProcessState.cpp
    Tutorial/Process/TutorialProcessModel.cpp
    Tutorial/ApplicationPlugin/TutorialApplicationPlugin.cpp
    Tutorial/Panel/TutorialPanelDelegate.cpp
    Tutorial/StateProcess/TutorialStateProcess.cpp
    Tutorial/Settings/TutorialSettingsModel.cpp
    Tutorial/Settings/TutorialSettingsView.cpp
    Tutorial/Settings/TutorialSettingsPresenter.cpp
    Tutorial/DocumentPlugin/TutorialDocumentPlugin.cpp
    Tutorial/Commands/AddBanana.cpp
    Tutorial/Commands/removebanana.cpp
    Tutorial/Commands/AddEntity.cpp
    Tutorial/SimpleElement/SimpleEntity.cpp
    Tutorial/PolymorphicEntity/PolymorphicEntity.cpp
    Tutorial/PolymorphicEntity/PolymorphicEntityFactory.cpp
    Tutorial/PolymorphicEntity/Implementation/ConcretePolymorphicEntity.cpp

    iscore_addon_tutorial.cpp
)

# Creation of the library
add_library(${PROJECT_NAME} ${SRCS} ${HDRS} ${QRCS})

# Code generation
iscore_generate_command_list_file(${PROJECT_NAME} "${HDRS}")

# Link
target_link_libraries(${PROJECT_NAME} PUBLIC iscore_plugin_engine)

# Target-specific options
setup_iscore_plugin(${PROJECT_NAME})

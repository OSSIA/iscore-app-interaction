#include "TutorialApplicationPlugin.hpp"

namespace Tutorial
{

ApplicationPlugin::ApplicationPlugin(
        const iscore::GUIApplicationContext& app):
    GUIApplicationPlugin {app}
{

}

void ApplicationPlugin::on_newDocument(
        iscore::Document& doc)
{

}

void ApplicationPlugin::on_documentChanged(
        iscore::Document* olddoc,
        iscore::Document* newdoc)
{

}

void ApplicationPlugin::initialize()
{
}

iscore::GUIElements ApplicationPlugin::makeGUIElements()
{
    return {};
}

bool ApplicationPlugin::handleStartup()
{
    return false;
}

void ApplicationPlugin::on_initDocument(iscore::Document& doc)
{
}

void ApplicationPlugin::on_loadedDocument(iscore::Document& doc)
{
}

void ApplicationPlugin::on_createdDocument(iscore::Document& doc)
{
}

void ApplicationPlugin::prepareNewDocument()
{
}

void ApplicationPlugin::on_activeWindowChanged()
{
}

}

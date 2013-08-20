#include "BasePlugin.h"

#include <iostream>

namespace GPPGeneric
{

GenericVisitor* BasePlugin::getVisitor()
{
    return this;
}

void BasePlugin::initialize(PluginAPI* plugin)
{
    this->plugin = plugin;
}

} // end GPPGeneric
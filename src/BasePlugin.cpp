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
    _plugin = plugin;
}

} // end GPPGeneric
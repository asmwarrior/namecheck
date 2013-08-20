#include "BasePlugin.h"

#include <iostream>

namespace GPPGeneric
{

void BasePlugin::initialize(PluginAPI* plugin)
{
	this->plugin = plugin;
}

} // end GPPGeneric
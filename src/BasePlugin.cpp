/**
* Taller Technologies - Software Development Company
* Copyright 2013 - All rights reserved
*
* @file        BasePlugin.cpp
* @author      Francisco Herrero and Marcos Diaz
* @date        2013-09-06
* @brief       This is the implementation of BasePlugin interface
*/

#include <iostream>
#include "BasePlugin.h"

namespace GPPGeneric
{

GenericVisitor* BasePlugin::getVisitor()
{
    return this;
}

void BasePlugin::initialize(PluginApi* plugin)
{
    _plugin = plugin;
}

} // end GPPGeneric
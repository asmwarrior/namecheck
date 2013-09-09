/**
* Taller Technologies - Software Development Company
* Copyright 2013 - All rights reserved
*
* @file        BasePlugin.cpp
* @author      Francisco Herrero and Marcos Diaz
* @date        2013-09-06
* @brief       This is the implementation of BasePlugin interface
*/

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
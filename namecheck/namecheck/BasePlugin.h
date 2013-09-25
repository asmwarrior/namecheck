/**
 * Taller Technologies - Software Development Company
 * Copyright 2013 - All rights reserved
 *
 * @file        BasePlugin.h
 * @author      Fracisco Herrero and Marcos Diaz
 * @date        2013-09-06
 * @brief       Header file for namecheck providing BasePlugin class.
 */

#ifndef GPP_BASE_PLUGIN_H
#define GPP_BASE_PLUGIN_H

#include <traverser/GenericVisitor.h>
#include "PluginAPI.h"

namespace NamingChecker
{

/**
 *  @brief Base class for the visitor.
 *
 * This class add to the vistor's interface the initialization method, the _plugin attribute and a method to get
 * the visitor.
 */
class BasePlugin: private GPPGeneric::GenericVisitor
{
public:

    /**
     * @brief this sets the _plugin .
     *
     * @param plugin this is the pointer to the plugin that is going to be set.
     */
    void initialize(PluginApi* plugin);

    /**
     * @brief this gets the visitor.
     *
     * The visitor is this class. But it could change.
     * @return The visitor (in this case a pointer to this).
     */
    GPPGeneric::GenericVisitor* getVisitor();

protected:

    /**
     * @brief This is the plugin for the warnings and error messages.
     *
     */
    PluginApi* _plugin;

};

} // end namespace

#endif
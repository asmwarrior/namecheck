/**
* Taller Technologies - Software Development Company
* Copyright 2013 - All rights reserved
*
* @file        NamingConventionCheckerInline.h
* @author      Franco Riberi
* @date        2013-09-06
* @brief       Header file for namecheck providing NamingConventionPlugin inline implementation.
*/

#ifndef NAMING_CONVENTION_PLUGIN_INLINE_H
#error Internal header file
#endif

#include "NamingConventionPlugin.h"

namespace GPPGeneric
{

inline void NamingConventionPlugin::setPluginWarning(const GenericTree& decl, const std::string& name, const std::string& message)
{
    _errmsg = message + _errmsg + " in " + name;
    _plugin->warning(decl, _errmsg);
}

} //end GPPGeneric
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
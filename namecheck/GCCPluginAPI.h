#ifndef GCC_PLUGIN_API
#define GCC_PLUGIN_API

#include "PluginAPI.h"

namespace GPPGeneric
{

class GCCPluginAPI: public PluginAPI
{
    void warning(const tree& decl, const std::string& message);
    void error(const tree& decl, const std::string& message);
};

} // end GPPGeneric

#endif
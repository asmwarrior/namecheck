#ifndef GPP_PLUGIN_API_H
#define GPP_PLUGIN_API_H

#include <gmp.h>

extern "C"
{
#include "gcc-plugin.h"
#include "tree.h"
}

#include <string>

namespace GPPGeneric
{

struct PluginAPI
{
	virtual void warning(const tree& decl, const std::string& message) = 0;
	virtual void error(const tree& decl, const std::string& message) = 0;
};

} // end GPPGeneric

#endif
#include "GCCPluginAPI.h"
#include <iostream>

namespace GPPGeneric
{

void GCCPluginAPI::warning(const GenericTree& /* decl */, const std::string& message)
{
    //warning_at(DECL_SOURCE_LOCATION(decl), 0, message.c_str());
    std::cerr << message << std::endl;
}

void GCCPluginAPI::error(const GenericTree& /* decl */, const std::string& message)
{
    //error_at(DECL_SOURCE_LOCATION(decl), 0,  message.c_str());
    std::cerr << message << std::endl;
}

} // end GPPGeneric

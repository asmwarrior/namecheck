#include <gtest/gtest.h>
#include <gmock/gmock.h>
#define private public
#define protected public
#include "NamingConventionPlugin.h"
#include "PluginAPI.h"

using ::testing::_;

namespace GPPGeneric{

class APIMock : public PluginAPI
{
public:
    MOCK_METHOD2(warning, void(const GenericTree& decl, const std::string& message));
    MOCK_METHOD2(error, void(const GenericTree& decl, const std::string& message));
};



TEST(PluginAPITests, InterfacesTest2)
{
    NamingConventionPlugin plugin;
    APIMock api;
    PluginAPI* apip = &api;
    GenericTree decl;
    plugin.initialize(apip);
    EXPECT_CALL(api, warning(_,_))              
      .Times(1);
    plugin.visitClassDeclaration(decl, "marcos");
    plugin.visitClassDeclaration(decl, "Marcos");
}

}
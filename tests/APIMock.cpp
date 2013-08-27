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



TEST(PluginAPITests, ClassNameTest)
{
    NamingConventionPlugin plugin;
    APIMock api;
    GenericTree decl = NULL;
    plugin.initialize(&api);
    EXPECT_CALL(api, warning(_,_))              
      .Times(1);
    plugin.visitClassDeclaration(decl, "marcos");
    plugin.visitClassDeclaration(decl, "Marcos");
}

}
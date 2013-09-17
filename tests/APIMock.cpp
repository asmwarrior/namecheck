#include <gtest/gtest.h>
#include <gmock/gmock.h>
#define private public
#define protected public
#include "Visitor/NamingConventionPlugin.h"
#include "Visitor/PluginAPI.h"

using ::testing::_;
using namespace GPPGeneric;

class APIMock : public PluginApi
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
    .Times(7);
    //correct names
    plugin.visitClassDeclaration(decl, "ClassName");

    plugin.visitClassDeclaration(decl, "class_name");
    plugin.visitClassDeclaration(decl, "_className");
    plugin.visitClassDeclaration(decl, "_ClassName");
    plugin.visitClassDeclaration(decl, "isclassname");
    plugin.visitClassDeclaration(decl, "toclassname");
    plugin.visitClassDeclaration(decl, "classNAME");
    plugin.visitClassDeclaration(decl, "CLASSNAME");
}

TEST(PluginAPITests, VariableAndMethodsNamesTest)
{
    NamingConventionPlugin plugin;
    APIMock api;
    GenericTree decl = NULL;
    plugin.initialize(&api);
    const bool isConst = false;
    const std::string typeName = "int";
    EXPECT_CALL(api, warning(_,_))
    .Times(13);

    //correct variable names
    plugin.visitVariableDeclaration(decl, "amount", isConst, typeName);
    plugin.visitVariableDeclaration(decl, "i", isConst, typeName);
    plugin.visitVariableDeclaration(decl, "amoutVisible", isConst, typeName);
    plugin.visitVariableDeclaration(decl, "isVisible", isConst, typeName);

    //incorrect variable names
    plugin.visitVariableDeclaration(decl, "Amout", isConst, typeName);
    plugin.visitVariableDeclaration(decl, "_amout", isConst, typeName);
    plugin.visitVariableDeclaration(decl, "AMOUT", isConst, typeName);
    plugin.visitVariableDeclaration(decl, "amountAvailablE", isConst, typeName);
    plugin.visitVariableDeclaration(decl, "22amout", isConst, typeName);
    plugin.visitVariableDeclaration(decl, "amoutVisible2", isConst, typeName);
    plugin.visitVariableDeclaration(decl, "amout_visible", isConst, typeName);

    //correct method names
    plugin.visitFunctionDeclaration(decl, "process");
    plugin.visitFunctionDeclaration(decl, "processFile");
    plugin.visitFunctionDeclaration(decl, "calculateScore");

    // //incorrect method names
    plugin.visitFunctionDeclaration(decl, "Process");
    plugin.visitFunctionDeclaration(decl, "_calculateScore");
    plugin.visitFunctionDeclaration(decl, "PROCESS_FILE");
    plugin.visitFunctionDeclaration(decl, "processFile_");
    plugin.visitFunctionDeclaration(decl, "processFile_2");
    plugin.visitFunctionDeclaration(decl, "process_file");
}

TEST(PluginAPITests, AttributeNameTest)
{
    NamingConventionPlugin plugin;
    APIMock api;
    GenericTree decl = NULL;
    const bool isConst = false;
    const std::string typeName = "std::string";
    const AccessModifier access = AccessPublic;
    plugin.initialize(&api);
    EXPECT_CALL(api, warning(_,_))
    .Times(7);
    //correct names
    plugin.visitAttributeDeclaration(decl, access, "_amout", isConst, typeName);
    plugin.visitAttributeDeclaration(decl, access, "_i", isConst, typeName);
    plugin.visitAttributeDeclaration(decl, access, "_amoutOfChar", isConst, typeName);
    plugin.visitAttributeDeclaration(decl, access, "_isCircFigure", isConst, typeName);

    //incorrect names
    plugin.visitAttributeDeclaration(decl, access, "__isCircFigure", isConst, typeName);
    plugin.visitAttributeDeclaration(decl, access, "isCircFigure", isConst, typeName);
    plugin.visitAttributeDeclaration(decl, access, "_S", isConst, typeName);
    plugin.visitAttributeDeclaration(decl, access, "amout_available", isConst, typeName);
    plugin.visitAttributeDeclaration(decl, access, "Amout_available", isConst, typeName);
    plugin.visitAttributeDeclaration(decl, access, "_Amout_available", isConst, typeName);
    plugin.visitAttributeDeclaration(decl, access, "_amout_available", isConst, typeName);
}

TEST(PluginAPITests, GlobalConstNameTest)
{
    NamingConventionPlugin plugin;
    APIMock api;
    GenericTree decl = NULL;
    plugin.initialize(&api);
    EXPECT_CALL(api, warning(_,_))
    .Times(4);
    //correct names
    plugin.visitGlobalConstDeclaration(decl, "AMOUT");
    plugin.visitGlobalConstDeclaration(decl, "THIS_IS_A_CONSTANT");

    plugin.visitGlobalConstDeclaration(decl, "THIS_IS_A_CONSTANT_");
    plugin.visitGlobalConstDeclaration(decl, "_amout");
    plugin.visitGlobalConstDeclaration(decl, "Amount");
    plugin.visitGlobalConstDeclaration(decl, "THIS_IS_A_CONSTANT_2");
}

TEST(PluginAPITests, EnumTypeAndValueNamesTest)
{
    NamingConventionPlugin plugin;
    APIMock api;
    GenericTree decl = NULL;
    plugin.initialize(&api);
    EXPECT_CALL(api, warning(_,_))
    .Times(7); //two times per enum type
    //correct enum type names
    plugin.visitEnumTypeDeclaration(decl, "EnumType");

    //incorrect enum type names
    plugin.visitEnumTypeDeclaration(decl, "COLOR");
    plugin.visitEnumTypeDeclaration(decl, "_typeEnum");
    plugin.visitEnumTypeDeclaration(decl, "colorType");

    //correct enum value names
    plugin.visitEnumValueDeclaration(decl, "Red");
    plugin.visitEnumValueDeclaration(decl, "Blue");
    plugin.visitEnumValueDeclaration(decl, "BrownAndBlack");
    plugin.visitEnumValueDeclaration(decl, "Brown_AndB  _lack");

    //incorrect enum value names
    plugin.visitEnumValueDeclaration(decl, "THIS_IS_A_ENUM_VALUE");
    plugin.visitEnumValueDeclaration(decl, "_Value");
    plugin.visitEnumValueDeclaration(decl, "value");
}

TEST(PluginAPITests, TypedefNamesTest)
{
    NamingConventionPlugin plugin;
    APIMock api;
    GenericTree decl = NULL;
    plugin.initialize(&api);
    EXPECT_CALL(api, warning(_,_))
    .Times(6);
    //correct names
    plugin.visitTypeDeclaration(decl, "Regexs");
    plugin.visitTypeDeclaration(decl, "GenericBackends");

    //incorrect names
    plugin.visitTypeDeclaration(decl, "REGEXS");
    plugin.visitTypeDeclaration(decl, "_REGEXS");
    plugin.visitTypeDeclaration(decl, "_Regexs");
    plugin.visitTypeDeclaration(decl, "regexs");
    plugin.visitTypeDeclaration(decl, "regexs_");
    plugin.visitTypeDeclaration(decl, "Regexs_");
}
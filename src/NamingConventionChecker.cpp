#include "NamingConventionChecker.h"

NamingConventionChecker::NamingConventionChecker() : regexs(NameRulesSize), errmsgs(NameRulesSize)
{
    regexs[MatchTypedefName] = "^\\u.*?\\l";
    regexs[MatchClassName] = "^\\u.*?\\l";
    regexs[MatchGlobalConstName] = "^\\u[A-Z_]*?\\u";
    regexs[MatchEnumTypeName] = "^\\u.*?\\l";
    regexs[MatchEnumValueName] = "^\\u.*?\\l";
    regexs[MatchMethodName] = "^\\l.*?\\l";
    regexs[MatchVariableName] = "^\\l.*?\\l";
    regexs[MatchAttributeName] = "^_\\l.*?\\l";
    regexs[MatchUnionName] = "^\\u.*?\\l";
    regexs[MatchUnionValueName] = "^\\l.*?\\l";
    regexs[MatchNamespaceName] = "^\\u.*?\\l";

    errmsgs[MatchTypedefName] = "Typedef names should start with uppercase";
    errmsgs[MatchClassName] = "Class names should start with uppercase";
    errmsgs[MatchGlobalConstName] = "Global const names should start with uppercase and end with uppercase";
    errmsgs[MatchEnumTypeName] = "Enum type names should start with uppercase";
    errmsgs[MatchEnumValueName] = "Enum type names should start with uppercase";
    errmsgs[MatchMethodName] = "Methods names should start with lowercase";
    errmsgs[MatchVariableName] = "Variables names should start with lowercase";
    errmsgs[MatchAttributeName] = "Attribute name should start with underscore followed by an lowercase letter";
    errmsgs[MatchUnionName] = "Union names should start with uppercase";
    errmsgs[MatchUnionValueName] = "Union value names should start with lowercase";
    errmsgs[MatchNamespaceName] = "Namespace should start with uppercase";
}

bool NamingConventionChecker::generic_checker(const std::string &s, const int regex, std::string &errmsg) const
{
    const bool result = boost::regex_match(s, regexs[regex]);
    if(!result)
        errmsg = errmsgs[regex];
    return result;
}

bool NamingConventionChecker::correct_typedef_name(const std::string &s, std::string &errmsg) const
{
    return generic_checker(s, MatchTypedefName, errmsg);
}

bool NamingConventionChecker::correct_class_name(const std::string &s, std::string &errmsg) const
{
    return generic_checker(s, MatchClassName, errmsg);
}

bool NamingConventionChecker::correct_global_const_name(const std::string &s, std::string &errmsg) const
{
    return generic_checker(s, MatchGlobalConstName, errmsg);
}

bool NamingConventionChecker::correct_enum_type_name(const std::string &s, std::string &errmsg) const
{
    return generic_checker(s, MatchEnumTypeName, errmsg);
}

bool NamingConventionChecker::correct_enum_value_name(const std::string &s, std::string &errmsg) const
{
    return generic_checker(s, MatchEnumValueName, errmsg);
}

bool NamingConventionChecker::correct_method_name(const std::string &s, std::string &errmsg) const
{
    return generic_checker(s, MatchMethodName, errmsg);
}

bool NamingConventionChecker::correct_variable_name(const std::string &s, std::string &errmsg) const
{
    return generic_checker(s, MatchVariableName, errmsg);
}

bool NamingConventionChecker::correct_attribute_name(const std::string &s, std::string &errmsg) const
{
    return generic_checker(s, MatchAttributeName, errmsg);
}

bool NamingConventionChecker::correct_union_name(const std::string &s, std::string &errmsg) const
{
    return generic_checker(s, MatchUnionName, errmsg);
}

bool NamingConventionChecker::correct_union_value_name(const std::string &s, std::string &errmsg) const
{
    return generic_checker(s, MatchUnionValueName, errmsg);
}

bool NamingConventionChecker::correct_namespace_name(const std::string &s, std::string &errmsg) const
{
    return generic_checker(s, MatchNamespaceName, errmsg);
}
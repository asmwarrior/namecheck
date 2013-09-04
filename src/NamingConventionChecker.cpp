#include "NamingConventionChecker.h"

NamingConventionChecker::NamingConventionChecker() : regexs(NameRulesSize), errmsgs(NameRulesSize)
{
    regexs[MatchStartWithUpper] = "^\\u.*?";
    regexs[MatchStartWithLower] = "^\\l.*?";
    regexs[MatchStartUnderscore] = "^_.*?";
    regexs[MatchEndLower] = ".*?[^\\u_\\d]\\l?$";
    regexs[MatchEndUpper] = ".*?\\u$";
    regexs[MatchEndLowerRestricted] = ".*?\\l$";
    regexs[MatchUpperAndUnderscore] = "[A-Z_]*?";

    errmsgs[MatchStartWithUpper] = "names should start with uppercase";
    errmsgs[MatchStartWithLower] = "names should start with lowercase";
    errmsgs[MatchStartUnderscore] = "names should start with underscore";
    errmsgs[MatchEndLower] = "names should end with lowercase";
    errmsgs[MatchEndUpper] = "names should end with uppercase";
    errmsgs[MatchEndLowerRestricted] = "names should end with lowercase";
    errmsgs[MatchUpperAndUnderscore] = "names should be written with uppercase and underscore";
}


bool NamingConventionChecker::generic_checker(const std::string &s, const Rules& rules, std::string &errmsg) const
{
    bool result(true);
    size_t i(0);
    while(result && i != rules.size())
    {
        result = boost::regex_match(s, regexs[rules[i]]);
        if(!result)
            errmsg = errmsgs[rules[i]];
        ++i;
    }
    return result;
}

void NamingConventionChecker::ruleCamelCase(Rules& rules) const
{
    rules.push_back(MatchStartWithUpper);
    rules.push_back(MatchEndLowerRestricted);
}

void NamingConventionChecker::ruleCamelBack(Rules& rules) const
{
    rules.push_back(MatchStartWithLower);
    rules.push_back(MatchEndLower);
}

bool NamingConventionChecker::correct_typedef_name(const std::string &s, std::string &errmsg) const
{
    Rules typedefRules;
    ruleCamelCase(typedefRules);
    return generic_checker(s, typedefRules, errmsg);
}

bool NamingConventionChecker::correct_class_name(const std::string &s, std::string &errmsg) const
{
    Rules classRules;
    ruleCamelCase(classRules);
    return generic_checker(s, classRules, errmsg);
}

bool NamingConventionChecker::correct_struct_name(const std::string &s, std::string &errmsg) const
{
    Rules structRules;
    ruleCamelCase(structRules);
    return generic_checker(s, structRules, errmsg);
}

bool NamingConventionChecker::correct_global_const_name(const std::string &s, std::string &errmsg) const
{
    Rules globalConstRules;
    globalConstRules.push_back(MatchStartWithUpper);
    globalConstRules.push_back(MatchUpperAndUnderscore);
    globalConstRules.push_back(MatchEndUpper);
    return generic_checker(s, globalConstRules, errmsg);
}

bool NamingConventionChecker::correct_enum_type_name(const std::string &s, std::string &errmsg) const
{
    Rules enumTypeRules;
    ruleCamelCase(enumTypeRules);
    return generic_checker(s, enumTypeRules, errmsg);
}

bool NamingConventionChecker::correct_enum_value_name(const std::string &s, std::string &errmsg) const
{
    Rules enumValueRules;
    ruleCamelCase(enumValueRules);
    return generic_checker(s, enumValueRules, errmsg);
}

bool NamingConventionChecker::correct_method_name(const std::string &s, std::string &errmsg) const
{
    Rules methodRules;
    ruleCamelBack(methodRules);
    return generic_checker(s, methodRules, errmsg);
}

bool NamingConventionChecker::correct_variable_name(const std::string &s, std::string &errmsg) const
{
    Rules varRules;
    ruleCamelBack(varRules);
    return generic_checker(s, varRules, errmsg);
}

bool NamingConventionChecker::correct_attribute_name(const std::string &s, std::string &errmsg) const
{
    Rules attributeRules;
    attributeRules.push_back(MatchStartUnderscore);
    attributeRules.push_back(MatchEndLower);
    return generic_checker(s, attributeRules, errmsg);
    return true;
}

bool NamingConventionChecker::correct_union_name(const std::string &s, std::string &errmsg) const
{
    Rules unionRules;
    ruleCamelCase(unionRules);
    return generic_checker(s, unionRules, errmsg);
}

bool NamingConventionChecker::correct_union_value_name(const std::string &s, std::string &errmsg) const
{
    Rules unionValueRules;
    ruleCamelCase(unionValueRules);
    return generic_checker(s, unionValueRules, errmsg);
}

bool NamingConventionChecker::correct_namespace_name(const std::string &s, std::string &errmsg) const
{
    Rules namespaceRules;
    ruleCamelCase(namespaceRules);
    return generic_checker(s, namespaceRules, errmsg);
}
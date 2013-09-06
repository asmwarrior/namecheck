#ifndef NAMING_CONVENTION_CHECKER_H
#define NAMING_CONVENTION_CHECKER_H

#include <string>
#include <boost/regex.hpp>

class NamingConventionChecker
{
public:

    NamingConventionChecker();
    inline bool correct_typedef_name(const std::string &s, std::string &errmsg) const;
    bool correct_class_name(const std::string &s, std::string &errmsg) const;
    bool correct_struct_name(const std::string &s, std::string &errmsg) const;
    bool correct_global_const_name(const std::string &s, std::string &errmsg) const;
    bool correct_enum_type_name(const std::string &s, std::string &errmsg) const;
    bool correct_enum_value_name(const std::string &s, std::string &errmsg) const;
    bool correct_method_name(const std::string &s, std::string &errmsg) const;
    bool correct_variable_name(const std::string &s, std::string &errmsg) const;
    bool correct_attribute_name(const std::string &s, std::string &errmsg) const;
    bool correct_union_name(const std::string &s, std::string &errmsg) const;
    bool correct_union_value_name(const std::string &s, std::string &errmsg) const;
    bool correct_namespace_name(const std::string &s, std::string &errmsg) const;

private:

    typedef boost::regex Regex;
    typedef std::vector<Regex> Regexs;
    typedef std::vector<std::string> ErrorMsgs;
    typedef std::vector<int> Rules;

    enum NameRules
    {
        MatchStartWithUpper,
        MatchStartWithLower,
        MatchStartUnderscore,
        MatchEndLower,
        MatchEndUpper,
        MatchEndLowerRestricted,
        MatchUpperAndUnderscore,
        NameRulesSize
    };

    void ruleCamelCase(Rules& rules) const;
    void ruleCamelBack(Rules& rules) const;
    void ruleGlobalCont(Rules& rules) const;
    void ruleAttribute(Rules& rules) const;
    void setRules();
    bool generic_checker(const std::string &s, const Rules& rules, std::string &errmsg) const;

    Regexs _regexs;
    ErrorMsgs _errmsgs;    

    //Rules for declaration
    Rules _typedefRules;
    Rules _classRules;
    Rules _structRules;
    Rules _globalConstRules;
    Rules _enumTypeRules;
    Rules _enumValueRules;
    Rules _methodRules;
    Rules _varRules;
    Rules _attributeRules;
    Rules _unionRules;
    Rules _unionValueRules;
    Rules _namespaceRules;
};

#define NAMING_CONVENTION__CHECKER_INLINE_H
#include "NamingConventionCheckerInline.h"
#undef NAMING_CONVENTION__CHECKER_INLINE_H

#endif
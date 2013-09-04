#ifndef NAMING_CONVENTION_CHECKER_H
#define NAMING_CONVENTION_CHECKER_H

#include <string>
#include <boost/regex.hpp>


class NamingConventionChecker
{
public:

    NamingConventionChecker();
    bool correct_typedef_name(const std::string &s, std::string &errmsg) const;
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
    bool generic_checker(const std::string &s, const Rules& rules, std::string &errmsg) const;

    Regexs regexs;
    ErrorMsgs errmsgs;
};

#endif
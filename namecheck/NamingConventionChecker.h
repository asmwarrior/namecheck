/**
* Taller Technologies - Software Development Company
* Copyright 2013 - All rights reserved
*
* @file        NamingConventionChecker.h
* @author      Fracisco Herrero, Marcos Diaz and Franco Riberi
* @date        2013-09-06
* @brief       Header file for namecheck providing NamingConventionChecker class.
*/

#ifndef NAMING_CONVENTION_CHECKER_H
#define NAMING_CONVENTION_CHECKER_H

#include <string>
#include <boost/regex.hpp>

class NamingConventionChecker
{
public:  

    struct Result
    {
        bool match;
        std::string message;
    };

    NamingConventionChecker();
    inline bool correctTypedefName(const std::string& s, Result& result) const;
    inline bool correctClassName(const std::string& s, Result& result) const;
    inline bool correctStructName(const std::string& s, Result& result) const;
    inline bool correctGlobalConstName(const std::string& s, Result& result) const;
    inline bool correctEnumTypeName(const std::string& s, Result& result) const;
    inline bool correctEnumValueName(const std::string& s, Result& result) const;
    inline bool correctMethodName(const std::string& s, Result& result) const;
    inline bool correctVariableName(const std::string& s, Result& result) const;
    inline bool correctAttributeName(const std::string& s, Result& result) const;
    inline bool correctUnionName(const std::string& s, Result& result) const;
    inline bool correctUnionValueName(const std::string& s, Result& result) const;
    inline bool correctNamespaceName(const std::string& s, Result& result) const;

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
        MatchWithoutUndescore,
        NameRulesSize
    };

    void ruleCamelCase(Rules& rules) const;
    void ruleCamelBack(Rules& rules) const;
    void ruleGlobalCont(Rules& rules) const;
    void ruleAttribute(Rules& rules) const;
    void setRules();
    void genericChecker(const std::string& s, const Rules& rules, Result& result) const;

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

#define NAMING_CONVENTION_CHECKER_INLINE_H
#include "NamingConventionCheckerInline.h"
#undef NAMING_CONVENTION_CHECKER_INLINE_H

#endif
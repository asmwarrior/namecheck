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

namespace NamingChecker
{

class NamingConventionChecker
{
public:

    typedef std::string ErrorMessage;

    struct Result
    {
        bool _match;
        ErrorMessage _message;
    };

    NamingConventionChecker();
    void checkCorrectTypedefName(const std::string& declarationName, Result& result) const;
    void checkCorrectClassName(const std::string& declarationName, Result& result) const;
    void checkCorrectStructName(const std::string& declarationName, Result& result) const;
    void checkCorrectGlobalConstName(const std::string& declarationName, Result& result) const;
    void checkCorrectEnumTypeName(const std::string& declarationName, Result& result) const;
    void checkCorrectEnumValueName(const std::string& declarationName, Result& result) const;
    void checkCorrectMethodName(const std::string& declarationName, Result& result) const;
    void checkCorrectVariableName(const std::string& declarationName, Result& result) const;
    void checkCorrectAttributeName(const std::string& declarationName, Result& result) const;
    void checkCorrectUnionName(const std::string& declarationName, Result& result) const;
    void checkCorrectUnionValueName(const std::string& declarationName, Result& result) const;
    void checkCorrectNamespaceName(const std::string& declarationName, Result& result) const;

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
    void genericChecker(const std::string& declarationName, const Rules& rules, Result& result) const;

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

} //end namespace
#endif
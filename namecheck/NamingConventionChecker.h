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

/**
*  @brief A checker of Naming conventions. 
*
* This class with its methods checks with regexs if a name is correct for its type and gives an error message if not.
*/
class NamingConventionChecker
{
public:

    typedef std::string ErrorMessage;

    /**
    *  @brief The resul of a check. 
    *  
    *  This has the result of a name check in a bool, it also has the error message in case the name is wrong
    */
    struct Result
    {
        bool _match;
        ErrorMessage _message;
    };

    /**
    *  @brief constructor. 
    *  
    *  It initializes the regexes used, the error messages and the rules for each type
    */
    NamingConventionChecker();

    /**
    * @brief checks if the typedef name is correct and return the result.
    * 
    * @param declarationName the name to check.
    * @param result the result of the check.
    */
    inline void checkCorrectTypedefName(const std::string& declarationName, Result& result) const;

    /**
    * @brief checks if the class name is correct and return the result.
    * 
    * @param declarationName the name to check.
    * @param result the result of the check.
    */
    inline void checkCorrectClassName(const std::string& declarationName, Result& result) const;

    /**
    * @brief checks if the struct name is correct and return the result.
    * 
    * @param declarationName the name to check.
    * @param result the result of the check.
    */
    inline void checkCorrectStructName(const std::string& declarationName, Result& result) const;

    /**
    * @brief checks if the Global constant name is correct and return the result.
    * 
    * @param declarationName the name to check.
    * @param result the result of the check.
    */
    inline void checkCorrectGlobalConstName(const std::string& declarationName, Result& result) const;

    /**
    * @brief checks if the enum name is correct and return the result.
    * 
    * @param declarationName the name to check.
    * @param result the result of the check.
    */
    inline void checkCorrectEnumTypeName(const std::string& declarationName, Result& result) const;

    /**
    * @brief checks if the enum value name is correct and return the result.
    * 
    * @param declarationName the name to check.
    * @param result the result of the check.
    */
    inline void checkCorrectEnumValueName(const std::string& declarationName, Result& result) const;

    /**
    * @brief checks if the method name is correct and return the result.
    * 
    * @param declarationName the name to check.
    * @param result the result of the check.
    */
    inline void checkCorrectMethodName(const std::string& declarationName, Result& result) const;

    /**
    * @brief checks if the variable name is correct and return the result.
    * 
    * @param declarationName the name to check.
    * @param result the result of the check.
    */
    inline void checkCorrectVariableName(const std::string& declarationName, Result& result) const;

    /**
    * @brief checks if the attribute name is correct and return the result.
    * 
    * @param declarationName the name to check.
    * @param result the result of the check.
    */
    inline void checkCorrectAttributeName(const std::string& declarationName, Result& result) const;

    /**
    * @brief checks if the union name is correct and return the result.
    * 
    * @param declarationName the name to check.
    * @param result the result of the check.
    */
    inline void checkCorrectUnionName(const std::string& declarationName, Result& result) const;

    /**
    * @brief checks if the union member name is correct and return the result.
    * 
    * @param declarationName the name to check.
    * @param result the result of the check.
    */
    inline void checkCorrectUnionValueName(const std::string& declarationName, Result& result) const;

    /**
    * @brief checks if the namespace name is correct and return the result.
    * 
    * @param declarationName the name to check.
    * @param result the result of the check.
    */
    inline void checkCorrectNamespaceName(const std::string& declarationName, Result& result) const;

private:

    /** 
    * @brief a Regular Expresion to match.
    * 
    */
    typedef boost::regex Regex;
    typedef std::vector<Regex> Regexs;
    typedef std::vector<std::string> ErrorMsgs;
    typedef std::vector<int> Rules;

    /** 
    * @brief name of used rules.
    * 
    */
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

    /** 
    * @brief Add the corresponding regexs to meet a Camel Case convention into the vector of rules passed.
    * 
    * @param rules the vector of rules that is going to be modified
    */
    void ruleCamelCase(Rules& rules) const;

    /** 
    * @brief Add the corresponding regexs to meet a Camel Back convention into the vector of rules passed.
    * 
    * @param rules the vector of rules that is going to be modified
    */
    void ruleCamelBack(Rules& rules) const;

    /** 
    * @brief Add the corresponding regexs to meet a Global const naming convention into the vector of rules passed.
    * 
    * @param rules the vector of rules that is going to be modified
    */
    void ruleGlobalCont(Rules& rules) const;

    /** 
    * @brief Add the corresponding regexs to meet an Attribute naming convention into the vector of rules passed.
    * 
    * @param rules the vector of rules that is going to be modified
    */
    void ruleAttribute(Rules& rules) const;

    /** 
    * @brief this initializes all the vector of rules corresponding to each type.
    * 
    */
    void setRules();

    /** 
    * @brief this checks a name with all the rules in a vector and returns a result.
    *
    * @param declarationName the name to check.
    * @param rules a vector of rules that the name will be checked with.
    * @param result the result of checking the name with the rules
    */
    void genericChecker(const std::string& declarationName, const Rules& rules, Result& result) const;

    /** 
    * @brief This is a vector with all the regex used by this class.
    * 
    */
    Regexs _regexs;

    /** 
    * @brief This is a vector with all the error messages corresponding to each regex.
    * 
    */
    ErrorMsgs _errmsgs;


    /** 
    * @brief This is a vector that will have all the regex that a typedef name should match.
    * 
    */
    Rules _typedefRules;

    /** 
    * @brief This is a vector that will have all the regex that a typedef name should match.
    * 
    */
    Rules _classRules;

    /** 
    * @brief This is a vector that will have all the regex that a struct name should match.
    * 
    */
    Rules _structRules;

    /** 
    * @brief This is a vector that will have all the regex that a global constant name should match.
    * 
    */
    Rules _globalConstRules;

    /** 
    * @brief This is a vector that will have all the regex that a enum name should match.
    * 
    */
    Rules _enumTypeRules;

    /** 
    * @brief This is a vector that will have all the regex that a enum value name should match.
    * 
    */
    Rules _enumValueRules;

    /** 
    * @brief This is a vector that will have all the regex that a method name should match.
    * 
    */
    Rules _methodRules;

    /** 
    * @brief This is a vector that will have all the regex that a variable name should match.
    * 
    */
    Rules _varRules;

    /** 
    * @brief This is a vector that will have all the regex that an attribute name should match.
    * 
    */
    Rules _attributeRules;

    /** 
    * @brief This is a vector that will have all the regex that an union name should match.
    * 
    */
    Rules _unionRules;

    /** 
    * @brief This is a vector that will have all the regex that a union value name should match.
    * 
    */
    Rules _unionValueRules;

    /** 
    * @brief This is a vector that will have all the regex that a namespace name should match.
    * 
    */
    Rules _namespaceRules;
};

#define NAMING_CONVENTION_CHECKER_INLINE_H
#include "NamingConventionCheckerInline.h"
#undef NAMING_CONVENTION_CHECKER_INLINE_H

} //end namespace
#endif
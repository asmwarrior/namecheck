/**
* Taller Technologies - Software Development Company
* Copyright 2013 - All rights reserved
*
* @file        NamingConventionCheckerInline.h
* @author      Franco Riberi
* @date        2013-09-06
* @brief       Header file for namecheck providing NamingConventionChecker inline implementation.
*/

#ifndef NAMING_CONVENTION_CHECKER_INLINE_H
#error Internal header file
#endif

#include "NamingConventionChecker.h"

inline bool NamingConventionChecker::correctTypedefName(const std::string& s, Result& result) const
{
    genericChecker(s, _typedefRules, result);
    return result.match;
}

inline bool NamingConventionChecker::correctClassName(const std::string& s, Result& result) const
{
    genericChecker(s, _classRules, result);
    return result.match;
}

inline bool NamingConventionChecker::correctStructName(const std::string& s, Result& result) const
{
    genericChecker(s, _structRules, result);
    return result.match; 
}

inline bool NamingConventionChecker::correctGlobalConstName(const std::string& s, Result& result) const
{
     genericChecker(s, _globalConstRules, result);
    return result.match;
}

inline bool NamingConventionChecker::correctEnumTypeName(const std::string& s, Result& result) const
{
    genericChecker(s, _enumTypeRules, result);
    return result.match;
}

inline bool NamingConventionChecker::correctEnumValueName(const std::string& s, Result& result) const
{
    genericChecker(s, _enumValueRules, result);
    return result.match;
}

inline bool NamingConventionChecker::correctMethodName(const std::string& s, Result& result) const
{
    genericChecker(s, _methodRules, result);
    return result.match;
}

inline bool NamingConventionChecker::correctVariableName(const std::string& s, Result& result) const
{
    genericChecker(s, _varRules, result);
    return result.match;
}

inline bool NamingConventionChecker::correctAttributeName(const std::string& s, Result& result) const
{
    genericChecker(s, _attributeRules, result);
    return result.match;
}

inline bool NamingConventionChecker::correctUnionName(const std::string& s, Result& result) const
{
    genericChecker(s, _unionRules, result);
    return result.match;
}

inline bool NamingConventionChecker::correctUnionValueName(const std::string& s, Result& result) const
{
    genericChecker(s, _unionValueRules, result);
    return result.match;
}

inline bool NamingConventionChecker::correctNamespaceName(const std::string& s, Result& result) const
{
    genericChecker(s, _namespaceRules, result);
    return result.match;
}
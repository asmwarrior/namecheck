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

inline bool NamingConventionChecker::correctTypedefName(const std::string& s, std::string& errmsg) const
{
    return genericChecker(s, _typedefRules, errmsg);
}

inline bool NamingConventionChecker::correctClassName(const std::string& s, std::string& errmsg) const
{
    return genericChecker(s, _classRules, errmsg);
}

inline bool NamingConventionChecker::correctStructName(const std::string& s, std::string& errmsg) const
{
    return genericChecker(s, _structRules, errmsg);
}

inline bool NamingConventionChecker::correctGlobalConstName(const std::string& s, std::string& errmsg) const
{
    return genericChecker(s, _globalConstRules, errmsg);
}

inline bool NamingConventionChecker::correctEnumTypeName(const std::string& s, std::string& errmsg) const
{
    return genericChecker(s, _enumTypeRules, errmsg);
}

inline bool NamingConventionChecker::correctEnumValueName(const std::string& s, std::string& errmsg) const
{
    return genericChecker(s, _enumValueRules, errmsg);
}

inline bool NamingConventionChecker::correctMethodName(const std::string& s, std::string& errmsg) const
{
    return genericChecker(s, _methodRules, errmsg);
}

inline bool NamingConventionChecker::correctVariableName(const std::string& s, std::string& errmsg) const
{
    return genericChecker(s, _varRules, errmsg);
}

inline bool NamingConventionChecker::correctAttributeName(const std::string& s, std::string& errmsg) const
{
    return genericChecker(s, _attributeRules, errmsg);
}

inline bool NamingConventionChecker::correctUnionName(const std::string& s, std::string& errmsg) const
{
    return genericChecker(s, _unionRules, errmsg);
}

inline bool NamingConventionChecker::correctUnionValueName(const std::string& s, std::string& errmsg) const
{
    return genericChecker(s, _unionValueRules, errmsg);
}

inline bool NamingConventionChecker::correctNamespaceName(const std::string& s, std::string& errmsg) const
{
    return genericChecker(s, _namespaceRules, errmsg);
}
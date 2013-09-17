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

inline void NamingConventionChecker::checkCorrectTypedefName(const std::string& declarationName, Result& result) const
{
    genericChecker(declarationName, _typedefRules, result);
}

inline void NamingConventionChecker::checkCorrectClassName(const std::string& declarationName, Result& result) const
{
    genericChecker(declarationName, _classRules, result);
}

inline void NamingConventionChecker::checkCorrectStructName(const std::string& declarationName, Result& result) const
{
    genericChecker(declarationName, _structRules, result);
}

inline void NamingConventionChecker::checkCorrectGlobalConstName(const std::string& declarationName, Result& result) const
{
    genericChecker(declarationName, _globalConstRules, result);
}

inline void NamingConventionChecker::checkCorrectEnumTypeName(const std::string& declarationName, Result& result) const
{
    genericChecker(declarationName, _enumTypeRules, result);
}

inline void NamingConventionChecker::checkCorrectEnumValueName(const std::string& declarationName, Result& result) const
{
    genericChecker(declarationName, _enumValueRules, result);
}

inline void NamingConventionChecker::checkCorrectMethodName(const std::string& declarationName, Result& result) const
{
    genericChecker(declarationName, _methodRules, result);
}

inline void NamingConventionChecker::checkCorrectVariableName(const std::string& declarationName, Result& result) const
{
    genericChecker(declarationName, _varRules, result);
}

inline void NamingConventionChecker::checkCorrectAttributeName(const std::string& declarationName, Result& result) const
{
    genericChecker(declarationName, _attributeRules, result);
}

inline void NamingConventionChecker::checkCorrectUnionName(const std::string& declarationName, Result& result) const
{
    genericChecker(declarationName, _unionRules, result);
}

inline void NamingConventionChecker::checkCorrectUnionValueName(const std::string& declarationName, Result& result) const
{
    genericChecker(declarationName, _unionValueRules, result);
}

inline void NamingConventionChecker::checkCorrectNamespaceName(const std::string& declarationName, Result& result) const
{
    genericChecker(declarationName, _namespaceRules, result);
}
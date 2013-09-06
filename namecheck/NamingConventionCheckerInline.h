#ifndef NAMING_CONVENTION__CHECKER_INLINE_H
#error Internal header file
#endif

#include "NamingConventionChecker.h"

inline bool NamingConventionChecker::correct_typedef_name(const std::string &s, std::string &errmsg) const
{
    return generic_checker(s, _typedefRules, errmsg);
}

inline bool NamingConventionChecker::correct_class_name(const std::string &s, std::string &errmsg) const
{
    return generic_checker(s, _classRules, errmsg);
}

inline bool NamingConventionChecker::correct_struct_name(const std::string &s, std::string &errmsg) const
{
    return generic_checker(s, _structRules, errmsg);
}

inline bool NamingConventionChecker::correct_global_const_name(const std::string &s, std::string &errmsg) const
{
    return generic_checker(s, _globalConstRules, errmsg);
}

inline bool NamingConventionChecker::correct_enum_type_name(const std::string &s, std::string &errmsg) const
{
    return generic_checker(s, _enumTypeRules, errmsg);
}

inline bool NamingConventionChecker::correct_enum_value_name(const std::string &s, std::string &errmsg) const
{
    return generic_checker(s, _enumValueRules, errmsg);
}

inline bool NamingConventionChecker::correct_method_name(const std::string &s, std::string &errmsg) const
{
    return generic_checker(s, _methodRules, errmsg);
}

inline bool NamingConventionChecker::correct_variable_name(const std::string &s, std::string &errmsg) const
{
    return generic_checker(s, _varRules, errmsg);
}

inline bool NamingConventionChecker::correct_attribute_name(const std::string &s, std::string &errmsg) const
{
    return generic_checker(s, _attributeRules, errmsg);
}

inline bool NamingConventionChecker::correct_union_name(const std::string &s, std::string &errmsg) const
{
    return generic_checker(s, _unionRules, errmsg);
}

inline bool NamingConventionChecker::correct_union_value_name(const std::string &s, std::string &errmsg) const
{
    return generic_checker(s, _unionValueRules, errmsg);
}

inline bool NamingConventionChecker::correct_namespace_name(const std::string &s, std::string &errmsg) const
{
    return generic_checker(s, _namespaceRules, errmsg);
}
/**
* Taller Technologies - Software Development Company
* Copyright 2013 - All rights reserved
*
* @file        LowerCamelCaseRule.h
* @author      Franco Riberi
* @date        2013-09-17
* @brief       Header file for namecheck providing LowerCamelCaseRule class.
*/

#ifndef LOWER_CAMEL_CASE_RULE_H
#define LOWER_CAMEL_CASE_RULE_H

#include "DefaultRules.h"

namespace NamingChecker
{

class LowerCamelCaseRule : public DefaultRules
{
public:

    LowerCamelCaseRule();
};

} //end namespace

#endif
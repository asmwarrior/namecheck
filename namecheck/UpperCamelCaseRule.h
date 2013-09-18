/**
* Taller Technologies - Software Development Company
* Copyright 2013 - All rights reserved
*
* @file        UpperCamelCaseRule.h
* @author      Franco Riberi
* @date        2013-09-17
* @brief       Header file for namecheck providing UpperCamelCaseRule class.
*/

#ifndef UPPER_CAMEL_CASE_RULE_H
#define UPPER_CAMEL_CASE_RULE_H

#include "DefaultRules.h"

namespace NamingChecker
{

class UpperCamelCaseRule : public DefaultRules
{
public:

    UpperCamelCaseRule();
};

} //end namespace

#endif
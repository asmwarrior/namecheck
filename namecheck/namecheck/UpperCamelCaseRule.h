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

#include "RegexCollection.h"

namespace NamingChecker
{

/**
 * @brief This class represents a upper camel case rule
 */
class UpperCamelCaseRule : public RegexCollection
{
public:

    /**
     * @brief Constructor of class
     *
     */
    UpperCamelCaseRule();
};

} //end namespace

#endif
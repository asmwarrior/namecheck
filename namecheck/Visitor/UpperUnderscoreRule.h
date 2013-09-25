/**
* Taller Technologies - Software Development Company
* Copyright 2013 - All rights reserved
*
* @file        UpperUnderscoreRule.h
* @author      Franco Riberi
* @date        2013-09-17
* @brief       Header file for namecheck providing UpperUnderscoreRule class.
*/

#ifndef UPPER_UNDERSCORE_RULE_H
#define UPPER_UNDERSCORE_RULE_H

#include "Visitor/DefaultRules.h"

namespace NamingChecker
{

/**
 * @brief This class represents a upper underscore rule
 *
 */
class UpperUnderscoreRule : public DefaultRules
{
public:

	/**
	 * @brief Constructor of class
	 *
	 */
    UpperUnderscoreRule();
};

} //end namespace

#endif
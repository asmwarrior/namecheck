/**
* Taller Technologies - Software Development Company
* Copyright 2013 - All rights reserved
*
* @file        LowerUnderscoreRule.h
* @author      Franco Riberi
* @date        2013-09-17
* @brief       Header file for namecheck providing LowerUnderscoreRule class.
*/

#ifndef LOWER_UNDERSCORE_RULE_H
#define LOWER_UNDERSCORE_RULE_H

#include "DefaultRules.h"

namespace NamingChecker
{

/**
 * @brief This class represents a lower underscore rule
 *
 */
class LowerUnderscoreRule : public DefaultRules
{
public:

	/**
	 * @brief Constructor of class
	 *
	 */
    LowerUnderscoreRule();
};

} //end namespace

#endif
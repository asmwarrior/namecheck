/**
* Taller Technologies - Software Development Company
* Copyright 2013 - All rights reserved
*
* @file        ReservedNameRule.h
* @author      Franco Riberi
* @date        2013-09-23
* @brief       Header file for namecheck providing ReservedNameRule class.
*/

#ifndef RESERVED_NAME_RULE_H
#define RESERVED_NAME_RULE_H

#include "Visitor/DefaultRules.h"

namespace NamingChecker
{

/**
 * @brief This class represents a reserved name rule
 *
 */
class ReservedNameRule : public DefaultRules
{
public:

	/**
	 * @brief Represents a reserved name rules
	 */
	enum MatchReserved
	{
		MatchNotUnderscoreUpper,
    	MatchNotEDOrUpper,
    	MatchNotIsOrToLower,
    	MatchNotLCUnderscore,
    	MatchNotSIGUnderscore,
	    MatchNotStrMemWcsLower,
	    MatchNotUnderscoretEnding,
	    MatchAmount
	};

	/**
	 * @brief Constructor of class
	 *
	 */
    ReservedNameRule();
};

} //end namespace

#endif
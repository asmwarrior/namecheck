/**
* Taller Technologies - Software Development Company
* Copyright 2013 - All rights reserved
*
* @file        Rule.h
* @author      Franco Riberi
* @date        2013-09-16
* @brief       Header file for namecheck providing Rule interface.
*/

#ifndef RULE_H
#define RULE_H

#include <boost/regex.hpp>

namespace NamingChecker
{

/**
 * @brief Represents a regular expression
 */
typedef boost::regex BoostRegex;

/**
 * @brief Represents a output message
 */
typedef std::string Message;

/**
 *  @brief The result of a check. 
 *  
 *  This has the result of a name check in a bool, it also has the error message in case the name is wrong
 */
struct Result
{
    bool _match;
    Message _message;
};

/**
 * Interface for a rule
 */
struct Rule
{
	/**
 	 * @brief Checks if declarationName is correct and return the result.
 	 * 
 	 * @param declarationName the name to check 
 	 * @param result to fill with the result
 	 */
    virtual void checkRule(const std::string& declarationName, Result& result) const = 0;
};

} //end namespace

#endif
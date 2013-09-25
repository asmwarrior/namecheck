/**
* Taller Technologies - Software Development Company
* Copyright 2013 - All rights reserved
*
* @file        Regex.h
* @author      Franco Riberi
* @date        2013-09-17
* @brief       Header file for namecheck providing Regex class.
*/

#ifndef REGEX_H
#define REGEX_H

#include <boost/regex.hpp>
#include "Rule.h"

namespace NamingChecker
{

/**
 * @brief Specific Rule
 *
 * This class represents a regex which is a specific rule
 */
class Regex : public Rule
{
public:

	Regex(const std::string& reg, const std::string& msg);	
    
private:

    virtual void checkRule(const std::string& declarationName, Result& result) const;

    /**
     * @brief Represent a specific regex
     */
    boost::regex _regex;

    /**
     * @brief Represent a error message
     */
    Message _errmsg;
};

} //end namespace

#endif
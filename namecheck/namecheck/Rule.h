/**
 * @file     Rule.h
 * @brief    Provides the interface to define diferent rules.
 *
 * @author   Franco Riberi
 * @email    franco.riberi AT tallertechnologies.com
 *
 * Contents: Header file for namecheck providing Rule interface.
 *
 * System:    namecheck: Naming Convention Checker
 * Language:  C++
 *
 * @date      September 16, 2013
 *
 * This file is part of namecheck.
 *
 * namecheck is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * namecheck is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with namecheck. If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef RULE_H
#define RULE_H

#include <boost/regex.hpp>

namespace NamingChecker
{

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

    /**
     * @brief Destructor of class
     *
     */
    virtual ~Rule() {}
};

} //end namespace

#endif
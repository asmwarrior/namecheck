/**
 * @file     Regex.h
 * @brief    Provides the interface to represents a regex
 *           which is a specific rule
 *
 * @author   Franco Riberi
 * @email    franco.riberi AT tallertechnologies.com
 *
 * Contents: Header file for namecheck providing Regex class.
 *
 * System:    namecheck: Naming Convention Checker
 * Language:  C++
 *
 * @date      September 17, 2013
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

#ifndef REGEX_H
#define REGEX_H

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

    /**
     * @brief Constructor of class
     *
     */
    Regex(const std::string& reg, const std::string& msg);

private:

    virtual void checkRule(const std::string& declarationName, Result& result) const;

    virtual ~Regex() {}
    
    /**
     * @brief Represent a specific regex
     */
    const RegexType _regex;

    /**
     * @brief Represent a error message
     */
    const Message _errmsg;
};

} //end namespace

#endif

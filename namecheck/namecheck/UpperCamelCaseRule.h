/**
 * @file     UpperCamelCaseRule.h
 * @brief    Provides the interface to UpperCamelCaseRule class.
 *
 * @author   Franco Riberi
 * @email    franco.riberi AT tallertechnologies.com
 *
 * Contents: Header file for namecheck providing UpperCamelCaseRule interface.
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

#ifndef UPPER_CAMEL_CASE_RULE_H
#define UPPER_CAMEL_CASE_RULE_H

#include "RegexCollection.h"

namespace NSNamingChecker
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

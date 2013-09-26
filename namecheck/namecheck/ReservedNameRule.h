/**
 * @file     ReservedNameRule.h
 * @brief    Provides the interface to ReservedNameRule class.
 *
 * @author   Franco Riberi
 * @email    franco.riberi AT tallertechnologies.com
 *
 * Contents: Header file for namecheck providing ReservedNameRule interface.
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

#ifndef RESERVED_NAME_RULE_H
#define RESERVED_NAME_RULE_H

#include "RegexCollection.h"

namespace NamingChecker
{

/**
 * @brief This class represents a reserved name rule
 *
 */
class ReservedNameRule : public RegexCollection
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

/*
 * @file     RulesContainer.cpp
 * @brief    This is the implementation of RulesContainer interface.
 *
 * @author   Franco Riberi
 * @email    franco.riberi AT tallertechnologies.com
 *
 * Contents: Source file for namecheck providing RulesContainer implementation.
 *
 * System:   namecheck: Naming Convention Checker
 * Language: C++
 *
 * @date September 17, 2013
 *
 * This file is part of namecheck
 *
 * namecheck is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * namecheck is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with namecheck.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include <fstream>
#include <sstream>
#include <mili/mili.h>
#include "namecheck/RulesContainer.h"
#include "namecheck/Regex.h"
#include "namecheck/UpperCamelCaseRule.h"
#include "namecheck/LowerCamelCaseRule.h"
#include "namecheck/UpperUnderscoreRule.h"
#include "namecheck/LowerUnderscoreRule.h"
#include "namecheck/ReservedNameRule.h"

using mili::operator>>;

namespace NSNamingChecker
{

RulesContainer::RulesContainer() : _rules(CheckCount)
{
    _declarationMap["ClassDeclaration"] = ClassDeclaration;
    _declarationMap["VariableDeclaration"] = VariableDeclaration;
    _declarationMap["EnumTypeDeclaration"] = EnumTypeDeclaration;
    _declarationMap["EnumValueDeclaration"] = EnumValueDeclaration;
    _declarationMap["FunctionDeclaration"] = FunctionDeclaration;
    _declarationMap["ParameterDeclaration"] = ParameterDeclaration;
    _declarationMap["TypeDeclaration"] = TypeDeclaration;
    _declarationMap["StructDeclaration"] = StructDeclaration;
    _declarationMap["UnionDeclaration"] = UnionDeclaration;
    _declarationMap["UnionValueDeclaration"] = UnionValueDeclaration;
    _declarationMap["PublicMethodDeclaration"] = PublicMethodDeclaration;
    _declarationMap["PrivateMethodDeclaration"] = PrivateMethodDeclaration;
    _declarationMap["ProtectedMethodDeclaration"] = ProtectedMethodDeclaration;
    _declarationMap["PublicAttributeDeclaration"] = PublicAttributeDeclaration;
    _declarationMap["PrivateAttributeDeclaration"] = PrivateAttributeDeclaration;
    _declarationMap["ProtectedAttributeDeclaration"] = ProtectedAttributeDeclaration;
    _declarationMap["NamespaceDeclaration"] = NamespaceDeclaration;
    _declarationMap["GlobalConstDeclaration"] = GlobalConstDeclaration;
    _declarationMap["TemplateTypeParameterDeclaration"] = TemplateTypeParameterDeclaration;
}

RulesContainer::~RulesContainer()
{
    for (size_t i(0); i < CheckCount; ++i)
    {
        mili::delete_container(_rules[i]);
    }
}

void RulesContainer::check(const DeclarationToCheck& decl, const DeclName& declarationName, Rule::Result& result) const
{
    if (!_rules[decl].empty())
    {
        Rules::const_iterator it = _rules[decl].begin();
        do
        {
            (*it)->checkRule(declarationName, result);
            ++it;
        }
        while (result._match && it != _rules[decl].end());
    }
}

static const size_t REGEX_SIZE = 4;
static const size_t DEFAULT_SIZE = 2;
static const size_t DECLARATION_NAME = 0;
static const size_t RULE_TYPE = 1;
static const size_t SPECIFIC_REGEX = 2;
static const size_t ERROR_MESSAGE = 3;
static const std::string REGEX = "0";

void RulesContainer::checkLine(const StringVector& line)
{
    if (line[RULE_TYPE] == REGEX)
        mili::assert_throw<InvalidFormatFile>(line.size() == REGEX_SIZE);
    else
        mili::assert_throw<InvalidFormatFile>(line.size() == DEFAULT_SIZE);
    mili::assert_throw<InvalidDeclaration>(_declarationMap.find(line[DECLARATION_NAME]) != _declarationMap.end());   
}

Rule* RulesContainer::rulesFactory(const RuleType& rule, const StringVector& fileLine)
{
    Rule* ret;
    switch (rule)
    {
        case SpecificRegex:
        {
            ret = new Regex(fileLine[SPECIFIC_REGEX], fileLine[ERROR_MESSAGE]);            
            break;
        }
        case UpCamelCaseRule:
        {
            ret = new UpperCamelCaseRule();
            break;
        }
        case LowCamelCaseRule:
        {
            ret = new LowerCamelCaseRule();
            break;
        }
        case UpUnderscoreRule:
        {
            ret = new UpperUnderscoreRule();            
            break;
        }
        case LowUnderscoreRule:
        {
            ret = new LowerUnderscoreRule();
            break;
        }
        case ReservNameRule:
        {
            ret = new ReservedNameRule();
            break;
        }
        default :
            throw InvalidRuleType();
    }
    return ret;
}

void RulesContainer::process(const StringVector& fileLine)
{    
    const size_t ruleType = mili::from_string<size_t>(fileLine[RULE_TYPE]);    
    const RuleType specificRule = RuleType(ruleType);
    Rule* const rule = rulesFactory(specificRule, fileLine);
    _rules[_declarationMap[fileLine[DECLARATION_NAME]]].push_back(rule);
}

void RulesContainer::load(const FileName& fileName)
{
    std::ifstream ifs;
    ifs.open(fileName.c_str());
    mili::assert_throw<FileNotFound>(ifs);

    StringVector fileLine;
    while (ifs >> mili::Separator(fileLine, ','))
    {
        checkLine(fileLine);
        process(fileLine);
        fileLine.clear();
    }
}

} // end namespace
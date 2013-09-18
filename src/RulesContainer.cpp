/**
* Taller Technologies - Software Development Company
* Copyright 2013 - All rights reserved
*
* @file        RulesContainer.cpp
* @author      Franco Riberi
* @date        2013-09-17
* @brief       Header file for namecheck providing RulesContainer class.
*/

#include "RulesContainer.h"
#include "UpperCamelCaseRule.h"
#include "LowerCamelCaseRule.h"
#include "UpperUnderscoreRule.h"
#include "LowerUnderscoreRule.h"

namespace NamingChecker
{

RulesContainer::RulesContainer() : _rules(CheckCount)
{
    _upperCamelCaseRule = new UpperCamelCaseRule();
    _lowerCamelCaseRule = new LowerCamelCaseRule();
    _upperUnderscoreRule = new UpperUnderscoreRule();
    _lowerUnderscoreRule = new LowerUnderscoreRule();
}

RulesContainer::~RulesContainer()
{
    delete _upperCamelCaseRule;
    delete _lowerCamelCaseRule;
    delete _upperUnderscoreRule;
    delete _lowerUnderscoreRule;
}

void RulesContainer::check(const DeclarationToCheck& decl, const std::string& declarationName, Result& result) const
{
    if (_rules[decl].size() != 0)
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

static const size_t DECLARATION = 0;

void RulesContainer::load(const FileName& fileName)
{
    _rules[ClassDeclaration].push_back(_upperCamelCaseRule);
    _rules[VariableDeclaration].push_back(_lowerCamelCaseRule);
    _rules[EnumTypeDeclaration].push_back(_upperCamelCaseRule);
    _rules[EnumValueDeclaration].push_back(_upperCamelCaseRule);
    _rules[FunctionDeclaration].push_back(_lowerCamelCaseRule);
    _rules[ParameterDeclaration].push_back(_lowerCamelCaseRule);
    _rules[TypeDeclaration].push_back(_upperCamelCaseRule);
    _rules[StructDeclaration].push_back(_upperCamelCaseRule);
    _rules[UnionDeclaration].push_back(_upperCamelCaseRule);
    _rules[UnionValueDeclaration].push_back(_upperCamelCaseRule);
    _rules[MethodDeclaration].push_back(_lowerCamelCaseRule);
    _rules[AttributeDeclaration].push_back(_lowerUnderscoreRule);
    _rules[NamespaceDeclaration].push_back(_upperCamelCaseRule);
    _rules[GlobalConstDeclaration].push_back(_upperUnderscoreRule);
}

} // end namespace
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
{}

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

	//read file and fill _rules	
	std::auto_ptr<Rule> upperCamelCaseRule(new UpperCamelCaseRule());	
	std::auto_ptr<Rule> lowerCamelCaseRule(new LowerCamelCaseRule());	
	std::auto_ptr<Rule> upperUnderscoreRule(new UpperUnderscoreRule());	
	std::auto_ptr<Rule> lowerUnderscoreRule(new LowerUnderscoreRule());	
	
	_rules[ClassDeclaration].push_back(upperCamelCaseRule.get());	
	_rules[VariableDeclaration].push_back(lowerCamelCaseRule.get());
	_rules[EnumTypeDeclaration].push_back(upperCamelCaseRule.get());
	_rules[EnumValueDeclaration].push_back(upperCamelCaseRule.get());
	_rules[FunctionDeclaration].push_back(lowerCamelCaseRule.get());
	_rules[ParameterDeclaration].push_back(lowerCamelCaseRule.get());
	_rules[TypeDeclaration].push_back(upperCamelCaseRule.get());
	_rules[StructDeclaration].push_back(upperCamelCaseRule.get());
	_rules[UnionDeclaration].push_back(upperCamelCaseRule.get());
	_rules[UnionValueDeclaration].push_back(upperCamelCaseRule.get());
	_rules[MethodDeclaration].push_back(lowerCamelCaseRule.get());
	_rules[AttributeDeclaration].push_back(lowerUnderscoreRule.get());
	_rules[NamespaceDeclaration].push_back(upperCamelCaseRule.get());
	_rules[GlobalConstDeclaration].push_back(upperUnderscoreRule.get());	
}

} // end namespace
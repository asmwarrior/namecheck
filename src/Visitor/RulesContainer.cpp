/**
* Taller Technologies - Software Development Company
* Copyright 2013 - All rights reserved
*
* @file        RulesContainer.cpp
* @author      Franco Riberi
* @date        2013-09-17
* @brief       Header file for namecheck providing RulesContainer class.
*/
#include <fstream>
#include <mili/mili.h>

#include "Visitor/RulesContainer.h"
#include "Visitor/Regex.h"
#include "Visitor/UpperCamelCaseRule.h"
#include "Visitor/LowerCamelCaseRule.h"
#include "Visitor/UpperUnderscoreRule.h"
#include "Visitor/LowerUnderscoreRule.h"
#include "Visitor/ReservedNameRule.h"
                
using mili::operator>>;

namespace NamingChecker
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
    _declarationMap["MethodDeclaration"] = MethodDeclaration;
    _declarationMap["AttributeDeclaration"] = AttributeDeclaration;
    _declarationMap["NamespaceDeclaration"] = NamespaceDeclaration;
    _declarationMap["GlobalConstDeclaration"] = GlobalConstDeclaration;
    _declarationMap["TemplateTypeParameterDeclaration"] = TemplateTypeParameterDeclaration;
}

RulesContainer::~RulesContainer()
{
    for(int i=0; i < CheckCount; ++i)
    {
        mili::delete_container(_rules[i]);
    }
}

void RulesContainer::check(const DeclarationToCheck& decl, const std::string& declarationName, Result& result) const
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

void RulesContainer::checkLine(StringVector line)
{
    if(line[RULE_TYPE] == REGEX) 
        mili::assert_throw<InvalidFormatFile>(line.size() == REGEX_SIZE);
    else
        mili::assert_throw<InvalidFormatFile>(line.size() == DEFAULT_SIZE);
    
    if(_declarationMap.find(line[DECLARATION_NAME]) == _declarationMap.end())    
        throw InvalidDeclaration();
}

void RulesContainer::process(const StringVector& fileLine)
{           
    const char *cstr = fileLine[RULE_TYPE].c_str();
    switch(cstr[0])
    {
        case SpecificRegex:
        {
            Rule* reg = new Regex(fileLine[SPECIFIC_REGEX], fileLine[ERROR_MESSAGE]);
            _rules[_declarationMap[fileLine[DECLARATION_NAME]]].push_back(reg);          
            break;
        }
        case UpCamelCaseRule:
        {
            Rule* ucc = new UpperCamelCaseRule();
            _rules[_declarationMap[fileLine[DECLARATION_NAME]]].push_back(ucc);
            break;
        }
        case LowCamelCaseRule:
        {
            Rule* lcc = new LowerCamelCaseRule();
            _rules[_declarationMap[fileLine[DECLARATION_NAME]]].push_back(lcc);
            break;
        }
        case UpUnderscoreRule:
        {
            Rule* uu = new UpperUnderscoreRule();
            _rules[_declarationMap[fileLine[DECLARATION_NAME]]].push_back(uu);
            break;
        }
        case LowUnderscoreRule:
        {
            Rule* lu = new LowerUnderscoreRule();
            _rules[_declarationMap[fileLine[DECLARATION_NAME]]].push_back(lu);
            break;
        }
        case ReservNameRule:
        {
            Rule* rn = new ReservedNameRule();
            _rules[_declarationMap[fileLine[DECLARATION_NAME]]].push_back(rn);
            break;
        }
        default : 
            throw InvalidRuleType();
    }
}

void RulesContainer::load(const FileName& fileName)
{       
    std::ifstream ifs;
    ifs.open(fileName.c_str());
    mili::assert_throw<FileNotFound>(ifs);    
    
    StringVector fileLine;
    ifs >> mili::Separator(fileLine, ',');
    do
    {
        checkLine(fileLine);
        process(fileLine);
        fileLine.clear();
    }
    while (ifs >> mili::Separator(fileLine, ','));
}

} // end namespace
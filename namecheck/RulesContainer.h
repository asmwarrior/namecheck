/**
* Taller Technologies - Software Development Company
* Copyright 2013 - All rights reserved
*
* @file        RulesContainer.h
* @author      Franco Riberi
* @date        2013-09-17
* @brief       Header file for namecheck providing RulesContainer class.
*/

#ifndef RULES_CONTAINER_H
#define RULES_CONTAINER_H


#include <vector>
#include <list>
#include "Rule.h"

namespace NamingChecker
{

class RulesContainer
{
public:

    typedef enum
    {
        ClassDeclaration,
        VariableDeclaration,
        EnumTypeDeclaration,
        EnumValueDeclaration,
        FunctionDeclaration,
        ParameterDeclaration,
        TypeDeclaration,
        StructDeclaration,
        UnionDeclaration,
        UnionValueDeclaration,
        MethodDeclaration,
        AttributeDeclaration,
        NamespaceDeclaration,
        GlobalConstDeclaration,
        CheckCount
    } DeclarationToCheck;

    typedef std::string FileName;

    RulesContainer();
    ~RulesContainer();

    void check(const DeclarationToCheck& decl, const std::string& declarationName, Result& result) const;

    void load(const FileName& fileName);

private:

    typedef std::list<Rule*> Rules;
    std::vector<Rules> _rules;

    Rule* _upperCamelCaseRule;
    Rule* _lowerCamelCaseRule;
    Rule* _upperUnderscoreRule;
    Rule* _lowerUnderscoreRule;
};

} // end namespace

#endif
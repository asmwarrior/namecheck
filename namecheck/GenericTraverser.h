/**
* Taller Technologies - Software Development Company
* Copyright 2013 - All rights reserved
*
* @file        GenericTraverser.h
* @author      Fracisco Herrero and Marcos Diaz
* @date        2013-09-06
* @brief       Header file for namecheck providing GenericTraverser class.
*/

#ifndef PLUGIN_MEDIATOR_H
#define PLUGIN_MEDIATOR_H

#include "GenericVisitor.h"
#include "GenericTree.h"
#include <string>

namespace GPPGeneric
{

class GenericTraverser
{
public:
    #include "GenericTraverserInline.h"

private:
    GenericVisitor* _visitor;

    static void getName(const GenericTree decl, std::string& name);
    static bool isConstant(const GenericTree decl);
    static void getTypeName(const GenericTree decl, std::string& type_name);
    static bool isReservedDeclaration(const GenericTree decl);
    static AccessModifier getAccess(const GenericTree decl);

    void processParameters(const GenericTree decl) const;
    void processAttributes(const GenericTree decl) const;
    void processMethods(const GenericTree decl) const;
    void processEnumType(const GenericTree decl) const;
    void processEnumValues(const GenericTree decl) const;
    void processDeclaration(const GenericTree decl) const;
    void processStatement(const GenericTree decl) const;
    void processVariableDeclaration(const GenericTree decl) const;
    void processTemplateDeclaration(const GenericTree decl) const;
    void processType(const GenericTree decl) const;
    void unionOrRecord(const GenericTree decl, const GenericTree type, std::string& name) const;
    void processTypeDeclArtificial(const GenericTree decl) const;
    void processRecordDeclaration(const GenericTree decl) const;
    void functionOrMethod(const GenericTree decl, std::string& name) const;
    void processFunction(const GenericTree decl) const;
    void processFunctionBody(const GenericTree decl) const;
    void processSubblocks(const GenericTree block) const;
    void processBlock(const GenericTree decl) const;
    void processBlockVariables(const GenericTree decl) const;
    void traverse(const GenericTree ns) const;
    void traverseNamespaces(const GenericTree level) const;
    void traverseDeclarations(const GenericTree level) const;
    static void checkArrayTypeName(GenericTree decl, std::string& type_name);
    static void checkReferenceTypeName(GenericTree decl, std::string& type_name);
    static void checkPointerTypeName(GenericTree decl, std::string& type_name);

};

} // end GPPGeneric

#endif
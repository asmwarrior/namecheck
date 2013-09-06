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
    void traverse(const GenericTree ns, GenericVisitor* visitor);

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
    void processDeclaration(const GenericTree decl) const;
    void processStatement(const GenericTree decl) const;
    void processVariableDeclaration(const GenericTree decl) const;
    void processType(const GenericTree decl) const;
    void processClassStructUnion(const GenericTree decl) const;
    void processRecordDeclaration(const GenericTree decl) const;
    void processFunction(const GenericTree decl) const;
    void processBlock(const GenericTree decl) const;
    void processBlockVariables(const GenericTree decl) const;
    void traverse(const GenericTree ns) const;
};

} // end GPPGeneric

#endif
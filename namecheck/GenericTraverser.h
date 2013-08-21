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
    GenericVisitor* visitor;

    static const std::string getName(const GenericTree decl);

    void processDeclaration(const tree GenericTree) const;
    void processVariableDeclaration(const GenericTree decl) const;
    void processClass(const GenericTree decl) const;
    void processFunction(const GenericTree decl) const;
    void processBlock(const GenericTree decl) const;
    void traverse(const GenericTree ns) const;
};

} // end GPPGeneric

#endif
#ifndef PLUGIN_MEDIATOR_H
#define PLUGIN_MEDIATOR_H

#include "GenericVisitor.h"

#include <gmp.h>

extern "C" {
#include "gcc-plugin.h"
#include "tree.h"
}

#include <set>
#include <string>

namespace GPPGeneric
{

class GenericTraverser
{
public:
    void traverse(const tree ns, GenericVisitor* visitor);

private:
    GenericVisitor* visitor;

    static const std::string getName(const tree decl);

    void processDeclaration(const tree decl) const;
    void processVariableDeclaration(const tree decl) const;
    void processClass(const tree decl) const;
    void processFunction(const tree decl) const;
    void processBlock(const tree decl) const;
    void traverse(const tree ns) const;
};

} // end GPPGeneric

#endif
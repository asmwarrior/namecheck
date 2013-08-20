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

private:
    struct declComparator
    {
        bool operator() (tree x, tree y) const
        {
            location_t xl (DECL_SOURCE_LOCATION (x));
            location_t yl (DECL_SOURCE_LOCATION (y));

            return xl < yl;
        }
    };

    GenericVisitor* visitor;

    static const std::string getName(const tree decl);

    void processDeclaration(const tree decl) const;
    void processVariableDeclaration(const tree decl) const;
    void processClass(const tree decl) const;
    void processFunction(const tree decl) const;
    void processBlock(const tree decl) const;
    void traverse(const tree ns) const;

public:
    void traverse(const tree ns, GenericVisitor* visitor);
};

} // end GPPGeneric

#endif
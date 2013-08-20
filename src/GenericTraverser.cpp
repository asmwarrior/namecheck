#include "GenericTraverser.h"

extern "C"
{
#include "gcc-plugin.h"
#include "plugin-version.h"
#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "tree.h"
#include "intl.h"

#include "tm.h"

#include "cp/cp-tree.h"
#include "c-family/c-common.h"
#include "c-family/c-pragma.h"
#include "diagnostic-core.h"
}

#include <cassert>

namespace GPPGeneric
{

void GenericTraverser::traverse(const tree ns) const
{
    tree decl;
    const cp_binding_level* level(NAMESPACE_LEVEL(ns));

    // Traverse declarations.
    for (decl = level->names; decl != 0; decl = TREE_CHAIN(decl))
    {
        processDeclaration(decl);
    }

    // Traverse namespaces.
    for (decl = level->namespaces; decl != 0; decl = TREE_CHAIN(decl))
    {
        processDeclaration(decl);
    }
}

void GenericTraverser::traverse(const tree ns, GenericVisitor* visitor) 
{
    this->visitor = visitor;
    traverse(ns);
}


void GenericTraverser::processDeclaration(const tree decl) const
{

    if (!DECL_IS_BUILTIN(decl))
    {
        int tree_code = TREE_CODE(decl);
        
        if (tree_code == FUNCTION_DECL)
        {
            processFunction(decl);
        }
        else if (tree_code == TYPE_DECL)

        {
			if (DECL_ARTIFICIAL(decl))
            	processClass(decl);
            else
            	visitor->visitTypeDeclaration(decl, getName(decl));
        }
        else
        {
            processVariableDeclaration(decl);
        }

        if (tree_code == NAMESPACE_DECL)
        {
            traverse(decl);
        }
    }
}

const std::string GenericTraverser::getName(const tree decl) const
{
	const tree id(DECL_NAME(decl));
    return std::string(id ? IDENTIFIER_POINTER(id) : "<unnamed>");
}


void GenericTraverser::processVariableDeclaration(const tree decl) const
{
	visitor->visitVariableDeclaration(decl, getName(decl));
}

void GenericTraverser::processClass(const tree decl) const
{
    assert((TREE_CODE(decl) == TYPE_DECL) && DECL_ARTIFICIAL(decl));

    tree type (TREE_TYPE (decl));
    tree biv (TYPE_BINFO (type));
    size_t biv_size (biv ? BINFO_N_BASE_BINFOS (biv) : 0);

    tree id (DECL_NAME(decl));
    const char* name (IDENTIFIER_POINTER(id));

	visitor->visitClassDeclaration(decl, std::string(name));

    declSet set;
 
    for (tree d(TYPE_FIELDS(type)); d != 0; d = TREE_CHAIN(d))
    {
        switch (TREE_CODE (d))
        {
        case TYPE_DECL:
            if(!DECL_SELF_REFERENCE_P(d))
				if (DECL_ARTIFICIAL(d))
	            	processClass(d);
	            else
	            	visitor->visitTypeDeclaration(d, getName(d));
            break;
        
        case FIELD_DECL:
            if(!DECL_ARTIFICIAL(d))
                visitor->visitFieldDeclaration(d, getName(d));
            break;
        
        default:
            //set.insert(d);
            break;  
        }
    }

    for (tree d(TYPE_METHODS(type)); d != 0; d = TREE_CHAIN(d))
    {
        if (!DECL_ARTIFICIAL(d))
	        processFunction(d);
    }
}


void GenericTraverser::processFunction(const tree decl) const
{
    assert(TREE_CODE(decl) == FUNCTION_DECL);

    const tree id(DECL_NAME(decl));
    const char* name (IDENTIFIER_POINTER(id));

    if (TREE_CODE(TREE_TYPE(decl)) == METHOD_TYPE)
    	visitor->visitMethodDeclaration(decl, getName(decl));
    else
    	visitor->visitFunctionDeclaration(decl, getName(decl));

    for (tree d(DECL_ARGUMENTS(decl)); d != 0; d = TREE_CHAIN(d))
    {
        visitor->visitParameterDeclaration(d, getName(d));
    }

    processBlock(DECL_INITIAL(decl));

}

void GenericTraverser::processBlock(const tree decl) const
{
    assert(TREE_CODE(decl) == BLOCK);

    for (tree d(BLOCK_VARS(decl)); d != 0; d = TREE_CHAIN(d))
    {
        processDeclaration(d);
    }
    
    tree subblocks(BLOCK_SUBBLOCKS(decl));
    if (subblocks != NULL_TREE) 
    {
        processBlock(subblocks);
    }
}


} // end GPPGeneric
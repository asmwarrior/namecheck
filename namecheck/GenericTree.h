#ifndef GCC_GENERIC_TREE_H
#define GCC_GENERIC_TREE_H

#include <gmp.h>

extern "C" {
#include "config.h"
#undef HAVE_DECL_GETOPT
#define HAVE_DECL_GETOPT 1
#include "gcc-plugin.h"
#include "tree.h"
}

namespace GPPGeneric
{

typedef tree GenericTree;

}

#endif
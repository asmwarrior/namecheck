/**
* Taller Technologies - Software Development Company
* Copyright 2013 - All rights reserved
*
* @file        GenericTree.h
* @author      Fracisco Herrero and Marcos Diaz
* @date        2013-09-06
* @brief       Header file for namecheck providing GenericTree type.
*/

#ifndef GCC_GENERIC_TREE_H
#define GCC_GENERIC_TREE_H

#include <gmp.h>

extern "C"
{
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
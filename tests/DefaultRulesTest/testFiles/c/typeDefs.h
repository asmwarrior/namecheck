/*******************************************************************************
                        		Copyright (C) 2012
                                  	FixView SRL
                      	This file is part of the SADI Project.

    Historial de Cambios:
    <dd/mm/aaaa>    <Cambio>                                    <Autor>
     11/10/2012      Creacion.                                   Mariano Serra

Definiciones de tipo de datos específicas del proyecto.

*******************************************************************************/

#ifndef __Type_Defs_H_
#define __Type_Defs_H_


/***************** Inclusiones ************************************************/
#include "stddef.h"


/***************** Enumeraciones **********************************************/

typedef enum
{
    False = 0,
    True = 1
} CBool;

typedef char                char_type;
typedef signed char         int8_type;
typedef unsigned char       uint8_type;
/* typedef signed short         int16_type; */
/* typedef unsigned short   uint16_type; */
typedef signed int          int16_type;
typedef unsigned int        uint16_type;
typedef signed long         int32_type;
typedef unsigned long       uint32_type;
typedef long long           int64_type;
/* typedef signed long long int64_type; */
/* typedef unsigned long long   uint64_type; */
typedef float               float32_type;
typedef double              float64_type;           /* Activar -fno-short-double. */
typedef long double         float128_type;



/***************** Definiciones ***********************************************/


#endif


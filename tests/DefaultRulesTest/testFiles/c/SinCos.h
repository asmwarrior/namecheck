/*******************************************************************************
                        Copyright (C) 2012  Mariano Serra
                                  FixView SRL
                      This file is part of the SADI Project.

    Historial de Cambios:
    <dd/mm/aaaa>    <Cambio>                                    <Autor>
    10/05/13        Creacion                                Federico Garcia Cruz
*******************************************************************************/
#ifndef SinCos_H
#define SinCos_H


/************* Inclusiones ************************************************/
#include "typeDefs.h"

/************* Enumeraciones **********************************************/


/************* Definiciones ***********************************************/
/**
@brief              Devuelve el valor del coseno del angulo.
@param  angle       Angulo al que se le calculara el conseno.
@note               El angulo se encuentra en formato Q(10,2).
@return int32_type        Coseno del angulo recibido como argumento.
@note               El valor del coseno retornado se encuentra en formato Q(0,7).
*/
int32_type cosTable(int32_type angle);


/**
@brief              Devuelve el valor del seno del angulo.
@param  angle       Angulo al que se le calculara el seno.
@note               El angulo se encuentra en formato Q(10,2).
@return int32_type        Seno del angulo recibido como argumento.
@note               El valor del seno retornado se encuentra en formato Q(0,7).
*/
int32_type sinTable(int32_type angle);

/************* Variabes Locales *******************************************/


#endif

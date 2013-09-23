/*******************************************************************************
                        Copyright (C) 2012  Mariano Serra
                                  FixView SRL
                      This file is part of the SADI Project.

    Historial de Cambios:
    <dd/mm/aaaa>    <Cambio>                                    <Autor>
    04/04/2013     Creacion.                                   Matias Jejer
    05/04/2013     Implementación funciones                    Matias Jejer
    21/08/2013     Modificaciones en configError               Matias Jejer

Librería encargada del manejo de errores. Los errores se encuentran listados
en un enumerado propio de cada proyecto y esta API recibe enteros únicamente.
Su única responsabilidad es guardarlos en un buffer para ser informados luego.

*******************************************************************************/
#ifndef ERROR_HANDLER_H
#define ERROR_HANDLER_H


/***************** Inclusiones ************************************************/
#include "typeDefs.h"               /* para uso         */

/***************** Enumeraciones **********************************************/


/***************** Definiciones ***********************************************/

typedef uint16_type ErrorType;

/***************** Prototipos *************************************************/


/**
@brief              Aloca en memoria un vector de estructuras que incluye: punteros a función,
                    maximas ocurrencias permisibles y contador de ocurrencias.
                    También inicializa un buffer para encolado de errores.
@param  void
@return bool        Indica el éxito de la operación
*/
CBool initErrorHandler(void);




/**
@brief              Lee del bufer de errores para determinar la existencia de un
                    error y llama a la función de recuperación que corresponda.
@note               El buffer de errores contiene el "enumerado" de posibles errores
@param  errorCode   Puntero a variable de tipo entero sin signo donde se devuelve el
                    codigo de error.
@return bool        Indica si se ha producido un error que deba ser notificado
*/
CBool popError(ErrorType* errorCode);


/**
@brief              Ingresa un código de error en el buffer de errores.
@note
@param  errorCode   Código de error casteado a char (entero sin signo de 8 bits)
@param  notifyEnable CBool que indica si el error debe ser notificado (errores críticos)
@return void
*/
void setError(ErrorType errorCode, CBool notifyEnabled);


/**
@brief              Habilita las notificaciones de todos los errores, sean relevantes o no
@note               Es utilizada en modo debug para tener una trazabilidad de errores.
@note               No se realiza testing ya que no posee lógica sinó que modifica una variable
                    local del modulo unicamente.
@param  enable      CBooleano que indica si se debe habilitar la notificación de todos los errores
                    o únicamente los criticos.
*/
void setEnableAllNotif(CBool enable);

/**
@brief              Libera el espacio de memoria donde se aloco el vector de estructuras
                    y el buffer de errores
@param              void
@return             void
*/
void deInitErrorHandler(void);

#endif

/*******************************************************************************
                                  FixView SRL
                      This file is part of the SADI Project.

    Historial de Cambios:
    <dd/mm/aaaa>    <Cambio>                            <Autor>
     20/08/2012      Creacion.                           Matías Jejer
     29/10/2012      Documentación                       Matías Jejer
     24/01/2013      Modificaciones SMET-2               Matías Jejer

*******************************************************************************/

#include "cbuffer.h"                /* Para implementación      */

/************* Definiciones ***************************************************/

struct CircularBuffer
{
    size_t cont;                 /**< Contador para manejo de índices (delta lectura-escritura)  */
    size_t readIndex;               /**< Indice de lectura */
    size_t writeIndex;              /**< Indice de escritura */
    uint16_type maxIndex;          /**< Capacidad del buffer (máximo valor del índice) */
    uint8_type* bufferStart;              /**< Puntero al comienzo del buffer */
};

/************* Funciones Estaticas ********************************************/

/**
@brief              Determina la cantidad de bytes libres (para escritura) que
                    queda en el buffer
@note               capacidad disponible en bytes
@param CBHandler    Puntero al buffer deseado (Es un "nombre" para el usuario,
                    con el que accederá al buffer)
@return  size_t     Capacidad disponible en el buffer
*/
STATIC INLINE size_t writeCapacity(const CBHandler cb);


/**< Función inline para determinar la cantidad de bytes disponibles (no leídos) que hay en el buffer */


/**
@brief              Determina la cantidad de bytes disponibles para lectura que
                    quedan en el buffer
@param CBHandler    Puntero al buffer deseado (Es un "nombre" para el usuario,
                    con el que accederá al buffer)
@return  size_t     Cantidad de bytes no leidos en el buffer
*/
STATIC INLINE size_t readCapacity(const CBHandler cb);






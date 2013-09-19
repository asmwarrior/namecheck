/*******************************************************************************
                                  FixView SRL
                      This file is part of the SADI Project.

    Historial de Cambios:
    <dd/mm/aaaa>    <Cambio>                            <Autor>
     05/08/2012      Creacion.                           Matías Jejer
     29/10/2012      Documentacion                       Matías Jejer
     24/01/2013      Modificaciones SMET-2  (memcpy)     Matías Jejer

*******************************************************************************/




/************* Inclusiones ****************************************************/

#include <stdlib.h>                 /* Para uso                 */
#include <assert.h>                 /* Para uso                 */
#include <string.h>                 /* Para uso                 */
#include "cbufferDefs.h"            /* Para uso(implementación) */
#include "errorHandler.h"           /* Para uso                 */

/************* Funciones ******************************************************/


/**
@brief          Determinar la cantidad de bytes libres que queda en el buffer
@note           La resta de maxIndex-cont es la capacidad (en bytes) disponibles para escritura
@param  cb      Puntero al buffer deseado
@return size    cantidad de bytes libres que queda en el buffer
*/
STATIC INLINE size_t writeCapacity(CBHandler const cb)
{
    return ((size_t)cb->maxIndex - cb->cont);
}

/**
@brief          Determinar la cantidad de bytes ocupados en el buffer
@note           usada para TESTING
@param  cb      Puntero al buffer deseado
@return size    cantidad de bytes ocupados en el buffer
*/
STATIC INLINE size_t readCapacity(CBHandler const cb)
{
    return (cb->cont);
}


size_t cbWriteCapacity(CBHandler const cb)
{
    return writeCapacity(cb);
}

size_t cbReadCapacity(CBHandler const cb)
{
    return readCapacity(cb);
}



CBHandler cbCreate(size_t capacity)
{
    CBHandler cb;                                                   /*  Función de Creación del buffer (Aloca memoria y devuelve el puntero a dicha región de memoria)   */
    cb = (CBHandler)malloc(sizeof(struct CircularBuffer));          /*  Alocación de memoria de la estructura CircularBuffer (contiene la información del buffer)     */
    if (cb != NULL)
    {
        cb->bufferStart = (uint8_type*)malloc(capacity * sizeof(uint8_type));   /*  Alocación de memoria del Buffer Circular (Contenendrá los datos a guardar)      */
        if (cb->bufferStart != NULL)
        {
            cb->maxIndex = (uint16_type)capacity;
            cb->readIndex = 0;
            cb->writeIndex = 0;
            cb->cont = 0;
        }
        else
        {
            free(cb);
            cb = NULL;
        }
    }

    return cb;

}


void cbFree(CBHandler cb)
{
    assert(cb->bufferStart != NULL);

    free(cb->bufferStart);                                  /* Libera memoria del "vector" (datos guardados)          */
    free(cb);                                               /* Libera memoria de la estructura del buffer (Información de manejo del buffer)      */
}

CBool cbPushBack1(CBHandler cb, const uint8_type src)
{
    const CBool pushSuccess = (CBool)(writeCapacity(cb) > 0);

    if (pushSuccess)
    {
        cb->bufferStart[cb->writeIndex] = src;          /*  Guarda el dato recibido como parámetro en la posición apuntada por el Indice de lectura en el vector apuntado     */
        cb->writeIndex++;                               /*  por el campo bufferStart de la estructura                                                                       */
        cb->cont++;

        cb->writeIndex %= (size_t)cb->maxIndex;                 /*  Reinicia el índice de escritura al llegar al límite superior de la zona de memoria asignada */
    }
    return pushSuccess;
}



CBool cbPushBack(CBHandler cb, const uint8_type* src, size_t sz)
{
    size_t brPoint;
    const CBool pushSuccess = (CBool)(writeCapacity(cb) >= sz);      /* Se verifica que el buffer tenga capacidad de guardar el dato completo    */
    assert(src != NULL);                                    /* Se verifica que el puntero no sea nulo                                   */

    if (pushSuccess)
    {
        brPoint = (size_t)cb->maxIndex - cb->writeIndex;
        if (brPoint >= sz)                  /* Se verifica que el buffer tenga capacidad de guardar el dato completo en una sola operación de memcpy    */
        {
            memcpy(&cb->bufferStart[cb->writeIndex], src, sz);
            cb->writeIndex = cb->writeIndex + sz;
        }
        else                                /* En caso que no pueda guardar todo (la cantidad de memoria hasta el final del buffer no sea suficiente) se realizan 2 operaciones */
        {
            memcpy(&cb->bufferStart[cb->writeIndex], src, brPoint);  /* Copia bytes desde la posición actual hasta el final del buffer    */
            memcpy(cb->bufferStart, src + brPoint, sz - brPoint);   /* Copia bytes desde la posición inicial del buffer mientras haya datos disponibles */
            cb->writeIndex = sz - brPoint;
        }
        cb->cont = cb->cont + sz;
    }
    /*else
        setError((ErrorType)CBufferPushError);*/

    return pushSuccess;
}




CBool cbPopFront1(CBHandler cb, uint8_type* dest)
{
    const CBool popSuccess = (CBool)(readCapacity(cb) > 0);
    assert(dest != NULL);                           /* Verificación que el puntero no sea nulo */

    if (popSuccess)
    {
        (*dest) = cb->bufferStart[cb->readIndex];   /*  Guarda el elemento apuntado por el índice de lectura del buffer apuntado por bufferStart en la posición apuntada      */
        cb->readIndex++;                            /*  por dest (parámetro pasado como argumento de la función                                                               */
        cb->cont--;

        cb->readIndex %= (size_t)cb->maxIndex;              /*  Reinicia el índice de lectura al llegar al límite de la zona de memoria asignada al buffer    */
    }

    return popSuccess;
}


CBool cbPopFront(CBHandler cb, uint8_type* dest, size_t sz)
{
    size_t brPoint;
    const CBool popSuccess = (CBool)(readCapacity(cb) >= sz);           /* Se verifica que el buffer tenga tantos datos como se pretende leer       */
    assert(dest != NULL);                                       /* Se verifica que el puntero no sea nulo                                   */


    if (popSuccess)
    {
        brPoint = (size_t)cb->maxIndex - cb->readIndex;
        if (brPoint >= sz)                  /* Se verifica que el buffer tenga capacidad de leer el dato completo en una sola operación de memcpy    */
        {
            memcpy(dest, &cb->bufferStart[cb->readIndex], sz);
            cb->readIndex = cb->readIndex + sz;
        }
        else                                /* En caso que no pueda leer todo (el dato se encuentra particionado) se realizan 2 operaciones */
        {
            memcpy(dest, &cb->bufferStart[cb->readIndex], brPoint);  /* Copia bytes desde la posición actual hasta el final del buffer    */
            memcpy(dest + brPoint, cb->bufferStart, sz - brPoint);   /* Copia bytes desde la posición inicial del buffer mientras haya datos disponibles */
            cb->readIndex = sz - brPoint;
        }
        cb->cont = cb->cont - sz;
    }

    return popSuccess;
}

/*******************************************************************************
                                  FixView SRL
                      This file is part of the SADI Project.

    Historial de Cambios:
    <dd/mm/aaaa>    <Cambio>                            <Autor>
     20/08/2012      Creacion.                           Matías Jejer
     25/10/2012      Documentación                       Matías Jejer
     24/01/2013      Modificaciones SMET-2               Matías Jejer

*******************************************************************************/


#ifndef _THE_HEADER_buffer1B_h_
#   define _THE_HEADER_buffer1B_h_

/************* Inclusiones ****************************************************/

#include "typeDefs.h"       /* Para uso     */
#include "platformDetection.h"

/************* Definiciones ***************************************************/


struct CircularBuffer;                      /*!< Estructura para manejo de buffer */
typedef struct CircularBuffer* CBHandler;   /* Information Hiding: El usuario no sabe que es un puntero */

#define NO_BUFFER NULL


/************* Prototipos *****************************************************/


/**
@brief              Crea un nuevo buffer de tamaño de dato variable
@note               Los datos a contener pueden ser de distinto tipo y tamaño
@param  capacity    Número de elementos a almacenar en el buffer
@return CBHandler   Puntero al comienzo del buffer (Es un "nombre" para el usuario,
                    con el que accederá al buffer)
*/
CBHandler cbCreate(size_t capacity);




/**
@brief          Elimina un buffer existente
@note           Precondición: El buffer debe haber sido alocado previamente
@param  cb      Puntero a la variable de tipo estructura CircularBuffer
@return void
*/
void cbFree(CBHandler cb);



/**
@brief          Inserta un nuevo item (de 1 Byte de longitud) en el buffer
                \n Ingresa el item pasado como argumento a la cola de la FIFO (Buffer)
@note           El tamaño del item debe ser de 8 bits de longitud
@param  cb      Puntero al buffer deseado
@param  src     Valor de la variable que se desea ingresar a la FIFO
@return bool    Indicador de éxito de la operación
*/
CBool cbPushBack1(CBHandler cb, const uint8_type src);





/**
@brief          Inserta un nuevo item en el buffer
                \n Ingresa el item pasado como argumento a la cola de la FIFO (Buffer)
@note           Permite ingresar un dato de tamaño variable especificando este parámetro
@param  cb      Puntero al buffer deseado
@param  src     Puntero a la variable que se desea ingresar a la FIFO
@param  sz      Tamaño del dato a ingresar (en bytes)
@return bool    Indicador de éxito de la operación
*/
CBool cbPushBack(CBHandler cb, const uint8_type* src, size_t sz);





#define cbPushBackData(cb, src) cbPushBack(cb, (uint8_type*)&src, sizeof(src))   /** Macro para ingreso de datos en el buffer de manera inteligente /n Determina el tamaño mediante sizeof */



/**
@brief          Extrae un item (de 8 bits) del buffer
                \n Retira el último item del buffer y lo almacena en la posición indicada
@note           El tamaño del item debe ser de 8 bits de longitud
@param  cb      Puntero al buffer deseado
@param  dest    Puntero a la variable donde se desea almacenar el dato extraído
@return bool    Indicador de éxito de la operación
*/
CBool cbPopFront1(CBHandler cb, uint8_type* dest);





/**
@brief          Extrae un item del buffer
                \n Retira el último item del buffer y lo almacena en la posición indicada
@note           El tamaño del item debe ser concordante con el valor pasado como argumento
@param  cb      Puntero al buffer deseado
@param  dest    Puntero a la variable donde se desea almacenar el dato extraído
@param  sz      Tamaño del dato a extraer (en bytes)
@return bool    Indicador de éxito de la operación
*/
CBool cbPopFront(CBHandler cb, uint8_type* dest, size_t sz);




#define cbPopFrontData(cb, dest) cbPopFront(cb, (uint8_type*)&dest, sizeof(dest))    /** Macro para extracción de datos en el buffer de manera inteligente /n Determina el tamaño mediante sizeof */

/**
@brief          Determinar la cantidad de bytes libres que queda en el buffer
@note           usada para TESTING
@param  cb      Puntero al buffer deseado
@return size    cantidad de bytes libres que queda en el buffer
*/
size_t cbWriteCapacity(const CBHandler cb);

/**
@brief          Determinar la cantidad de bytes ocupados en el buffer
@note           usada para TESTING
@param  cb      Puntero al buffer deseado
@return size    cantidad de bytes ocupados en el buffer
*/
size_t cbReadCapacity(const CBHandler cb);

#endif


#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
//Funciones obtenidas desde el classroom viendo los videos del profesor Davila.
/**
 * \brief chequea si la cadena ingresada es flotante
 * \param cadena de caracteres
 * \return devuelce 1 si la cadena es flotante y 0 si no
 *
 */int esNumeroFlotante(char* cadena);

/**
* \brief busca un "\0" y verifica  que no supere el tamaño maximo
 *
 * \param  array
 * \param el tamaño del array.
 * \return int longitud en bytes y si se desborda, devuelve el maximo.
 */int strnlen1(const char *s,size_t maxlen);

/**
 * \brief lee hasta '\n' y copia la cadena
 *
 * \param puntero al espacio de memoria
 * \param tamaño de la cadena
 * \return devuelve 0 si se obtiene una cadena y -1 si no
 *
 */int getString(char* cadena, int longitud);

/**
* \brief pide un numero al usuario y verifica
* \param puntero al espacio de memoria
* \param tamaño del array resultado
* \param el mensaje a mostrar
* \param el mensaje de error
* \param cantidad de reintentos
* \return devuelve 1 si se obtuvo el nombre y -1 si no
*
*/int utn_getNombre(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);

/**
* \brief adquiere numero al usuario y filtra
* \param puntero al espacio de memoria
* \param es el mensaje a ser mostrado
* \param mensaje de Error a ser mostrado
* \param numero maximo a ser aceptado
* \param minimo minimo a ser aceptado
* \return devuelve1 si se obtuvo el numero y -1 si no
*
*/int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

/**
* \brief adquiere numero entero
* \param  puntero al espacio de memoria
* \return devuelve 0 si se obtiene un numero entero y -1 si no
*
*/int getInt(int* pResultado);

/**
* \brief pide un numero y filtra si es correcto
* \param puntero al espacio de memoria
* \param mensaje a mostrar
* \param mensaje de Error
* \param  el numero maximo
* \param  el minimo minimo
* \return devuelve 1 si se obtuvo el numero y -1 si no
*
*/int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);

/**
 * \brief pide y verifica si la cadena ingresada es flotante
 * \param puntero al espacio de memoria
 * \return devulve 0 si se obtiene un numero flotante y -1 si no
 *
 */int getFloat(float* pResultado);

/**
* \brief obtiene una cadena de caracteres valido
* \param puntero al espacio de memoria
* \return devuelve 1 si se obtiene un numero flotante y -1  si no
*
*/int getNombre(char* pResultado, int longitud);

/**
* \brief Chequea si la cadena ingresada es un nombre valido
* \param cadena de caracteres
* \return devuelve 0 si la cadena es valida y 0 si no
*
*/int esUnNombreValido(char* cadena,int longitud);

/**
 * \brief chequea si la cadena ingresada es formato numero
 * \param cadena Cadena de caracteres
 * \return devuelve 1 si la cadena es numerica, 0 si no  y -1 si da error
 *
 */int esFormatoNumero(char* cadena, int limite);
 int utn_getEntero(int* pEntero,int reintentos,char* msg,char*msgError,int min,int max);

#endif // VALIDACIONES_H_INCLUDED

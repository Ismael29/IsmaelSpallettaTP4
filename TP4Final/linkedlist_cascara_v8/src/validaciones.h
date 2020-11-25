#ifndef VALIDA_H_INCLUDED
#define VALIDA_H_INCLUDED

#endif // VALIDA_H_INCLUDED
/** \brief pide ingreso de un char, lo valida entre dos opciones posibles
 *
 * \param mensaje es un puntero a cadena de char, mensaje para pedir datos
 * \param mensajeError es un puntero a cadena de char, mensaje para pedir datos tras error de ingreso de caracter
 * \param resp1 es el primer char valido
 * \param resp2 es el segundo char valido
 * \return devuelve char de resp1 o resp2 segun corresponda
 *
 */char validaChar2 (char* mensaje, char* mensajeError, char resp1, char resp2);

/** \brief pide ingreso de una cadena de char, valida que no supere largo maximo, lo carga en otro vector auxiliar
 *
 * \param mensaje es puntero a char, texto pidiendo el dato a ingresar
 * \param mensajeError es puntero a char, texto informando ingreso de dato invalido
 * \param maxStrLen es int, cantidad maxima de caracteres +1 ('/0') para el vector
 * \param auxiliar es vector de char, es el vector donde se cargara la cadena ya validada
 * \return devuelve 1 si cargo bien el puntero, 0 si no pudo
 *
 */int validaString (char* mensaje, char* mensajeError, int maxStrLen, char* Pauxiliar);

/** \brief Recibe una cadena de caracteres y pasa a myuscula la primera letra de cada palabra
 *
 * \param nombre es un vector de char.
 *
 */void poneMayuscula (char* nombre);

/** \brief Muestra mensaje para pedir un float y lo valida
 *
 * \param char* mensaje para pedir numero
 * \param char* mensaje en caso que se ingrese dato erroneo
 * \param int determina si acepta numeros negativos (1 para si, 0 para no)
 * \param float* puntero a variable a cargar tras validacion
 * \return devuelve 1 si valido OK, 0 si no.
 */int validaFloat (char* mensaje, char* mensajeError, int negativos, float* Pauxiliar);

/** \brief Muestra mensaje para pedir un int y lo valida
 *
 * \param char* mensaje para pedir numero
 * \param char* mensaje en caso que se ingrese dato erroneo
 * \param int determina si acepta numeros negativos (1 para si, 0 para no)
 * \param int* puntero a variable a cargar tras validacion
 * \return devuelve 1 si valido OK, 0 si no.
 */int validaInt (char* mensaje, char* mensajeError,int negativos, int* Pauxiliar);

 //--------
 int utn_getEntero(int* pEntero,int reintentos,char* msg,char*msgError,int min,int max);
 int getInt(int* pAux);
 int getCadena(char* pAux,int limite);
 int isInt(char *pAux);



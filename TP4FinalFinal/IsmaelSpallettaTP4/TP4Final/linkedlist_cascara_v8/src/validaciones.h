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
 //int getInt(int* pAux);
 int getCadena(char* pAux,int limite);
 int isInt(char *pAux);
 /**
 * \brief Solicita un numero al usuario, leuego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param minimo Es el numero maximo a ser aceptado
 * \param maximo Es el minimo minimo a ser aceptado
 * \return Retorna 1 si se obtuvo el numero y -1 si no
 *
 */int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);


/**
 * \brief Verifica si la cadena ingresada es flotante
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero flotante y -1 (ERROR) si no
 *
 */int getFloat(float* pResultado);


/**
 * \brief Verifica si la cadena ingresada es flotante
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (vardadero) si la cadena es flotante y 0 (falso) si no lo es
 *
 */int esFlotante(char* cadena);


/**
* \brief busca un '\0' y a su vez, busca no pasarse del tamaño maximo que tiene el array que le paso en la llamada.
 *
 * \param el array que le paso.
 * \param el tamaño de dicho array.
 * \return int longitud en bytes y si se desborda, devuelve el maximo.
 */int strnlen1(const char *s, size_t maxlen);


/**
 * \brief 	Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena
 * 			un máximo de 'longitud - 1' caracteres.
 * \param pResultado Puntero al espacio de memoria donde se copiara la cadena obtenida
 * \param longitud Define el tamaño de cadena
 * \return Retorna 0 (EXITO) si se obtiene una cadena y -1 (ERROR) si no
 *
 */int getString(char* cadena, int longitud);


 /**
 * \brief Solicita un nombre al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param longitud Es la longitud del array resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param reintentos Cantidad de reintentos
 * \return Retorna 1 si se obtuvo el nombre y -1 si no
 *
 */ int utn_getNombre(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);


 /**
 * \brief Obtiene un string valido como nombre
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 1 (EXITO) si se obtiene un numero flotante y -1 (ERROR) si no
 *
 */ int getNombre(char* pResultado, int longitud);


 /**
 * \brief Verifica si la cadena ingresada es un nombre valido
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 0 (verdadero) si la cadena es valida y 0 (falso) si no lo es
 *
 */ int esNombre(char* cadena,int longitud);


 /**
 * \brief Solicita un numero al usuario, leuego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param minimo Es el numero maximo a ser aceptado
 * \param maximo Es el minimo minimo a ser aceptado
 * \return Retorna 1 si se obtuvo el numero y -1 si no
 *
 */ int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);


 /**
 * \brief Obtien un numero entero
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 *
 */int getInt(int* pResultado);


/**
 * \brief Verifica si la cadena ingresada es numerica
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es numerica, 0 (falso) si no lo es y -1 en caso de error
 *
 */int esNumerica(char* cadena, int limite);




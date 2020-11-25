#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include "validaciones.h"
char validaChar2 (char* mensaje, char* mensajeError, char resp1, char resp2)
{
    char respuesta;
    printf("%s",mensaje);
    fflush(stdin);
    respuesta = getchar();
    respuesta = tolower(respuesta);
    while (respuesta!=resp1 && respuesta!=resp2)
    {
        printf("\r%s",mensajeError);
        fflush(stdin);
        respuesta = getchar();
    }
    return respuesta;

}
int validaString (char* mensaje, char* mensajeError, int maxStrLen, char* auxiliar)
{
    int todoOk = 0;
    char aux[500];
    int numeros;

    printf("%s", mensaje);
    fflush(stdin);
    gets(aux);
    numeros = atoi(aux) ;
    if (strlen(aux)<=maxStrLen || numeros == 0)
    {
        todoOk = 1;
    }
    while (strlen(aux)>maxStrLen || numeros != 0 )
    {
        printf("%s", mensajeError);
        fflush(stdin);
        gets(aux);
        numeros = atoi(aux) ;
        if (strlen(aux)<=maxStrLen || numeros == 0)
        {
            todoOk = 1;
        }
    }
    strcpy(auxiliar,aux);
    return todoOk;
}
void poneMayuscula (char* nombre)
{
    int tam;
    tam = strlen(nombre);
    for (int i=0; i<tam; i++)
    {
        nombre[i] = tolower(nombre[i]);
    }
    for (int i=0; i<tam; i++)
    {
        if (i==0 || nombre[i-1]==' ')
        {
            nombre[i] = toupper(nombre[i]);
        }
    }
}

int validaFloat (char* mensaje, char* mensajeError, int negativos, float* Pauxiliar)
{

    int todoOK = 0;
    int esNumero;

    printf("%s",mensaje);
    fflush(stdin);
    esNumero = scanf("%f",Pauxiliar);

    if (!negativos)
    {
        while ((*Pauxiliar) < 0 || !esNumero)
        {
            printf("%s",mensajeError);
            fflush(stdin);
            esNumero = scanf("%f",Pauxiliar);
        }
        todoOK = 1;
    }
    else if (negativos)
    {
        while (!esNumero)
        {
            printf("%s",mensajeError);
            fflush(stdin);
            esNumero = scanf("%f",Pauxiliar);
        }
        todoOK = 1;
    }
    return todoOK;
}

int validaInt (char* mensaje, char* mensajeError, int negativos, int* Pauxiliar)
{
    int todoOK = 0;
    int esNumero;

    printf("%s",mensaje);
    fflush(stdin);
    esNumero = scanf("%d",Pauxiliar);
    if (negativos == 0)
    {
        while ((*Pauxiliar) < 0 || !esNumero)
        {
            printf("%s",mensajeError);
            fflush(stdin);
            esNumero = scanf("%d",Pauxiliar);
        }
        todoOK = 1;
    }
    else if (negativos == 1)
    {
        while (!esNumero)
        {
            printf("%s",mensajeError);
            fflush(stdin);
            esNumero = scanf("%d",Pauxiliar);
        }
        todoOK = 1;
    }
    return todoOK;
}
//-------------
int utn_getEntero(int* pEntero,int reintentos,char* msg,char*msgError,int min,int max)
{
    int todoOk = -1;
    int auxInt;

    if(pEntero!=NULL&& msg !=NULL && msgError!=NULL && min<= max && reintentos>=0)
    {
        do
        {
            reintentos--;
            printf("%s",msg);
            if(getInt(&auxInt) == 0 && auxInt >= min && auxInt<=max)
            {
                *pEntero= auxInt;
                todoOk = 0;
                break;
            }
            else
            {
                printf("%s",msgError);
            }
        }
        while(reintentos >= 0);
    }
    return todoOk;
}
int getInt(int* pAux)
{
    char auxString[200];
    int todoOk =-1;
    if(getCadena(auxString,200)==0 && isInt(auxString)==0)
    {
        *pAux=atoi(auxString);
        todoOk=0;
    }
    return todoOk;
}
int getCadena(char* pAux,int limite)
{
    char auxString[2000];
    int todoOk =-1;
    if (pAux != NULL && limite >0)
    {
        fflush(stdin);
        fgets(auxString,sizeof(auxString),stdin);
        if (auxString[strlen(auxString)-1]=='\n')
        {
            auxString[strlen(auxString)-1]='\0';
        }
        if(strlen(auxString)<= limite)
        {
            strncpy(pAux,auxString,limite);
            todoOk=0;
        }
    }
    return todoOk;
}
int isInt(char *pAux)
{
    int todoOk=-1;
    int i=0;
    do
    {
        if(*(pAux+i)<48||*(pAux+i)>57)
        {
            break;
        }
        i++;
    }while (i<strlen(pAux));
    if(i==strlen(pAux))
    {
        todoOk=0;
    }
    return todoOk;
}
int strnlen1(const char *s, size_t maxlen)
{
    size_t len;

    for (len = 0; len < maxlen; len++, s++)
    {
        if (!*s)
            break;
    }
    return (len);
}

int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos)
{
    float bufferFloat;
    int retorno = -1;
    while(reintentos>=0)
    {
        reintentos--;
        printf("%s",mensaje);
        if(getFloat(&bufferFloat) == 0)
        {
            if(bufferFloat >= minimo && bufferFloat <= maximo)
            {
                *pResultado = bufferFloat;
                retorno = 1;
                break;
            }
        }
        printf("%s",mensajeError);
    }
    return retorno;
}

int getFloat(float* pResultado)
{
    int retorno=-1;
    char buffer[64];

    if(pResultado != NULL)
    {
        if(getString(buffer,sizeof(buffer))==0 && esFlotante(buffer))
        {
            *pResultado = atof(buffer);
            retorno = 0;
        }
    }
    return retorno;
}

int getString(char* cadena, int longitud)
{
    int retorno=-1;
    char bufferString[4096];

    if(cadena != NULL && longitud > 0)
    {
        fflush(stdin);
        if(fgets(bufferString,sizeof(bufferString),stdin) != NULL)
        {
            if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n')
            {
                bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
            }
            if(strnlen(bufferString,sizeof(bufferString)) <= longitud)
            {
                strncpy(cadena,bufferString,longitud);
                retorno=0;
            }
        }
    }
    return retorno;
}

int esFlotante(char* cadena)
{
    int i=0;
    int retorno = 1;
    int contadorPuntos=0;

    if(cadena != NULL && strlen(cadena) > 0)
    {
        for(i=0 ; cadena[i] != '\0'; i++)
        {
            if(i==0 && (cadena[i] == '-' || cadena[i] == '+'))
            {
                continue;
            }
            if(cadena[i] < '0' || cadena[i] > '9' )
            {
                if(cadena[i] == '.' && contadorPuntos == 0)
                {
                    contadorPuntos++;
                }
                else
                {
                    retorno = 0;
                    break;
                }
            }
        }
    }
    return retorno;
}

int utn_getNombre(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos)
{
    char bufferString[4096];
    int retorno = -1;
    while(reintentos>=0)
    {
        reintentos--;
        printf("%s",mensaje);
        if(getNombre(bufferString,sizeof(bufferString)) == 0 && strnlen(bufferString,sizeof(bufferString)) < longitud )
        {
            strncpy(pResultado,bufferString,longitud);
            retorno = 1;
            break;
        }
        printf("%s",mensajeError);
    }
    return retorno;
}

int getNombre(char* pResultado, int longitud)
{
    int retorno=-1;
    char buffer[4096];

    if(pResultado != NULL)
    {
        if(	getString(buffer,sizeof(buffer))==0 &&
                esNombre(buffer,sizeof(buffer)) &&
                strnlen(buffer,sizeof(buffer))<longitud)
        {
            strncpy(pResultado,buffer,longitud);
            retorno = 0;
        }
    }
    return retorno;
}

int esNombre(char* cadena,int longitud)
{
    int i=0;
    int retorno = 1;

    if(cadena != NULL && longitud > 0 )
    {
        for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
        {
            if((cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ))
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
    int retorno = -1;
    int bufferInt;
    do
    {
        printf("%s",mensaje);
        if(	getInt(&bufferInt) == 0 &&
                bufferInt >= minimo &&
                bufferInt <= maximo)
        {
            retorno = 1;
            *pResultado = bufferInt;
            break;
        }
        printf("%s",mensajeError);
        reintentos--;
    }
    while(reintentos>=0);

    return retorno;
}
int esNumerica(char* cadena, int limite)
{
    int retorno = -1;
    int i;
    if(cadena != NULL && limite > 0)
    {
        retorno = 1;
        for(i=0; i<limite && cadena[i] != '\0'; i++)
        {
            if(i==0 && (cadena[i] == '+' || cadena[i] == '-'))
            {
                continue;
            }
            if(cadena[i] < '0'||cadena[i] > '9')
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

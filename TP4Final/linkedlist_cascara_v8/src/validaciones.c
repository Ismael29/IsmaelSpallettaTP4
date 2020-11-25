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

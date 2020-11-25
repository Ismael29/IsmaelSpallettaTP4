#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Employee.h"
#include "validaciones.h"
#include "controller.h"

Employee* employee_new()
{
    Employee* newEmployee = (Employee*) malloc(sizeof(Employee));
    if (newEmployee != NULL)
    {
        newEmployee->id = 0;
        strcpy(newEmployee->nombre," ");
        newEmployee->sueldo = 0;
        newEmployee->horasTrabajadas = 0;
    }
    return newEmployee;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
    Employee* nuevo = employee_new();

    if (nuevo != NULL)
    {
        employee_setId(nuevo, atoi(idStr));
        employee_setNombre(nuevo, nombreStr);
        employee_setHorasTrabajadas(nuevo, atoi(horasTrabajadasStr));
        employee_setSueldo(nuevo, atoi(sueldoStr));
    }
    return nuevo;
}

int employee_setId(Employee* this,int id)
{

    int todoOk = 0;

    if (this != NULL)
    {
        this->id = id;
        todoOk = 1;
    }
    return todoOk;
}

int employee_setNombre(Employee* this,char* nombre)
{

    int todoOk = 0;

    if (this != NULL)
    {
        strcpy(this->nombre, nombre);
        todoOk = 1;
    }
    return todoOk;

}


int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{

    int todoOk = 0;

    if (this != NULL)
    {

        this->horasTrabajadas = horasTrabajadas;
        todoOk = 1;
    }

    return todoOk;

}
int employee_setSueldo(Employee* this,int sueldo)
{
    int todoOk = 0;

    if (this != NULL)
    {
        this->sueldo = sueldo;
        todoOk = 1;
    }
    return todoOk;
}

int employee_getId(Employee* this,int* id)
{

    int todoOk = 0;

    if (this != NULL && id !=NULL)
    {

        *id = this->id;
        todoOk = 1;


    }

    return todoOk;

}

int employee_getSueldo(Employee* this,int* sueldo)
{

    int todoOk = 0;

    if (this != NULL && sueldo !=NULL)
    {

        *sueldo = this->sueldo;
        todoOk = 1;
    }
    return todoOk;
}

int employee_getHorasTrabajadas(Employee* this,int* horas)
{
    int todoOk = 0;
    if (this != NULL && horas !=NULL)
    {
        *horas = this->horasTrabajadas;
        todoOk = 1;
    }
    return todoOk;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int todoOk = 0;
    if (this != NULL && nombre !=NULL)
    {
        strcpy(nombre,this->nombre );
        todoOk = 1;
    }
    return todoOk;
}
void employee_delete(Employee* this)
{
    free(this);
}
int altaEmpleado (LinkedList* lista)
{
    int todoOk =0;
    int id;
    Employee* temporal = (Employee*) employee_new();
    system("cls");
    printf("***** ALTA EMPLEADO *****\n");
    validaInt("Ingrese ID: ", "ERROR, EL ID DEBE SER NUMERICO\nIngrese ID: ",0, &id);
    if (verificaId(lista, id))
    {
        temporal->id = id;
        validaString("Ingrese nombre: ", "ERROR, el nombre no acepta numeros ni puede superar los 128 caracteres\nIngrese nombre: ", 128, temporal->nombre);
        poneMayuscula(temporal->nombre);
        validaInt("Ingrese horas trabajadas: ", "ERROR, DEBE INGRESAR UN NUMERO POSITIVO\nIngrese horas trabajadas: ",0, &temporal->horasTrabajadas);
        validaInt("ingrese sueldo: ", "ERROR, DEBE INGRESAR UN NUMERO POSITIVO\ningrese sueldo: ",0, &temporal->sueldo);
        if (ll_add(lista, temporal) == 0)
        {
            todoOk = 1;
            printf("ALTA EXITOSA\n");
        }
    }
    else
    {
        printf("ID DUPLICADA\n");
    }
    if (!todoOk)
    {
        employee_delete(temporal);
    }
    return todoOk;
}
int verificaId (LinkedList* lista, int id)
{
    int todoOk = 1;

    Employee* temporal = (Employee*) employee_new();

    if (temporal != NULL)
    {

        for (int i=0; i<ll_len(lista); i++)
        {
            temporal = ll_get(lista, i);

            if (temporal->id == id)
            {
                todoOk = 0;
                break;
            }
        }
    }
    return todoOk;
}

int modificaEmpleado (LinkedList* lista)
{
    int todoOk = 0;
    int id;
    int index;
    int flag = 0;
    char respuesta;
    Employee* temporal = (Employee*) employee_new();

    if (lista != NULL && temporal !=NULL)
    {
        system("cls");
        printf("**** MODIFICACION DE EMPLEADO ****\n");

        do
        {
            validaInt("Seleccione Id para dar de baja o ingrese 0 para ver lista completa: ",
                      "ERROR, DEBE INGRESAR UN NUMERO POSITIVO\nSeleccione Id para dar de baja o ingrese 0 para ver lista completa: ", 0, &id );

            if (id == 0)
            {
                listarEmpleados(lista);
            }
            else
            {
                for (int i=0; i<ll_len(lista); i++)
                {
                    temporal = ll_get(lista, i);
                    if (temporal->id == id)
                    {
                        index = i;
                        flag = 1;
                        break;
                    }
                }
                if (flag)
                {
                    system("cls");
                    printf("Se va a modificar a: \n");
                    printf("  ID        NOMBRE  HORAS TRABAJADAS  SUELDO\n");
                    listarEmpleado(lista, index);
                    printf("\n\nEs correcto (s/n)? ");
                    fflush(stdin);
                    respuesta = getchar();
                    respuesta = tolower(respuesta);

                    if (respuesta == 's')
                    {
                        if (switchModificaEmpleado(lista, index))
                        {
                            todoOk = 1;
                        }
                    }
                    else if (respuesta != 's')
                    {
                        printf("Modificacion cancelada\n");
                    }

                    break;
                }
                else
                {
                    printf("El ID no corresponde a ningun empleado activo \n");
                    break;
                }
            }
        }
        while (flag == 0);
    }
    return todoOk;
}
int switchModificaEmpleado (LinkedList* lista, int index)
{
    int opcion;
    do
    {
        opcion = menuModificaEmpleado();
        switch(opcion)
        {
        case 1:
            modificaId(lista, index);
            system("pause");
            break;

        case 2:
            modificaNombre(lista, index);
            system("pause");
            break;

        case 3:
            modificaHoras(lista, index);
            system("pause");
            break;

        case 4:
            modificaSueldo(lista, index);
            system("pause");
            break;
        }
    }
    while(opcion != 5);
    return opcion;
}
int menuModificaEmpleado()
{

    int opcion;

    system("cls");
    printf("**** MODIFICACION DE EMPLEADO ****\n\n");
    printf("1. Modificar ID.\n");
    printf("2. Modificar Nombre.\n");
    printf("3. Modificar Horas trabajadas.\n");
    printf("4. Modificar Sueldo.\n");
    printf("5. Salir\n");

    validaInt("Elija opcion: ", "DATO INVALIDO.\nElija opcion: ", 0, &opcion);
    return opcion;
}
int modificaId(LinkedList* lista,int  index)
{

    int todoOk = 0;
    int id;
    Employee* temporal = (Employee*) employee_new();
    temporal = ll_get(lista, index);

    if (temporal != NULL)
    {
        validaInt("Ingrese nuevo ID: ", "ERROR, EL ID DEBE SER NUMERICO\nIngrese nuevo ID: ",0, &id);
        if (verificaId(lista, id))
        {
            printf("Se modifico el ID %d por %d\n", temporal->id, id);
            temporal->id = id;
            todoOk = 1;
        }
        else
        {
            printf("ID DUPLICADA\n");
        }
    }
    else
    {
        printf("No se pudo modificar el ID");
    }
    return todoOk;
}

int modificaNombre(LinkedList* lista,int  index)
{
    int todoOk = 0;
    char nombre[128];

    Employee* temporal = (Employee*) employee_new();
    temporal = ll_get(lista, index);

    if (temporal != NULL)
    {
        validaString("Ingrese nuevo nombre: ", "ERROR, el nombre no acepta numeros ni puede superar los 128 caracteres\nIngrese nuevo nombre: ", 128, nombre);
        poneMayuscula(nombre);

        printf("Se modifico el nombre %s por %s\n", temporal->nombre, nombre);
        strcpy(temporal->nombre, nombre);
        todoOk = 1;
    }
    else
    {
        printf("No se pudo modificar el nombre");
    }
    return todoOk;
}

int modificaHoras(LinkedList* lista,int  index)
{
    int todoOk = 0;
    int horas;

    Employee* temporal = (Employee*) employee_new();
    temporal = ll_get(lista, index);

    if (temporal != NULL)
    {
        validaInt("Ingrese nueva cantidad de horas trabajdas: ", "ERROR, DEBE INGRESAR UN NUMERO POSITIVO\nIngrese nueva cantidad de horas trabajdas: ",
                  0, &horas);
        printf("Se modificaron las %d horas trabajadas por %d\n", temporal->horasTrabajadas, horas);
        temporal->horasTrabajadas = horas;
        todoOk = 1;
    }
    else
    {
        printf("No se pudo modificar las horas trabajadas");
    }
    return todoOk;
}

int modificaSueldo(LinkedList* lista,int  index)
{

    int todoOk = 0;
    int sueldo;

    Employee* temporal = (Employee*) employee_new();
    temporal = ll_get(lista, index);

    if (temporal != NULL)
    {
        validaInt("Ingrese nuevo sueldo: ", "ERROR, DEBE INGRESAR UN NUMERO POSITIVO\nIngrese nuevo sueldo: ",0, &sueldo);

        printf("Se modifico el sueldo %d por %d\n", temporal->sueldo, sueldo);
        temporal->sueldo = sueldo;
        todoOk = 1;
    }
    else
    {
        printf("No se pudo modificar el sueldo");
    }

    return todoOk;
}

int bajaEmpleado(LinkedList* lista)
{
    int todoOk = 0;
    int id;
    int index;
    int flag = 0;
    char respuesta;
    Employee* temporal = (Employee*) employee_new();

    if (lista != NULL)
    {
        system("cls");
        printf("**** BAJA DE EMPLEADO ****\n");

        do
        {
            validaInt("Seleccione Id para dar de baja o ingrese 0 para ver lista completa: ",
                      "ERROR, DEBE INGRESAR UN NUMERO POSITIVO\nSeleccione Id para dar de baja o ingrese 0 para ver lista completa: ", 0, &id );
            if (id == 0)
            {
                listarEmpleados(lista);
            }
            else
            {
                for (int i=0; i<ll_len(lista); i++)
                {
                    temporal = ll_get(lista, i);
                    if (temporal->id == id)
                    {
                        index = i;
                        flag = 1;
                        break;
                    }
                }

                if (flag)
                {
                    system("cls");
                    printf("Se va a dar de baja a: \n");
                    printf("  ID        NOMBRE  HORAS TRABAJADAS  SUELDO\n");
                    listarEmpleado(lista, index);
                    printf("\n\nEs correcto (s/n)? ");
                    fflush(stdin);
                    respuesta = getchar();
                    respuesta = tolower(respuesta);

                    if (respuesta == 's' && ll_remove(lista, index)==0)
                    {
                        printf("BAJA EXITOSA\n");
                        todoOk = 1;
                    }
                    else if (respuesta != 's')
                    {
                        printf("Baja cancelada\n");
                    }
                    else
                    {
                        printf("error realizando la baja\n");
                    }
                }
                else
                {
                    printf("El ID no corresponde a un empleado activo\n");
                    flag = 1;
                }
            }
        }
        while (flag == 0);
    }

    return todoOk;

}
void listarEmpleados(LinkedList* lista)
{
    printf("  ID        NOMBRE  HORAS TRABAJADAS  SUELDO\n");
    for (int i=0; i<ll_len(lista); i++)
    {
        listarEmpleado(lista, i);
    }
}

void listarEmpleado(LinkedList* lista, int index)
{

    Employee* temp = (Employee*) employee_new();

    temp = ll_get(lista, index);
    printf("%4d  %12s  %8d          %d \n", temp->id, temp->nombre, temp->horasTrabajadas, temp->sueldo);
}

int switchOrdenaEmpleado(LinkedList* lista)
{
    int opcion;
    int criterio = -1;

    do
    {
        opcion = menuOrdenaEmpleado();
        if (opcion < 5)
        {
            while (criterio != 0 && criterio !=1)
            {
                validaInt("Seleccione 1 para orden ascendente, 0 para orden descendente: ",
                          "ERROR, debe ingresar 1 o 0\nSeleccione 1 para orden ascendente, 0 para orden descendente: ",0, &criterio);
            }
        }
        switch(opcion)
        {
        case 1:
            ll_sort(lista, ordenaPorId, criterio);
            break;
        case 2:
            ll_sort(lista, ordenaPorNombre, criterio);
            break;
        case 3:
            ll_sort(lista, ordenaPorHoras, criterio);
            break;
        case 4:
            ll_sort(lista, ordenaPorSueldo,criterio);
            break;
        }
    }
    while(opcion != 5);

    return opcion;
}
int menuOrdenaEmpleado()
{

    int opcion;

    system("cls");
    printf("**** ORDEN DE EMPLEADO ****\n\n");
    printf("1. Ordenar por ID.\n");
    printf("2. Ordenar por Nombre.\n");
    printf("3. Ordenar por Horas trabajadas.\n");
    printf("4. Ordenar por Sueldo.\n");
    printf("5. Salir\n");
    validaInt("Elija opcion: ", "DATO INVALIDO.\nElija opcion: ", 0, &opcion);


    return opcion;
}

int ordenaPorId(void* e1, void* e2)
{

    int respuesta;
    int id1;
    int id2;

    employee_getId(e1, &id1);
    employee_getId(e2, &id2);
    if (id1 > id2)
    {
        respuesta = 1;
    }
    else if (id1 < id2)
    {
        respuesta = -1;
    }
    else
    {
        respuesta = 0;
    }
    return respuesta;
}

int ordenaPorSueldo(void* e1, void* e2)
{
    int respuesta;
    int sueldo1;
    int sueldo2;

    employee_getSueldo(e1, &sueldo1);
    employee_getSueldo(e2, &sueldo2);

    if (sueldo1 > sueldo2)
    {
        respuesta = 1;
    }
    else if (sueldo1 < sueldo2)
    {
        respuesta = -1;
    }
    else
    {
        respuesta =0;
    }
    return respuesta;
}

int ordenaPorHoras(void* e1, void* e2)
{
    int respuesta;
    int horas1;
    int horas2;

    employee_getHorasTrabajadas(e1,&horas1);
    employee_getHorasTrabajadas(e2,&horas2);

    if (horas1 > horas2)
    {
        respuesta = 1;
    }
    else if (horas1 < horas2)
    {
        respuesta = -1;
    }
    else
    {
        respuesta =0;
    }
    return respuesta;
}
int ordenaPorNombre(void* e1, void* e2)
{
    int respuesta;
    char nombre1[128];
    char nombre2[128];

    employee_getNombre(e1, nombre1);
    employee_getNombre(e2, nombre2);
    if (strcmp(nombre1, nombre2) > 0)
    {
        respuesta = 1;
    }
    else if (strcmp(nombre1, nombre2) < 0)
    {
        respuesta = -1;
    }
    else
    {
        respuesta =0;
    }
    return respuesta;
}
int menu()
{
    int opcion;
    system("cls");
    printf("--------------------------------------\n");
    printf("---TRABAJO PRACTICO NRO 4-------------\n");
    printf("--------------------------------------\n");
    printf("MENU DE OPCIONES:\n");
    printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n");
    printf("2. Cargar los datos de los empleados desde el archivo data.bin (modo binario)\n");
    printf("3. Alta de empleado\n");
    printf("4. Modificar datos de empleado\n");
    printf("5. Baja de empleado\n");
    printf("6. Listar empleados\n");
    printf("7. Ordenar empleados\n");
    printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf("9. Guardar los datos de los empleados en el archivo data.bin (modo binario).\n");
    printf("10. Vaciar lista\n");
    printf("11. Crear Reespaldo De Lista\n");
    printf("12. Ver lista respaldo\n");
    printf("13. Comparar Lista Con Lista Respaldo \n");
    printf("14. Crear Lista Con Empleados Que Su Sueldo Es Mas Se 40.000\n");
    printf("15. Crear SubLista Con Empleados Que Su id esta entre 1 y 20\n");
    printf("16. Elegir empleado parar mover a lista de eliminados\n");
    printf("17. Salir\n");
    validaInt("Elija opcion: ", "DATO INVALIDO.\nElija opcion: ", 0, &opcion);
    return opcion;
}

int esSueldoAlto(void* pElement)
{
    int retorno = 0;
    Employee* empAux;

    if(pElement != NULL)
    {
        empAux = (Employee*)pElement;
        if(empAux->sueldo>40000)
        {
            retorno = 1;
        }
    }
    return retorno;
}

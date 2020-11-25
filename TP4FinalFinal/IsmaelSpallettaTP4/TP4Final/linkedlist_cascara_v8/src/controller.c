#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Controller.h"
#include "validaciones.h"
#include "parser.h"
#include <ctype.h>
#include<string.h>
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int todoOk = 0;

    FILE* f = fopen(path, "r");

    if (f != NULL)
    {
        if (parser_EmployeeFromText(f, pArrayListEmployee))
        {
            todoOk = 1;
        }
    }
    fclose(f);
    return todoOk;
}

int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int todoOk = 0;

    FILE* f = fopen(path, "rb");

    if (f != NULL)
    {
        if (parser_EmployeeFromBinary(f, pArrayListEmployee))
        {
            todoOk = 1;
        }
    }
    fclose(f);
    return todoOk;
}

int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    altaEmpleado(pArrayListEmployee);
    return 1;
}

int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    modificaEmpleado(pArrayListEmployee);
    return 1;
}

int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    bajaEmpleado(pArrayListEmployee);
    return 1;
}

int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    listarEmpleados(pArrayListEmployee);
    return 1;
}

int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    switchOrdenaEmpleado(pArrayListEmployee);
    return 1;
}

int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int todoOk = 0;

    FILE* f = fopen(path, "w");
    Employee* temp = (Employee*) employee_new();

    if (path != NULL && pArrayListEmployee != NULL && f != NULL )
    {
        fprintf(f, "id,nombre,horasTrabajadas,sueldo\n");
        for (int i=0; i<ll_len(pArrayListEmployee); i++)
        {
            temp = ll_get(pArrayListEmployee, i);

            fprintf(f, "%d,%s,%d,%d\n", temp->id, temp->nombre, temp->horasTrabajadas, temp->sueldo );
        }
        printf("ARCHIVO GUARDADO CON EXITO\n");
        todoOk = 1;
    }
    else
    {
        printf("OCURRIO UN ERROR GUARDANDO EL ARCHIVO\n");
    }
    return todoOk;
}

int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    int cant;
    Employee* temp = (Employee*) employee_new();
    FILE* f = fopen(path, "wb");
    if (path != NULL && pArrayListEmployee != NULL && f != NULL && temp != NULL )
    {
        for (int i=0; i<ll_len(pArrayListEmployee); i++)
        {
            temp = ll_get(pArrayListEmployee, i);
            cant = fwrite(temp, sizeof(Employee), 1, f );
            if (cant<1)
            {
                printf("OCURRIO UN ERROR GUARDANDO EL ARCHIVO\n");
                return todoOk;
            }
        }
        todoOk = 1;
        printf("ARCHIVO GUARDADO\n");
    }
    return todoOk;
}
int controller_createSubList(LinkedList* pArrayListEmployee)
{
    system("cls");
    int todoOk = 1;
    int desde;
    int hasta;
    LinkedList* sublista;
    if(!(utn_getEntero(&desde, 2, "Ingrese desde que Id donde desea crear la sublista: ", "Error. Ingrese un numero positivo o mas chico.\n\n", 0, ll_len(pArrayListEmployee))))
    {
        if(!(utn_getEntero(&hasta, 2, "Ingrese hasta que Id desea crear la sublista: ", "Error. Ingrese un numero positivo o mas chico.\n\n", 0, ll_len(pArrayListEmployee))))
        {
            sublista = ll_subList(pArrayListEmployee,desde,hasta);
            controller_ListEmployee(sublista);
            todoOk = 0;
        }
        ll_deleteLinkedList(sublista);
    }
    return todoOk;
}
int controller_moverEmpleado(LinkedList* pListaEmpleados)
{

    system("cls");
    Employee* aux = employee_new();
    Employee* auxDos = employee_new();
    int indice;
    int nuevoIndice;
    int error = 1;
    if(!(utn_getEntero(&aux->id,3,"Ingrese el ID del empleado desea mover: ","Error. Ingrese un ID valido",0,150000)))
    {
        indice = (aux->id);
        listarEmpleado(pListaEmpleados, indice);
        auxDos = (Employee*) ll_pop(pListaEmpleados,indice);
        if(!(utn_getEntero(&nuevoIndice,3,"Ingrese la nueva posicion del emplado","Error. Ingrese una posicion valida.\n",0,ll_len(pListaEmpleados))))

            if(!(ll_push(pListaEmpleados, nuevoIndice, auxDos)))
            {
                printf("Empleado Movido.\n\n");
                employee_delete(aux);
                employee_delete(auxDos);
                error = 0;
            }
    }
    return error;
}

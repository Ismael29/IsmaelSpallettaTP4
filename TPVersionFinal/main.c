#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
//ismael ignacio spalletta 1A Segundo Cuatrimestre 2020 TP3
int main()
{
    char seguir='s';
    char confirma=0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    LinkedList* listaEmpleadosRespaldo = ll_newLinkedList();
    LinkedList* listaFiltrada = ll_newLinkedList();
    do
    {
        switch(menu())
        {
        case 1:
            controller_loadFromText("data.csv",listaEmpleados);
            system("PAUSE");
            break;
        case 2:
            controller_loadFromBinary("data.bin",listaEmpleados);
            system("PAUSE");
            break;
        case 3:
            controller_addEmployee(listaEmpleados);
            break;
        case 4:
            if(!ll_isEmpty(listaEmpleados))
            {
                controller_editEmployee(listaEmpleados);
            }
            else
            {
                printf("La Lista De Empleados Esta Vacia!! Primero Cargue Un Empleado. \n");
                system("PAUSE");
            }
            break;
        case 5:
            controller_removeEmployee(listaEmpleados);
            system("PAUSE");
            break;
        case 6:
            if(!ll_isEmpty(listaEmpleados))
            {
                controller_ListEmployee(listaEmpleados);
            }
            else
            {
                printf("La Lista De Empleados Esta Vacia!! Primero Cargue Un Empleado. \n");
            }
            system("PAUSE");
            break;
        case 7:
            if(!ll_isEmpty(listaEmpleados))
            {
                controller_sortEmployee(listaEmpleados);
            }
            else
            {
                printf("La Lista De Empleados Esta Vacia!! Primero Cargue Un Empleado. \n");
            }
            system("PAUSE");
            break;
        case 8:
            if(!ll_isEmpty(listaEmpleados))
            {
                controller_saveAsText("data.csv",listaEmpleados);
                printf("Empleados Guardados Correctamente!!\n");
            }
            else
            {
                printf("La Lista De Empleados Esta Vacia!! Primero Cargue Un Empleado. \n");
            }
            system("PAUSE");
            break;
        case 9:
            if(!ll_isEmpty(listaEmpleados))
            {
                if(controller_saveAsBinary("data.bin",listaEmpleados))
                {
                    printf("Empleados Guardados Correctamente!!\n");
                }
                else
                {
                    printf("Error Al Guardar!! Intentelo Nuevamente. \n");
                }
            }
            else
            {
                printf("La Lista De Empleados Esta Vacia!! Primero Cargue Un Empleado. \n");
            }
            system("PAUSE");
            break;
            fflush(stdin);
        case 10:
            if (!ll_isEmpty(listaEmpleados))
            {

                if (!ll_clear(listaEmpleados))
                {
                    printf("Se vacio la lista cargada\n");
                }
            }
            else
            {
                printf("Aun no se cargo el archivo de datos (opcion 1)\n");
            }
            system("pause");
            break;
        case 11:
            if (!ll_isEmpty(listaEmpleados))
            {
                if ( (listaEmpleadosRespaldo = ll_clone(listaEmpleados)) )
                {
                    printf("se realizo la copia de la lista cargada\n");
                }
            }
            else
            {
                printf("Aun no se cargo el archivo de datos (opcion 1)\n");
            }
            system("pause");
            break;
        case 12:
            if (!ll_isEmpty(listaEmpleados) || !ll_isEmpty(listaEmpleadosRespaldo))
            {
                controller_ListEmployee(listaEmpleadosRespaldo);
            }
            else
            {
                printf("Aun no se cargo el archivo de datos (opcion 1)\n");
            }
            system("pause");
            break;
        case 13:
            if (!ll_isEmpty(listaEmpleados))
            {
                if (ll_containsAll(listaEmpleados, listaEmpleadosRespaldo) && ll_containsAll(listaEmpleadosRespaldo, listaEmpleados)  )
                {
                    printf("Su lista original y su lista respaldo contienen los mismos elementos\n");
                }
                else
                {
                    printf("Hay diferencias entre la lista original y su lista respaldo\n");
                }
            }
            else
            {
                printf("Aun no se cargo el archivo de datos (opcion 1)\n");
            }
            system("pause");
            break;
        case 14:
            listaFiltrada = ll_filter(listaEmpleados,esSueldoAlto);
            if(!ll_isEmpty(listaFiltrada))
            {
                controller_saveAsText("personasConSueldoAlto.csv",listaFiltrada);
                printf("Se han guardado satisfactoriamente los empleados con sueldos altos\n");
            }
            else
            {
                printf("No se genero un archivo ya que no hay empleados con sueldos altos.\n");
            }
            system("pause");
            break;
        case 15:
            if(!ll_isEmpty(listaEmpleados))
            {
                controller_createSubList(listaEmpleados);
            }
            else
            {
                printf("La lista está vacia.\n\n");
            }
            system("pause");
            break;
        case 16:
            printf("Seguro Quiere Salir Del Programa?? (s/n): ");
            scanf("%c", &confirma);
            if(confirma=='s')
            {
                seguir='n';
            }
            break;
        }
    }
    while(seguir=='s');
    ll_deleteLinkedList(listaEmpleados);
    ll_deleteLinkedList(listaEmpleadosRespaldo);
    ll_deleteLinkedList(listaFiltrada);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"
int main(void)
{
    /*
                startTesting(1);  // ll_newLinkedList
                startTesting(2);  // ll_len
                startTesting(3);  // getNode - test_getNode
                startTesting(4);  // addNode - test_addNode
                startTesting(5);  // ll_add
                startTesting(6);  // ll_get
                startTesting(7);  // ll_set
                startTesting(8);  // ll_remove
                startTesting(9);  // ll_clear
                startTesting(10); // ll_deleteLinkedList
                startTesting(11); // ll_indexOf
                startTesting(12); // ll_isEmpty
                startTesting(13); // ll_push
                startTesting(14); // ll_pop
                startTesting(15); // ll_contains
                startTesting(16); // ll_containsAll
                startTesting(17); // ll_subList
                startTesting(18); // ll_clone
                startTesting(19); // ll_sort
                system("PAUSE");
    */
    int option = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    LinkedList* listaEmpleadosBkp = ll_newLinkedList();
    LinkedList* listaFiltrada = ll_newLinkedList();
    do
    {
        option = menu();
        switch(option)
        {
        case 1:
            if(ll_isEmpty(listaEmpleados))
            {
                if (controller_loadFromText("data.csv",listaEmpleados))
                {
                    printf("Archivo cargado con exito\n");
                }
                else
                {
                    printf("NO SE PUDO CARGAR EL ARCHIVO\n");
                }
            }
            else
            {
                printf("El archivo de datos ya fue cargado\n");
            }
            system("pause");
            break;
        case 2:
            if (ll_isEmpty(listaEmpleados))
            {
                if (controller_loadFromBinary("data.bin",listaEmpleados))
                {
                    printf("Archivo cargado con exito\n");

                }
                else
                {
                    printf("NO SE PUDO CARGAR EL ARCHIVO\n");
                }
            }
            else
            {
                printf("El archivo de datos ya fue cargado\n");

            }
            system("pause");
            break;
        case 3:
            if (!ll_isEmpty(listaEmpleados))
            {
                controller_addEmployee(listaEmpleados);
            }
            else
            {
                printf("Aun no se cargo el archivo de datos (opcion 1)\n");
            }
            system("pause");
            break;
        case 4:
            if (!ll_isEmpty(listaEmpleados))
            {
                controller_editEmployee(listaEmpleados);
            }
            else
            {
                printf("Aun no se cargo el archivo de datos (opcion 1)\n");
            }
            system("pause");
            break;
        case 5:
            if (!ll_isEmpty(listaEmpleados) )
            {
                controller_removeEmployee(listaEmpleados);
            }
            else
            {
                printf("Aun no se cargo el archivo de datos (opcion 1)\n");
            }
            system("pause");
            break;
        case 6:
            if (!ll_isEmpty(listaEmpleados))
            {

                controller_ListEmployee(listaEmpleados);
            }
            else
            {
                printf("Aun no se cargo el archivo de datos (opcion 1)\n");
            }
            system("pause");
            break;
        case 7:
            if (!ll_isEmpty(listaEmpleados))
            {
                controller_sortEmployee(listaEmpleados);
            }
            else
            {
                printf("Aun no se cargo el archivo de datos (opcion 1)\n");
            }
            system("pause");
            break;
        case 8:
            if (!ll_isEmpty(listaEmpleados))
            {
                controller_saveAsText("data.csv", listaEmpleados);
            }
            else
            {
                printf("Aun no se cargo el archivo de datos (opcion 1)\n");
            }
            system("pause");
            break;
        case 9:
            if (!ll_isEmpty(listaEmpleados))
            {
                controller_saveAsBinary("data.bin", listaEmpleados);
            }
            else
            {
                printf("Aun no se cargo el archivo de datos (opcion 1)\n");
            }
            system("pause");
            break;
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
                if ( (listaEmpleadosBkp = ll_clone(listaEmpleados)) )
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
            if (!ll_isEmpty(listaEmpleados) || !ll_isEmpty(listaEmpleadosBkp))
            {
                controller_ListEmployee(listaEmpleadosBkp);
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
                if (ll_containsAll(listaEmpleados, listaEmpleadosBkp) && ll_containsAll(listaEmpleadosBkp, listaEmpleados)  )
                {
                    printf("Su lista y el backup contienen los mismos elementos\n");
                }
                else
                {
                    printf("Hay diferencias entre la lista y su backup\n");
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
        }
    }
    while(option != 16);
    return 0;
}

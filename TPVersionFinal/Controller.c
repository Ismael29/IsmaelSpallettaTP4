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
    int error = -1;
    FILE* pFile;
    if(path != NULL && pArrayListEmployee != NULL)
    {
        pFile = fopen(path, "r");
        if(pFile != NULL)
        {
            if(parser_EmployeeFromText(pFile, pArrayListEmployee)==1)
            {
                error= 1;
                printf("Empleados Cargados!!. \n");
            }
            else
            {
                printf("Error Al Cargar Los Empleados!!.\n");
            }
            fclose(pFile);
        }
        else
        {
            printf("\n Error Al Abrir El Archivo.\n");
        }
    }

    return error;
}


int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int error = -1;
    FILE* pFile;
    if(path != NULL && pArrayListEmployee != NULL)
    {
        pFile=fopen(path,"rb");
        if( pFile != NULL)
        {
            if(parser_EmployeeFromBinary(pFile,pArrayListEmployee)==1)
            {
                error=1;
                printf("Empleados Cargados!!.\n");
            }
            else
            {
                printf("Error Al Cargar Los Empleados!!.\n");
            }
        }
        else
        {
            printf("\n Error Al Abrir El Archivo.\n");
        }
        fclose(pFile);
    }
    return error;
}
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int error = -1;
    int id ;
    int horasTrabajadas;
    int sueldo;
    int nuevoNombre;
    int nuevoHorasTrabajadas;
    int nuevoSalario;
    char nombre[128];
    char horasTrabajadasString[20];
    char sueldoString[20];
    char idString[20];

    Employee* auxEmpleado;
    system("cls");
    printf("**** Alta de nuevo empleado **** \n\n");

    if ( pArrayListEmployee != NULL)
    {
        nuevoNombre = utn_getNombre(nombre,127,"Ingrese Nombre Nuevo: ","Error!! Ingrese Solo Letras O Su Nombre Es Muy Largo!! \n",3);
        nuevoHorasTrabajadas = utn_getNumero(&horasTrabajadas, "Ingrese Cantidad De Horas Trabajadas: ","Error!! La Cantidad De Horas Tiene Que Ser Entre 1 Y 2000.\n",1,2000,3);
        nuevoSalario = utn_getNumero(&sueldo,"Ingrese Nuevo Sueldo: ","Error!! El Sueldo Tiene Que Ser Entre 1 y 500000.\n",1,500000,3);

        if(nuevoNombre&& nuevoHorasTrabajadas &&  nuevoSalario)
        {
            obtenerId(&id);
            strlwr(nombre);
            nombre[0]= toupper(nombre[0]);
            itoa(horasTrabajadas,horasTrabajadasString,10);
            itoa(sueldo,sueldoString,10);
            itoa(id,idString,10);
            auxEmpleado = employee_newParametros(idString,nombre,horasTrabajadasString,sueldoString);
            if (auxEmpleado != NULL)
            {
                ll_add(pArrayListEmployee,auxEmpleado);
                printf("Empleado Agregado!! \n");
                actualizarId(id);
                error = 1;
            }
        }
        else
        {
            printf("Error Al Cargar Nuevo Empleado!!! Reintente!!\n");

        }
    }
    system("PAUSE");
    return error;
}

int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int error=-1;
    int id;
    int indice;
    int idCorrecto;

    system("cls");
    if(pArrayListEmployee != NULL)
    {
        controller_ListEmployee(pArrayListEmployee);
        idCorrecto = utn_getNumero(&id, "Ingrese ID Del Empleado Que Quiere Modificar: ","Error El ID Tiene Que Ser Entre 1 y 2000.", 1, 2000, 3);
        if(idCorrecto!=-1)
        {
            indice = buscarEmpleadoPoriD(pArrayListEmployee,id);
            if(indice==-1)
            {
                printf("Error No Hay Empleado Con El ID: %d .\n",id);
                system("PAUSE");
            }
            else
            {
                modificarEmpleado((Employee*) ll_get(pArrayListEmployee,indice));
            }
        }
        else
        {
            printf("Error!! No Existe Empleado Guardado Con Ese ID !\n");
        }
    }
    return error;
}

int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int error = -1;
    int indice;
    int id;
    char confirma;

    if(pArrayListEmployee != NULL)
    {
        controller_ListEmployee(pArrayListEmployee);
        if(utn_getNumero(&id,"Ingrese ID Del Empleado A Remover: ","\nError!! ID Invalido! \n",0,20000,3) != -1)
        {
            indice = buscarEmpleadoPoriD(pArrayListEmployee, id);
            if(indice == -1)
            {
                printf("Error No Hay Empleado Con El ID: %d .\n",id);
                system("PAUSE");
            }
            else
            {
                printf("Empleado A Dar De Baja: \n\n");
                printf("\n  ID                Nombre  Horas Trabajadas          Sueldo \n");
                printf("------------------------------------------------------------------------\n");
                mostrarEmpleado((Employee*) ll_get(pArrayListEmployee,indice));
                printf("Confirma Baja? (s/n) ");
                fflush(stdin);
                scanf("%c", &confirma);
                if (tolower(confirma) == 's')
                {
                    ll_remove(pArrayListEmployee,indice);
                    printf("\nEmpleado Dado De Baja!!\n");
                    error = 1;
                }
                else
                {
                    printf("Baja Cancelada Por El Usuario!! \n");
                }
            }
        }
        else
        {
            printf("Error!! No Existe Empleado Guardado Con Ese ID !\n");
        }
    }
    return error;
}

int controller_ListEmployee(LinkedList* pArrayListEmployee)
{

    int error=-1;
    Employee* auxEmpleado;
    int tam=ll_len(pArrayListEmployee);
    int bandera1=0;

    if( pArrayListEmployee != NULL)
    {
        printf("\n  Id                Nombre  Horas Trabajadas          Sueldo \n");
        printf("--------------------------------------------------------------------------------\n");
        for(int i = 0; i< tam; i++)
        {
            auxEmpleado = (Employee*) ll_get(pArrayListEmployee, i);
            if (  auxEmpleado  != NULL )
            {
                mostrarEmpleado( auxEmpleado );
                bandera1 = 1;
            }
        }
        printf("\n\n");
        if(bandera1 == 0)
        {
            printf("\nNo Existen Empleados Para Mostrar!\n");
        }
        error = 1;
    }
    return error;
}


int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int ordenamiento;
    int ordenCorrecto = -1;
    char continuar= 's';
    ordenCorrecto = utn_getNumero(&ordenamiento,"Ingrese De Que Forma Quiere Ordenar.\n 0. Ascendente\n 1. Descendete\n","Error!!. Ingrese 1 o 0 Para Determinar Ordenamiento.\n", 0, 1, 3);
    if(pArrayListEmployee != NULL)
    {
        if(ordenCorrecto)
        {
            do
            {
                switch(menuDeOrdenamiento())
                {
                case 1:
                    ll_sort(pArrayListEmployee, ordenarEmpleadosPorNombre, ordenamiento);
                    printf("Empleados Ordenados!! \n");
                    system("PAUSE");
                    break;
                case 2:
                    ll_sort(pArrayListEmployee, ordenarEmpleadosPorId, ordenamiento);
                    printf("Empleados Ordenados!! \n");
                    system("PAUSE");
                    break;
                case 3:
                    ll_sort(pArrayListEmployee, ordenarEmpleadosPorSueldo, ordenamiento);
                    printf("Empleados Ordenados!! \n");
                    system("PAUSE");
                    break;
                case 4:
                    ll_sort(pArrayListEmployee, ordenarEmpleadosPorHorasTrabajadas, ordenamiento);
                    printf("Empleados Ordenados!! \n");
                    system("PAUSE");
                    break;
                case 5:
                    continuar = 'n';
                    printf("Volviendo Al Menu Principal...\n");
                    break;
                }
            }
            while(continuar=='s');
        }
    }

    return ordenCorrecto;
}

int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int error = -1;
    FILE* f = fopen(path,"w");
    Employee* auxEmpleado;
    int tam =  ll_len(pArrayListEmployee);

    if(f != NULL)
    {
        fprintf(f,"  ID                Nombre  Horas Trabajadas          Sueldo \n");
        for (int i=0; i<tam; i++)
        {
            auxEmpleado = (Employee*) ll_get(pArrayListEmployee, i);
            if (auxEmpleado !=NULL)
            {
                fprintf(f, "%d, %s, %d, %d \n", auxEmpleado->id, auxEmpleado->nombre, auxEmpleado->horasTrabajadas, auxEmpleado->sueldo);
                error = 1;
            }
        }
        fclose(f);
    }
    return error;
}

int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int error = -1;
    FILE* f = fopen(path,"wb");
    Employee* auxEmpleado;
    int tam = ll_len(pArrayListEmployee);
    if( f!= NULL)
    {
        for (int i =0; i<tam; i++)
        {
            auxEmpleado = (Employee*) ll_get(pArrayListEmployee, i);
            if (auxEmpleado != NULL)
            {
                fwrite(auxEmpleado, sizeof(Employee), 1, f);
                error = 1;
            }
        }
        fclose(f);
    }
    return error;
}

int obtenerId(int* id)
{
    int error = -1;
    FILE* f;
    f = fopen("proximoId.bin","rb");
    *id = 1001;
    if(f != NULL)
    {
        fread(id,sizeof(int), 1,f);
        fclose(f);
        error = 1;
    }
    return error;
}

int actualizarId(int id)
{
    int error  = -1;
    int proximoId =id;
    proximoId++;
    FILE* f;
    f = fopen("proximoid.bin","wb"); // en el caso que el primer id no sea 1001 borrar el proximoId.bin asi se resetea !

    if(f != NULL)
    {
        fwrite(&proximoId,sizeof(int),1,f);
        fclose(f);
        error = 1;
    }
    return error;
}
int controller_createSubList(LinkedList* pArrayListEmployee)
{
    system("cls");
    int error = 1;
    int desde;
    int hasta;
    LinkedList* sublista;
    if(!(utn_getEntero(&desde, 2, "Ingrese desde que Id donde desea crear la sublista: ", "Error. Ingrese un numero positivo o mas chico.\n\n", 0, ll_len(pArrayListEmployee))))
    {
        if(!(utn_getEntero(&hasta, 2, "Ingrese hasta que Id desea crear la sublista: ", "Error. Ingrese un numero positivo o mas chico.\n\n", 0, ll_len(pArrayListEmployee))))
        {
            sublista = ll_subList(pArrayListEmployee,desde,hasta);
            controller_ListEmployee(sublista);
            error = 0;
        }
        ll_deleteLinkedList(sublista);
    }
    return error;
}


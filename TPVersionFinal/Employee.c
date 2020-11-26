#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Employee.h"
#include "validaciones.h"
#include "Controller.h"

Employee* employee_new()
{
    return (Employee*) malloc(sizeof(Employee));
}

Employee* employee_newParametros(char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldo)
{
    Employee* newEmployee;

    newEmployee = employee_new();

    if(newEmployee != NULL)
    {
        if((employee_setId(newEmployee, atoi(idStr))== -1)||(employee_setNombre(newEmployee, nombreStr)==-1)||(employee_setHorasTrabajadas(newEmployee, atoi(horasTrabajadasStr))==-1)||(employee_setSueldo(newEmployee, atoi(sueldo))==-1))
        {
            employee_delete(newEmployee);
            newEmployee = NULL;
        }
    }
    return newEmployee;
}

int employee_setId(Employee* this,int id)
{
    int error = -1;

    if(this != NULL && id >0 && id <= 5000)
    {
        this-> id = id;
        error = 1;
    }
    return error;
}

int employee_getId(Employee* this,int* id)
{
    int error = -1;
    if(this != NULL && id!=NULL)
    {
        *id = this-> id;
        error = 1;
    }
    return error;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int error = -1;

    if (this != NULL  && strlen(nombre) >= 3  && strlen(nombre) < 127)
    {
        strcpy(this ->nombre,nombre);
        error = 1;
    }
    return error;
}

int employee_getNombre(Employee* this, char* nombre)
{
    int error = -1;
    if(this != NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        error = 1;
    }
    return error;
}

int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas)
{
    int error = -1;

    if(this != NULL && horasTrabajadas >0 && horasTrabajadas <= 2000 )
    {
        this->horasTrabajadas = horasTrabajadas;
        error = 1;
    }
    return error;
}

int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas)
{
    int error = -1;
    if(this!= NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        error = 1;
    }
    return error;
}

int employee_setSueldo(Employee* this, int sueldo)
{
    int error = -1;

    if(this != NULL && sueldo >0 && sueldo <= 100000 )
    {
        this-> sueldo = sueldo;
        error = 1;
    }
    return error;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
    int error = -1;
    if ( this != NULL && sueldo != NULL)
    {
        *sueldo = this -> sueldo;
        error = 1;
    }
    return error;
}

void employee_delete(Employee* this )
{
    if(this != NULL)
    {
        free(this);
    }
}

int mostrarEmpleado(Employee* this)
{
    int error =-1;
    if(this != NULL)
    {
        error = 1;
        printf("%4d  %20s  %4d                    %5d \n",this->id,this->nombre,this->horasTrabajadas,this->sueldo);
    }
    return error;
}

int ordenarEmpleadosPorNombre(void* empA,void* empB)
{
    int orden = 0;
    if( empA != NULL && empB != NULL )
    {
        Employee* pEmpA = (Employee*) empA;
        Employee* pEmpB = (Employee*) empB;
        if (strcmp(pEmpA->nombre, pEmpB->nombre) > 0)
        {
            orden = 1;
        }
        else if(strcmp(pEmpA->nombre, pEmpB->nombre) < 0)
        {
            orden = -1;
        }
    }
    return orden;
}

int menuDeModificacion()
{
    int opcion;
    system("cls");
    printf("\n****** Sub Menu De Modificacion De Empleado ****** \n");
    printf("-------------------------------------------------------");
    printf("\n1.  Modificar Nombre.\n");
    printf("2.  Modificar Horas Trabajadas.\n");
    printf("3.  Modificar Sueldo.\n");
    printf("4.  Salir.\n");

    if(utn_getNumero(&opcion,"Ingrese opcion:  ","",1,4,0) == -1)
    {
        opcion = 0;
    }
    return opcion;
}

int modificarEmpleado(Employee* this)
{
    int error = -1;
    int horasTrabajadas;
    int sueldo;
    int nuevoNombre;
    int nuevasHorasTrabajadas;
    int nuevoSueldo;
    char continuar = 's';
    char nombre[128];

    system("cls");
    do
    {
        switch(menuDeModificacion())
        {
        case 1:
            nuevoNombre = utn_getNombre(nombre, 127,"Ingrese Nombre Nuevo: ","Ingrese Solo Letras O Su Nombre Es Muy Largo!!",3);
            if (nuevoNombre== 1)
            {
                employee_setNombre(this, nombre);
                confirmacionDeModificacion(this);
                error = 1;
            }
            break;
        case 2:
            nuevasHorasTrabajadas = utn_getNumero(&horasTrabajadas, "Ingrese Cantidad Nueva De Horas Trabajadas: ","Error!! La Cantidad De Horas Tiene Que Ser Entre 1 Y 1000.\n",1,1000,3);
            if (nuevasHorasTrabajadas ==1)
            {
                employee_setHorasTrabajadas(this, horasTrabajadas);
                confirmacionDeModificacion(this);
                error = 1;
            }
            break;
        case 3:
            nuevoSueldo = utn_getNumero(&sueldo, "Ingrese Nuevo Sueldo: ","Error!! El Sueldo Tiene Que Ser Entre 1 y 100000.\n",1,100000,3);
            if(nuevoSueldo == 1)
            {
                employee_setSueldo(this, sueldo);
                confirmacionDeModificacion(this);
                error = 1;
            }
            break;
        case 4:
            continuar = 'n';
            printf("Volviendo Al Menu Principal...\n");
            system("PAUSE");
            break;
        case 0:
            printf("\nError!! Opcion Invalida!!\n");
            break;
        }
    }
    while(continuar=='s');


    return error;
}

void confirmacionDeModificacion(Employee* this)
{
    char confirma;

    printf("\n  ID                Nombre  Horas Trabajadas          Sueldo \n");
    printf("--------------------------------------------------------------------------\n");
    mostrarEmpleado(this);
    printf("\n\n Confirma Modificacion??  (s/n) ");
    fflush(stdin);
    scanf("%c", &confirma);
    if(tolower(confirma) == 's')
    {
        printf("Empleado Modificado!!\n");
        system("PAUSE");
    }
    else
    {
        printf("Modificacion Cancelada Por El Usuario!! \n");
        system("PAUSE");
    }
}

int buscarEmpleadoPoriD(LinkedList* pArrayListEmployee, int id)
{
    int empleadoIndice = -1;
    int idAuxiliar;
    Employee* auxEmpleado;

    for(int i = 0; i < ll_len(pArrayListEmployee); i++)
    {
        auxEmpleado = ll_get(pArrayListEmployee, i);
        if(employee_getId(auxEmpleado, &idAuxiliar) && idAuxiliar == id)
        {
            empleadoIndice = i;
            break;
        }
    }
    return empleadoIndice;
}

int menu()
{
    int opcion;

    system("cls");
    printf("********************************************************************************* \n\n");
    printf("*************************** \n");
    printf("**** Menu De Empleados **** \n");
    printf("*************************** \n\n");
    printf("1.   Cargar los datos de los empleados desde el archivo data.csv (modo texto).  \n");
    printf("2.   Cargar los datos de los empleados desde el archivo data.csv (modo binario). \n");
    printf("3.   Alta de empleado.\n");
    printf("4.   Modificar datos de empleado.\n");
    printf("5.   Baja de empleado.\n");
    printf("6.   Listar empleados.\n");
    printf("7.   Ordenar empleados.\n");
    printf("8.   Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf("9.   Guardar los datos de los empleados en el archivo data.csv (modo binario).\n");
    printf("10. Vaciar lista\n");
    printf("11. Crear Reespaldo De Lista\n");
    printf("12. Ver lista respaldo\n");
    printf("13. Comparar Lista Con Lista Respaldo \n");
    printf("14. Crear Lista Con Empleados Que Su Sueldo Es Mas Se 40.000\n");
    printf("15. Crear SubLista Con Empleados Que Su id esta entre 1(-1) y 20\n");
    printf("16.  Salir.\n");
    printf("********************************************************************************* \n\n");
    if(utn_getNumero(&opcion,"Ingrese Opcion: "," ",1,17,0)== -1)
    {
        opcion = 0;
    }
    return opcion;
}
int menuDeOrdenamiento()
{
    int opcion;
    system("cls");
    printf("\n****** Sub Menu De Ordenamiento De Empleado ****** \n");
    printf("-------------------------------------------------------");
    printf("\n1.  Ordenar Por Nombre.\n");
    printf("2.  Ordenar Por ID.\n");
    printf("3.  Ordenar Por Sueldo.\n");
    printf("4.  Ordenar Por Horas Trabajadas.\n");
    printf("5.  Salir.\n");

    if(utn_getNumero(&opcion,"Ingrese opcion:  ","",1,5,0) == -1)
    {
        opcion = 0;
    }
    return opcion;
}
int ordenarEmpleadosPorId(void* empleado1, void* empleado2){

    Employee* emp1=(Employee*) empleado1;
    Employee* emp2=(Employee*) empleado2;
    int orden;
    if(emp1!=NULL && emp2!=NULL){
        if(emp1->id == emp2->id){
            orden=0;
        }else{
            if(emp1->id > emp2->id){
                orden=-1;
            }else{
                orden=1;
            }
        }
    }
    return orden;
}
int ordenarEmpleadosPorSueldo(void* empleado1, void* empleado2){

    Employee* emp1=(Employee*) empleado1;
    Employee* emp2=(Employee*) empleado2;
    int orden;
    if(emp1!=NULL && emp2!=NULL){
        if(emp1->sueldo == emp2->sueldo){
            orden=0;
        }else{
            if(emp1->sueldo > emp2->sueldo){
                orden=-1;
            }else{
                orden=1;
            }
        }
    }
    return orden;
}
int ordenarEmpleadosPorHorasTrabajadas(void* empleado1, void* empleado2){

    Employee* emp1=(Employee*) empleado1;
    Employee* emp2=(Employee*) empleado2;
    int orden;
    if(emp1!=NULL && emp2!=NULL){
        if(emp1->horasTrabajadas == emp2->horasTrabajadas){
            orden=0;
        }else{
            if(emp1->horasTrabajadas > emp2->horasTrabajadas){
                orden=-1;
            }else{
                orden=1;
            }
        }
    }
    return orden;
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



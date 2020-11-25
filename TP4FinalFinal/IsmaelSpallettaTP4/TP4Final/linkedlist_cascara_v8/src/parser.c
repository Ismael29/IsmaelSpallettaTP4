#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    int cant;
    Employee* auxiliar = (Employee*) employee_new();
    if (pFile == NULL || pArrayListEmployee == NULL)
    {
        return todoOk;
    }
    char buffer[4][128];
    fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]",buffer[0], buffer[1], buffer[2], buffer[3]);
    while(!feof(pFile))
    {
        cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]",buffer[0], buffer[1], buffer[2], buffer[3]);
        if (cant == 4)
        {
            auxiliar = employee_newParametros(buffer[0], buffer[1], buffer[2], buffer[3]);

            if (auxiliar != NULL)
            {
                ll_add(pArrayListEmployee, auxiliar);
            }
        }
    }
    todoOk = 1;
    return todoOk;
}
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    int cant;
    if (pFile == NULL || pArrayListEmployee == NULL)
    {
        return todoOk;
    }
    while (!feof(pFile))
    {
        Employee* auxiliar = (Employee*) employee_new();
        if (auxiliar != NULL)
        {
            cant = fread(auxiliar, sizeof(Employee), 1, pFile);
            if (cant == 1)
            {
                ll_add(pArrayListEmployee, auxiliar);
                todoOk = 1;
            }
        }
    }
    return todoOk;
}

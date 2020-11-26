#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include "LinkedList.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

/** \brief crea un nuevo empleado
 *
 * \return Employee*
 *
 */Employee* employee_new();

/** \brief completa los parametros de un nuevo empleado
 *
 * \param idStr char*
 * \param nombreStr char*
 * \param horasTrabajadasStr char*
 * \return Employee*
 *
 */Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldo);

/** \brief elimia empleado
 *
 * \return void
 *
 */void employee_delete();

/** \brief asigna un id
 *
 * \param this Employee*
 * \param id int
 * \return int
 *
 */int employee_setId(Employee* this,int id);

/** \brief obtiene un id
 *
 * \param this Employee*
 * \param id int*
 * \return int
 *
 */int employee_getId(Employee* this,int* id);

/** \brief asigna un nombre
 *
 * \param this Employee*
 * \param nombre char*
 * \return int
 *
 */int employee_setNombre(Employee* this,char* nombre);

/** \brief obtiene un nombre
 *
 * \param this Employee*
 * \param nombre char*
 * \return int
 *
 */int employee_getNombre(Employee* this,char* nombre);

/** \brief asigna horas trabajadas
 *
 * \param this Employee*
 * \param horasTrabajadas int
 * \return int
 *
 */int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
/** \brief obiene horas trabajadas
 *
 * \param this Employee*
 * \param horasTrabajadas int*
 * \return int
 *
 */int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

/** \brief asgina sueldo
 *
 * \param this Employee*
 * \param sueldo int
 * \return int
 *
 */int employee_setSueldo(Employee* this,int sueldo);

/** \brief obtiene un sueldo
 *
 * \param this Employee*
 * \param sueldo int*
 * \return int
 *
 */int employee_getSueldo(Employee* this,int* sueldo);

/** \brief recibe un puntero a empleado y lo muestra por pantalla
 *
 * \param puntero a un empleado del tipo Employee
 * \return  devuelve 1 si el puntero recibido es distinto de nulo y -1 si el puntero recibido es nulo
 *
 */int mostrarEmpleado(Employee* this);

/** \brief castea a puntero a empleado los parametros recibidos y compara los nombres de los empleados recibidos por parametro
 *
 * \param puntero a void
 * \param puntero a void
 * \return devuelve 0 si los nombers de los empleados son iguales, 1 si el nombre del empA es mayor al nombre del empB y -1 si el nombre del empA es menor al nombre del empB
 *
 */int ordenDeEmpleadoPorNombre(void* pEmpleado1,void* pEmpleado2);


/** \brief recibe un puntero a Employee e interactua con el usuario para que elija que atributo desea modificar permitiendole modificarlo
 *
 * \param  puntero a un empleado del tipo Employee
 * \return devuelve 1 si se pudo realizar alguna modificacion, y -1 en caso contrario
 *
 */int modificarEmpleado(Employee* this);


/** \brief informa al usuario que se realizo satisfactoriamente la modificación y muestra al empleado modificado
 *
 * \param puntero a un empleado del tipo Employee
 *
 */void confirmacionDeModificacion(Employee* this);


/** \brief busca en la lista el empleado que posea el id recibido por parametro y devuelve su indice
 *
 * \param puntero a una lista de empleados del tipo LinkedList
 * \param variable del tipo entero
 * \return -1 si no existe en la lista un empleado con el id proporcionado o el indice del empleado con el id recibido si existe
 *
 */int buscarEmpleadoPoriD(LinkedList* pArrayListEmployee, int id);

/** \brief menu principal
 *
 * \return int
 *
 */int menu();

 /** \brief sub menu de modificacion
  *
  * \return int
  *
  */int menuDeModificacion();

/** \brief compara nombres de empleado y aplica ordenamiento
 *
 * \param empA void*
 * \param empB void*
 * \return int
 *
 */int ordenarEmpleadosPorNombre(void* empA,void* empB);

 /** \brief compara id y aplica ordenamiento
  *
  * \param empleado1 void*
  * \param empleado2 void*
  * \return int
  *
  */int ordenarEmpleadosPorId(void* empleado1, void* empleado2);

 /** \brief menu de ordenamiento (eolegir por que criterio ordenar)
  *
  * \return int
  *
  */int menuDeOrdenamiento();

 /** \brief ordena empleados por sueldo
  *
  * \param empleado1 void*
  * \param empleado2 void*
  * \return int
  *
  */int ordenarEmpleadosPorSueldo(void* empleado1, void* empleado2);

 /** \brief  ordena empleados por horas trabajadas
  *
  * \param empleado1 void*
  * \param empleado2 void*
  * \return int
  *
  */int ordenarEmpleadosPorHorasTrabajadas(void* empleado1, void* empleado2);
  int esSueldoAlto(void* pElement);
#endif // employee_H_INCLUDED

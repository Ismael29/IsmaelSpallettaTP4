#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED
#include "LinkedList.h"
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

/** \brief Reserva espacion en memoria para un Employee
 *
 * \return Employee* puntero al nuevo empleado
 *
 */Employee* employee_new();

/** \brief recibe datos como string, los convierte al tipo correcto y los carga en un nuevo Employee
 *
 * \param idStr char* id epleado
 * \param nombreStr char* nomnre emplead
 * \param horasTrabajadasStr char* horas trabajadas
 * \param sueldoStr char* sueldo empleado
 * \return Employee* puntero al nuevo empleado
 *
 */Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);

void employee_delete();

/** \brief carga Id del Employee
 *
 * \param this Employee* puntero al Employee
 * \param id int id del empleado
 * \return int
 *
 */int employee_setId(Employee* this,int id);

/** \brief Carga el Id de un employee en una variable
 *
 * \param this Employee* puntero al employee
 * \param id int* puntero a la variable
 * \return int
 *
 */int employee_getId(Employee* this,int* id);

/** \brief carga el nombre del Employee
 *
 * \param this Employee* puntero al employee
 * \param nombre char* nombre del empleado
 * \return int
 *
 */int employee_setNombre(Employee* this,char* nombre);

/** \brief Carga las horas trabajadas de un employee en una variable
 *
 * \param this Employee*
 * \param nombre char*
 * \return int
 *
 */int employee_getNombre(Employee* this,char* nombre);

/** \brief carga las horas trabajadas del employee
 *
 * \param this Employee*  puntero al employee
 * \param horasTrabajadas int cantidad de horas
 * \return int
 *
 */int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);

/** \brief Carga las horas trabajadas de un employee en una variable
 *
 * \param this Employee* puntero al employee
 * \param horas int* puntero a la variable
 * \return int
 *
 */int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

/** \brief carga el sueldo del Employee
 *
 * \param this Employee* puntero al employee
 * \param sueldo int sueldo del empleado
 * \return int
 *
 */int employee_setSueldo(Employee* this,int sueldo);

/** \brief Carga el sueldo de un employee en una variable
 *
 * \param this Employee* puntero al employee
 * \param sueldo int* puntero a la variable
 * \return int
 *
 */int employee_getSueldo(Employee* this,int* sueldo);

/** \brief Da de alta un nuevo empleado a la lista
 *
 * \param lista LinkedList* lista donde se cargara el nuevo empleado
 * \return  int
 *
 */int altaEmpleado (LinkedList* lista);

/** \brief Verfica si un ID esta en la lista
 *
 * \param lista LinkedList* Lista a recorrer
 * \param id int id a buscar
 * \return int
 *
 */int verificaId (LinkedList* lista, int id);

/** \brief Pide id del empleado y muestra menu para modificar sus datos
 *
 * \param lista LinkedList* lista donde se buscara el empleado
 * \return int
 *
 */int modificaEmpleado (LinkedList* lista);

/** \brief Llama la funcion que modifica el parametro seleccionado para un empleado de la lista
 *
 * \param lista LinkedList* lista donde se encuentra el empleado
 * \param index int indice de la lista en que se encuentra
 * \return int
 *
 */int switchModificaEmpleado (LinkedList* lista, int index);

/** \brief Muestra menu de opciones
 *
 * \return int el numero de opcion seleccionado
 *
 */int menuModificaEmpleado();



 /** \brief Borra un elemento de la lista por ID
 *
 * \param lista LinkedList* lista que se editara
 * \return int
 *
 */int bajaEmpleado (LinkedList* lista);

/** \brief Muestra en pantalla la lista completa
 *
 * \param lista LinkedList* lista que se va a mostrar
 * \return void
 *
 */void listarEmpleados (LinkedList* lista);
/** \brief Muestra por pantalla un elemento de la lista
 *
 * \param lista LinkedList* lista a mostrar
 * \param index int indice del elemento
 * \return void
 *
 */void listarEmpleado (LinkedList* lista, int index);

/** \brief Modifica el ID de un empleado
 *
 * \param lista LinkedList* lista donde esta el empleado
 * \param index int indice en el que se encuentra
 * \return int
 *
 */int modificaId(LinkedList* lista,int  index);

/** \brief Modifica las horas trabajadas por un empleado
 *
 * \param lista LinkedList* lista donde esta el empleado
 * \param index int indice en el que se encuentra
 * \return int
 *
 */int modificaHoras(LinkedList* lista,int  index);

/** \brief Modifica el nombre de un empleado
 *
 * \param lista LinkedList* lista donde esta el empleado
 * \param index int indice en el que se encuentra
 * \return int
 *
 */int modificaNombre(LinkedList* lista,int  index);

/** \brief Modifica el sueldo de un empleado
 *
 * \param lista LinkedList* lista donde esta el empleado
 * \param index int indice en el que se encuentra
 * \return int
 *
 */int modificaSueldo(LinkedList* lista,int  index);

/** \brief Ordena dos empleados por ID
 *
 * \param e1 void* primer empleado a ordenar
 * \param e2 void* segundo empleado a ordenar
 * \return int devuelve 1 el primero es mayor, -1 si es menor, 0 si son iguales
 *
 */int ordenaPorId(void* id1, void* id2);


/** \brief Ordena dos empleados por sueldo
 *
 * \param e1 void* primer empleado a ordenar
 * \param e2 void* segundo empleado a ordenar
 * \return int devuelve 1 el primero es mayor, -1 si es menor, 0 si son iguales
 *
 */int ordenaPorSueldo (void* e1, void* e2);

/** \brief Ordena dos empleados por Horas trabajadas
 *
 * \param e1 void* primer empleado a ordenar
 * \param e2 void* segundo empleado a ordenar
 * \return int devuelve 1 el primero es mayor, -1 si es menor, 0 si son iguales
 *
 */int ordenaPorHoras (void* e1, void* e2);

/** \brief Ordena dos empleados por Nombre
 *
 * \param e1 void* primer empleado a ordenar
 * \param e2 void* segundo empleado a ordenar
 * \return int devuelve 1 el primero es mayor, -1 si es menor, 0 si son iguales
 *
 */int ordenaPorNombre (void* e1, void* e2);

/** \brief Llama a la funcion que ordena la lista segun el criterio seleccionado
 *
 * \param lista LinkedList* lista a ordenar
 * \return int
 *
 */int switchOrdenaEmpleado (LinkedList* lista);

/** \brief Muestra menu de opciones
 *
 * \return int numero de opcion seleccionada
 *
 */int menuOrdenaEmpleado();

/** \brief Determina que elemtos de la lista tienen su campo sueldo mayor a 40mil
 *
 * \param pElement void*
 * \return cada elemebti de la lista con un sueldo mayor al pasado
 *
 */int esSueldoAlto(void* pElement);

/** \brief Muestra menu de opciones
 *
 * \return int el numero de opcion seleccionado
 *
 */int menu ();
#endif // EMPLEADO_H_INCLUDED

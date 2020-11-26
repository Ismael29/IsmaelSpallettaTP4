#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "validaciones.h"

/** \brief Abre el archivo proximoId.bin en modo lectura, si no existe lo crea y si existe lee el numero de id que contiene y lo guarda en la variable recibida por parametro
 *
 * \param int*
 * \return devuelve 1 si pudo conseguir el id del archivo y -1 si el archivo no existe
 *
 */int obtenerId(int* id);

/** \brief Al id recibido por parametro le suma 1 y lo escribe en el archivo proximoId.bin
 *
 * \param int
 * \return 1 si pudo actualizar el archivo , -1 no pudo
 *
 */int actualizarId(int id);

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);

/** \brief Alta a un empleado
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */int controller_addEmployee(LinkedList* pArrayListEmployee);

/** \brief Modifica un empleado
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */int controller_editEmployee(LinkedList* pArrayListEmployee);

/** \brief Da de baja a un empleado
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */int controller_removeEmployee(LinkedList* pArrayListEmployee);

/** \brief Lista los empleados
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */int controller_ListEmployee(LinkedList* pArrayListEmployee);

/** \brief ordena los empleados por nombre seleccionando el criterio ascendente o descentdente
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */int controller_sortEmployee(LinkedList* pArrayListEmployee);

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);
 /** \brief crea sub lista de empleados determinado por rango
  *
  * \param pArrayListEmployee LinkedList*
  * \return int
  *
  */int controller_createSubList(LinkedList* pArrayListEmployee);


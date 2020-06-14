#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

/** \brief esta funcion devuelve un puntero tipo employee
 *
 * \return Employee* delvuelve la direccion de memoria tipo employee si se pudo realizar con exito si no devuelve null
 *
 */
Employee* employee_new();
/** \brief esta funcion convierte los datos y los guarda en un empleado
 *
 * \param idStr char* recibe id (en caracteres)
 * \param nombreStr char* recibe nombre
 * \param horasTrabajadasStr char* recibe horas trabajadas (en caracteres)
 * \param sueldoStr char* recibe sueldo (en caracteres)
 * \return Employee* devuelve un employee cargado
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);
/** \brief esta funcion elimina un empleado
 *
 * \param This Employee* recibe el empleado a borrar
 * \return void
 *
 */
void employee_delete(Employee * This);

/** \brief esta funcion carga un id al empleado
 *
 * \param This Employee* empleado a cargar id
 * \param id int id a cargar
 * \return int retorna 1 si se pudo realizar con exito y 0 si no se pudo
 *
 */
int employee_setId(Employee* This,int id);
/** \brief esta funcion devuelve un id
 *
 * \param This Employee* empleado del cual se quiere devolver el id
 * \param id int* id a devolver
 * \return int retorna 1 si se pudo realizar con exito y 0 si no se pudo
 *
 */
int employee_getId(Employee* This,int* id);

/** \brief esta funcion carga un nombre al empleado
 *
 * \param This Employee* empleado a cargar nombre
 * \param nombre char* nombre a cargar
 * \return int retorna 1 si se pudo realizar con exito y 0 si no se pudo
 *
 *
 */
int employee_setNombre(Employee* This,char* nombre);
/** \brief esta funcion devuelve un nombre
 *
 * \param This Employee* empleado del cual se quiere devolver el nombre
 * \param nombre char* nombre a devolver
 * \return int retorna 1 si se pudo realizar con exito y 0 si no se pudo
 *
 */
int employee_getNombre(Employee* This,char* nombre);

/** \brief esta funcion carga horas trabajadas al empleado
 *
 * \param This Employee* empleado a cargar horas trabajadas
 * \param horasTrabajadas int horas trabajadas a cargar
 * \return int retorna 1 si se pudo realizar con exito y 0 si no se pudo
 *
 */
int employee_setHorasTrabajadas(Employee* This,int horasTrabajadas);
/** \brief esta funcion devuelve horas trabajadas
 *
 * \param This Employee* empleado del cual se quiere devolver las horas trabajadas
 * \param horasTrabajadas int* horas trabajadas a devolver
 * \return int retorna 1 si se pudo realizar con exito y 0 si no se pudo
 *
 */
int employee_getHorasTrabajadas(Employee* This,int* horasTrabajadas);

/** \brief esta funcion carga sueldo al empleado
 *
 * \param This Employee* empleado a cargar sueldo
 * \param sueldo int sueldo a cargar
 * \return int retorna 1 si se pudo realizar con exito y 0 si no se pudo
 *
 */
int employee_setSueldo(Employee* This,int sueldo);
/** \brief esta funcion devuelve un sueldo
 *
 * \param This Employee* empleado del cual se quiere devolver el sueldo
 * \param sueldo int* sueldo a devolver
 * \return int retorna 1 si se pudo realizar con exito y 0 si no se pudo
 *
 */
int employee_getSueldo(Employee* This,int* sueldo);

/** \brief esta funcion compara dos nombres
 *
 * \param e1 void* nombre 1 a comparar
 * \param e2 void* nombre 2 a comparar
 * \return int devuelve un entero que refleja la comparacion
 *
 */
int employee_CompareByName(void * e1, void * e2);
/** \brief esta funcion compara dos id
 *
 * \param e1 void* id 1 a comparar
 * \param e2 void* id 2 a comparar
 * \return int devuelde 1 (si el id 1 es mayor al id 2), devuelve 0 si son iguales y devuelve -1 (si el id 2 es mayor al id 1)
 *
 */
int employee_CompareById(void * e1, void * e2);
/** \brief esta funcion compara dos horas de trabajo
 *
 * \param e1 void* horas de trabajo 1 a comparar
 * \param e2 void* horas de trabajo 2 a comparar
 * \return int devuelde 1 (si la hora de trabajo 1 es mayor a la hora de trabajo 2), devuelve 0 si son iguales y devuelve -1 (si la hora de trabajo 2 es mayor a la hora de trabajo 1)
 *
 */
int employee_CompareByHorasTrabajadas(void * e1, void * e2);
/** \brief esta funcion compara dos sueldos
 *
 * \param e1 void* sueldo 1 a comparar
 * \param e2 void* sueldo 2 a comparar
 * \return int devuelde 1 (si el sueldo 1 es mayor al sueldo 2), devuelve 0 si son iguales y devuelve -1 (si el sueldo 2 es mayor al sueldo 1)
 *
 */
int employee_CompareBySueldo(void * e1, void * e2);

#endif // employee_H_INCLUDED

#include <stdio.h>
#include <string.h>



typedef struct
{
 int id;
 char name[51];
 char lastName[51];
 float salary;
 int sector;
 int isEmpty;
}Employee;

/** \brief esta funcion inicializa los estados en 0 (empty)
 *
 * \param [] Employee empleados recibe el array de employee
 * \param t int recibe el tamaño del array
 * \return int devuelve 0 si se pudo realizar la accion y -1 si no se pudo realizar
 *
 */
int initEmployees(Employee empleados [], int t);
/** \brief esta funcion se encarga de cargar 1 empleado con los datos recibidos por parametros
 *
 * \param [] Employee empleados recibe el array de employee
 * \param t int recibe el tamaño del array
 * \param id int recibe el id del empleado
 * \param name[] char   recibe el nombre del empleado
 * \param lastName[] char recibe el apellido del empleado
 * \param salary float recibe el salario del empleado
 * \param sector int recibe el sector del empleado
 * \return int  devuelve 0 si se pudo realizar la accion y -1 si no se pudo realizar
 *
 */
int addEmployee(Employee empleados [], int t, int id, char name[],char lastName[],float salary,int sector);
/** \brief esta funcion busca un estado 0 (empty) en el array
 *
 * \param [] Employee empleados recibe el array de employee
 * \param t int recibe el tamaño del array
 * \return int  devuelve el indice si se pudo realizar la accion y -1 si no se pudo realizar
 *
 */
int buscarLibre( Employee empleados [], int t);
/** \brief esta funcion genera automaticamente un id para el empleado
 *
 * \param empleados[] Employee recibe el array de employee
 * \param t int recibe el tamaño del array
 * \return int  devuelve el id generado
 *
 */
int generadorID(Employee empleados[], int t);
/** \brief esta funcion muestra el salario total, el promedio de los salarios y los empleados que superen el promedio del salario
 *
 * \param recibe el array de employee
 * \param recibe el tamaño del array
 * \return  devuelve 0 si se pudo realizar la accion
 *
 */
int mostrarSalaryPromedioSuperiorPromedio (Employee empleado [],int t);
/** \brief esta funcion da de baja un empleado de manera logica
 *
 * \param [] Employee empleado  recibe el array de employee
 * \param t int recibe el tamaño del array
 * \param id int recibe el id del empleado que se quiere dar de baja
 * \return int  devuelve 0 si se pudo realizar la accion y -1 si no se pudo realizar
 *
 */
int removeEmployee(Employee empleado [], int t,int id);
/** \brief esta funcion modifica el nombre o apellido o sector o salario de un empleado existente
 *
 * \param [] Employee empleado  recibe el array de employee
 * \param t int recibe el tamaño del array
 * \param id int recibe el id del empleado que se quiere modificar
 * \return int  devuelve 0 si se pudo realizar la accion y -1 si no se pudo realizar
 *
 */
int modificarEmployee(Employee empleado [], int t,int id);
/** \brief ordena el array de manera ascendente por doble criterio apellido y sector
 *
 * \param empleados[] Employee  recibe el array de employee
 * \param t int recibe el tamaño del array
 * \return int  devuelve 0 si se pudo realizar la accion y -1 si no se pudo realizar
 *
 */
int sortStudentsByNameAndAverage(Employee empleados[], int t);
/** \brief esta funcion suma todos los salarios
 *
 * \param empleados[] Employee  recibe el array de employee
 * \param t int recibe el tamaño del array
 * \return int devuelve la suma de todos los salarios
 *
 */
float salaryTotal (Employee empleados [], int t);
/** \brief esta funcion calcula el promedio de la suma de todos los salarios
 *
 * \param empleados[] Employee  recibe el array de employee
 * \param t int recibe el tamaño del array
 * \return int devuelve el promedio de la suma de todos los salarios
 *
 */
float promedio (Employee empleados [], int t);
/** \brief esta funcion busca cuantos empleados superan el promedio de todos los salarios
 *
 * \param empleados[] Employee  recibe el array de employee
 * \param t int recibe el tamaño del array
 * \return int devuelve cuantos empleados superan el promedio de todos los salarios
 *
 */
int superiorPromedio (Employee empleados [], int t);
/** \brief esta funcion muestra los datos cargados de los empleados en el array
 *
 * \param empleados[] Employee  recibe el array de employee
 * \param t int recibe el tamaño del array
 * \return int  devuelve 0 si se pudo realizar la accion y -1 si no se pudo realizar
 *
 */
int printEmployees (Employee empleados [],int t);




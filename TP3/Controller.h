/** \brief abre el archivo csv para lectura para su lectura y llama a parser para cargar los datos
 *
 * \param path char* recibe un puntero tipo char que contiene el nombre del archivo y su formato
 * \param pArrayListEmployee LinkedList* recibe la lista de empleados
 * \return int retorna 1 si se pudo realizar con exito y 0 si no se pudo
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
/** \brief abre el archivo .bin para lectura para su lectura y llama a parser para cargar los datos
 *
 * \param path char* char* recibe un puntero tipo char que contiene el nombre del archivo y su formato
 * \param pArrayListEmployee LinkedList* recibe la lista de empleados
 * \return int retorna 1 si se pudo realizar con exito y 0 si no se pudo
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
/** \brief esta funcion añade un nuevo empleado a la lista
 *
 * \param pArrayListEmployee LinkedList* recibe la lista de empleados
 * \return int retorna 1 si se pudo realizar con exito y 0 si no se pudo
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee);
/** \brief esta funcion edita un empleado de la lista
 *
 * \param pArrayListEmployee LinkedList* recibe la lista de empleados
 * \return int retorna 1 si se pudo realizar con exito y 0 si no se pudo
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);
/** \brief esta funcion elimina un empleado de la lista
 *
 * \param pArrayListEmployee LinkedList* recibe la lista de empleados
 * \return int retorna 1 si se pudo realizar con exito y 0 si no se pudo
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee);
/** \brief esta funcion imprime la lista de empleados
 *
 * \param pArrayListEmployee LinkedList* recibe la lista de empleados
 * \return int retorna 1 si se pudo realizar con exito y 0 si no se pudo
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee);
/** \brief esta funcion ordena la lista de empleados por (id o nombre o sueldo o horas trabajadas)
 *
 * \param pArrayListEmployee LinkedList* recibe la lista de empleados
 * \return int retorna 1 si se pudo realizar con exito y 0 si no se pudo
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee);
/** \brief esta funcion guarda todos los datos en el archivo en modo texto
 *
 * \param path char* recibe el nombre del archivo y su tipo
 * \param pArrayListEmployee LinkedList* recibe la lista de empleados
 * \return int retorna 1 si se pudo realizar con exito y 0 si no se pudo
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
/** \brief esta funcion guarda todos los datos en el archivo en modo binario
 *
 * \param path char* recibe el nombre del archivo y su tipo
 * \param pArrayListEmployee LinkedList* recibe la lista de empleados
 * \return int retorna 1 si se pudo realizar con exito y 0 si no se pudo
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);



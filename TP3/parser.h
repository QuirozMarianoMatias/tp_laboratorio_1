/** \brief pasa los archivos leidos del .csv a la lista de empleados
 *
 * \param pFile FILE* recibe el nombre del archivo
 * \param pArrayListEmployee LinkedList* puntero a la lista de empleados
 * \return int retorna 1 si se realizo con exito y 0 si hubo error
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);
/** \brief pasa los archivos leidos del .bin a la lista de empleados
 *
 * \param pFile FILE* recibe el nombre del archivo
 * \param pArrayListEmployee LinkedList* puntero a la lista de empleados
 * \return int retorna 1 si se realizo con exito y 0 si hubo error
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);

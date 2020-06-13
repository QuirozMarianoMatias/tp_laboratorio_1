#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);
void employee_delete();

int employee_setId(Employee* This,int id);
int employee_getId(Employee* This,int* id);

int employee_setNombre(Employee* This,char* nombre);
int employee_getNombre(Employee* This,char* nombre);

int employee_setHorasTrabajadas(Employee* This,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* This,int* horasTrabajadas);

int employee_setSueldo(Employee* This,int sueldo);
int employee_getSueldo(Employee* This,int* sueldo);

int employee_CompareByString(void * e1, void * e2);
int employee_CompareByInt(void * e1, void * e2);

#endif // employee_H_INCLUDED

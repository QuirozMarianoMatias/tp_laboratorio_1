#include <stdio.h>
#define VACIO 0
#define OCUPADO 1
#define ERROR -1


typedef struct
{
 int id;
 char name[51];
 char lastName[51];
 float salary;
 int sector;
 int isEmpty;
}Employee;

int initEmployees(Employee empleados [], int t);
int addEmployee(Employee empleados [], int t);
Employee cargarEmplado(void);
int buscarLibre( Employee empleados [], int t);



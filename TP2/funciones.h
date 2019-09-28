#include <stdio.h>
#include <string.h>
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
int addEmployee(Employee empleados [], int t, int id, char name[],char lastName[],float salary,int sector);
int buscarLibre( Employee empleados [], int t);
int generadorID(Employee empleados[], int t);
void mostrarEmpleado (Employee empleado [],int t);
int removeEmployee(Employee empleado [], int t,int id);
int modificarEmployee(Employee empleado [], int t,int id);




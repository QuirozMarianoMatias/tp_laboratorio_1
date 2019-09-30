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

int initEmployees(Employee empleados [], int t);
int addEmployee(Employee empleados [], int t, int id, char name[],char lastName[],float salary,int sector);
int buscarLibre( Employee empleados [], int t);
int generadorID(Employee empleados[], int t);
int mostrarSalaryPromedioSuperiorPromedio (Employee empleado [],int t);
int removeEmployee(Employee empleado [], int t,int id);
int modificarEmployee(Employee empleado [], int t,int id);
int sortStudentsByNameAndAverage(Employee empleados[], int t);
float salaryTotal (Employee empleados [], int t);
float promedio (Employee empleados [], int t);
int superiorPromedio (Employee empleados [], int t);
int printEmployees (Employee empleados [],int t);




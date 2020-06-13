#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee * auxLista = employee_new();
    int read =0;
    int i= 0;
    char auxId[50];
    char auxName[50];
    char auxHoras[50];
    char auxSueldo[50];

    if (auxLista!= NULL)
    {
        read = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxName,auxHoras,auxSueldo);
        while(!feof(pFile))
        {
            read = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxName,auxHoras,auxSueldo);
            if(read==4)
            {
                auxLista = employee_newParametros(auxId,auxName,auxHoras,auxSueldo);
                ll_add(pArrayListEmployee, auxLista);
                i++;
            }
        }
    }




    return i;

}




int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{

    Employee auxEmployee;
    int i = 0;

    fread(&auxEmployee, sizeof(Employee), 1, pFile);

    while(!feof(pFile))
    {
        Employee *employeeNew = employee_new();
        employee_setId(employeeNew,auxEmployee.id);
        employee_setHorasTrabajadas(employeeNew,auxEmployee.horasTrabajadas);
        employee_setNombre(employeeNew,auxEmployee.nombre);
        employee_setSueldo(employeeNew,auxEmployee.sueldo);
        i ++;
        ll_add(pArrayListEmployee, employeeNew);
        fread(&auxEmployee, sizeof(Employee), 1, pFile);
    }


    return i;
}

#include <stdlib.h>
#include "Employee.h"
#include <string.h>

Employee* employee_new()
{  Employee * pEmployee;
    pEmployee = (Employee*) calloc(sizeof (Employee),1);


    return pEmployee;

}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee * auxEmployee;
    auxEmployee = employee_new();
    int id;
    int horastrabajo;
    int sueldo;

    if (auxEmployee != NULL)
    {

        id = atoi(idStr);
        horastrabajo = atoi(horasTrabajadasStr);
        sueldo = atoi(sueldoStr);

        employee_setId(auxEmployee,id);
        employee_setNombre(auxEmployee,nombreStr);
        employee_setHorasTrabajadas(auxEmployee,horastrabajo);
        employee_setSueldo(auxEmployee,sueldo);


    }

    return auxEmployee;

}

int employee_setNombre(Employee* This,char* nombre)
{
    int retorno = 0;
if (This != NULL)
{
    strcpy(This->nombre,nombre);
    retorno = 1;
}
return retorno;
}

int employee_getNombre(Employee* This,char* nombre)
{
       int retorno = 0;
if (This != NULL )
{
    strcpy(nombre,This->nombre);
    retorno = 1;
}
return retorno;


}



int employee_setSueldo(Employee* This,int sueldo)
{
    int retorno = 0;

    if (This != NULL)
    {
        This->sueldo = sueldo;
        retorno = 1;
    }

return retorno;
}
int employee_getSueldo(Employee* This,int* sueldo)
{

int retorno = 0;

    if (This != NULL)
    {
        *sueldo = This->sueldo;
        retorno = 1;
    }

return retorno;
}

int employee_setId(Employee* This,int id)
{
int retorno = 0;

    if (This != NULL)
    {
        This->id = id;
        retorno = 1;
    }

return retorno;
}
int employee_getId(Employee* This,int* id)
{
int retorno = 0;

    if (This != NULL)
    {
        *id = This->id;
        retorno = 1;
    }

return retorno;
}

int employee_setHorasTrabajadas(Employee* This,int horasTrabajadas)
{
int retorno = 0;

    if (This != NULL)
    {
        This->horasTrabajadas = horasTrabajadas;
        retorno = 1;
    }

return retorno;
}
int employee_getHorasTrabajadas(Employee* This,int* horasTrabajdas)
{

int retorno = 0;

    if (This != NULL)
    {
        *horasTrabajdas = This->horasTrabajadas;
        retorno = 1;
    }

return retorno;
}


int employee_CompareByString(void * e1, void * e2)
{

    int retorno;
    char auxE1 [128];
    char auxE2 [128];


    if((e1 != NULL)&&(e2 !=NULL))
    {
        employee_getNombre(e1 , auxE1);
        employee_getNombre(e2, auxE2);

        retorno = strcmp(auxE1, auxE2);

    }





    return retorno;
}

int employee_CompareByInt(void * e1, void * e2)
{
        int retorno;
        int auxA;
        int auxB;

    if((e1 != NULL)&&(e2 !=NULL))
    {

        employee_getId(e1,&auxA);
        employee_getId(e2,&auxB);

        if(auxA > auxB)
        {
            retorno = 1;
        }
        else if(auxA == auxB)
        {
            retorno = 0;
        }
        else
        {
            retorno = -1;
        }



    }




    return retorno;
}


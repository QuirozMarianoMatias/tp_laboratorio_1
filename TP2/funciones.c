#include "funciones.h"


int initEmployees(Employee empleados [], int t)
{
    int i;

    for (i=0;i<t;i++)
    {
    empleados[i].isEmpty=VACIO;
    }

 return VACIO;
}

int buscarLibre( Employee empleados [], int t)
{
    int indice = ERROR;
    int i;

    for(i=0;i<t;i++)
    {
        if(empleados[i].isEmpty!=OCUPADO)
        {
            indice = i;
            break;
        }
    }
    return indice;

}



{
 return -1;
}







iint addEmployee(Employee empleados [], int t, int id, char name[],char lastName[],float salary,int sector)

{

    int i;
    int indice;
    int estado= ERROR;
    indice = buscarLibre(empleados, t);

 for (i=0;i<t;i++)
 {
    if(indice!=ERROR)
    {
        empleados [indice] = cargarEmplado();
        empleados [indice].id = indice+1;




        estado=OCUPADO;
        break;
    }
 }


return estado;

}


int findEmployeeById(Employee empleado[], int t,int id)


{
    int i;
    int idEncontrado = ERROR;

    for (i=0;i<t;i++)

    {

        if (id == empleado[i].id)

        {
            idEncontrado = empleado[i].id;
        }
    }

    return idEncontrado;



}


int removeEmployee(Employee empleado [], int t,int id)

{
    int estado = ERROR;

    empleado.id = findEmployeeById(empleado,t,id);

   if (empleado.id =! ERROR)
   {

       empleado[id].isEmpty= VACIO;
       estado = OCUPADO;
   }


    return estado;
}

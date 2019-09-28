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

int generadorID(Employee empleados[], int t)
{
    int i;
    int id =1;

    for(i=0; i<t; i++)
    {
        if(empleados[i].isEmpty ==VACIO)
        {
            id = id+i;
            break;
        }
    }
    return id;
}




int addEmployee(Employee empleados [], int t, int id, char name[],char lastName[],float salary,int sector)

{

    int i;
    int indice;
    int estado= ERROR;
    indice = buscarLibre(empleados, t);

 for (i=0;i<t;i++)
 {
    if(indice!=ERROR)
    {

        empleados [indice].id = id;
        empleados [indice].salary = salary;
        empleados [indice].sector = sector;
        empleados [indice].isEmpty =OCUPADO;
        strcpy(empleados[indice].name,name);
        strcpy(empleados[indice].lastName,lastName);



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

        if (id == empleado[i].id && empleado[i].isEmpty == OCUPADO)

        {
            idEncontrado = i;
            break;
        }
    }

    return idEncontrado;



}


int removeEmployee(Employee empleado [], int t,int id)

{
    int estado = -1;
    int index;

    index = findEmployeeById(empleado,t,id);

   if (index != -1)
   {

       empleado[index].isEmpty = VACIO;
       estado = OCUPADO;
   }


    return estado;
}
void mostrarEmpleado (Employee empleado [],int t)
{
    int i;

    for (i=0;i<t;i++)
        {
            if (empleado[i].isEmpty == OCUPADO)
            {


            printf("%d %s %s %f %d\n",empleado[i].id,empleado[i].name,empleado[i].lastName,empleado[i].salary,empleado[i].sector);
            }
        }
}

int modificarEmployee(Employee empleado [], int t,int id)

{
    int estado = -1;
    int index;
    int Nsector;
    char Nname[30];
    char NlastName[30];
    float Nsalary;

    index = findEmployeeById(empleado,t,id);

   if (index != -1)
   {

        printf("Ingrese nuevo sector: ");
        scanf("%d", &Nsector);
        printf("Ingrese nuevo nombre: ");
        fflush(stdin);
        gets(Nname);
        printf("Ingrese nuevo apellido: ");
        fflush(stdin);
        gets(NlastName);
        printf("Ingrese nuevo salario: ");
        scanf("%f", &Nsalary);

        empleado[index].sector = Nsector;
        empleado[index].salary = Nsalary;
        strcpy(empleado[index].name,Nname);
        strcpy(empleado[index].lastName,NlastName);



   }


    return estado;
}



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
    float total;
    float pro;
    int super;

    total = salaryTotal(empleado,t);
    pro = promedio(empleado,t);
    super = superiorPromedio(empleado,t);


            printf("Id\tName\tLast Name\tSalary\tSector\n");
    for (i=0;i<t;i++)
        {
            if (empleado[i].isEmpty == OCUPADO)
            {

            printf("%d\t%s\t%s\t%14.2f\t%2d\n",empleado[i].id,empleado[i].name,empleado[i].lastName,empleado[i].salary,empleado[i].sector);
            }
        }

        printf("\n %f\n",total);
        printf("\n %f\n",pro);
        printf("\n %d\n",super);
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


int sortStudentsByNameAndAverage(Employee empleados[], int t)
{
    int i;
    int j;
    int estado = -1;
    Employee auxempleado;

    for(i=0; i<t-1; i++)
    {
        for(j=i+1; j<t; j++)
        {
            if(strcmp(empleados[i].lastName,empleados[j].lastName)>0)
            {
                auxempleado = empleados[i];
                empleados[i] = empleados[j];
                empleados[j] = auxempleado;
            }

            else
            {
                if(strcmp(empleados[i].lastName,empleados[j].lastName)==0)
                {
                    if(empleados[i].sector>empleados[j].sector)
                    {
                        auxempleado = empleados[i];
                        empleados[i] = empleados[j];
                        empleados[j] = auxempleado;
                    }
                }
            }
        }

    }
    return estado;
}

float salaryTotal (Employee empleados [], int t)

{

    int i;
    float total=0;

    for (i=0;i<t;i++)
    {

        if (empleados[i].isEmpty == OCUPADO)
        {
            total += empleados[i].salary;


        }
    }
    return total;
}

float promedio (Employee empleados [], int t)

{
    int i;
    int cont=0;
    float total;
    float prom;

    total = salaryTotal(empleados,t);

     for (i=0;i<t;i++)
    {

        if (empleados[i].isEmpty == OCUPADO)
        {
            cont++;
        }
    }

    prom = total / cont;

    return prom;
}


int superiorPromedio (Employee empleados [], int t)
{
    float prom;
    int i;
    int cont=0;

    prom = promedio(empleados,t);

    for (i=0;i<t;i++)
    {
        if (empleados[i].salary > prom && empleados[i].isEmpty == OCUPADO)
        {
            cont++;
        }
    }

    return cont;
}

#include <stdlib.h>
#include "funciones.h"
#define T 5
int main()
{
    Employee empleados[T];
    int opcion;
    int estado;
    int id;
    int sector;
    char name[30];
    char lastName[30];
    float salary;
    int baja;
    int quePaso;
    int modificar;

  estado = initEmployees(empleados,T);



   do {
   printf("\n1. ALTAS: \n");
   printf("\n2. MODIFICAR: \n");
   printf("\n3. BAJA: \n");
   printf("\n4. INFORMAR: \n");
   printf("\n5. SALIR: \n");
   scanf("%d",&opcion);

   switch(opcion)
        {
        case 1 :
        printf("Ingrese sector: ");
        scanf("%d", &sector);
        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(name);
        printf("Ingrese apellido: ");
        fflush(stdin);
        gets(lastName);
        printf("Ingrese su salario: ");
        scanf("%f", &salary);
        id = generadorID(empleados,T);
        estado = addEmployee(empleados,T,id,name,lastName,salary,sector);

        break;

        case 2 :

            printf("ingrese id que desea Modificar: ");
            scanf("%d",&modificar);
            quePaso =  modificarEmployee(empleados,T,modificar);

            break;

        case 3 :
            printf("ingrese id que desea dar de baja: ");
            scanf("%d",&baja);
            quePaso =  removeEmployee(empleados,T,baja);

        break;

        case 4 :
        mostrarEmpleado(empleados,T);
        break;
        case 5 :
        printf("usted salio!!!");
        break;


        default :
        printf("Opcion incorrecta!!!");


        }


   }while (opcion != 5);


    return 0;
}

#include <stdlib.h>
#include "funciones.h"
#define T 1000
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
    int modificar;

  initEmployees(empleados,T);



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
        printf("Ingrese sector: \n");
        scanf("%d", &sector);
        printf("Ingrese nombre: \n");
        fflush(stdin);
        gets(name);
        printf("Ingrese apellido: \n");
        fflush(stdin);
        gets(lastName);
        printf("Ingrese su salario: \n");
        scanf("%f", &salary);
        id = generadorID(empleados,T);
        estado = addEmployee(empleados,T,id,name,lastName,salary,sector);

        break;

        case 2 :
            if (estado== 0)
            {printf("ingrese id que desea Modificar: \n");
            scanf("%d",&modificar);
            modificarEmployee(empleados,T,modificar);
            }

              else
            {
                printf("usted no ingreso ningun usuario\n");
            }

            break;

        case 3 :
            if (estado == 0)
            {printf("ingrese id que desea dar de baja: \n");
            scanf("%d",&baja);
            removeEmployee(empleados,T,baja);
            }
             else
            {
                printf("usted no ingreso ningun usuario\n");
            }
        break;

        case 4 :
            if (estado == 0)
        {   sortStudentsByNameAndAverage(empleados,T);
            printEmployees (empleados,T);
            mostrarSalaryPromedioSuperiorPromedio(empleados,T);
        }

        else
            {
                printf("usted no ingreso ningun usuario\n");
            }
        break;


        case 5 :
        printf("usted salio!!!\n");
        break;


        default :
        printf("Opcion incorrecta!!!\n");


        }

    system("pause");
    system("cls");
   }while (opcion != 5);


    return 0;
}

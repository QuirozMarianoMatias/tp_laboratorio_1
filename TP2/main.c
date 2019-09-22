#include <stdlib.h>
#include "funciones.h"
#define T 5
int main()
{
    Employee empleados[T];
    int opcion;
    int estado;

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
        scanf("%d", &empleados.sector);
        printf("Ingrese nombre: ");
        fflush(stdin);
        scanf("%[^\n]", empleados.name);
        printf("Ingrese apellido: ");
        fflush(stdin);
        scanf("%[^\n]", empleados.lastName);
        printf("Ingrese su salario: ");
        scanf("%f", &empleados.salary);

        break;

        case 2 :
        printf("usted esta modificando!!!");
        break;

        case 3 :
        printf("usted esta dando de baja!!!");
        break;

        case 4 :
        mostrarUnEmpleado(empleados[0]);
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

#include <stdio.h>
#include <stdlib.h>
#include "OperacionesAritmeticas.h"

int main()
{   int numero1;
    int numero2;
    float total;
    char opcion;
    do
    {
        printf("Ingresar primer numero: \n");
        scanf("%d",&numero1);
        printf("Ingresar segundo numero: \n");
        scanf("%d",&numero2);
        printf("si desea hacer una suma presione:(a)\n");
        printf("si desea hacer una resta presione:(b)\n");
        printf("si desea hacer una division presione:(c)\n");
        printf("si desea hacer una multiplicacion presione:(d)\n");
        printf("si desea hacer un factorial presione:(e)\n");
        printf("si desea salir presione:(s)\n");
        fflush(stdin);
        scanf("%c", &opcion);
        switch(opcion)
        {
            case 'a':
                total = suma (numero1,numero2);
                printf("la suma de: %d + %d es: %.2f\n",numero1,numero2,total);
                break;
            case 'b':
                total = resta (numero1,numero2);
                printf("la resta de: %d - %d es: %.2f\n",numero1,numero2,total);
                break;
            case 'c':
                if (numero2 != 0)
                {total = division (numero1,numero2);
                printf("la division de: %d / %d es: %.2f\n",numero1,numero2,total);
                }
                else {
               printf("no se puede dividir por: 0\n");
                }
                break;
            case 'd':
                total = multiplicacion(numero1,numero2);
                printf("la multiplicacion de: %d * %d es: %.2f\n",numero1,numero2,total);
                break;
            case 'e':
                if (numero1 >=0)
                    {
                    total = factorial(numero1);
                    printf("el factorial de: %d es: %.2f \n",numero1,total);
                    }

                    else
                    {printf("no se puede sacar factorial de: %d porque es un numero negativo\n",numero1);

                    }

                    if (numero2 >=0)
                    {
                    total = factorial(numero2);
                    printf("el factorial de: %d es: %.2f \n",numero2,total);

                    }

                else
                    {printf("no se puede sacar factorial de: %d porque es un numero negativo\n",numero2);

                    }
                break;
            case 's':
                printf("usted salio!\n");
                break;
            default:
                printf("Opcion incorrecta!\n");


        }
    system("pause");
    system("cls");
    }
    while(opcion!='s');
return 0;
    }

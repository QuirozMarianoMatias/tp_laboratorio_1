#include <stdio.h>
#include <stdlib.h>
#include "OperacionesAritmeticas.h"

int main()
{

   int opcion;
   int flag1 = 0;
   int flag2 = 0;
   int flagresultados;
   int num1;
   int num2;
   int totalSuma;
   int totalResta;
   int totalFactorial1;
   int totalFactorial2;
   int totalMultiplicacion;
   float totalDivision;
        do
        {


            printf("\n-----------------------CALCULADORA-----------------------\n");

          if (flag1 == 0)
          {
              printf("1- Ingresar 1er operando: \n");

          }
          else
          {
              printf("1- Reingresar 1er operando el actual es: (x = %d)\n",num1);
          }
            if (flag2==0)
          {
              printf("2- Ingresar 2do operando: \n");

          }
          else
          {
              printf("2- Reingresar 2do operando el actual es:(y = %d)\n",num2);
          }
            printf("3- Calcular todas las operaciones: \n");
            printf("4- Informar resultados: \n");
            printf("5- salir\n");
            printf("---------------------------------------------------------\n");
            printf("\nprisone numeros del (1 al 5) para eliger la opcion a usar: ");
            scanf("%d", &opcion);


                switch(opcion)
                    {case 1:
                        printf("\ningrese primer operandor: ");
                        scanf("%d",&num1);
                        flag1= 1;
                        break;

                    case 2:
                        printf("\ningrese segundo operandor: ");
                        scanf("%d",&num2);
                        flag2= 1;
                        break;
                    case 3: if (flag1 == 1 && flag2 ==1)
                    {
                            printf("\na) Calcular la suma (%d+%d)",num1,num2);
                            totalSuma = suma(num1,num2);
                            printf("\nb) Calcular la resta (%d-%d)",num1,num2);
                            totalResta = resta(num1,num2);
                            if (num2!=0)
                            {
                                printf("\nc) Calcular la division (%d/%d)",num1,num2);
                                totalDivision = division(num1,num2);
                            }
                            else
                            {
                                printf("\nno se puede dividir por 0\n");
                            }
                            printf("\nd) Calcular la multiplicacion (%d*%d)",num1,num2);
                            totalMultiplicacion = multiplicacion(num1,num2);
                            if (num1 >= 0 && num2 >= 0)
                            {
                                printf("\ne) Calcular el factorial de (%d!) y de (%d!)\n",num1,num2);
                                totalFactorial1 = factorial(num1);
                                totalFactorial2 = factorial(num2);
                            }
                            else
                            {
                                printf("\nno se puede sacar el operando de un numero negativo\n");
                            }

                    }
                    else
                    {
                        printf("\nusted no ingreso los dos operandos no se puede realizar los calculos\n");
                    }
                    flagresultados = 1;
                        break;
                    case 4:if (flag1 == 1 && flag2 ==1)
                    {
                            if(flagresultados == 1)
                            {



                            printf("\na) el resultado de la suma (%d+%d) es : %d",num1,num2,totalSuma);

                            printf("\nb) el resultado de la resta (%d-%d) es : %d",num1,num2,totalResta);

                          if(num2!=0)
                            {
                            printf("\nc) el resultado de la division (%d/%d) es : %f",num1,num2,totalDivision);
                            }
                        else{
                            printf("\nno se puede dividir por 0");
                            }

                            printf("\nd) el resultado de la multiplicacion (%d*%d) es : %d",num1,num2,totalMultiplicacion);

                          if (num1 >= 0 && num2 >=0)
                            {
                            printf("\ne) el resultado del factorial de (%d!) es: %d y de (%d!) es :  %d\n",num1,totalFactorial1,num2,totalFactorial2);
                            }
                        else
                            {
                            printf("\nno se puede sacar factorial de numeros negativos\n");
                            }
                            flagresultados = 0;
                        }
                        else
                        {
                            printf("\nno realizo primero el calculo\n");
                        }
                    }
                    else
                        {
                            printf("no se puede mostrar ningun resultado porque usted no ingreso operandos");
                        }
                        break;
                    case 5:
                        printf("\nusted salio\n");
                    default:
                        printf("\nsu opcion ingresada es erronia\n");
                    }
    system("pause");
    system("cls");
    }while(opcion != 5);
    return 0;
}

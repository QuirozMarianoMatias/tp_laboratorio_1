#include "OperacionesAritmeticas.h"

int suma (int a, int b)
{
  int  resultado;
 resultado  = a + b;

 return resultado;
}

int resta (int a, int b)
{
  int  resultado;
 resultado  = a - b;

 return resultado;
}

int multiplicacion (int a, int b)
{
  int  resultado;
 resultado  = a * b;

 return resultado;
}

float division (int a, int b)
{
  float  resultado;
 resultado  =  (float)a / b;

 return resultado;
}
int factorial (int a)
{
int resultado=1;
int i;


for (i=a;i!=0;i--)
    {
    resultado= resultado * i;
    }

return (resultado);
}


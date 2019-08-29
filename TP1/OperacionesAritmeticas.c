#include "OperacionesAritmeticas.h"

float suma (float a, float b)
{
  float  resultado;
 resultado  = a + b;

 return resultado;
}

float resta (float a, float b)
{
 float resultado;
 resultado  = a - b;

 return resultado;
}

float multiplicacion (float a, float b)
{
  float  resultado;
 resultado  = a * b;

 return resultado;
}

float division (float a, float b)
{
  float  resultado;
 resultado  =  (float)a / b;

 return resultado;
}
int factorial (int a)
{
int resultado=1;
int i;


for (i=(int)a;i!=0;i--)
    {
    resultado= resultado * i;
    }

return (resultado);
}


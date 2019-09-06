#include "OperacionesAritmeticas.h"

/** \brief Esta funcion suma dos enteros y devuelve el resultado de dicha suma
 *
 * \param int a recibe un entero
 * \param int b recibe un entero
 * \return int devuelve un entero
 *
 */
int suma (int a, int b)
{
  int  resultado;
 resultado  = a + b;

 return resultado;
}

/** \brief Esta funcion resta dos enteros y devuelve el resultado de dicha resta
 *
 * \param int a recibe un entero
 * \param int b recibe un entero
 * \return int devuelve un entero
 *
 */
int resta (int a, int b)
{
 int resultado;
 resultado  = a - b;

 return resultado;
}

/** \brief Esta funcion multiplica dos enteros y devuelve el resultado de dicha multiplicacion
 *
 * \param int a recibe un entero
 * \param int b recibe un entero
 * \return int devuelve un entero
 *
 */
int multiplicacion (int a, int b)
{
  int  resultado;
 resultado  = a * b;

 return resultado;
}

/** \brief Esta funcion divide dos enteros y devuelve el resultado de dicha division
 *
 * \param int a recibe un entero
 * \param int b recibe un entero
 * \return float devuelve un flotante
 *
 */
float division (int a, int b)
{
  float  resultado;
 resultado  =  (float)a / b;

 return resultado;
}

/** \brief Esta funcion saca factorial de un entero y devuelve el resultado de dicho factorial
 *
 * \param int a recibe un entero
 * \return int devuelve un entero
 *
 */
int factorial(int a)
{

   int resultado;

    if (a == 0)
    {
        resultado = 1;
    }

    else
    {
        resultado = a* factorial(a-1);
    }
    return resultado;
}


#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/** \brief busca encontrar algun caracter que no sea un numero o un .
 *
 * \param stringRecibido char* recibe una cadena de caracteres
 * \return int devuelve 1 si no encontro error y 0 si encontro algun caracter distinto a un numero o un .
 *
 */
int isValidFloatNumber(char* stringRecibido);
/** \brief esta funcion recibe una cadena de caracteres y valida que sean solo numeros flotantes
 *
 * \param msg char* se le ingresa un mensaje al usuario para que ingrese el dato
 * \param msgError char* se le muestra un mensaje de error al usuario
 * \param minSize int cantidad minima de caracteres que se pueden ingresar
 * \param maxSize int cantidad maxima de caracteres que se pueden ingresar
 * \param reintentos int* cantidad de reintentos que tiene el usuario para ingresar el dato correctamente
 * \param resultado int* si se ingreso correctamente el dato se le da el valor a la variable a travez del puntero input
 * \return int retorna -1 si se acabaron los reintentos y no se ingreso el dato correctamente y 0 si se ingreso correctamente el dato
 *
 */
int getFloat(char* msg, char* msgError, int minSize, int maxSize, int reintentos, float* input);
/** \brief esta funcion busca encontrar algun caracter que no sea un numero para verificar error posible
 *
 * \param stringRecibido char* recibe una cadena de caracteres
 * \return int retorna 1 si no hubo error y 0 si se encontro alguna letra
 *
 */
int isValidNumber(char* stringRecibido);
/** \brief esta funcion recibe una cadena de caracteres y valida que sean solo numeros
 *
 * \param msg char* se le ingresa un mensaje al usuario para que ingrese el dato
 * \param msgError char* se le muestra un mensaje de error al usuario
 * \param minSize int cantidad minima de caracteres que se pueden ingresar
 * \param maxSize int cantidad maxima de caracteres que se pueden ingresar
 * \param reintentos int* cantidad de reintentos que tiene el usuario para ingresar el dato correctamente
 * \param resultado int* si se ingreso correctamente el dato se le da el valor a la variable a travez del puntero input
 * \return int retorna -1 si se acabaron los reintentos y no se ingreso el dato correctamente y 0 si se ingreso correctamente el dato
 *
 */
int getInt (char* msg,char* msgError,int minSize,int maxSize,int reintentos,int* input);
/** \brief esta funcion recibe una cadena de caracteres y busca si contiene algun caracter que no sea una letra
 *
 * \param stringRecibido char* recibe una cadena de caracteres
 * \return int devuelve 1 si no encontro error y 0 si encontro algun caracter que no sea una letra
 *
 */
int isValidName(char* stringRecibido);
/** \brief esta funcion recibe una cadena de caracteres y valida que sean solo letras
 *
 * \param msg char* se le ingresa un mensaje al usuario para que ingrese el dato
 * \param msgError char* se le muestra un mensaje de error al usuario
 * \param mini int cantidad minima de la cadena de caracteres
 * \param maxi int cantidad maxima de la cadena de caracteres
 * \param reintentos int* cantidad de reintentos que tiene el usuario para ingresar el dato correctamente
 * \param resultado char* si se ingreso correctamente el dato se le da el valor a la variable a travez del puntero resultado
 * \return int retorna -1 si se acabaron los reintentos y no se ingreso el dato correctamente y 0 si se ingreso correctamente el dato
 *
 */
int getName (char* msg, char* msgError, int mini, int maxi, int reintentos, char* resultado);
/** \brief esta funcion recibe una cadena de caracteres y la valida
 *
 * \param msg char* se le ingresa un mensaje al usuario para que ingrese el dato
 * \param msgError char* se le muestra un mensaje de error al usuario
 * \param mini int cantidad minima de la cadena de caracteres
 * \param maxi int cantidad maxima de la cadena de caracteres
 * \param reintentos int* cantidad de reintentos que tiene el usuario para ingresar el dato correctamente
 * \param resultado char* si se ingreso correctamente el dato se le da el valor a la variable a travez del puntero resultado
 * \return int retorna -1 si se acabaron los reintentos y no se ingreso el dato correctamente y 0 si se ingreso correctamente el dato
 *
 */
int getString(char* msg, char* msgError, int mini, int maxi, int* reintentos, char* resultado);

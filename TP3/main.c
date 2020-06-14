#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "input.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int opcion = 0;
    int flagCsv = 0;
    int flagBin = 0;
    char salir[3];
    LinkedList* listaEmpleados = ll_newLinkedList();

    do
    {   strcpy(salir,"no");
        getInt("1-cargar empleados del archivo .csv\n2-cargar empleados del archivo .bin\n3-cargar nuevo empleado\n4-editar empleado\n5-eliminar empleado\n6-listar empleados\n7-ordenar empleados\n8-guardar archivo csv\n9-guardar archivo bin \n10-salir\n","error\n",1,3,0,&opcion);
        switch(opcion)
        {
        case 1:
            if(flagCsv == 0 && flagBin !=1)
            {
                controller_loadFromText("data.csv",listaEmpleados);

                flagCsv = 1;
            }
            else
            {
                printf("ya se cargaron los datos previamente\n");
            }
            system("pause");
            break;
        case 2:
            if(flagCsv !=1 && flagBin == 0)
            {

                controller_loadFromBinary("data.bin", listaEmpleados);
                flagBin = 1;
            }
            else
            {
                printf("ya se cargaron los datos previamente\n");
            }
            system("pause");
            break;
        case 3:
            if(flagCsv == 1 || flagBin == 1)
            {
                controller_addEmployee(listaEmpleados);
            }
            else
            {
                printf("No ha cargado los datos aun \n");
            }
            system("pause");
            break;
        case 4:
            if( flagCsv == 1 || flagBin == 1)
            {
                controller_editEmployee(listaEmpleados);
            }
            else
            {
                printf("No ha cargado los datos aun \n");
            }
            system("pause");
            break;
        case 5:
            if( flagCsv == 1 || flagBin == 1)
            {
                controller_removeEmployee(listaEmpleados);
            }
            else
            {
               printf("No ha cargado los datos aun\n");
            }
            system("pause");
            break;
        case 6:
            if( flagCsv == 1 || flagBin == 1)
            {
                controller_ListEmployee(listaEmpleados);
            }
            else
            {
                printf("No ha cargado los datos aun \n");
            }
            system("pause");
            break;;
        case 7:
            if( flagCsv == 1 || flagBin == 1)
            {
                controller_sortEmployee(listaEmpleados);
            }
            else
            {
                printf("No ha cargado los datos aun \n");
            }
            system("pause");
            break;;
        case 8:
            if(flagCsv == 1|| flagBin == 1)
            {
                controller_saveAsText("data.csv",listaEmpleados);
            }
            else
            {
                printf("No ha cargado los datos aun \n");
            }
            system("pause");
            break;
        case 9:
            if(flagCsv == 1|| flagBin == 1)
            {
                controller_saveAsBinary("data.bin",listaEmpleados);
            }
            else
            {
                printf("No ha cargado los datos aun \n");
            }
            system("pause");
            break;
        case 10:
            getName("esta seguro que desea salir?(si) los datos no guardados seran borrados\n","error\n",1,3,0,salir);
           if(strcmp(salir,"si"))
           {
               ll_deleteLinkedList(listaEmpleados);
           }


            break;
        default:
            printf("Opcion invalida\n");
            break;
        }

        system("cls");
    }
    while(strcmp(salir,"si")!= 0);
    return 0;
}

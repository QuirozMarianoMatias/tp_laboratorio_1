#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "input.h"



int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
 FILE *pArchivo;
 int retorno = 0;
    pArchivo = fopen(path, "r");
    if(pArchivo !=NULL)
    {
        parser_EmployeeFromText(pArchivo, pArrayListEmployee);
        retorno = 1;
    }
else
    {


    printf("Error al leer el archivo\n");

    }


return retorno;
}


int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{FILE *pArchivo ;
 int retorno = 0;

 pArchivo = fopen(path, "rb");

    if(pArchivo != NULL)
    {

        parser_EmployeeFromBinary(pArchivo, pArrayListEmployee);
        retorno = 1;
    }
    else
    {
        printf("Error al leer el archivo\n");

    }

    fclose(pArchivo);

return retorno;
}


int controller_addEmployee(LinkedList* pArrayListEmployee)
{
  Employee* newEmployees = employee_new();
    int retorno = 0;
    char auxId[50];
    char auxName[50];
    char auxHorasTrabajadas[50];
    char auxSueldo [50];
    int auxhorasI;
    int auxSueldoI;
    int auxIdI;
    int i;
    int tamLista;

    tamLista = ll_len(pArrayListEmployee);
    newEmployees = employee_new();


    if(pArrayListEmployee !=NULL)
    {
       if(getInt("Ingrese id del nuevo empleado: ","error\n",1,5,3,&auxIdI)==0);
        {itoa(auxIdI, auxId, 10);

        for( i = 0; i <tamLista ; i++ )
        {
            newEmployees = (Employee*)ll_get(pArrayListEmployee, i);
            if( newEmployees->id == auxIdI)
            {
                printf("Ese id ya existe\n");
                break;

            }
        }

        if( newEmployees->id != auxIdI)
        {

          if( getName("ingrese el nombre del empleado: ","error\n",2,20,3,auxName)== 0
               && getInt("ingrese horas trabajadas: ","error\n",1,3,3,&auxhorasI)== 0
               && getInt("ingrese sueldo: ","error\n",1,7,3,&auxSueldoI)==0);
            {


            itoa(auxhorasI, auxHorasTrabajadas, 10);
            itoa(auxSueldoI, auxSueldo, 10);

            newEmployees = employee_newParametros(auxId, auxName, auxHorasTrabajadas, auxSueldo);
            ll_add(pArrayListEmployee, newEmployees);
            retorno = 1;
        }
        }
        }
    }

    return retorno;
}


int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    Employee *auxEmployee;
    char auxName[50];
    int auxId;
    int auxSueldo;
    int auxHorasTrabajadas;
    int opcion;
    int retorno;
    int tamLista;
    int i;
    tamLista = ll_len(pArrayListEmployee);

    if(pArrayListEmployee != NULL)
    {
       if(getInt("Ingrese el id que desea modificar: ","error\n",1,6,3,&auxId)==0)
        {
           for( i = 0; i <tamLista ; i++ )
        {

            auxEmployee = (Employee*)ll_get(pArrayListEmployee, i);
            if( auxId == auxEmployee->id )
            {
                do
                {
                    retorno = 0;
                   getInt("menu modificar\n1-modificar nombre\n2-modificar horas trabajadas\n3-modificar sueldo\n4-salir\n","error\n",1,4,0,&opcion);

                    switch(opcion)
                    {
                    case 1:
                     if(getName("ingrese nuevo nombre: ","error",2,20,3,auxName)==0)
                       {
                           employee_setNombre(auxEmployee, auxName);
                           retorno = 1;
                       }
                        break;
                    case 2:
                      if (getInt("ingrese nueva hora trabajada: ","error\n",1,3,3,&auxHorasTrabajadas)==0)
                       {
                           employee_setHorasTrabajadas(auxEmployee, auxHorasTrabajadas);
                            retorno = 1;
                       }
                        break;
                    case 3:
                         if (getInt("ingrese nueva sueldo: ","error\n",1,7,3,&auxSueldo)==0)
                        {employee_setSueldo(auxEmployee, auxSueldo);
                        retorno = 1;
                        }
                        break;
                    case 4:
                               printf("usted salio");
                        break;
                    default:
                        printf("Opcion invalida");
                        break;
                    }
                }
                while(opcion != 4);

            }
        }
        }


    }
  return retorno;
}


int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    Employee* auxEmployee;
    int tamLista;
    int i;
    int auxId;
    int retorno;

    tamLista = ll_len(pArrayListEmployee);

    if(pArrayListEmployee !=NULL)
    {
        getInt("ingrese ID  a remover","error\n",1,6,3,&auxId);

        for(i=0; i<tamLista; i++)
        {
            auxEmployee = (Employee*)ll_get(pArrayListEmployee, i);

            if(auxEmployee->id == auxId)
            {
                ll_remove(pArrayListEmployee, i);
                printf("Empleado borrado con exito!\n");
                employee_delete(auxEmployee);
                retorno = 1;
                break;
            }
        }
        if( auxEmployee->id != auxId)
        {
            printf("Ese id no existe\n");
        }

    }


    return retorno;
}


int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    Employee* auxEmployee;
    int retorno = 0;
    int auxId;
    char auxName[50];
    int auxHorasTrabajadas;
    int auxSueldo;
    int tamLista;
    int i;

    tamLista = ll_len(pArrayListEmployee);

    if(pArrayListEmployee!=NULL)
    {
        if(tamLista>0)
        {
            printf("Id\tNombre\t  Horas trabajadas\t  Sueldo \n");

            for(i = 0; i < tamLista; i++)
            {
                auxEmployee = (Employee*)ll_get(pArrayListEmployee, i);
                employee_getId(auxEmployee, &auxId);
                employee_getNombre(auxEmployee,auxName);
                employee_getHorasTrabajadas(auxEmployee,&auxHorasTrabajadas);
                employee_getSueldo(auxEmployee,&auxSueldo);
                printf("%d  %13s %13d  %19d\n",auxId, auxName, auxHorasTrabajadas, auxSueldo);
            }

            retorno = 1;

        }
        else
        {
            printf("no se han cargado datos\n");
        }
    }
    return retorno;


}


int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int opcion;
    int orden;

    if(pArrayListEmployee != NULL)
    {
      if(getInt("1-ordenar por id\n2-ordenar por nombre\n3-ordenar por horas trabajadas\n4-ordenar por sueldo\n","error\n",1,2,3,&opcion)==0&&
        getInt("1-manera ascendente\n0-manera descendente\n","error\n",1,2,0,&orden)==0 );

{
    switch(opcion)
    {
    case 1:


        if (orden == 1 || orden == 0)
            {
            ll_sort(pArrayListEmployee, employee_CompareById, orden);
            }
             else
            {
                printf("opcion incorrecta");
            }

        break;
    case 2:

         if (orden == 1 || orden == 0)
            {
            ll_sort(pArrayListEmployee, employee_CompareByName, orden);
            }
             else
            {
                printf("opcion incorrecta");
            }
        break;
    case 3:

         if (orden == 1 || orden == 0)
            {
            ll_sort(pArrayListEmployee, employee_CompareByHorasTrabajadas, orden);
            }
             else
            {
                printf("opcion incorrecta");
            }
        break;
    case 4:

         if (orden == 1 || orden == 0)
            {
            ll_sort(pArrayListEmployee, employee_CompareBySueldo, orden);
            }

            else
            {
                printf("opcion incorrecta");
            }
        break;
    default :
        printf("opcion invalida");
    }
}
}


return 1;
}


int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int tamLista;
    Employee* auxEmployee;
    FILE* pArchivo;
    int retorno = 0;
    int i;

    tamLista = ll_len(pArrayListEmployee);
    pArchivo = fopen(path, "w");

    if(pArchivo != NULL)
    {

        fprintf(pArchivo, "id,nombre,horasTrabajadas,sueldo\n");

        if(pArrayListEmployee!=NULL)
        {
            for(i = 0; i < tamLista; i++)
            {
                auxEmployee = (Employee*)ll_get(pArrayListEmployee, i);
                fprintf(pArchivo, "%d,%s,%d,%d\n", auxEmployee->id, auxEmployee->nombre, auxEmployee->horasTrabajadas, auxEmployee->sueldo);
            }
            printf("Archivo de texto guardado con exito\n");
        }
        fclose(pArchivo);
        retorno = 1;
    }
    else
    {
        printf("Error al abrir archivo\n");

    }
return retorno;
}


int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    Employee* auxEmployee;
    FILE* pArchivo;
    int tamLista;
    int retorno = 0;
    int i;

    pArchivo = fopen(path, "wb");
    tamLista = ll_len(pArrayListEmployee);



    if(pArrayListEmployee!= NULL && pArchivo != NULL)
    {
        for(i = 0; i < tamLista; i++)
        {
            auxEmployee = (Employee*)ll_get(pArrayListEmployee, i);
            fwrite(auxEmployee,sizeof(Employee), 1, pArchivo);
        }
        printf("Archivo binario guardado\n");
        retorno = 1;
    }
    fclose(pArchivo);
    return retorno;

}


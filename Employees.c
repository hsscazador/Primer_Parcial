#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "Employees.h"
#include "Funciones.h"
#include "Orquesta.h"
#include "Instrumento.h"



/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initEmployees(Employee* list, int len)
{
    int i;
    int TRUE=1;
    int flag=-1;
    // recorre y asigna
    if(list!=NULL)
    {
        for(i=0;i<len;i++)
        {
            list[i].isEmpty=TRUE;

            flag=1;
        }
    }
    return flag;
}

/** \brief add in a existing list of employees the values received as parameters
* in the first empty position
* \param list employee*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param edad float
* \param idInstrumento int
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
*
*/
int addEmployee(Employee* list, int len, int id, char name[], char lastName[], int edad, int idInstrumento, int idOrquesta)
{
    int aux, flag=-1;

    aux=obtenerEspacioLibre(list,Len);

    if(aux != -1&&list!=NULL)
    {
        list[aux].id = id;
        strcpy(list[aux].name,name);
        strcpy(list[aux].lastName,lastName);
        list[aux].edad=edad;
        list[aux].idInstrumento=idInstrumento;
        list[aux].idOrquesta=idOrquesta;
        list[aux].isEmpty=0;
        flag=1;
    }
    else
    {
        printf("\nNo hay campos vacios para el ingreso.\n");
    }

    return flag;
}

/** \brief find an Employee by Id en returns the index position in array.
*
* \param list Employee*
* \param len int
* \param id int
* \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
*
*/
int findEmployeeById(Employee* list, int len,int id)
{
    int retorno=-1;
    int i;

    if(list!=NULL)
    {
        for(i=0;i<len;i++)
        {
            if((list[i].id)==id)
            {
                retorno=i;
                break;
            }
        }
    }
    else
    {
        printf("\nNo se encontro registro:");
        getchar();
    }
    return retorno;
}

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
*
* \param list Employee*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
*
*/
int removeEmployee(Employee* list, int len, int id)
{
    int flag=-1;
    int index, rep=-1;

    index=findEmployeeById(list, len, id); //Busca ID y regresa indice.
    if(index!=-1&&list!=NULL)
    {
        barra(72);
        printf("|%6s|%51s|%51s|%6s|\n","ID","Nombre","Apellido","edad");
        barra(72);

        printf("|%6d|%51s|%51s|%6d|\n",list[index].id, list[index].name, list[index].lastName, list[index].edad);

        flag=valSyN("Proceder con la baja S/N:"); //Validador de S o N, devuelve 1 o 0
        if(flag == 1)
        {
            list[index].isEmpty=1; //Deja disponible para usar
            //flag=1;
            printf("\nSe procedio con la baja.\n");
            rep=0;
        }
        else
        {
            list[index].isEmpty=0;
            //flag=0;
            printf("\nSe cancela baja.\n");

        }

        barra(72);
    }
return rep;
}

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
*
* \param list Employee*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortEmployees(Employee* list, int len, int order)
{
    int i,j;
    int aInt=0; //auxiliar para hacer swap
    int aAux;
    int flag=-1;
    char auxN[100];
    char auxLN[100];

    for(i=0;i<len;i++) // si el flag es 0 almeno hay 1 cargado
    {
        if(list[i].isEmpty==0)
        {
            flag=0;
            break;
        }
    }

    if(flag==0)
    {
        if(order==1)
        for(i=0;i<len;i++)
        {
            for(j=i+1;j<len;j++)
            {
                // condicion verifica que este cargado i y j y luego compara los nombres
                if(list[i].isEmpty==0 && list[j].isEmpty==0 && strcasecmp(list[i].name,list[j].name)>0)
                {

                    aInt=list[i].id;
                    list[i].id=list[j].id;
                    list[j].id=aInt;

                    strcpy(auxN,list[i].name);
                    strcpy(list[i].name,list[j].name);
                    strcpy(list[j].name,auxN);

                    strcpy(auxLN,list[i].lastName);
                    strcpy(list[i].lastName,list[j].lastName);
                    strcpy(list[j].lastName,auxLN);

                    aAux=list[i].edad;
                    list[i].edad=list[j].edad;
                    list[j].edad=aAux;

                    aInt=list[i].idInstrumento;
                    list[i].idInstrumento=list[j].idInstrumento;
                    list[j].idInstrumento=aInt;

                    aInt=list[i].idOrquesta;
                    list[i].idOrquesta=list[j].idOrquesta;
                    list[j].idOrquesta=aInt;

                    aInt=list[i].isEmpty;
                    list[i].isEmpty=list[j].isEmpty;
                    list[j].isEmpty=aInt;
                }
            }
        }

        if(order==0)
        for(i=0;i<len;i++)
        {
            for(j=i+1;j<len;j++)
            {
                // condicion verifica que este cargado i y j y luego compara los nombres
                if(list[i].isEmpty==0 && list[j].isEmpty==0 && strcasecmp(list[i].name,list[j].name)<0)
                {
                    aInt=list[i].id;
                    list[i].id=list[j].id;
                    list[j].id=aInt;

                    strcpy(auxN,list[i].name);
                    strcpy(list[i].name,list[j].name);
                    strcpy(list[j].name,auxN);

                    strcpy(auxLN,list[i].lastName);
                    strcpy(list[i].lastName,list[j].lastName);
                    strcpy(list[j].lastName,auxLN);

                    aAux=list[i].edad;
                    list[i].edad=list[j].edad;
                    list[j].edad=aAux;

                    aInt=list[i].idInstrumento;
                    list[i].idInstrumento=list[j].idInstrumento;
                    list[j].idInstrumento=aInt;

                    aInt=list[i].idOrquesta;
                    list[i].idOrquesta=list[j].idOrquesta;
                    list[j].idOrquesta=aInt;

                    aInt=list[i].isEmpty;
                    list[i].isEmpty=list[j].isEmpty;
                    list[j].isEmpty=aInt;
                }
            }
        }

    }
    else
    {
        printf("No hay campos para ordenar.\n");
        getchar();
    }


return flag;
}

/** \brief print the content of employees array
*
* \param list Employee*
* \param length int
* \return int
*
*/
int printEmployees(Employee* list, int length)
{
    int i;
    barra(72);
    printf("|%6s|%51s|%51s|%51s|\n","ID","Nombre","Apellido","idInstrumento");
    barra(72);

    for(i=0;i<length;i++)
    {
        if(list[i].isEmpty==0)
        {
            printf("|%6d|%51s|%51s|%51s|\n",list[i].id,list[i].name,list[i].lastName,list[i].idInstrumento);
        }
    }
    barra(72);

return 0;
}

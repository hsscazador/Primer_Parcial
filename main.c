//https://github.com/hsscazador/Primer_Parcial.git

#include <stdio.h>
#include <stdlib.h>
#include "Employees.h"
#include "Funciones.h"
#define AConst 1000


int main()
{
    int flag=-1,flagI=-1,flagO=-1;
    int ID=AConst;
    int aux, index,idAux,Bandera;
    char seguir='s';


    Employee padron[Len];
    flag=initEmployees(padron, Len);

    Orquesta GrupoDeMusicos[LenOrq];
    flag=initOrquesta(GrupoDeMusicos, LenOrq);

    Instumento ArtilujiosMusicales[lenInst];
    flag=initInstrumento(ArtilujiosMusicales, lenInst);

    do
    {
        switch(menu("1- Alta Orquesta\n2- Eliminar Orquesta\n3- Imprimir Orquesta\n4- Abregar Musico"
                    "\n5- Modificar Musico\n6)- Eliminar Musico\n7- Imprimir Musico\n8Agregar Instrumento\n9- Imprimir Instrumento\n0-  Salir\n",0,9))
        {
            case 1: //ALTAS
                aux=obtenerEspacioLibre(padron,Len);

                if(aux != -1)
                {
                    agregarPersona(padron,Len,ID);

                    ID++;
                    flag=1;
                }
                else
                {
                    printf("No hay campos vacios para el ingreso.\n");
                    getchar();
                }

            break;

            case 2: //MODIFICAR


                if(aux!=-1&&flag==1)
                {
                    idAux=menu("\nIngrese ID:",AConst,AConst+Len);

                    index=findEmployeeById(padron, Len,idAux);
                    promedios(padron, EstaCalculo, Len, idAux, 0);
                    EditString(padron,index);
                    promedios(padron, EstaCalculo, Len, idAux, 1);

                }
                else
                {
                    printf("Todos los campos estan vacios\n");
                }

                break;

            case 3://BAJA
                if(flag==1)
                {
                   aux=menu("\nIngrese ID:",AConst,AConst+Len);

                   Bandera=removeEmployee(padron,Len,aux);
                   if(Bandera==0)
                   {
                       promedios(padron, EstaCalculo, Len, aux, 0);
                   }
                }
                else
                {
                    printf("Todos los campos estan vacios\n");
                }

                //system("PAUSE");
                getchar();

                break;
            case 4://INFORMAR

                 if(flag==1)
                {
                    index=menu("\nOpciones de orden\n1 - Acendente\n2 - Decendente\nOrdenar: ",1,2);
                    if(index!=1)
                    {
                        index=0;
                    }
                    else
                    {
                        index=1;
                    }

                    sortEmployees(padron, Len, index);
                }
                else
                {
                    printf("Todos los campos estan vacios\n");
                }
                printEmployees(padron,Len);
                printf("Sueldo Maximo: %.2f  minimo %.02f  promedio %.2f\n", EstaCalculo->Max, EstaCalculo->Min, EstaCalculo->promedio);
                system("PAUSE");

                break;
            case 5:
                seguir = 'n';
                break;

        }

        system("cls");
    }while(seguir=='s');

    return 0;
}

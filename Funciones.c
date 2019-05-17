#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "Employees.h"
#include "Funciones.h"
#include "Orquesta.h"
#include "Instrumento.h"



/**
* \brief Funcion para crear un menu de opciones
* \param Son los items del menu de opciones.
* \param Define el rango minimo de opciones.
* \param Define el rango maximo de opciones.
* \return Devuelve la opcion elegida por el usuario.
*/
int menu(char texto[],int Min,int Max)
{
  int opcion=0;
  char Dato[4000];

  printf("\n%s\nOpcion: ",texto);

  gets(Dato);

  while(validarInt(Dato,Min,Max)!=1)
  {
    printf("\nIngreso invalido. \nIngrese opcion valida.\n\n%s\nOpcion: ",texto);

    gets(Dato);

  }

  opcion=atoi(Dato);
  return opcion;
}

/** \brief Valida que se devuelva entre los valores S y N
 *
 * \param Ingresa string de texto a mostrar.
 * \param Salida que se ingrese s o n
 * \return 1 o 0
 *
 */

int valSyN(char Texto[])
{
    int flag=-1;
    char DatoRespuesta[500];
    char respuesta;

    printf("\n%s", Texto);
    gets(DatoRespuesta);

    do
    {
        respuesta=DatoRespuesta[0]; //guarda la respuesta en una variable char

        respuesta=tolower(respuesta); // cambia el formato a minusculas

        if(respuesta == 's' || respuesta == 'n') // evalua si la respuesta es correcta
        {
            if(respuesta == 's')
            {
                //list[index].isEmpty=1;
                flag=1;
            }
            else
            {
                //list[index].isEmpty=0;
                flag=0;
            }

        }
        else
        {
            do
            {
                printf("Ingreso Invalido\n Escriba S o N: \n");
                gets(DatoRespuesta);
            }while(validarChar(DatoRespuesta)!=1); // valida que la entrada sea de un solo caracter
        }
    }while(respuesta != 's' && respuesta != 'n'); // doble validacion de la respuesta.

    return flag;
}


/**
* \brief funcion para imprimir x cantidad '-' para estetica.
*/
void barra(int cant)
{
    int i;
    for(i=0;i<cant;i++) printf("-");
    printf("\n");
}

/**
* \brief Funcion para verificar el tamaño del ingreso del usuario.
* \param Entrada el usuario
* \param Tamaño minimo.
* \param Tamaño maximo.
* \return Devuelve 1 si el String es correcto o devuelve 0 si es incorrecto.
*
*/
int validarString(char Dato[],int min,int max)
{
    int tam ,aux=0;

    tam=strlen(Dato);

    if(tam >= min && tam <= max)
    {
        aux=1;
    }
    return aux;
}

/**
* \brief Funcion para limpiar el cache como el fflush.
*/
void flush_in()
{
  int cache;
  while( (cache = fgetc(stdin)) != EOF && cache != '\n' )
    {}
}


/**
* \brief Funcion para verificar si el usuario ingreso un char
* \param Recibe la entrada por teclado del usuario
* \return Devuelve 1 si es un char y devuelve 0 si no lo es.
*
*/
int validarChar(char Dato[])
{
    int tam, aux=0;

    tam=strlen(Dato);

    if(tam==1)
    {
        aux=1;
    }

    return aux;
}

/**
* \brief Trasnforma una cadena de numeros a un entero(int).
* \param Recibe la cadena de numeros.
* \return Devuelve la cadena transformado a un entero.
*
*/
int cadena_entero(char numero[])
{
    int num=0; //RETURN
    int aux=strlen(numero); // CARGA EN AUX LA CANTIDAD DE ELEMENTOS DEL ARRAY
    int i; // AUX CONTADOR
    int digito; // AUXILIAR PARA OBTENER LOS DIGITOS

    for(i=aux;i>0;i--)
    {
        digito=numero[i-1]-48; // TRANSFORMA EL ELEMENTO A UN DIGITO ENTERO
        num=num+(digito*pow(10,aux-i)); // ARMA EL NUMERO FINAL digito*10^n

    }

    return num;
}


/**
* \brief Obtieve el primer espacio libre
* \param recibe la estructura completa
* \param recibe el len de la estructura
* \return devuele el indice libre, sino encontro libres devuelve -1
*
*/
int obtenerEspacioLibre(Employee* lista,int len)
{
    int i;
    int indice=-1;

    for(i=0;i<len;i++)
    {
        if(lista[i].isEmpty==1)
        {
            indice=i;

            break;
        }
    }
    return indice;
}


/**
* \brief Obtieve el primer espacio libre
* \param recibe la estructura completa
* \param recibe el len de la estructura
* \return devuele el indice libre, sino encontro libres devuelve -1
*
*/
int obtenerEspacioOrquesta(Orquesta* lista,int len)
{
    int i;
    int indice=-1;

    for(i=0;i<len;i++)
    {
        if(lista[i].isEmpty==1)
        {
            indice=i;

            break;
        }
    }
    return indice;
}

/**
* \brief Obtieve el primer espacio libre
* \param recibe la estructura completa
* \param recibe el len de la estructura
* \return devuele el indice libre, sino encontro libres devuelve -1
*
*/
int obtenerEspacioInstrumento(Instumento* lista,int len)
{
    int i;
    int indice=-1;

    for(i=0;i<len;i++)
    {
        if(lista[i].isEmpty==1)
        {
            indice=i;

            break;
        }
    }
    return indice;
}


/**
* \brief Funcion para agregar una persona con todos sus datos
* \param Recibe la estructura completa
* \param Recibe el len tamaño
* \return Devuele 1 si el usuario confirmo la operacion o 0 sino la confirmo.
*
*/
int agregarPersona(Employee* list,int len, int ID)
{

    char DatoNombre[500]; // auxialiar para almacenar temporalmente el name
    char DatolastName[500]; // auxiliar para almacenar temporalmente el apellido
    char idInstrumento[500]; // Dato para validar del id Instrumento
    char idOrquesta[500]; // Dato para validar del id Orquesta
    int Iaux; // Auxiliar enteros
    float Faux; //Auxiliar flotantes


    int aux=0; //  variable para validar el ingreso de la respuesta (doble validacion)
    int retorno;

    printf("\nIngrese el name: "); // pide el name y lo guarda en el auxiliar
    gets(DatoNombre);

    while(validarString(DatoNombre,3,51)!=1) // verifica que sea un string entre 3 y 51 caracteres
    {
        printf("\nIngreso invalido. \nEscriba el name (3 a 51 caracteres)\n");
        printf("\nIngrese el name: ");
        gets(DatoNombre);

    }

    printf("\nIngrese Apellido: "); // pide apellido  y lo guarda en el auxiliar
    gets(DatolastName);

    while(validarString(DatolastName,3,51)!=1) // verifica que sea un string entre 3 y 51 caracteres
    {
        printf("\nIngreso invalido. \nEscriba el Apellido (3 a 51 caracteres)\nIngrese el Apellido: ");

        gets(DatolastName);
    }


    printf("\nIngrese id Orquesta: "); // ingresa la id Orquesta
    gets(idOrquesta);

    while(validarInt(idOrquesta,1,99)!= 1) // verifica que el usuario ingreso un entero
    {
        printf("\nIngreso invalido. \nEscriba el id Orquesta (Entre 1 y 99)\nIngrese id Orquesta: ");

        gets(idOrquesta);
    }

     printf("\nIngrese id Instrumento: "); // ingresa la edad
    gets(idInstrumento);

    while(validarFloat(idInstrumento,1,99)!= 1) // verifica que el usuario ingreso un flotante
    {
        printf("\nIngreso invalido. \nEscriba el id Instrumento (Entre %d y %d)\nIngrese id Instrumento: ",SalMin,SalMaximo);

        gets(idInstrumento);
    }


    Iaux=atoi(idOrquesta); //guarda los numeros del string en una variable tipo int
    Faux=atof(idInstrumento); //guarda los numeros del string en una variable tipo float

    printf("\nLos siguientes datos son validos?\nNombre: %s \nApellido: %s \nSector: %d \nSalario: %.2f",DatoNombre,DatolastName,Iaux,Faux);

    aux=valSyN("\nDesea confirmar la operacion? s/n: \n");

    if(aux== 1) // confirma la operacion . guarda los datos en los campos definitivos
    {
       retorno=addEmployee(list,  len,  ID, DatoNombre, DatolastName, Faux, Iaux);
    }
    else
    {
        retorno=aux;
    }

    return retorno;


} // FIN agregar



/**
* \brief Valida si el usuario ingreso un entero positivo
* \param Recibe como parametro una cadena de caracteres
* \return Devuelve 0 si la cadena posee letras o signos y no esta en el rango correcto. Devuelve 1 si la cadena posee numeros y esta dentro del rango.
*
*/
int validarInt(char Dato[],int min,int max)
{
    int aux=1; // RETURN
    int valAux; // AUXILIAR
    int i=0; // AUXILIARCONTADOR
    int numero;

    valAux=strlen(Dato); // CARGA EN AUX LA CANTIDAD DE ELEMENTOS DEL ARRAY

	while( i<valAux && aux == 1)
    {
	  if(isdigit(Dato[i])!=0) // isdigit devuelve 1 si es numero o 0 sino lo es.
      {
	      i++;
      }
	  else
      {
	      aux=0;
      }
	}
	if(aux==1)
	{
        numero=atoi(Dato);

        if(numero < min || numero > max)
        {
            aux=0;
        }

	}

    return aux;
}

/**
* \brief Valida si el usuario ingreso un flotante positivo
* \param Recibe como parametro una cadena de caracteres
* \return Devuelve 0 si la cadena posee letras o signos y no esta en el rango correcto. Devuelve 1 si la cadena posee numeros y esta dentro del rango.
*
*/
int validarFloat(char Dato[],int min,int max)
{
    int aux=1; // RETURN
    int valAux; // AUXILIAR
    int i=0; // AUXILIARCONTADOR
    int numero;

    valAux=strlen(Dato); // CARGA EN AUX LA CANTIDAD DE ELEMENTOS DEL ARRAY
printf("valor de valAux: %d", valAux);
	while( i<valAux && aux == 1)
    {
        printf("\nValor de iteracion");
	  if(isdigit(Dato[i])!=0) // isdigit devuelve 1 si es numero o 0 sino lo es.
      {
	      aux=1;
      }
	  else
      {
	      aux=0;
      }

      if(Dato[i]==',')// paso la coma a punto.
      {
          Dato[i]='.';
      }
      if(Dato[i]=='.') // valida que el punto de flotante esta dentro de los datos validos, volviendo a poner en 1 a aux
      {
          aux=1;
      }
      i++;
	}
	if(aux==1)
	{
        numero=atof(Dato); //convierte en flotante

        if(numero < min || numero > max)
        {
            aux=0;
        }

	}

    return aux;
}

int EditString(Employee* list,int id)
{
    char DatoNombre[500]; // auxialiar para almacenar temporalmente el name
    char DatolastName[500]; // auxiliar para almacenar temporalmente el apellido
    char idInstrumento[500]; // Dato para validar del id Instrumento
    char idOrquesta[500]; // Dato para validar del id Orquesta
    char seguir='n';
    int Iaux; // Auxiliar enteros
    float Faux; //Auxiliar flotantes
    int flag=-1;
    int aux=-1; //  variable para validar el ingreso de la respuesta (doble validacion)
    int retorno;

    system("cls");
    printf("\nDatos a modificar\n");
    barra(72);
    printf("|%6s|%51s|%51s|%3s|%6s|\n","ID","Nombre","Apellido","id Orquesta","Sueldo");
    barra(72);

    printf("|%6d|%51s|%51s|%3d|%6.2f|\n",list[id].id,list[id].name,list[id].lastName,list[id].id Orquesta,list[id].salary);
    barra(72);


    do
    {
        switch(menu("Menu de opciones para editar.\n1- Nombre.\n2- Apellido\n3- id Instrumento.\n4- id Orquesta\n5- Salir\n",1,5))
        {
            case 1: //Nombre
            {
                aux=list[id].isEmpty;

                if(aux==0 && (list != NULL))
                {
                    printf("\nIngrese el name: "); // pide el name y lo guarda en el auxiliar
                    gets(DatoNombre);

                    while(validarString(DatoNombre,3,51)!=1) // verifica que sea un string entre 3 y 51 caracteres
                    {
                        printf("\nIngreso invalido. \nEscriba el name (3 a 51 caracteres)\n");
                        printf("\nIngrese el name: ");
                        gets(DatoNombre);

                    }
                    printf("\nEL datos es validos?\nNombre: %s ",DatoNombre);

                    flag=valSyN("\nES correcto? s/n: \n");

                    if(flag== 1) // confirma la operacion . guarda los datos en los campos definitivos
                    {
                        strcpy(list[id].name,DatoNombre);
                        retorno=flag;
                    }
                    else
                    {
                        printf("\nNo se realiza cambio.");
                        retorno=flag;
                    }
                }
                else
                {
                    printf("\nEl campo invalido.\n");
                    getchar();
                    retorno=flag;
                }
            }
            break;

            case 2: //Apellido

                aux=list[id].isEmpty;

                if(aux==0 && list!=NULL)
                {
                    printf("\nIngrese Apellido: "); // pide apellido  y lo guarda en el auxiliar
                    gets(DatolastName);

                    while(validarString(DatolastName,3,51)!=1) // verifica que sea un string entre 3 y 51 caracteres
                    {
                        printf("\nIngreso invalido. \nEscriba el Apellido (3 a 51 caracteres)\n");
                        printf("\nIngrese el Apellido: ");
                        gets(DatolastName);

                    }
                    printf("\nEL datos es validos?\nApellido: %s ",DatolastName);

                    flag=valSyN("\nES correcto? s/n: \n");

                    if(flag== 1) // confirma la operacion . guarda los datos en los campos definitivos
                    {
                        strcpy(list[id].lastName,DatolastName);
                        retorno=flag;
                    }
                    else
                    {
                        printf("\nNo se realiza cambio.");
                        retorno=flag;
                    }
                }
                else
                {
                    printf("\nEl campo invalido.\n");
                    getchar();
                    retorno=flag;
                }

            break;

            case 3: //id Instrumento

                aux=list[id].isEmpty;

                if(aux==0 && list!=NULL)
                {
                    printf("\nIngrese id Instrumento: "); // pide apellido  y lo guarda en el auxiliar
                    gets(idInstrumento);

                    while(validarFloat(idInstrumento,SalMin,SalMaximo)!= 1) // verifica que el usuario ingreso un flotante
                    {
                        printf("\nIngreso invalido. \nEscriba el id Instrumento (Entre %d y %d)\nIngrese id Instrumento: ",SalMin,SalMaximo);
                        gets(idInstrumento);

                    }
                    printf("\nEL datos es validos?\nSalario: %s ",idInstrumento);

                    flag=valSyN("\nES correcto? s/n: \n");

                    if(flag== 1) // confirma la operacion . guarda los datos en los campos definitivos
                    {
                        Faux=atof(idInstrumento); //guarda los numeros del string en una variable tipo float
                        list[id].salary=Faux;
                        retorno=flag;
                    }
                    else
                    {
                        printf("\nNo se realiza cambio.");
                        retorno=flag;
                    }
                }
                else
                {
                    printf("\nEl campo invalido.\n");
                    getchar();
                    retorno=flag;
                }
            break;

            case 4: //id Orquesta
                aux=list[id].isEmpty;

                if(aux==0 && list!=NULL)
                {
                    printf("\nIngrese id Orquesta: "); // ingresa la id Orquesta
                    gets(idOrquesta);

                    while(validarInt(idOrquesta,1,99)!= 1) // verifica que el usuario ingreso un entero
                    {
                        printf("\nIngreso invalido. \nEscriba el id Orquesta (Entre 1 y 99)\nIngrese id Orquesta: ");
                        gets(idOrquesta);

                    }
                    printf("\nEL datos es validos?\nSector: %s ",idOrquesta);

                    flag=valSyN("\nES correcto? s/n: \n");

                    if(flag== 1) // confirma la operacion . guarda los datos en los campos definitivos
                    {
                        Iaux=atoi(idOrquesta); //guarda los numeros del string en una variable tipo int
                        list[id].id Orquesta=Iaux;
                        retorno=flag;
                    }
                    else
                    {
                        printf("\nNo se realiza cambio.");
                        retorno=flag;
                    }
                }
                else
                {
                    printf("\nCampo invalido.\n");
                    getchar();
                    retorno=flag;
                }
            break;

            case 5:
                seguir = 'n';

            break;
        }
    }while(seguir=='s');


    return retorno;

}
/** \brief calcula maximo, minimo y promedio
 *
 * \param recibe puntero Employee* list y ConEstadistica* Estadistica

 * \param
 * \return void
 *
 */


void promedios(Employee* list, ConEstadistica* Estadistica, int len, int ID, int op)
{
    int index;
    index=findEmployeeById(list,len,ID);


    if(op==1)
    {
        Estadistica->Total=Estadistica->Total + list[index].salary;
        Estadistica->contador++;
    }
    if(op==0)
    {
        Estadistica->Total-=list[index].salary;
        Estadistica->contador--;
    }
    if(Estadistica->Max<list[index].salary)
    {
        Estadistica->Max=list[index].salary;
    }
    if(Estadistica->Min>list[index].salary)
    {
        Estadistica->Min=list[index].salary;
    }

    Estadistica->promedio=Estadistica->Total/Estadistica->contador;

}


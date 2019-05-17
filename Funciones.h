#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define Len 100
#define SalMin 100
#define SalMaximo 50000

int menu(char texto[],int Min,int Max);
int valSyN(char Texto[]);

int validarInt(char Dato[],int min,int max);
int validarFloat(char Dato[],int min,int max);
int validarChar(char Dato[]);
int validarString(char Dato[],int min,int max);
void flush_in();
void barra(int);

int obtenerEspacioLibre(Employee* lista,int len);
int agregarPersona(Employee* list,int len, int ID);
int EditString(Employee* list,int id);
void promedios(Employee* list, ConEstadistica* Estadistica, int len, int ID, int op);






#endif // FUNCIONES_H_INCLUDED

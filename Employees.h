#ifndef EMPLOYEES_H_INCLUDED
#define EMPLOYEES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


#define LenMusico 1000

typedef struct
{
int id;
char name[51];
char lastName[51];
int edad;
int idInstrumento;
int idOrquesta;
int isEmpty;
} Employee;

int initEmployees(Employee* list, int len);
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);
int findEmployeeById(Employee* list, int len,int id);
int removeEmployee(Employee* list, int len, int id);
int sortEmployees(Employee* list, int len, int order);
int printEmployees(Employee* list, int length);


#endif // EMPLOYEES_H_INCLUDED

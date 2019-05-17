#ifndef ORQUESTA_H_INCLUDED
#define ORQUESTA_H_INCLUDED
typedef struct
{
    char name[51];
    char Lugar[51];
    char Tipo[51];
    int id;
    int isEmpty;
} Orquesta;

int initOrquesta(Orquesta* list, int len);
int addOrquesta(Orquesta* list, int len, int id, char name[],char Lugar[],char Tipo[]);
int findOrquesta(Orquesta* list, int len,int id);
int removeOrquesta(Orquesta* list, int len, int id);
int sortOrquesta(Orquesta* list, int len, int order);
int printOrquesta(Orquesta* list, int length);




#endif // ORQUESTA_H_INCLUDED

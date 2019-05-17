#ifndef INSTRUMENTO_H_INCLUDED
#define INSTRUMENTO_H_INCLUDED

typedef struct
{
    char name[51];
    char Tipo[51];
    int id;
    int isEmpty;
} Instumento;

int initInstrumento(Instrumento* list, int len);
int addInstrumento(Instrumento* list, int len, int id, char name[],char Tipo[]);
int findInstrumentoId(Instrumento* list, int len,int id);
int removeInstrumento(Instrumento* list, int len, int id);
int sortInstrumento(Instrumento* list, int len, int order);
int printInstrumento(Instrumento* list, int length)



#endif // INSTRUMENTO_H_INCLUDED

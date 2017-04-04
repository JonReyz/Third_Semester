#ifndef _LISTAG
#define _LISTAG


#include "listaG.h"


typedef struct Graphl Graphl;

void createGraphl(Graphl **, int);
//int **createMatrix(int );
void imprimirGraphl(Graphl *);
void makeTranpost(Graphl *);

void findingArcs(Graphl *, int);

void addGraph(Graphl **,int, int,int);
void adicionandoG(Graphl **,int, int, int);

void removeEdge(Graphl *,int, int);
void removendoG(Graphl *,int, int);

void menorPesol(Graphl *);
void destroyGraphl(Graphl *);

#endif
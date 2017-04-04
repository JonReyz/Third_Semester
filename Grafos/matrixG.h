#ifndef _MATRIXG
#define _MATRIXG


#include "matrixG.h"


typedef struct Graph Graph;

void createGraph(Graph **, int);
void nullified(int, int*);
int **createMatrix(int );
void imprimirGraph(Graph *);
void tranpost(Graph *);
void adjacenteGraph(Graph *, int);
void addAGraphND(Graph *,int, int,int);
void addAGraphD(Graph *,int, int, int);
void removeAGraphND(Graph *,int, int);
void removeAGraphD(Graph *,int, int);
void menorPesoD(Graph *);
void menorPesoND(Graph *);
void destroyGraph(Graph *);

#endif
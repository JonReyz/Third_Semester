#include <stdlib.h>
#include <stdio.h>

typedef struct Graph {
	int n;
	int **matrix;
} Graph;	
// função que inicia a matriz com -1
void nullified(int n, int *matrix){
	int i;
	for(i=0;i<n;i++){
		matrix[i] = -1;
	}
}
//cria a matriz e já a inicializa com peso -1
int **createMatrix(int n){
	int i;
	int **matrix = malloc(sizeof(int*)*n);
	for(i=0;i<n;i++){
		matrix[i] = calloc(sizeof(int),n);
		nullified(n, matrix[i]);
	}

	return matrix;
}
// cria o grapho por referencia
void createGraph(Graph **g, int n){
	*g = malloc(sizeof(Graph)*1);
	(*g)->matrix = createMatrix(n);
	(*g)->n = n;
}


void imprimirGraph(Graph *graph){
	int i,j;
	for(i=0;i<graph->n;i++){
		for(j=0;j<graph->n;j++){
			if(graph->matrix[i][j] == -1) printf(". ");
			else printf( "%d ",graph->matrix[i][j]);
		}
		printf("\n");
	}
}
//printa a matriz de maneira transposta
void tranpost(Graph *graph){
	int i,j;
	for(i=0;i<graph->n;i++){
		for(j=0;j<graph->n;j++){
			if(graph->matrix[j][i] == -1) printf(". ");
			else printf( "%d ",graph->matrix[j][i]);
		}
		printf("\n");
	}
}

// printa os vértices adj
void adjacenteGraph(Graph *graph, int v){
	int i;
	for(i=0;i<graph->n;i++){
		if(graph->matrix[v][i]!= -1) printf( "%d ",i);
	}
	printf("\n");
}
// realiza a inserção de um grafo não direcionado
void addAGraphND(Graph *graph,int v1, int v2, int peso){
	graph->matrix[v1][v2] = peso;
	graph->matrix[v2][v1] = peso;
}
//realiza a remoção de um grago não direcionado
void removeAGraphND(Graph *graph,int v1, int v2){
	graph->matrix[v1][v2] = -1;
	graph->matrix[v2][v1] = -1;	
}

//realiza a remoção de um grago direcionado
void addAGraphD(Graph *graph,int v1, int v2, int peso){
	graph->matrix[v1][v2] = peso;
}
//realiza a remoção de um grago direcionado
void removeAGraphD(Graph *graph,int v1, int v2){
	graph->matrix[v1][v2] = -1;	
}

void menorPesoD(Graph *graph){
	int i,j;
	int min1 = 123123;
	int v1, v2;
	for(i=0;i<graph->n;i++){
		for(j=0;j<graph->n;j++){
			if(graph->matrix[i][j] < min1 && graph->matrix[i][j] != -1){
				min1 = graph->matrix[i][j];
				v1 = i;
				v2 = j;
			}
		}
	}
	printf("%d %d\n",v1,v2);
}

void destroyGraph(Graph *g){
	int i;
	for(i=0;i<g->n;i++){
		free(g->matrix[i]);
	}
	free(g);
}



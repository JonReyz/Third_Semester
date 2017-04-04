#include <stdlib.h>
#include <stdio.h>
#include "matrixG.h"

typedef struct node Node;

typedef struct node {
	int vertex;
	int peso;
	Node *prox;

} Node;

typedef struct graphl {
	int n;
	Node **list;
} Graphl;	

// retorna um no com o vertica e o peso
Node *createNode(int vertex, int peso){
	Node *no  = malloc(sizeof(Node));
	no->vertex = vertex;
	no->peso = peso;
	no->prox = NULL;

	return no;
}
// retorna um vetor de nos
Node **createNodeList(int n){
	int i;
	Node **list = malloc(sizeof(Node*)*n);
	for(i=0;i<n;i++){
		list[i] = malloc(sizeof(Node));
		list[i] = createNode(i,0);
	}

	return list;
}


void createGraphl(Graphl **g, int n){
	(*g) = malloc(sizeof(Graphl));
	//criei vetores de nós
	(*g)->list = createNodeList(n);
	(*g)->n = n;
}

void imprimirList(Node *no){
	while(no!=NULL){
		printf("%d(%d) ",no->vertex,no->peso);
		no = no->prox;
	}
}
void imprimirGraphl(Graphl *g){
	int i;
	for(i=0;i<g->n;i++){
		printf("%d. ",g->list[i]->vertex);
		imprimirList(g->list[i]->prox);
		printf("\n");
	}
}



void addGraph(Graphl **g, int v1, int v2, int peso){
	Node *node = createNode(v2,peso);
	Node *aux = (*g)->list[v1];
	Node *aux2;
	aux2 = aux;
	while(aux->prox != NULL){
		aux = aux->prox;
		//ordenando durante a inserção
		if(aux->vertex > node->vertex){
			node->prox = aux;
			aux2->prox = node;
			return;
		}
		//se ja inserir um vertice igual, apenas substitui o peso
		if(aux->vertex == node->vertex){
			aux->peso = peso;
			return;
		}
		aux2 = aux;
	}
		aux->prox =node;
}
//realiza a adição de um grago não direcionado
void adicionandoG(Graphl **g, int v1,int v2 ,int peso){
	addGraph(g,v1,v2,peso);
	addGraph(g,v2,v1,peso);
}


// remove um vertice
void removeEdge(Graphl *g, int v1, int v2){
	Node *aux;
	Node *node;
	aux = g->list[v1];

	node = aux;
	while(aux->prox!=NULL){
		aux = aux->prox;
		if(aux->vertex == v2){
			node->prox = aux->prox;
			free(aux);
			return;
		}
		node = aux;
	}
	return;
}

void removendoG(Graphl *g, int v1,int v2){
	removeEdge(g,v1,v2);
	removeEdge(g,v2,v1);
}


void menorPesol(Graphl *g){
	int i;
	int min, v1, v2;
	Node *header, *node;
	v1 = 0;
	v2 = 0;
	min = 123123123;
	for(i=0; i <g->n;i++){
		header = g->list[i];
		//printf("%d", i);
		node = header->prox;
		while(node!=NULL){
			if(node->peso < min){
				v1 = i;
				v2 = node->vertex;
				min = node->peso;
			}
			node = node->prox;
		}
	}
	printf("%d %d\n",v1,v2);
}

//cria uma matrix com os valores existentes no grafo para ser utilizado na transposição
int **makeMatrix(Graphl *g){
	int i;
	Node *aux;
	int **matrix = malloc(sizeof(int* ) * g->n);
	for(i=0;i< g->n;i++){
		matrix[i] = malloc(sizeof(int) * g->n);
		nullified(g->n,matrix[i]);
		aux = g->list[i];
		while(aux->prox!=NULL){
			aux = aux->prox;
			matrix[i][aux->vertex] = aux->peso;
		}	
	}

	return matrix;
}
//printa a matrix com os dados do grafo de maneira transposta
void printMatrix(int **matrix, int n){
	int i,j;
	for(i=0;i<n;i++){
	 	printf("%d. ",i);
		for(j=0;j<n;j++){
			if(matrix[j][i]!= -1){
				printf( "%d(%d) ",j,matrix[j][i]);
			}
		}
		printf("\n");
	}
}
void makeTranpost(Graphl *g){
	int **matrix = makeMatrix(g);
	printMatrix(matrix,g->n);
	return;
}

//procura os vertices adj
void findingArcs(Graphl *g, int v1){
	Node *no = g->list[v1];
	while(no->prox!=NULL){
		no = no->prox;
		printf("%d ",no->vertex);
	}
	printf("\n");
}


//função recursiva para apagar uma lista
void destroyNode(Node *no){
	if(no->prox!=NULL) destroyNode(no->prox);
	free(no);
}

void destroyGraphl(Graphl *g){
	int i;
	for(i=0;i<g->n;i++){
		destroyNode(g->list[i]);
	}
	free(g);
}
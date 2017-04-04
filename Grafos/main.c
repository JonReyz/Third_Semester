#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "matrixG.h"
#include "listaG.h"

int main(){
	char dir,est;
	int nVertex, nEdges;
	int i, v1, v2, peso;
	Graph *graph;
	Graphl *graphl;
	char *option = malloc(sizeof(char) * 2);
	scanf("%c %c %d %d",&dir,&est,&nVertex,&nEdges);
	if(est == 'M') createGraph(&graph,nVertex);
	else createGraphl(&graphl,nVertex);
	for(i=0;i<nEdges;i++){
		scanf("%d %d %d", &v1, &v2, &peso);
		if(dir == 'G' && est == 'M') addAGraphND(graph,v1, v2, peso);
		if(dir == 'D' && est == 'M') addAGraphD(graph,v1, v2, peso);
		if(dir == 'G' && est == 'L') adicionandoG(&graphl,v1, v2, peso);
		if(dir == 'D' && est == 'L') addGraph(&graphl,v1, v2, peso); 

	}
	while(scanf("%s",option)!=EOF){
		if((strcmp(option,"IG") == 0) && est == 'M')  {
			imprimirGraph(graph);
		}
		if((strcmp(option,"VA")== 0) && est == 'M'){
			scanf("%d",&v1);
			//printf("eeeentru");
			adjacenteGraph(graph, v1);
		}	
		if((strcmp(option,"AA")==0) && est == 'M'){
			scanf("%d %d %d",&v1,&v2, &peso);
			if(dir == 'D') addAGraphD(graph,v1, v2,peso);
			else addAGraphND(graph,v1, v2,peso);
		}
		if((strcmp(option,"RA")== 0) && est == 'M'){
			scanf("%d %d",&v1, &v2);
			if(dir == 'D') removeAGraphD(graph,v1, v2);
			else removeAGraphND(graph,v1, v2);
		}
		if(((strcmp(option,"IT")== 0) && (est == 'M')) && (dir == 'D')){
				//printf("euuu %c ", dir);
				tranpost(graph);
		} 
		if((strcmp(option,"MP")== 0) && est == 'M'){
			if(dir == 'D') menorPesoD(graph);
			else menorPesoD(graph);
		}
		if((strcmp(option,"IG") == 0) && est == 'L')  {
			imprimirGraphl(graphl);
		}
		if((strcmp(option,"VA")== 0) && est == 'L'){
			scanf("%d",&v1);
			findingArcs(graphl, v1);
		}	
		if((strcmp(option,"AA")==0) && est == 'L'){
			scanf("%d %d %d",&v1,&v2, &peso);
			if(dir == 'D') addGraph(&graphl,v1, v2,peso);
			else adicionandoG(&graphl,v1, v2,peso);
		}
		if((strcmp(option,"RA")== 0) && est == 'L'){
			scanf("%d %d",&v1, &v2);
			if(dir == 'D') removeEdge(graphl,v1, v2);
			else removendoG(graphl,v1, v2);
		}
		if(((strcmp(option,"IT")== 0) && (est == 'L')) && (dir == 'D')){
				makeTranpost(graphl);
		} 
		if((strcmp(option,"MP")== 0) && est == 'L'){
			menorPesol(graphl);
		}
	}

	if(est == 'M'){
		destroyGraph(graph);
	}
	else destroyGraphl(graphl);

	free(option);

	return 0;
}
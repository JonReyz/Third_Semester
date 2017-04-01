#include <stdlib.h>
#include <stdio.h>



int main(){

	int weeks;
	int i,n,j;
	int people;

	int s, c;

	int sum = 0;
	int r;
	//240 - 25 = 215 - 10 = 205
	// 4*60 - 10 - maior tempo para jantar
	// o resultado é o maior tempo de todos os participantes para pedir e comer;
	scanf("%d",&weeks);
	for(i=0;i<weeks;i++){
		scanf("%d",&n);
		for(j=0;j<n;j++){
			scanf("%d %d", &s, &c);
			if((s+c) > sum )sum = s+c;
		}
		r = 230 - sum;
		//sum = 230 - sum;

		if(r<0) printf("0\n");
		else printf("%d\n",r);
		//printf("%d\n",230 - sum);
	}
}
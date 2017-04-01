#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct  PESSOA{
	int size; // 20 + 24 + 4
	char *nome;
	int n;
	char *rua;
	int r;
	int num;
	int p;
	char *complemento;
	int c;
} Pessoa;

char *readline(int *i){
	//int 
	i[0]=0;
	char c;
	char *string = NULL;
	do {
		c = fgetc(stdin);
		string = (char *) realloc(string,sizeof(char)*(i[0]+1));
		string[i[0]++]=c;
	}while(c!=10&&c!=EOF);
	string[i[0]-1]='\0';

	return string;
}

typedef char byte;

int main(){
	int nReg,nName,nComp,nRua;

	int size = 16;
	int quatro = 4;
	int i;
	int op;
	int iexit = 1;


	printf("Bem vindo ao Exercício 1 ;)\n");
	printf("Digite 1 para inserir um registro -------- >\n");
	printf("Digite 2 para exibir todos os registros -------- >\n");
	printf("Digite 3 para exibir um registro por rrn -------- >\n");

	scanf("%d",&op);
	fgetc(stdin);
	if(op==1){
		FILE *fp;
		fp = fopen("exe2.dat","ab"); //criando o arquivo
		if(fp == NULL) {
			printf("Erro na criação de arquivos"); //caso dê erro
			return -1;
		}
		
		Pessoa *people = malloc(sizeof(Pessoa));

		while(iexit == 1){
			 size = 16;
			 printf("Digite o nome do cadasto :\n");
			 people->nome = readline(&nName);
		 	 people->n = nName;
			 size+=nName;
			// printf("\nTamanho do %d\n",nName);
			 
			 printf("Digite o endereço do cadasto :\n");
			 people->rua = readline(&nRua);
			 people->r = nRua;
			 size+=nRua;
			// printf("\nTamanho da rua%d\n",nRua);

			 printf("Digite o complemento :\n");
			 people->complemento = readline(&nComp);
			 people->c = nComp;
			 size+=nComp;
			 //printf("Tamanho do %d\n",nComp);

			 printf("Digite o numero :\n");
			 scanf("%d",&(people->num));
			 size+=4;

			 
			 fwrite(&size,sizeof(int),1,fp);
			 fwrite(&nName,sizeof(int),1,fp);
			 fwrite(people->nome,sizeof(char),nName,fp);
			 fwrite(&nRua,sizeof(int),1,fp);
			 fwrite(people->rua,sizeof(char),nRua,fp);
			 fwrite(&quatro,sizeof(int),1,fp);
			 fwrite(&(people->num),sizeof(int),1,fp);
			 fwrite(&nComp,sizeof(int),1,fp);
			 fwrite(people->complemento,sizeof(char),nComp,fp); 

			 printf("Inserir mais um registro? (1 = Sim, 2 = Não)\n");
			 scanf("%d",&iexit);
			 fgetc(stdin);
		}
			fclose(fp);
	}


	if(op == 2 ){
		FILE *fp2 = fopen("exe2.dat","rb");
		if(fp2 == NULL) {
			printf("Arquivo não existe"); //caso dê erro
			return -1;
		}
		fseek(fp2,0, SEEK_END);
		int tam = ftell(fp2);
		int nReg;
		int jump;
		fseek(fp2,0, SEEK_SET);
		byte *bytes = malloc(sizeof(byte)*tam);
		fread(bytes,sizeof(byte),tam,fp2); //peguei todos os dados e armazenei em bytes;
		byte *aux = bytes; // crio um ponteiro auxiliar
		nReg = *((int*)aux);//pego o tamanho do registro inicial
		
		for(i=0;i<tam;){
			printf("%d",*((int*)aux));
			aux+=4; //pulo 4 bytes no ponteiro para ignorar o tamanho do registro
			i+=4;   // faço a mesma coisa com o contador para ter noção de onde estou no vetor de bytes
			jump = *((int*)aux);// a variavel jump recebe o tamanho do primeiro campo

			aux+=4; //pulo os bytes que representavam o tamanhou do campo
			i+=4;   // idem com o contador
			printf("\n Nome : %s ",aux);
			aux += jump; // recebo o tamanho do campo para realizar um pulo e chegar no proximo indicador de campo
			i+=jump;    // idem com o contador
			jump = *((int*)aux);// recebo o tamanho do próximo campo
			
			aux+=4; // pulo os 4 bytes do tamanho do campo
			i+=4;
			printf("Endereço: %s ",aux);
			aux += jump; //pulo o tamanho total do campo
			i+=jump;
			
			aux += 4;
			i+=4;
			printf("Numero: %d ",*((int*)aux));
			aux += 4;//pulo os 4 bytes do int
			i+=4;
			
			jump = *((int*)aux);
			aux+=4;
			i+=4;
			printf("Complemento :%s\n",aux);
			aux += jump;
			i+=jump;
		}
		free(bytes);
		fclose(fp2);
	}
		
	if(op == 3 ){
		FILE *fp3 = fopen("exe2.dat","rb");
		if(fp3 == NULL) {
			printf("Arquivo não existe"); //caso dê erro
			return -1;
		}
		fseek(fp3,0, SEEK_END);
		int tam2 = ftell(fp3);
		int nReg2;
		int jump2;
		int i2;
		fseek(fp3,0, SEEK_SET);
		byte *bytes2 = malloc(sizeof(byte)*tam2);
		fread(bytes2,sizeof(byte),tam2,fp3); //peguei todos os dados e armazenei em bytes;
		byte *aux2 = bytes2; // crio um ponteiro auxiliar
		int rrn;
		
		printf("Digite o RRN Desejado :\n");
		scanf("%d", &rrn);
		i2 = 0;
		i = 0;
		while(i2<rrn){ // esse laço vai contando os registros encontrados até achar o desejado
			if(i<tam2){ // se o contador ainda estiver dentro dos limites do tamanho de arquivo
				nReg2 = *((int*)aux2); // recebo o tamanho do registro
				//printf("%d ",nReg2);
				aux2+=nReg2 + 4; // faço o ponteiro pular o tamanho do registro para chegar no próximo
				i+= nReg2 + 4; // idem com o contador, para ter o controle de onde estamos no arquivo
			}		
			i2++;	
		}

		if(i>=tam2) { // caso o usuario digite um rrn inexistente
			printf("Tamanho de rrn não existente:");
			return -1;
		}
			aux2+=4;   //realizo a mesma lógica da parte 2
			jump2 = *((int*)aux2);
			aux2+=4;
			printf("\n Nome : %s ",aux2);
			aux2 += jump2;

			jump2 = *((int*)aux2);
			aux2+=4;
			printf("Endereço: %s ",aux2);
			aux2 += jump2;

			aux2 += 4;
			printf("Numero: %d ",*((int*)aux2));
			aux2 += 4;
			
			jump2 = *((int*)aux2);
			aux2+=4;
			printf("Complemento :%s\n",aux2);
			aux2 += jump2;
		free(bytes2);
		fclose(fp3);

	}





	return 0;
}
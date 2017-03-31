#include <stdlib.h>
#include <stdio.h>


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
			
			 printf("Digite o nome do cadasto :\n");
			 people->nome = readline(&nName);
		 	 people->n = nName;
			 size+=nName;
			 
			 printf("Digite o endereço do cadasto :\n");
			 people->rua = readline(&nRua);
			 people->r = nRua;
			 size+=nRua;
			 
			 printf("Digite o complemento :\n");
			 people->complemento = readline(&nComp);
			 people->c = nComp;
			 size+=nComp;
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
		int i;
		fseek(fp2,0, SEEK_SET);
		byte *bytes = malloc(sizeof(byte)*tam);
		fread(bytes,sizeof(byte),tam,fp2); //peguei todos os dados e armazenei em bytes;
		byte *aux = bytes; // crio um ponteiro auxiliar
		nReg = *((int*)aux);
		//printf("%d",nReg);
		for(i=0;i<(tam/(nReg +4));i++){
			aux+=4;
			jump = *((int*)aux);
			aux+=4;
			printf("\n Nome : %s ",aux);
			aux += jump;

			jump = *((int*)aux);
			aux+=4;
			printf("Endereço: %s ",aux);
			aux += jump;

			aux += 4;
			printf("Numero: %d ",*((int*)aux));
			aux += 4;
			
			jump = *((int*)aux);
			aux+=4;
			printf("Complemento :%s\n",aux);
			aux += jump;
		}
		fclose(fp2);
		//free(byte);
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
		nReg2 = *((int*)aux2);
		int rrn;
		printf("Digite o RRN Desejado :\n");
		scanf("%d", &rrn);
		//printf("%d",nReg);
		//for(i2=0;i2<(tam/(nReg2 +4));i2++){
			aux2+= rrn * (nReg2+4);

			aux2+=4;
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
		//}
		fclose(fp3);
		//free(byte);

	}





	return 0;
}
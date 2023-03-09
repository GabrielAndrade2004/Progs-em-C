#include<stdio.h>
#include <string.h>
#include<windows.h>
#include <locale.h> 
#define SIZE 200
char nome[SIZE] [50];
char email[SIZE] [50];
char cpf[SIZE][50];
int cpfInt[SIZE];
int op;
void cadastro();
void pesquisa();
void lista();
int main(void) {
	setlocale(LC_ALL, "");
	do{
		system("cls");
		printf("\n-----Menu-----\n1 - Cadastrar\n2 - Listar todos\n3 - Pesquisar\n4 - Sair");
		printf("\nDigite sua opção: ");
		scanf("%d", &op);
		switch(op) {
			case 1:
				cadastro();
				
				break;
			case 2:
				lista();
				break;	
			case 3:
				pesquisa();
				break;
			case 4:
				system("exit");
				break;
			default:
				printf("Opcao invalida");
				getchar();
				getchar();
				break;
		}
	}while(op!=4);
}
void lista(){
	int i;
	for(i=0;i<SIZE;i++) {
		if(cpfInt[i]>0) {
			printf("\nNome: %s\nEmail: %s\nCPF: %s", nome[i], email[i], cpf[i]);
		}else{
			break;
		}		
	}
	getchar();
        getchar();
}
void cadastro(){
	static int linha;
	int op_cadastro;
	do{
		printf("\nDigite o nome: ");
		scanf("%s", &nome[linha]);
		printf("\nDigite o email: ");
		scanf("%s", &email[linha]);
		printf("\nDigite o cpf: ");
		scanf("%s", &cpf[linha]);
		cpfInt[linha] = 1;
		printf("\nDigite 1 para continuar ou outro valor para sair: ");
		scanf("%d", &op_cadastro);
		linha++;
	}while(op_cadastro==1);
}
void pesquisa() {
	char cpfPesquisa[50];
	char emailPesquisa[50];
	int i;
	int opPesquisa;
	do{
		printf("\nDigite 1 para pesquisar por CPF ou 2 para pesquisar por email: ");
		scanf("%d", &opPesquisa);
		switch(opPesquisa) {
			case 1:
				printf("\nDigite o CPF: ");
				scanf("%s", &cpfPesquisa);
				for(i=0;i<SIZE;i++) {
					if(strcmp(cpf[i], cpfPesquisa)==0) {
						printf("\nNome: %s\nEmail: %s\nCPF: %s", nome[i], email[i], cpf[i]);
						break;
					}
					if(i==199){
						i+=1;
						//printf("\n%d",i);
					}
					if(strcmp(cpf[i], cpfPesquisa)!=0 && i == SIZE){
						printf("Pessoa não encontrada !");
					}
				}
				break;
			case 2: 
				printf("\nDigite o E-mail: ");
				scanf("%s", emailPesquisa);
				for(i=0; i<SIZE; i++) {
					if(strcmp(email[i], emailPesquisa)==0) {
						printf("\nNome: %s\nEmail: %s\nCPF: %s", nome[i], email[i], cpf[i]);
					}
					if(i==199){
						i+=1;
						//printf("\n%d",i);
					}
					else if(strcmp(email[i], emailPesquisa)!=0 && i == SIZE){
						printf("Pessoa não encontrada !");
					}
				}
				break;
			default:
				printf("\n Opção invalida");	
				break;
		}
		printf("\nDigite 1 para continuar pesquisando ou outro valor para sair: ");
		scanf("%d", &opPesquisa);
	}while(opPesquisa==1);	
}

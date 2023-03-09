#include <stdio.h>
#include <stdlib.h>

int i;
void cadastrarBolo(void);
void consultarEstoque(void);
void calcularVendasDoDia(void);
void calcularLucroPorItem(void);
void cadastrarFonecedores(void);
void consultarFornecedores(void);
void validarValores(float valor);

struct TipoBolo{
	float valor;
	char sabor[50];
	int quantidade;
}bolo[10];

struct TipoFornecedores{
	char nome[100];
	int codigo;
	char cnpj[100];
	char telefone[50];
	char email[50];
	char ramo[50];
}fornecedores[10];

main(){
int opcao;

printf("----------- Bem vindo ao Sistema de Confeitaria -----------\n");
	printf("\n>>>>>>>>>> MENU <<<<<<<<<<");
	while(opcao!=7){
	printf("\nEscolha a opcao desejada:\n");
	printf("\n1 - Cadastrar Bolo");
	printf("\n2 - Consultar Estoque");
	printf("\n3 - Calcular Vendas do Dia");
	printf("\n4 - Calcular Lucro por Item");
	printf("\n5 - Cadastrar Fornecedores");
	printf("\n6 - Consultar Fornecedores");
	printf("\n7 - Sair do Sistema");
	
	printf("\n\nOPCAO: ");
	scanf("%d", &opcao);
	fflush(stdin);
	
		switch(opcao){
			case 1: 
			cadastrarBolo();
				break;
			
			case 2: 
				consultarEstoque();
				break;
				
			case 3: 
				calcularVendasDoDia();
				break;
				
			case 4: 
				calcularLucroPorItem();
				break;
				
			case 5: 
				cadastrarFonecedores();
				break;
				
			case 6: 
				consultarFornecedores();
				break;		
			case 7:
				system("color 0F");
				system("cls");
				printf("\n\nVoce saiu do sistema.\n");
				break;
				
			default:
				printf("Opcao invalida! Por favor, digite novamente");
				break;
			
		}
	}
}

void cadastrarBolo(void){
	system("color 7D");
	char resposta = 's';
	system("cls");
	printf("---------- Cadastro de Bolos ----------\n");
			for(i = 0; i < 10 && resposta=='s'; i++){
				printf("\nNome/Sabor do Bolo: ");
				fgets(bolo[i].sabor, 100, stdin);
				
				printf("\nValor do Bolo: R$");
				scanf("%f", &bolo[i].valor);
				fflush(stdin);
				
				printf("\nQuantidade: ");
				scanf("%d", &bolo[i].quantidade);
				fflush(stdin);
				
				printf("\nDados registrados com sucesso!\n");
				printf("\nDeseja registrar mais algum item? s/n: ");
				scanf("%c", &resposta);
				fflush(stdin);
			}
	
		return;
}

void consultarEstoque(void){
	system("color 7D");
	system("cls");
	printf("\n----------Estoque atual----------\n");
		for(i = 0; i < 10; i++){
			if(bolo[i].sabor != '\0' && bolo[i].valor!=0){
				printf("\nNome/Sabor do Bolo: %s", bolo[i].sabor);
				printf("Valor do Bolo: R$%.2f", bolo[i].valor);
				printf("\nQuantidade: %d\n\n", bolo[i].quantidade);	
				printf("-------------------------------------");
			}	
		}
		if(bolo[0].valor == 0){
			printf("Sem estoque. Por favor cadastre algum item\n");
			return;
		}	
	return;
}

void calcularVendasDoDia(void){
	system("color 8E");
	system("cls");
	char bolo[50];
	int i, quantidade_item, vendas_hoje;
	float valor, total = 0;
	printf("\n---------- Calculo Vendas do Dia ----------\n\n");
	printf("Informe o total de itens vendidos hoje: ");
	scanf("%d", &vendas_hoje);
	fflush(stdin);
	
	for(i = 0; i < vendas_hoje; i++){
		printf("\nInforme o nome do item vendido: ");
		fgets(bolo, 50, stdin);
		fflush(stdin);
		
		printf("Informe o valor do item %s R$", bolo);
		scanf("%f", &valor);
		fflush(stdin);
		
		printf("Informe a quantidade vendida do item: ");
		scanf("%d", &quantidade_item);
		fflush(stdin);
		printf("----------------------------------------------\n");
		
		total = total + (valor*quantidade_item);
	}
	printf("Total de vendas do dia em dinheiro: R$%.2f", total);
	printf("\n----------------------------------------------\n");
	return;
}

void calcularLucroPorItem(void){
	system("color 8E");
	system("cls");
	
	char receita[50], ingredientes[50];
	int quantidade_produtos, x, qtd;
	float valor, venda, total = 0, extras, gasto_total, lucro;
	
	printf("\n---------- Calculo Lucro por Item ----------\n\n");
	printf("Informe o nome do receita que deseja comprar : ");
	fgets(receita, 50, stdin);
	printf("Informe a quantidade de ingredientes que deseja comprar para fazer a receitar: ");
	scanf("%d", &quantidade_produtos);
	fflush(stdin);
	
	for(x=0; x<quantidade_produtos; x++){
		printf("Informe o nome do ingrediente %d: ", x + 1);
		fgets(ingredientes, 50, stdin);
		fflush(stdin);
		printf("Informe o valor do ingrediente: R$");
		scanf("%f", &valor);
		fflush(stdin);
		printf("Informe a quantidade do ingrediente escolhido: ");
		scanf("%d", &qtd);
		fflush(stdin);
		total += valor*qtd;
	}
	extras = total*0.20;
	gasto_total = total + extras;
	
	printf("Informe o preco de venda da receita %s R$", receita);
	scanf("%f", &venda);
	fflush(stdin);
	
	lucro = venda - gasto_total;
	
	printf("----- Receita: %s", receita);
	printf("Valor total dos ingredientes: R$%.2f\n", total);
	printf("Gastos extras - agua, luz, gas, embalagens e mao de obra (20%% de R$%.2f): R$%.2f\n", total, extras);
	printf("Custo total: R$%.2f\n", gasto_total);
	printf("Lucro total: R$%.2f\n", lucro);
	printf("Lucro total em porcentagem: %.1f%%\n", (lucro/venda)*100);
	
	return;
}
	void cadastrarFonecedores(void){
		system("color 1F");
		system("cls");
		char resposta = 's';
		printf("----------- Sistema de Cadastro de Fornecedores -----------\n");
			for(i = 0; i < 10 && resposta=='s'; i++){
				printf("\nNome / Razao Social: ");
				fgets(fornecedores[i].nome, 100, stdin);
				fflush(stdin);
				
				printf("\nCodigo do fornecedor: ");
				scanf("%d", &fornecedores[i].codigo);
				fflush(stdin);
				
				printf("\nCNPJ/CPF: ");
				fgets(fornecedores[i].cnpj, 100, stdin);
				fflush(stdin);
				
				printf("\nTelefone: ");
				fgets(fornecedores[i].telefone, 50, stdin);
				fflush(stdin);
				
				printf("\nE-mail: ");
				fgets(fornecedores[i].email, 50, stdin);
				fflush(stdin);
				
				printf("\nRamo: ");
				fgets(fornecedores[i].ramo, 50, stdin);
				fflush(stdin);
				
				printf("\nDados registrados com sucesso!\n");
				printf("\nDeseja registrar mais algum fornecedor? s/n: ");
				scanf("%c", &resposta);
				fflush(stdin);
			}
		return;
	}
	
	void consultarFornecedores(void){
		system("color 1F");
		system("cls");
		printf("\n---------- Consulta de Fornecedores ----------\n\n");
			for(i = 0; i < 10; i++){
				if(fornecedores[i].nome != '\0' && fornecedores[i].codigo!=0){
					printf("\nNome / Razao Social: %s", fornecedores[i].nome);
					printf("\nCodigo do Fornecedor: %d\n", fornecedores[i].codigo);
					printf("\nCNPJ/CPF: %s", fornecedores[i].cnpj);
					printf("\nTelefone: %s", fornecedores[i].telefone);
					printf("\nE-mail: %s", fornecedores[i].email);
					printf("\nRamo: %s", fornecedores[i].ramo);
					printf("-------------------------------------");	
				}	
			}
			if(fornecedores[0].codigo == 0){
				printf("Sem registro de fornecedores.\n");
			}	
		return;
	}
	
	

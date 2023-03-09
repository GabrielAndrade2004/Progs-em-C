#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
#include<conio.h>

int op, teste, escolha;    
	int qtdU;
    int qtdC;
    int qtd;
    int escolha;
float soma, total;

/*struct ficha{
	char nome [30];
	int tel;
	char ender [100];
};

typedef struct ficha ficha; */



void cervejas(){
    printf("\nCOD 1 - Itaipava Cx:  R$25,00       Und: R$1,50");
    printf("\nCOD 2 - Devassa  Cx:  R$28,00       Und: R$1,80");
    printf("\nCOD 3 - Bohemia  Cx:  R$29,00       Und: R$1,85");
    printf("\nCOD 4 - Amstel   Cx:  R$30,00       Und: R$2,10");
    printf("\n0 - Voltar");
    printf("\n\nDigite o COD do produto:");
    scanf("%d",&teste);

	

    do{
    	system("cls");
        if(teste != 0){
            printf("\n 1 - Caixa\n");
            printf("\n 2 - Unidade\n");
            printf("\n 0 - Voltar\n");

            printf("\n Digite sua opção:");
            scanf("%d",&escolha);
            if(escolha == 1){
                switch(teste){
                    case 1:
                        printf("\n\nDigite a quantidade de caixas de Itaipava: ");
                        scanf("%d",&qtd);
                        soma += 25.00 * qtd;
                        printf("Valor total: %.2f",soma);
                        Sleep(3000);
                        break;
                        
                    case 2:
                        printf("\n\nDigite a quantidade de caixas de Devassa: ");
                        scanf("%d",&qtd);
                        soma += 28.00 * qtd;
                        printf("Valor total: %.2f",soma);
                        Sleep(3000);
                        break;
                    	
					case 3:
                    	printf("\n\nDigite a quantidade de caixas de Bohemia: ");
                        scanf("%d",&qtd);
                        soma += 30.00 * qtd;
                        printf("Valor total: %.2f",soma);
                        Sleep(3000);
                        break;
                        
                    case 4:
                    	printf("\n\nDigite a quantidade de caixas de Amstel: ");
                        scanf("%d",&qtd);
                        soma += 29.00 * qtd;
                        printf("Valor total: %.2f",soma);
                        Sleep(3000);
                        break;
                    	

                }
            }
            if(escolha == 2){
                switch(teste){
                    case 1:
                        printf("\n\nDigite a quantidade de unidades de Itaipava: ");
                        scanf("%d",&qtd);
                        soma += 1.50 * qtd;
                        printf("Valor total: %.2f",soma);
                        Sleep(3000);
                        break;
                        
                    case 2:
                        printf("\n\nDigite a quantidade de unidades de Devassa: ");
                        scanf("%d",&qtd);
                        soma += 1.80 * qtd;
                        printf("Valor total: %.2f",soma);
                        Sleep(3000);
                        break;
                        
                    case 3: 
                    	printf("\n\nDigite a quantidade de unidades de Bohemia: ");
                        scanf("%d",&qtd);
                        soma += 1.85 * qtd;
                        printf("Valor total: %.2f",soma);
                        Sleep(3000);
                        break;
                    
                    case 4:
                    	printf("\n\nDigite a quantidade de unidades de Amstel: ");
                        scanf("%d",&qtd);
                        soma += 2.10 * qtd;
                        printf("Valor total: %.2f",soma);
                        Sleep(3000);
                        break;

                }	
            }
					
        }			
        system("cls");

    }while(escolha!=0);
	
}
void refri(){
	printf("\nCOD 1 - Pepsi     Engradado: R$35,00  ||  Und 1L: R$5,00  ||  Und 300 ML: 2,50");
	printf("\nCOD 2 - Coca Cola Engradado: R$37,00  ||  Und 1L: R$5,50  ||  Und 300 ML: 3,00");
	printf("\nCOD 3 - Fanta     Engradado: R$33,00  ||  Und 1L: R$4,50  ||  Und 300 ML: 2,00");
	printf("\n0 - Voltar");
    printf("\n\nDigite o COD do produto:");
    scanf("%d",&teste);
	
	
	 do{
    	system("cls");
        if(teste != 0){
            printf("\n 1 - Caixa\n");
            printf("\n 2 - Unidade 1L\n");
            printf("\n 3 - Unidade 300ml\n");
            printf("\n 0 - Voltar\n");

            printf("\n Digite sua opção:");
            scanf("%d",&escolha);
            if(escolha == 1){
                switch(teste){
                    case 1:
                        printf("\n\nDigite a quantidade de engradados de Pepsi: ");
                        scanf("%d",&qtd);
                        soma += 35.00 * qtd;
                        printf("Valor total: %.2f",soma);
                        Sleep(3000);
                        break;
                        
                    case 2:
                        printf("\n\nDigite a quantidade de engradados de Coca Cola: ");
                        scanf("%d",&qtd);
                        soma += 37.00 * qtd;
                        printf("Valor total: %.2f",soma);
                        Sleep(3000);
                        break;
                        
                    case 3:
                    	printf("\n\nDigite a quantidade de engradados de Fanta: ");
                        scanf("%d",&qtd);
                        soma += 33.00 * qtd;
                        printf("Valor total: %.2f",soma);
                        Sleep(3000);
                        break;
                        
                    

                }
            }
            if(escolha == 2){
                switch(teste){
                    case 1:
                        printf("\n\nDigite a quantidade de unidades de 1L de Pepsi: ");
                        scanf("%d",&qtd);
                        soma += 5.00 * qtd;
                        printf("Valor total: %.2f",soma);
                        Sleep(3000);
                        break;
                        
                     case 2:
                        printf("\n\nDigite a quantidade de unidades de 1L de Coca Cola: ");
                        scanf("%d",&qtd);
                        soma += 5.50 * qtd;
                        printf("Valor total: %.2f",soma);
                        Sleep(3000);
                        break;
                        
                    case 3:
                    	printf("\n\nDigite a quantidade de unidades de 1L de Fanta: ");
                        scanf("%d",&qtd);
                        soma += 4.50 * qtd;
                        printf("Valor total: %.2f",soma);
                        Sleep(3000);
                        break;

                }
            }
            
            if(escolha == 3){
                switch(teste){
                    case 1:
                        printf("\n\nDigite a quantidade de unidades de 300ml de Pepsi: ");
                        scanf("%d",&qtd);
                        soma += 2.50 * qtd;
                        printf("Valor total: %.2f",soma);
                        Sleep(3000);
                        break;
                        
                    case 2:
                        printf("\n\nDigite a quantidade de unidades de 300ml de Coca Cola: ");
                        scanf("%d",&qtd);
                        soma += 3.00 * qtd;
                        printf("Valor total: %.2f",soma);
                        Sleep(3000);
                        break;
                        
                    case 3:
                    	printf("\n\nDigite a quantidade de unidades de 300ml de Fanta: ");
                        scanf("%d",&qtd);
                        soma += 2.00 * qtd;
                        printf("Valor total: %.2f",soma);
                        Sleep(3000);
                        break;

                }
            }

        }
        system("cls");

    }while(escolha!=0);
}



void agua(){
	printf("\nCOD 1 - Indaia  Und 1L: R$3,50         ||    Und 500 ML: R$2,00");
	printf("\nCOD 2 - Crystal Und 1L: R$3,20         ||    Und 500 ML: R$1,80");
	printf("\nCOD 3 - Dias d'Ávila Und 1L: R$ 3,10   ||    Und 500 ML: R$1,50");
	printf("\n\nDigite o COD do produto:");
    scanf("%d",&teste);

	

    do{
    	system("cls");
        if(teste != 0){
            printf("\n 1 - Unidade 1L\n");
            printf("\n 2 - Unidade 500ml\n");
            printf("\n 0 - Voltar\n");

            printf("\n Digite sua opção:");
            scanf("%d",&escolha);
            if(escolha == 1){
                switch(teste){
                    case 1:
                        printf("\n\nDigite a quantidade de unidades de água Indaia 1L: ");
                        scanf("%d",&qtd);
                        soma += 3.20 * qtd;
                        printf("Valor total: %.2f",soma);
                        Sleep(3000);
                        break;
                        
                    case 2:
                        printf("\n\nDigite a quantidade de unidades de água Crystal 1L: ");
                        scanf("%d",&qtd);
                        soma += 3.50 * qtd;
                        printf("Valor total: %.2f",soma);
                        Sleep(3000);
                        break;
                    	
					case 3:
                    	printf("\n\nDigite a quantidade de unidades de água Dias d'Ávila 1L: ");
                        scanf("%d",&qtd);
                        soma += 3.10 * qtd;
                        printf("Valor total: %.2f",soma);
                        Sleep(3000);
                        break;
    
                }
            }
            if(escolha == 2){
                switch(teste){
                    case 1:
                        printf("\n\nDigite a quantidade de unidades de água Indaia 500ml: ");
                        scanf("%d",&qtd);
                        soma += 2.00 * qtd;
                        printf("Valor total: %.2f",soma);
                        Sleep(3000);
                        break;
                        
                    case 2:
                        printf("\n\nDigite a quantidade de unidades de água Crystal 500ml: ");
                        scanf("%d",&qtd);
                        soma += 1.80 * qtd;
                        printf("Valor total: %.2f",soma);
                        Sleep(3000);
                        break;
                        
                    case 3: 
                    	printf("\n\nDigite a quantidade de unidades de água Dias d'Ávila 500ml: ");
                        scanf("%d",&qtd);
                        soma += 1.50 * qtd;
                        printf("Valor total: %.2f",soma);
                        Sleep(3000);
                        break;
                    
                }	
            }
					
        }			
        system("cls");

    }while(escolha!=0);
	
}


void suco(){
	printf("\nCOD 1 - Citrus Und 1L: R$4,00  ||  Und 500 ML: R$2,00");
	printf("\nCOD 2 - Skinka Und 1L: R$3,50  ||  Und 500 ML: R$1,75");
	printf("\nCOD 3 - Yulo   Und 1L: R$3,00  ||  Und 500 ML: R$1,50");
		printf("\n\nDigite o COD do produto:");
    scanf("%d",&teste);

	

    do{
    	system("cls");
        if(teste != 0){
            printf("\n 1 - Unidade 1L\n");
            printf("\n 2 - Unidade 500ml\n");
            printf("\n 0 - Voltar\n");

            printf("\n Digite sua opção:");
            scanf("%d",&escolha);
            if(escolha == 1){
                switch(teste){
                    case 1:
                        printf("\n\nDigite a quantidade de unidades de Suco Citrus 1L: ");
                        scanf("%d",&qtd);
                        soma += 4.00 * qtd;
                        printf("Valor total: %.2f",soma);
                        Sleep(3000);
                        break;
                        
                    case 2:
                        printf("\n\nDigite a quantidade de unidades de Suco Skinka 1L: ");
                        scanf("%d",&qtd);
                        soma += 3.50 * qtd;
                        printf("Valor total: %.2f",soma);
                        Sleep(3000);
                        break;
                    	
					case 3:
                    	printf("\n\nDigite a quantidade de unidades de Suco Yulo 1L: ");
                        scanf("%d",&qtd);
                        soma += 3.10 * qtd;
                        printf("Valor total: %.2f",soma);
                        Sleep(3000);
                        break;
    
                }
            }
            if(escolha == 2){
                switch(teste){
                    case 1:
                        printf("\n\nDigite a quantidade de unidades de Suco Citrus 500ml: ");
                        scanf("%d",&qtd);
                        soma += 2.00 * qtd;
                        printf("Valor total: %.2f",soma);
                        Sleep(3000);
                        break;
                        
                    case 2:
                        printf("\n\nDigite a quantidade de unidades de Suco Skinka 500ml: ");
                        scanf("%d",&qtd);
                        soma += 1.75 * qtd;
                        printf("Valor total: %.2f",soma);
                        Sleep(3000);
                        break;
                        
                    case 3: 
                    	printf("\n\nDigite a quantidade de unidades de Suco Yulo 500ml: ");
                        scanf("%d",&qtd);
                        soma += 1.50 * qtd;
                        printf("Valor total: %.2f",soma);
                        Sleep(3000);
                        break;
                    
                }	
            }
					
        }			
        system("cls");

    }while(escolha!=0);
	
}


void menu(){
	
	int opmenu;
	
	do{
		printf("\n1 - Cervejas\n2 - Refrigerantes\n3 - Vodkas\n4 - Whisky\n5 - Energéticos\n6 - Água\n7 - Sucos\n8 - Sair");
		printf("\nDigite sua opção: ");
		scanf("%d", &opmenu);
		
		switch (opmenu){
		case 1:
			system("cls");
			cervejas();
			break;	
		case 2: 
			system("cls");
			refri();
			break;
		}
		
	}while(opmenu!=8);
	
	system("cls");
}


main(){
setlocale(LC_ALL, "");
/*ficha cadastro;
	printf("Nome: ");
	scanf("%s", &cadastro.nome);
	printf("Telefone: ");
	scanf("%d", &cadastro.tel);
	printf("Endereco: ");
	scanf("%s", &cadastro.ender);*/


do{
	
	printf("\n----- Bem Vindo ao depósito de Bebidas -----");
	printf("\n1 - Realizar Compras");
	printf("\n2 - Emitir nota fiscal");
	printf("\n3 - Valor total da semana");
	printf("\nDigite sua opção: ");
	scanf("%d", &op);

	system("cls");
switch (op){
	case 1:
		system("cls");
		menu();
		break;	
	case 2: 
		system("cls");
		refri();
		break;
	case 3: 
		system("cls");
		//vodka();
		break;
	case 4: 
		system("cls");
		//whisky();
		break;
	case 5: 
		system("cls");
		//energ();
		break;
	case 6: 
		system("cls");
		agua();
		break;
	case 7: 
		system("cls");
		suco();
		break;
}


}while (op!=8);


}

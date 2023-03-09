#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#define LEN 1001
#define NULO '\0'
struct cadastro_funcionario{
	
	FILE *gerentes;
	FILE *arquivo;
	FILE *lista_func;
	FILE *arquivo_new;
	FILE *lista_new;
	int opcao_do_funcionario;
	char nome[15];
	char senha[15];	
	//char linha[100];
	char lista_nome[100];
	char modi_nomes[100];
	char cargo[20];
	int id;
	
}cadastro;

struct login_funcionario{
	
	char nome_login[15];
	char senha_login[15];
	char busca_funcionario[15];
	int alterar_perfil;
	char nome_trocar[15];
	char nome_colocar[15];
	char deletar_nom[15];
	//int linha_nome_deletar;
	int linha_nome_trocar;
	char senha_trocar[15];
	int linha_senha_trocar;
	int excluir_lista;
	int trc_nome;
	char lugar_nome[15];
	char loc_senha[15];
	
}login;

int main(){
	
cadastro.arquivo = fopen("funcionario.txt", "x");
fclose(cadastro.arquivo);
cadastro.lista_func = fopen("lista_funcionario.txt", "x");
fclose(cadastro.lista_func);
cadastro.gerentes = fopen("gerente.txt", "x");
fclose(cadastro.gerentes);


while(1){
	setlocale(LC_ALL,"Portuguese");
	printf("\n%45s", "GERENCIAMENTO DE FUNCIONÁRIOS");
	printf("\n\nESCOLHA UMA OPÇÃO:");
	printf("\n[1] - CADASTRAR NOVO FUNCIONÁRIO(A)");
	printf("\n[2] - FAZER LOGIN");
	printf("\n[3] - SAIR");

	printf("\nDIGITE SUA OPÇÃO:");
	scanf("%d", &cadastro.opcao_do_funcionario);
    if(cadastro.opcao_do_funcionario > 3){
    	printf("-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-==-");
        printf("\nOPÇÃO INVÁLIDA ! TENTE NOVAMENTE !");
        Sleep(2000);
        printf("\nVOLTANDO PARA A PÁGINA INICIAL...");
        printf("\n-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-==--=-=-=-=-=-=-\n");
        Sleep(2600);
		system("cls");
	}
    if(cadastro.opcao_do_funcionario == 1){
    	fflush(stdin);
    	printf("-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-==--=-=-=-=-=-=-");
    	printf("\n                    ÁREA DE CADASTRO");
    	//printf("\n   DE PREFERÊNCIA DIGITE O CARGO EM LETRAS MAIÚSCULAS SEM ACENTO!");
    	printf("\n\tCARGOS DISPONÍVEIS [FUNCIONÁRIO(A)] - [GERENTE]");
    	printf("\n\nCARGO:");
    	gets(cadastro.cargo);
    	//cadastro.cargo = strupr(cadastro.cargo);
    	//printf("%s", cadastro.cargo);
    	printf("",strupr(cadastro.cargo));
    	//printf("%s", cadastro.cargo);
		printf("NOME:");
    	gets(cadastro.nome);
        printf("SENHA:");
    	gets(cadastro.senha);
    	int i;
    	srand(time(NULL));
    	for (i=0; i < 1; i++){
    		cadastro.id = rand() % 1000;
  		}
        if(strcmp(cadastro.nome,cadastro.senha)!=0){
        	cadastro.gerentes = fopen("gerente.txt", "a");
        	cadastro.lista_func = fopen("lista_funcionario.txt", "a");
        	cadastro.arquivo = fopen("funcionario.txt", "a");
        	fprintf(cadastro.arquivo, "%s: %s\n", cadastro.cargo, cadastro.nome);
        	fprintf(cadastro.arquivo, "ID: %d\n", cadastro.id);
        	//fprintf(cadastro.arquivo, "%s: %s\n", cadastro.cargo, cadastro.nome);
        	fprintf(cadastro.arquivo, "SENHA: %s\n",cadastro.senha);
        	fputs("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n",cadastro.arquivo);
        	if(strcmp(cadastro.cargo, "GERENTE")==0){
        		fprintf(cadastro.gerentes, "%s: %s\n", cadastro.cargo, cadastro.nome);
			}
			if(strcmp(cadastro.cargo, "FUNCIONARIO") == 0 || strcmp(cadastro.cargo, "FUNCIONARIA") == 0){
				fprintf(cadastro.lista_func, "%s: %s\n", cadastro.cargo, cadastro.nome);
			}
    		fclose(cadastro.arquivo);
    		fclose(cadastro.lista_func);
    		fclose(cadastro.gerentes);
            printf("CADASTRO REALIZADO COM SUCESSO !");
            printf("\nO SEU ID É %d", cadastro.id);
            printf("\nVOLTANDO PARA A PÁGINA INICIAL...");
            printf("\n-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-==-\n");  	
            Sleep(2700);
			system("cls");
		}
        if(strcmp(cadastro.nome,cadastro.senha)==0){
            printf("SUA SENHA DEVE SER DIFERENTE DO NOME DO USUÁRIO !");
            Sleep(2000);
            printf("\nVOLTANDO PARA A PÁGINA INICIAL...");
            printf("\n-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-==--=-=-=-=-=-=-\n");
            Sleep(2900);
			system("cls");
    	}
	}
		
    if(cadastro.opcao_do_funcionario==2){
    	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==--=-=");
        printf("\n             ÁREA DE LOGIN");
        fflush(stdin);
        cadastro.arquivo = fopen("funcionario.txt", "r");
        printf("\nNOME:");
        int j = 0; 
        int achou1 = 0;
        char pegar_nome[15];
        int pegar_linha_nome;
        fgets(login.nome_login, 100, stdin);    
		login.nome_login[strlen(login.nome_login) -1] = 0;    
		do{
			fgets(cadastro.nome, 1000, cadastro.arquivo);        
			j++;        
			if(strstr(cadastro.nome, login.nome_login) != NULL){
				//printf("Linha %d: %s", j, cadastro.nome);
				pegar_linha_nome = j; 
				strcpy(pegar_nome,cadastro.nome);           
				achou1 = 1;        
			}				    
		}while(!feof(cadastro.arquivo)); 
		   
		char *tes;
  		char fatia_string[15];
  		//char teste4[15];
  		strtok_r(pegar_nome, ":", &tes);
		//printf("%s  %s\n",pegar_nome, tes);
		strcpy(fatia_string, pegar_nome);
		//printf("%s\n", fatia_string);
		
		rewind(cadastro.arquivo);
        printf("SENHA:");
        int achou = 0; 
		int i = 0;
		char pegar_senha[15];
		int pegar_linha_senha;
    
		fgets(login.senha_login, 100, stdin);    
		login.senha_login[strlen(login.senha_login) -1] = 0;    
		do{
			fgets(cadastro.senha, 1000, cadastro.arquivo);        
			i++;        
			if(strstr(cadastro.senha, login.senha_login) != NULL){
				//printf("Linha %d: %s", i, cadastro.senha);
				strcpy(pegar_senha,cadastro.senha);
				pegar_linha_senha = i;            
				achou = 1;        
			}
						    
		}while(!feof(cadastro.arquivo));
		fclose(cadastro.arquivo);
		int teste = 0;
		if(achou1 == 0 && achou == 0){
			teste = 1;
			printf("NOME E SENHA INVÁLIDOS !");
			printf("\nVOLTANDO PARA A PÁGINA INICIAL...");
            printf("\n-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-==--=-=-=-=-=-=-\n");
            Sleep(2900);
			system("cls");
		}
		if(achou == 0 && achou1 == 1 && teste == 0){
			printf("SENHA INCORRETA !");
			printf("\nVOLTANDO PARA A PÁGINA INICIAL...");
            printf("\n-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-==--=-=-=-=-=-=-\n");
            Sleep(2900);
			system("cls");    
		}
		if(achou1 == 0 && teste == 0){
			printf("NOME INVÁLIDO !");
			printf("\nVOLTANDO PARA A PÁGINA INICIAL...");
            printf("\n-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-==--=-=-=-=-=-=-\n");
            Sleep(2900);
			system("cls");    
		}
		if(teste == 1){
			teste = 0;
		}
	
		
		
		if(achou1 != 0 && achou != 0 && strcmp(fatia_string, "GERENTE") == 0){
			
			printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
			printf("\nLOGIN REALIZADO COM SUCESSO !");
			Sleep(2900);
			system("cls");
			printf("\n                  SEJA BEM-VINDO(A) %s", login.nome_login);
            printf("\n         AQUI ESTÁ AS NOSSAS FUNCIONALIDADES:");
            while(cadastro.opcao_do_funcionario!=5){
	            printf("\n\n[1] LISTA DE FUNCIONÁRIOS");
	            printf("\n[2] BUSCA DE FUNCIONÁRIO");
	            printf("\n[3] MODIFICAÇÕES DO PERFIL");
	            printf("\n[4] APAGAR FUNCIONÁRIO");
	            printf("\n[5] LOGOUT");
	            printf("\nDIGITE SUA OPÇÃO:");
	            scanf("%d", &cadastro.opcao_do_funcionario);
	            if(cadastro.opcao_do_funcionario==1){
	            	printf("-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-==--=-=-=-=-=-=-\n");
	            	printf("                LISTA DE FUNCIONÁRIOS(AS):\n");
	                cadastro.lista_func = fopen("lista_funcionario.txt", "r");
	                while(fgets(cadastro.lista_nome, 100, cadastro.lista_func) != NULL){
	                	printf("-%s", cadastro.lista_nome);	
					}
	  				fclose(cadastro.lista_func);
	  				printf("\nESTÁ É A LISTA DE TODOS OS FUNCIONÁRIOS CADASTRADOS !");
	  				printf("\nVOLTANDO PARA A PÁGINA INICIAL...");
            		printf("\n-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-==--=-=-=-=-=-=-\n");
	            	Sleep(3700);
					system("cls"); 
				}
				if(cadastro.opcao_do_funcionario==2){
					int busca_func;
					int b;
					fflush(stdin);
					cadastro.lista_func = fopen("lista_funcionario.txt", "r");
					printf("-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-==--=-=-=-=-=-=-\n");
	            	printf("                BUSCA DE FUNCIONÁRIOS(AS):\n");
                	printf("DIGITE O NOME DO FUNCIONÁRIO(A):");
                	fgets(login.busca_funcionario, 100, stdin);    
					login.busca_funcionario[strlen(login.busca_funcionario) -1] = 0;    
					do{
						fgets(cadastro.nome, 1000, cadastro.lista_func);        
						b++;        
						if(strstr(cadastro.nome, login.busca_funcionario) != NULL){
							printf("ESTÁ CADASTRADO(A) O(A) %s ", cadastro.nome);
							busca_func = 1;
							break;
						}
					}while(!feof(cadastro.lista_func)); 
					fclose(cadastro.lista_func);
					if(busca_func == 1){
						printf("\bVOLTANDO PARA A PÁGINA INICIAL...");
            			printf("\n-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-==--=-=-=-=-=-=-\n");
            			Sleep(3600);
						system("cls");
					}
				
					if(busca_func == 0){
						printf("NÃO FOI ENCONTRADO O FUNCIONÁRIO(A) %s", login.busca_funcionario);
						printf("\nVOLTANDO PARA A PÁGINA INICIAL...");
            			printf("\n-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-==--=-=-=-=-=-=-\n");
            			Sleep(3700);
						system("cls");    
					}
					if(busca_func == 1){
						busca_func = 0;
					}	
                }
                
				if(cadastro.opcao_do_funcionario==3){
					printf("-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-==--=-=-=-=-=-=-\n");
					int lll = 1;
					fflush(stdin);
					cadastro.arquivo = fopen("funcionario.txt", "r");
					//fflush(stdin);
	            	printf("                MODIFICAÇÕES DO PERFIL:\n");
	            	printf("[0]- VOLTAR\n");
					printf("[1]- TROCAR O NOME");
                    printf("\n[2]- TROCAR A SENHA");
                    printf("\n------------------FUNCIONÁRIOS CADASTRADOS-----------------\n");
                    rewind(cadastro.arquivo);
                    while(fgets(cadastro.modi_nomes, 100, cadastro.arquivo) != NULL){
	                	printf("-%s", cadastro.modi_nomes);
	                	lll++;
					}
					rewind(cadastro.arquivo);
					fclose(cadastro.arquivo);
                    //printf("\nLinha %d: %s", pegar_linha_nome, pegar_nome);
                    //printf("Linha %d: %s", pegar_linha_senha, pegar_senha); 
                    printf("\nQUAL MODIFICAÇÃO GOSTARIA DE SER FEITA? [0] - [1] - [2]:");
					scanf("%d", &login.alterar_perfil);
					if(login.alterar_perfil == 0){
						printf("\nVOLTANDO PARA A PÁGINA INICIAL...");
            			printf("\n-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-==--=-=-=-=-=-=-\n");
            			Sleep(3000);
						system("cls");
					}
					if(login.alterar_perfil==1){
						cadastro.arquivo = fopen("funcionario.txt", "r");
						cadastro.arquivo_new = fopen("novo_funcionario.txt", "w");
						int bli = 0;
						int gep;
						int yt;
						int nile = 1;
						int saex = 0;
						char name_troc[100];
						rewind(cadastro.arquivo);
						fflush(stdin);
						printf("DIGITE O NOME QUE DESEJA ALTERAR:");
						fgets(login.nome_trocar, 100, stdin);    
						login.nome_trocar[strlen(login.nome_trocar) -1] = 0;    
						do{
							fgets(cadastro.nome, 1000, cadastro.arquivo);        
							bli++;        
							if(strstr(cadastro.nome, login.nome_trocar) != NULL){
								//printf("Linha %d: %s", bli, login.nome_trocar);
								gep = bli;         
							}				    
						}while(!feof(cadastro.arquivo));
						rewind(cadastro.arquivo);
						printf("\nQUAL NOME GOSTARIA DE COLOCAR NO LUGAR?");
						fgets(login.lugar_nome, 100, stdin); 
						//fflush(stdin);
						for(yt = 0; !feof(cadastro.arquivo);yt++){
						memset(name_troc, NULO, 100); 
						fgets(name_troc, 101, cadastro.arquivo);
						if(nile == gep){
							fprintf(cadastro.arquivo_new, "FUNCIONÁRIO(A): %s", login.lugar_nome); 
							//fputs("", cadastro.arquivo_new); 
							nile = nile + 1; 
							saex = 1;
							continue; 
						}
						nile = nile + 1; 
						fputs(name_troc, cadastro.arquivo_new);
						}
						if(saex == 1){
							printf("\nNOME ALTERADO COM SUCESSO!");
							login.trc_nome = 1;
						}
						
						if(saex == 1){
							saex = 0;
						}
						fclose(cadastro.arquivo); 
						fclose(cadastro.arquivo_new); 
						remove("funcionario.txt");
						rename("novo_funcionario.txt", "funcionario.txt");
					}
					if(login.trc_nome == 1){
						int peint;
						int corr = 0;
						char notexbi[100];
						int zerline = 1;
						int incr;
						int zw = 0;
						login.excluir_lista = 0;
						//fflush(stdin);
						cadastro.lista_func = fopen("lista_funcionario.txt", "r");
						cadastro.lista_new = fopen("nova_lista.txt", "w");
						//login.deletar_nom[strlen(login.deletar_nom) -1] = 0; 
						rewind(cadastro.lista_func);   
						do{
							fgets(cadastro.nome, 1000, cadastro.lista_func);        
							zw++;        
							if(strstr(cadastro.nome, login.nome_trocar) != NULL){
								//printf("\nLinha %d: %s", q, login.deletar_nom);
								peint = zw;
								break;   
							}				    
						}while(!feof(cadastro.lista_func));
						//printf("\n%d",q);
						//printf("\n%d", ray);
						//fflush(stdin);
						rewind(cadastro.lista_func);
						
						for(incr = 0; !feof(cadastro.lista_func);incr++){
						memset(notexbi, NULO, 100); 
						fgets(notexbi, 101, cadastro.lista_func);
						if(zerline == peint){
							fprintf(cadastro.lista_new, "FUNCIONÁRIO(A): %s", login.lugar_nome); 
							//fputs("", cadastro.lista_new); 
							zerline = zerline + 1; 
							corr = 1;
							continue; 
						}
						zerline = zerline + 1; 
						fputs(notexbi, cadastro.lista_new);
						}
						if(corr == 1){
							printf("\nPROCESSANDO...");
							//Sleep(2000);
						}
						if(corr == 1){
							corr = 0;
						}
						fclose(cadastro.lista_func); 
						fclose(cadastro.lista_new); 
						remove("lista_funcionario.txt");
						rename("nova_lista.txt", "lista_funcionario.txt");
						printf("\nVOLTANDO PARA A PÁGINA INICIAL...");
	            		printf("\n-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-==--=-=-=-=-=-=-\n");
	            		Sleep(3600);
						system("cls");
					}
						
					if(login.alterar_perfil==2){
						cadastro.arquivo = fopen("funcionario.txt", "r");
						cadastro.arquivo_new = fopen("novo_funcionario.txt", "w");
						int lsenh = 0;
						int pesen;
						int rat;
						int lisen = 1;
						int arsen = 0;
						char sen_troc[100];
						rewind(cadastro.arquivo);
						fflush(stdin);
						printf("DIGITE A SENHA QUE DESEJA ALTERAR:");
						fgets(login.senha_trocar, 100, stdin);    
						login.senha_trocar[strlen(login.senha_trocar) -1] = 0;    
						do{
							fgets(cadastro.senha, 1000, cadastro.arquivo);        
							lsenh++;        
							if(strstr(cadastro.senha, login.senha_trocar) != NULL){
								//printf("Linha %d: %s", lsenh, login.senha_trocar);
								pesen = lsenh;         
							}				    
						}while(!feof(cadastro.arquivo));
						rewind(cadastro.arquivo);
						printf("\nQUAL SENHA GOSTARIA DE COLOCAR NO LUGAR?");
						fgets(login.loc_senha, 100, stdin); 
						//fflush(stdin);
						for(rat = 0; !feof(cadastro.arquivo);rat++){
						memset(sen_troc, NULO, 100); 
						fgets(sen_troc, 101, cadastro.arquivo);
						if(lisen == pesen){
							fprintf(cadastro.arquivo_new, "SENHA: %s", login.loc_senha); 
							//fputs("", cadastro.arquivo_new); 
							lisen = lisen + 1; 
							arsen = 1;
							continue; 
						}
						lisen = lisen + 1; 
						fputs(sen_troc, cadastro.arquivo_new);
						}
						if(arsen == 1){
							printf("\nSENHA ALTERADA COM SUCESSO!");
						}
						
						if(arsen == 1){
							arsen = 0;
						}
						fclose(cadastro.arquivo); 
						fclose(cadastro.arquivo_new); 
						remove("funcionario.txt");
						rename("novo_funcionario.txt", "funcionario.txt");
						printf("\nVOLTANDO PARA A PÁGINA INICIAL...");
	            		printf("\n-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-==--=-=-=-=-=-=-\n");
	            		Sleep(3600);
						system("cls");	
					}
				}
				if(cadastro.opcao_do_funcionario==4){
					int delet = 0;
					//int nome_deletado;
					int w;
					int nil = 1;
					int linha = 1;
					int j = 0;
					int teste;
					char textoArquivo[100];
					
					int w2;
					char textoArquivo2[100];
					int linha2 = 1;
					int delet2 = 0;
					
					int w3;
					char textoArquivo3[100];
					int linha3 = 1;
					int delet3 = 0;
					
					int w4;
					char textoArquivo4[100];
					int linha4 = 1;
					int delet4 = 0;

					fflush(stdin);
					cadastro.lista_func = fopen("lista_funcionario.txt", "r");
					cadastro.arquivo = fopen("funcionario.txt", "r");
					cadastro.arquivo_new = fopen("novo_funcionario.txt", "w");
					//cadastro.lista_new = fopen("nova_lista.txt", "w");
					printf("-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-==--=-=-=-=-=-=-\n");
	            	printf("                APAGAR FUNCIONÁRIO:\n");
	            	rewind(cadastro.arquivo);
	            	while(fgets(cadastro.lista_nome, 100, cadastro.lista_func) != NULL){
	                	printf("- %s", cadastro.lista_nome);
	                	nil++;
					}
					rewind(cadastro.lista_func);
					fclose(cadastro.lista_func);
	            	printf("DIGITE NOME DO FUNCIONÁRIO QUE DESEJA DELETAR:");
	            	fgets(login.deletar_nom, 100, stdin);    
					login.deletar_nom[strlen(login.deletar_nom) -1] = 0;    
					do{
						fgets(cadastro.nome, 1000, cadastro.arquivo);        
						j++;        
						if(strstr(cadastro.nome, login.deletar_nom) != NULL){
							printf("Linha %d: %s", j, login.deletar_nom);
							teste = j; 
							//strcpy(pegar_nome,cadastro.nome);           
							//achou1 = 1;        
						}				    
					}while(!feof(cadastro.arquivo));    
				
					rewind(cadastro.arquivo);
					//printf("\n%d", teste);
					//printf("\n%d", j);
					for(w = 0; !feof(cadastro.arquivo);w++){
					memset(textoArquivo, NULO, 100); 
					fgets(textoArquivo, 101, cadastro.arquivo);
					if(linha == teste){  
						fputs("", cadastro.arquivo_new); 
						linha = linha + 1; 
						delet = 1;
						continue; 
					}
					linha = linha + 1; 
					fputs(textoArquivo, cadastro.arquivo_new);
					}
					/*if(delet == 1){
						printf("\nFUNCIONÁRIO DELETADO COM SUCESSO!");
						//login.excluir_lista = 1;
					}
					
					if(delet == 1){
						delet = 0;
					}*/
					fclose(cadastro.arquivo); 
					fclose(cadastro.arquivo_new); 
					remove("funcionario.txt");
					rename("novo_funcionario.txt", "funcionario.txt");
					//printf("\nVOLTANDO PARA A PÁGINA INICIAL...");
					cadastro.arquivo = fopen("funcionario.txt", "r");
					cadastro.arquivo_new = fopen("novo_funcionario.txt", "w");

					rewind(cadastro.arquivo);
					for(w2=0;!feof(cadastro.arquivo);w2++){
						memset(textoArquivo2, NULO, 200);
						fgets(textoArquivo2, 201, cadastro.arquivo);
						if(linha2 == teste){
							fputs("", cadastro.arquivo_new); 
							linha2 = linha2 + 1; 
							delet2  = 1;
							continue; 
						}
					linha2 = linha2 + 1; 
					fputs(textoArquivo2, cadastro.arquivo_new);
					}
					
					fclose(cadastro.arquivo); 
					fclose(cadastro.arquivo_new); 
					remove("funcionario.txt");
					rename("novo_funcionario.txt", "funcionario.txt");
					
					cadastro.arquivo = fopen("funcionario.txt", "r");
					cadastro.arquivo_new = fopen("novo_funcionario.txt", "w");

					rewind(cadastro.arquivo);
					for(w3=0;!feof(cadastro.arquivo);w3++){
						memset(textoArquivo3, NULO, 200);
						fgets(textoArquivo3, 201, cadastro.arquivo);
						if(linha3 == teste){
							fputs("", cadastro.arquivo_new); 
							linha3 = linha3 + 1; 
							delet3  = 1;
							continue; 
						}
					linha3 = linha3 + 1; 
					fputs(textoArquivo3, cadastro.arquivo_new);
					}
					
					fclose(cadastro.arquivo); 
					fclose(cadastro.arquivo_new); 
					remove("funcionario.txt");
					rename("novo_funcionario.txt", "funcionario.txt");
					
					cadastro.arquivo = fopen("funcionario.txt", "r");
					cadastro.arquivo_new = fopen("novo_funcionario.txt", "w");

					rewind(cadastro.arquivo);
					for(w4=0;!feof(cadastro.arquivo);w4++){
						memset(textoArquivo4, NULO, 200);
						fgets(textoArquivo4, 201, cadastro.arquivo);
						if(linha4 == teste){
							fputs("", cadastro.arquivo_new); 
							linha4 = linha4 + 1; 
							delet4  = 1;
							continue; 
						}
					linha4 = linha4 + 1; 
					fputs(textoArquivo4, cadastro.arquivo_new);
					}
					if(delet4 == 1){
						printf("\nFUNCIONÁRIO DELETADO COM SUCESSO!");
						login.excluir_lista = 1;
					}
					
					if(delet4 == 1){
						delet4 = 0;
					}
					
					fclose(cadastro.arquivo); 
					fclose(cadastro.arquivo_new); 
					remove("funcionario.txt");
					rename("novo_funcionario.txt", "funcionario.txt");
				}
				if(login.excluir_lista == 1){
					int ray;
					int oki = 0;
					char litex[100];
					int circ = 1;
					int u;
					int q = 0;
					login.excluir_lista = 0;
					//fflush(stdin);
					cadastro.lista_func = fopen("lista_funcionario.txt", "r");
					cadastro.lista_new = fopen("nova_lista.txt", "w");
					//login.deletar_nom[strlen(login.deletar_nom) -1] = 0; 
					rewind(cadastro.lista_func);   
					do{
						fgets(cadastro.nome, 1000, cadastro.lista_func);        
						q++;        
						if(strstr(cadastro.nome, login.deletar_nom) != NULL){
							//printf("\nLinha %d: %s", q, login.deletar_nom);
							ray = q;
							break;   
						}				    
					}while(!feof(cadastro.lista_func));
					//printf("\n%d",q);
					//printf("\n%d", ray);
					//fflush(stdin);
					rewind(cadastro.lista_func);
					
					for(u = 0; !feof(cadastro.lista_func);u++){
					memset(litex, NULO, 100); 
					fgets(litex, 101, cadastro.lista_func);
					if(circ == ray){
						fputs("", cadastro.lista_new); 
						circ = circ + 1; 
						oki = 1;
						continue; 
					}
					circ = circ + 1; 
					fputs(litex, cadastro.lista_new);
					}
					if(oki == 1){
						printf("\nPROCESSANDO...");
						Sleep(2000);
					}
					if(oki == 1){
						oki = 0;
					}
					fclose(cadastro.lista_func); 
					fclose(cadastro.lista_new); 
					remove("lista_funcionario.txt");
					rename("nova_lista.txt", "lista_funcionario.txt");
					printf("\nVOLTANDO PARA A PÁGINA INICIAL...");
            		printf("\n-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-==--=-=-=-=-=-=-\n");
            		Sleep(3600);
					system("cls");	
				}
		
				if(cadastro.opcao_do_funcionario==5){
					printf("\nSAINDO....");
            		printf("\n-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-==--=-=-=-=-=-=-\n");
            		Sleep(3000);
					system("cls");
				}       
            }
		}
		if(achou1 != 0 && achou != 0 && strcmp(fatia_string, "FUNCIONARIO") == 0 || strcmp(fatia_string, "FUNCIONARIA") == 0){
			printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-");
			printf("\nLOGIN REALIZADO COM SUCESSO !");
			Sleep(2900);
			system("cls");
			printf("\n                  SEJA BEM-VINDO(A) %s", login.nome_login);
            printf("\n         AQUI ESTÁ AS NOSSAS FUNCIONALIDADES:");
            while(cadastro.opcao_do_funcionario!=0){
	            printf("\n\n[1] LISTA DE FUNCIONÁRIOS");
	            printf("\n[2] BUSCA DE FUNCIONÁRIO");
	            printf("\n[0] LOGOUT");
	            printf("\nDIGITE SUA OPÇÃO:");
	            scanf("%d", &cadastro.opcao_do_funcionario);
	            if(cadastro.opcao_do_funcionario==1){
	            	printf("-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-==--=-=-=-=-=-=-\n");
	            	printf("                LISTA DE FUNCIONÁRIOS(AS):\n");
	                cadastro.lista_func = fopen("lista_funcionario.txt", "r");
	                while(fgets(cadastro.lista_nome, 100, cadastro.lista_func) != NULL){
	                	printf("-%s", cadastro.lista_nome);	
					}
	  				fclose(cadastro.lista_func);
	  				printf("\nESTÁ É A LISTA DE TODOS OS FUNCIONÁRIOS CADASTRADOS !");
	  				printf("\nVOLTANDO PARA A PÁGINA INICIAL...");
            		printf("\n-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-==--=-=-=-=-=-=-\n");
	            	Sleep(3600);
					system("cls"); 
				}
				if(cadastro.opcao_do_funcionario==2){
					int busca_func;
					int b;
					fflush(stdin);
					cadastro.lista_func = fopen("lista_funcionario.txt", "r");
					printf("-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-==--=-=-=-=-=-=-\n");
	            	printf("                BUSCA DE FUNCIONÁRIOS(AS):\n");
                	printf("DIGITE O NOME DO FUNCIONÁRIO(A):");
                	fgets(login.busca_funcionario, 100, stdin);    
					login.busca_funcionario[strlen(login.busca_funcionario) -1] = 0;    
					do{
						fgets(cadastro.nome, 1000, cadastro.lista_func);        
						b++;        
						if(strstr(cadastro.nome, login.busca_funcionario) != NULL){
							printf("ESTÁ CADASTRADO(A) O(A) %s ", cadastro.nome);
							busca_func = 1;
							break;        
						}
					}while(!feof(cadastro.lista_func)); 
					fclose(cadastro.lista_func);
					if(busca_func == 1){
						printf("\bVOLTANDO PARA A PÁGINA INICIAL...");
            			printf("\n-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-==--=-=-=-=-=-=-\n");
            			Sleep(3500);
						system("cls");
					}
				
					if(busca_func == 0){
						printf("NÃO FOI ENCONTRADO O FUNCIONÁRIO(A) %s", login.busca_funcionario);
						printf("\nVOLTANDO PARA A PÁGINA INICIAL...");
            			printf("\n-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-==--=-=-=-=-=-=-\n");
            			Sleep(3400);
						system("cls");    
					}
					if(busca_func == 1){
						busca_func = 0;
					}	
                }
                if(cadastro.opcao_do_funcionario==0){
					printf("\nSAINDO....");
            		printf("\n-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-==--=-=-=-=-=-=-\n");
            		Sleep(3000);
					system("cls");
				}     
			}
		}
	}
	if(cadastro.opcao_do_funcionario == 3){
			printf("\nSAINDO....");
            printf("\n-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-==--=-=-=-=-=-=-\n");
        	Sleep(3000);
			system("cls");
			break;
	}		
				 
}
}

#include <stdio.h> // bibblioteca de comunica��o com o usu�rio
#include <stdlib.h> // biblioteca de aloca��o de espa�o e mem�ria
#include <locale.h> // biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() // Fun��o responsavel por registra os usu�rios no sistema 
{ 
	// Inicio da cria��o de vari�veis/string
	char arquivo[40]; 
	char cpf[40]; 
	char nome[40]; 
	char sobrenome[40]; 
	char cargo[40]; 
	// Final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); // Respons�vel por trazer o texto para o usu�rio 
	scanf("%s", cpf); // Respons�vel por coletar as informa��es do usu�rio  
	
	strcpy(arquivo, cpf); // Respons�vel por copiar as valores das string 
	
	FILE *file; // Respons�vel por cria o arquivo no bando de dados (computador) 
	file = fopen(arquivo, "w"); // Respons�vel por cria o arquivo na pasta onde salvo o sistema 
	fprintf(file,cpf); // Respons�vel por salva o valor da vari�vel 
	fclose(file); // Respons�vel por fecha o arquivo 
	
	file = fopen(arquivo, "a"); // Respons�vel por atualizar o arquivo na pasta onde salvo o sistema
	fprintf(file,","); // Respons�vel por salvar o valor da vari�vel 
	fclose(file); // Respons�vel por fecha o arquivo 
	
	printf("Digite o nome a ser cadastrado: "); // Respons�vel por trazer o texto para o usu�rio 
	scanf("%s",nome); // Respons�vel por coletar informa��es do usu�rio
	
	file = fopen(arquivo, "a"); // Respons�vel por atualizar o arquivo na pasta onde salvo o sistema
	fprintf(file,nome); // Respons�vel por salva o valor da vari�vel 
	fclose(file); // Respons�vel por fecha o arquivo 
	
	file = fopen(arquivo, "a"); // Respons�vel por atualizar o arquivo na pasta onde salvo o sistema
	fprintf(file,","); // Respons�vel por salvar o valor da vari�vel 
	fclose(file); // Respons�vel por fecha o arquivo 
	
	printf("Digite o sobrenome a ser cadastrado: "); // Respons�vel por trazer o texto para o usu�rio 
	scanf("%s",sobrenome); // Respons�vel por coletar informa��es do usu�rio 
	
	file = fopen(arquivo, "a"); // Respons�vel por atualizar o arquivo na pasta onde salvo o sistema
	fprintf(file,sobrenome); // Respons�vel por salva o valor da vari�vel 
	fclose(file); // Respons�vel por fecha o arquivo 
	
	file = fopen(arquivo, "a"); // Respons�vel por atualizar o arquivo na pasta onde salvo o sistema
	fprintf(file,","); // Respons�vel por salvar o valor da vari�vel 
	fclose(file); // Respons�vel por fecha o arquivo 
	
	printf("Digite o cargo a ser cadastrado: "); // Respons�vel por trazer o texto para o usu�rio 
	scanf("%s",cargo); // Respons�vel por coletar informa��es do usu�rio 
	
	file = fopen(arquivo, "a"); // Respons�vel por atualizar o arquivo na pasta onde salvo o sistema
	fprintf(file,cargo); // Respons�vel por salva o valor da vari�vel 
	fclose(file); // Respons�vel por fecha o arquivo
	
	system("pause"); // Responsavel por pausa o sistema at� o usu�rio decidir 
	
}

int consulta() // Fun��o responsavel por consulta os usu�rios no sistema
{ 
	setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	
	// Inicio da cria��o de vari�veis/string
	char cpf[40]; 
	char conteudo[200]; 
	// Final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser consultado: "); // Respons�vel por trazer o texto para o usu�rio 
	scanf("%s",cpf); // Respons�vel por coletar informa��es do usu�rio 
	
	FILE *file; // Respons�vel por cria o arquivo no bando de dados (computador) 
	file = fopen(cpf,"r"); // Respons�vel por ler o arquivo na pasta onde salvo o sistema 
	
	if(file == NULL) // if significa (se) // == significa compara��o // NULL significa nulo
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n"); // Respons�vel por trazer o texto para o usu�rio 
	}
	
	while(fgets(conteudo, 200, file) != NULL) // sigficica enquanto 
	{
		printf("\nEssas s�o as informa��es do usu�rio: "); // Respons�vel por trazer o texto para o usu�rio 
		printf("%s", conteudo); // Respons�vel por mostra a informa��o para o usu�rio 
		printf("\n\n"); // Respons�vel por trazer o texto para o usu�rio
	}
	
	system("pause"); // Responsavel por pausa o sistema at� o usu�rio decidir 
}

int deletar() // Fun��o responsavel por deletar os usu�rios no sistema
{ 
	// Inicio da cria��o de vari�veis/string
	char cpf[40]; 
	// Final da cria��o de vari�veis/string
	
	printf("Digite o CPF do usu�rio a ser deletado: "); // Respons�vel por trazer o texto para o usu�rio 
	scanf("%s",cpf); // significa coletar informa��es do usu�rio 
	
	remove(cpf); // Respons�vel por deletar arquivo cpf 
	
	FILE *file; // Respons�vel por cria o arquivo no bando de dados (computador) 
	file = fopen(cpf,"r"); // Respons�vel por ler o arquivo na pasta onde salvo o sistema 
	
	if(file == NULL) // if significa (se) // == significa compara��o // NULL significa nulo
	{
		printf("O usu�rio n�o se encontra no sistema!.\n"); // Respons�vel por trazer o texto para o usu�rio 
		system("pause"); // Responsavel por pausa o sistema at� o usu�rio decidir 
	}
}	

int main() // Fun��o principal, onde vai est� rodando o n�cleo do projeto 
{ 
	// Inicio da cria��o de vari�veis
	int opcao=0;  
	int laco=1;  
	// Final da cria��o de vari�veis
	
	for(laco=1;laco=1;) // Responsavel por fazer/repetir quantas vezes pedir 
	{
		
		system("cls"); // Responsavel por limpar 
	
	    setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
		
		// Inicio do menu
	    printf("### Cart�rio da EBAC ###\n\n"); 
	    printf("Escolha a op��o desejada do menu:\n\n"); 
	    printf("\t1 - Registrar nomes\n");  
	    printf("\t2 - Consultar nomes\n"); 
	    printf("\t3 - Deletar nomes\n\n"); 
	    printf("\t4 - Sair do sistema\n\n");
	    printf("Op��o: ");
		// Fim do menu 
	
	    scanf("%d", &opcao); // Responsavel por armazenar a escolha do usu�rio 
	
	    system("cls"); // Responsavel por limpar 
	
	    switch(opcao) // Inicio da sele��o do menu 
		{
			case 1: // significa caso 
			registro(); // Responsavel pela chamada da fun��o
		    break; // significa quebra 
		    
		    case 2: //: significa caso 
		    consulta(); // Responsavel pela chamada da fun��o
		    break; // significa quebra
		    
		    case 3: // significa caso 
		    deletar(); // Responsavel pela chamada da fun��os 
		    break; // significa quebra 
		    
		    case 4: // significa caso 
		    printf("Obrigado por ultilizar o sistema!\n"); // Responsavel por trazer o texto para o usu�rio
		    return 0; // Responsavel por retorna o valor zero e sair do sistema                                                              
		    break; // significa quebra
		     
		    default: // default caso nemhuma conpara��o case seja verdadeira a estrutura executar� a cl�usula default 
		    printf("Essa op��o n�o est� disponivel!\n"); // Responsavel por trazer o texto para o usu�rio 
		    system("pause"); // responsavel por pausa o sistema at� o usu�rio decidir 
		    break; // significa quebra 
		}
    }
}

#include <stdio.h> // bibblioteca de comunica��o com o usu�rio
#include <stdlib.h> // biblioteca de aloca��o de espa�o e mem�ria
#include <locale.h> // biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() // fun��o responsavel por registra os usu�rios no sistema 
{ 
	// Inicio da cria��o de vari�veis/string
	char arquivo[40]; 
	char cpf[40]; 
	char nome[40]; 
	char sobrenome[40]; 
	char cargo[40]; 
	// Final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); // significa trazer o texto para o usu�rio 
	scanf("%s", cpf); // significa coleta informa��es do usu�rio  
	
	strcpy(arquivo, cpf); // respons�vel por copiar as valores das string 
	
	FILE *file; // cria o arquivo no bando de dados (computador) 
	file = fopen(arquivo, "w"); // cria o arquivo na pasta onde salvo o sistema 
	fprintf(file,cpf); // salva o valor da vari�vel 
	fclose(file); // fecha o arquivo 
	
	file = fopen(arquivo, "a"); // atualizar o arquivo na pasta onde salvo o sistema
	fprintf(file,","); // fprintf significa  salvar o valor da vari�vel 
	fclose(file); // fecha o arquivo 
	
	printf("Digite o nome a ser cadastrado: "); // significa trazer o texto para o usu�rio 
	scanf("%s",nome); // significa coleta informa��es do usu�rio
	
	file = fopen(arquivo, "a"); // atualizar o arquivo na pasta onde salvo o sistema
	fprintf(file,nome); // salva o valor da vari�vel 
	fclose(file); // fecha o arquivo 
	
	file = fopen(arquivo, "a"); // atualizar o arquivo na pasta onde salvo o sistema
	fprintf(file,","); // fprintf significa salvar o valor da vari�vel 
	fclose(file); // fecha o arquivo 
	
	printf("Digite o sobrenome a ser cadastrado: "); // significa trazer o texto para o usu�rio 
	scanf("%s",sobrenome); // significa coleta informa��es do usu�rio 
	
	file = fopen(arquivo, "a"); // atualizar o arquivo na pasta onde salvo o sistema
	fprintf(file,sobrenome); // salva o valor da vari�vel 
	fclose(file); // fecha o arquivo 
	
	file = fopen(arquivo, "a"); // atualizar o arquivo na pasta onde salvo o sistema
	fprintf(file,","); // fprintf significa  salvar o valor da vari�vel 
	fclose(file); // fecha o arquivo 
	
	printf("Digite o cargo a ser cadastrado: "); // significa trazer o texto para o usu�rio 
	scanf("%s",cargo); 
	
	file = fopen(arquivo, "a"); // atualizar o arquivo na pasta onde salvo o sistema
	fprintf(file,cargo); // salva o valor da vari�vel 
	fclose(file); // fecha o arquivo
	
	system("pause"); // responsavel por pausa o sistema at� o usu�rio decidir 
	
}

int consulta() // fun��o responsavel por consulta os usu�rios no sistema
{ 
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	// Inicio da cria��o de vari�veis/string
	char cpf[40]; 
	char conteudo[200]; 
	// Final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser consultado: "); // significa trazer o texto para o usu�rio 
	scanf("%s",cpf); // significa coleta informa��es do usu�rio 
	
	FILE *file; // cria o arquivo no bando de dados (computador) 
	file = fopen(cpf,"r"); // Ler o arquivo na pasta onde salvo o sistema 
	
	if(file == NULL) // if significa (se) // () significa como o dado deve ser formatado // file sginifica nome do arquivo // == significa compara��o // NULL significa nulo
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n"); // significa trazer o texto para o usu�rio 
	}
	
	while(fgets(conteudo, 200, file) != NULL) // sigficica enquanto 
	{
		printf("\nEssas s�o as informa��es do usu�rio: "); // significa trazer o texto para o usu�rio 
		printf("%s", conteudo); // significa mostra a informa��o para o usu�rio 
		printf("\n\n"); // significa trazer o texto para o usu�rio
	}
	
	system("pause"); // responsavel por pausa o sistema at� o usu�rio decidir 
}

int deletar() // fun��o responsavel por deletar os usu�rios no sistema
{ 
	// Inicio da cria��o de vari�veis/string
	char cpf[40]; 
	// Final da cria��o de vari�veis/string
	
	printf("Digite o CPF do usu�rio a ser deletado: "); // significa trazer o texto para o usu�rio 
	scanf("%s",cpf); // significa coleta informa��es do usu�rio 
	
	remove(cpf); // deletar arquivo cpf 
	
	FILE *file; // cria o arquivo no bando de dados (computador) 
	file = fopen(cpf,"r"); // Ler o arquivo na pasta onde salvo o sistema 
	
	if(file == NULL) // if significa (se) // () significa como o dado deve ser formatado // file sginifica nome do arquivo // == significa compara��o // NULL significa nulo
	{
		printf("O usu�rio n�o se encontra no sistema!.\n"); // significa trazer o texto para o usu�rio 
		system("pause"); // responsavel por pausa o sistema at� o usu�rio decidir 
	}
}	

int main() // significa fun��o principal, onde vai est� rodando o n�cleo do projeto 
{ 
	int opcao=0; // definindo as vari�veis 
	int laco=1; // definindo as vari�veis 
	
	for(laco=1;laco=1;) // significa fa�a/repita quantas vezes pedir 
	{
		
		system("cls"); // Responsavel por limpar 
	
	    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
		
		//Inicio do menu
	    printf("### Cart�rio da EBAC ###\n\n"); 
	    printf("Escolha a op��o desejada do menu:\n\n"); 
	    printf("\t1 - Registrar nomes\n");  
	    printf("\t2 - Consultar nomes\n"); 
	    printf("\t3 - Deletar nomes\n\n"); 
	    printf("\t4 - Sair do sistema\n\n");
	    printf("Op��o: ");
		//Fim do menu 
	
	    scanf("%d", &opcao); // armazenando a escolha do usu�rio 
	
	    system("cls"); // Responsavel por limpar 
	
	    switch(opcao) // Inicio da sele��o do menu 
		{
			case 1: // significa caso 
			registro(); // chamada de fun��es o
		    break; // significa quebra 
		    
		    case 2: //: significa caso 
		    consulta(); // chamada de fun��es
		    break; // significa quebra
		    
		    case 3: // significa caso 
		    deletar(); // chamada de fun��es 
		    break; // significa quebra 
		    
		    case 4: // significa caso 
		    printf("Obrigado por ultilizar o sistema!\n"); // significa trazer o texto para o usu�rio
		    return 0; // sginifica retorna o valor zero e sair do sistema                                                              
		    break; // significa quebra
		     
		    default: // default caso nemhuma conpara��o case seja verdadeira a estrutura executar� a cl�usula default 
		    printf("Essa op��o n�o est� disponivel!\n"); // significa trazer o texto para o usu�rio 
		    system("pause"); // responsavel por pausa o sistema at� o usu�rio decidir 
		    break; // significa quebra 
		}
    }
}

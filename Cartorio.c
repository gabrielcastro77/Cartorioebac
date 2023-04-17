#include <stdio.h> // bibblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca de alocação de espaço e memória
#include <locale.h> // biblioteca de alocaçães de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() // função responsavel por registra os usuários no sistema 
{ 
	// Inicio da criação de variáveis/string
	char arquivo[40]; 
	char cpf[40]; 
	char nome[40]; 
	char sobrenome[40]; 
	char cargo[40]; 
	// Final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); // significa trazer o texto para o usuário 
	scanf("%s", cpf); // significa coleta informações do usuário  
	
	strcpy(arquivo, cpf); // responsável por copiar as valores das string 
	
	FILE *file; // cria o arquivo no bando de dados (computador) 
	file = fopen(arquivo, "w"); // cria o arquivo na pasta onde salvo o sistema 
	fprintf(file,cpf); // salva o valor da variável 
	fclose(file); // fecha o arquivo 
	
	file = fopen(arquivo, "a"); // atualizar o arquivo na pasta onde salvo o sistema
	fprintf(file,","); // fprintf significa  salvar o valor da variável 
	fclose(file); // fecha o arquivo 
	
	printf("Digite o nome a ser cadastrado: "); // significa trazer o texto para o usuário 
	scanf("%s",nome); // significa coleta informações do usuário
	
	file = fopen(arquivo, "a"); // atualizar o arquivo na pasta onde salvo o sistema
	fprintf(file,nome); // salva o valor da variável 
	fclose(file); // fecha o arquivo 
	
	file = fopen(arquivo, "a"); // atualizar o arquivo na pasta onde salvo o sistema
	fprintf(file,","); // fprintf significa salvar o valor da variável 
	fclose(file); // fecha o arquivo 
	
	printf("Digite o sobrenome a ser cadastrado: "); // significa trazer o texto para o usuário 
	scanf("%s",sobrenome); // significa coleta informações do usuário 
	
	file = fopen(arquivo, "a"); // atualizar o arquivo na pasta onde salvo o sistema
	fprintf(file,sobrenome); // salva o valor da variável 
	fclose(file); // fecha o arquivo 
	
	file = fopen(arquivo, "a"); // atualizar o arquivo na pasta onde salvo o sistema
	fprintf(file,","); // fprintf significa  salvar o valor da variável 
	fclose(file); // fecha o arquivo 
	
	printf("Digite o cargo a ser cadastrado: "); // significa trazer o texto para o usuário 
	scanf("%s",cargo); 
	
	file = fopen(arquivo, "a"); // atualizar o arquivo na pasta onde salvo o sistema
	fprintf(file,cargo); // salva o valor da variável 
	fclose(file); // fecha o arquivo
	
	system("pause"); // responsavel por pausa o sistema até o usuário decidir 
	
}

int consulta() // função responsavel por consulta os usuários no sistema
{ 
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	// Inicio da criação de variáveis/string
	char cpf[40]; 
	char conteudo[200]; 
	// Final da criação de variáveis/string
	
	printf("Digite o CPF a ser consultado: "); // significa trazer o texto para o usuário 
	scanf("%s",cpf); // significa coleta informações do usuário 
	
	FILE *file; // cria o arquivo no bando de dados (computador) 
	file = fopen(cpf,"r"); // Ler o arquivo na pasta onde salvo o sistema 
	
	if(file == NULL) // if significa (se) // () significa como o dado deve ser formatado // file sginifica nome do arquivo // == significa comparação // NULL significa nulo
	{
		printf("Não foi possivel abrir o arquivo, não localizado!.\n"); // significa trazer o texto para o usuário 
	}
	
	while(fgets(conteudo, 200, file) != NULL) // sigficica enquanto 
	{
		printf("\nEssas são as informações do usuário: "); // significa trazer o texto para o usuário 
		printf("%s", conteudo); // significa mostra a informação para o usuário 
		printf("\n\n"); // significa trazer o texto para o usuário
	}
	
	system("pause"); // responsavel por pausa o sistema até o usuário decidir 
}

int deletar() // função responsavel por deletar os usuários no sistema
{ 
	// Inicio da criação de variáveis/string
	char cpf[40]; 
	// Final da criação de variáveis/string
	
	printf("Digite o CPF do usuário a ser deletado: "); // significa trazer o texto para o usuário 
	scanf("%s",cpf); // significa coleta informações do usuário 
	
	remove(cpf); // deletar arquivo cpf 
	
	FILE *file; // cria o arquivo no bando de dados (computador) 
	file = fopen(cpf,"r"); // Ler o arquivo na pasta onde salvo o sistema 
	
	if(file == NULL) // if significa (se) // () significa como o dado deve ser formatado // file sginifica nome do arquivo // == significa comparação // NULL significa nulo
	{
		printf("O usuário não se encontra no sistema!.\n"); // significa trazer o texto para o usuário 
		system("pause"); // responsavel por pausa o sistema até o usuário decidir 
	}
}	

int main() // significa função principal, onde vai está rodando o núcleo do projeto 
{ 
	int opcao=0; // definindo as variáveis 
	int laco=1; // definindo as variáveis 
	
	for(laco=1;laco=1;) // significa faça/repita quantas vezes pedir 
	{
		
		system("cls"); // Responsavel por limpar 
	
	    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
		
		//Inicio do menu
	    printf("### Cartório da EBAC ###\n\n"); 
	    printf("Escolha a opção desejada do menu:\n\n"); 
	    printf("\t1 - Registrar nomes\n");  
	    printf("\t2 - Consultar nomes\n"); 
	    printf("\t3 - Deletar nomes\n\n"); 
	    printf("\t4 - Sair do sistema\n\n");
	    printf("Opção: ");
		//Fim do menu 
	
	    scanf("%d", &opcao); // armazenando a escolha do usuário 
	
	    system("cls"); // Responsavel por limpar 
	
	    switch(opcao) // Inicio da seleção do menu 
		{
			case 1: // significa caso 
			registro(); // chamada de funções o
		    break; // significa quebra 
		    
		    case 2: //: significa caso 
		    consulta(); // chamada de funções
		    break; // significa quebra
		    
		    case 3: // significa caso 
		    deletar(); // chamada de funções 
		    break; // significa quebra 
		    
		    case 4: // significa caso 
		    printf("Obrigado por ultilizar o sistema!\n"); // significa trazer o texto para o usuário
		    return 0; // sginifica retorna o valor zero e sair do sistema                                                              
		    break; // significa quebra
		     
		    default: // default caso nemhuma conparação case seja verdadeira a estrutura executará a cláusula default 
		    printf("Essa opção não está disponivel!\n"); // significa trazer o texto para o usuário 
		    system("pause"); // responsavel por pausa o sistema até o usuário decidir 
		    break; // significa quebra 
		}
    }
}

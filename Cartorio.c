#include <stdio.h> // bibblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca de alocação de espaço e memória
#include <locale.h> // biblioteca de alocaçães de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() // Função responsavel por registra os usuários no sistema 
{ 
	// Inicio da criação de variáveis/string
	char arquivo[40]; 
	char cpf[40]; 
	char nome[40]; 
	char sobrenome[40]; 
	char cargo[40]; 
	// Final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); // Responsável por trazer o texto para o usuário 
	scanf("%s", cpf); // Responsável por coletar as informações do usuário  
	
	strcpy(arquivo, cpf); // Responsável por copiar as valores das string 
	
	FILE *file; // Responsável por cria o arquivo no bando de dados (computador) 
	file = fopen(arquivo, "w"); // Responsável por cria o arquivo na pasta onde salvo o sistema 
	fprintf(file,cpf); // Responsável por salva o valor da variável 
	fclose(file); // Responsável por fecha o arquivo 
	
	file = fopen(arquivo, "a"); // Responsável por atualizar o arquivo na pasta onde salvo o sistema
	fprintf(file,","); // Responsável por salvar o valor da variável 
	fclose(file); // Responsável por fecha o arquivo 
	
	printf("Digite o nome a ser cadastrado: "); // Responsável por trazer o texto para o usuário 
	scanf("%s",nome); // Responsável por coletar informações do usuário
	
	file = fopen(arquivo, "a"); // Responsável por atualizar o arquivo na pasta onde salvo o sistema
	fprintf(file,nome); // Responsável por salva o valor da variável 
	fclose(file); // Responsável por fecha o arquivo 
	
	file = fopen(arquivo, "a"); // Responsável por atualizar o arquivo na pasta onde salvo o sistema
	fprintf(file,","); // Responsável por salvar o valor da variável 
	fclose(file); // Responsável por fecha o arquivo 
	
	printf("Digite o sobrenome a ser cadastrado: "); // Responsável por trazer o texto para o usuário 
	scanf("%s",sobrenome); // Responsável por coletar informações do usuário 
	
	file = fopen(arquivo, "a"); // Responsável por atualizar o arquivo na pasta onde salvo o sistema
	fprintf(file,sobrenome); // Responsável por salva o valor da variável 
	fclose(file); // Responsável por fecha o arquivo 
	
	file = fopen(arquivo, "a"); // Responsável por atualizar o arquivo na pasta onde salvo o sistema
	fprintf(file,","); // Responsável por salvar o valor da variável 
	fclose(file); // Responsável por fecha o arquivo 
	
	printf("Digite o cargo a ser cadastrado: "); // Responsável por trazer o texto para o usuário 
	scanf("%s",cargo); // Responsável por coletar informações do usuário 
	
	file = fopen(arquivo, "a"); // Responsável por atualizar o arquivo na pasta onde salvo o sistema
	fprintf(file,cargo); // Responsável por salva o valor da variável 
	fclose(file); // Responsável por fecha o arquivo
	
	system("pause"); // Responsavel por pausa o sistema até o usuário decidir 
	
}

int consulta() // Função responsavel por consulta os usuários no sistema
{ 
	setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	
	// Inicio da criação de variáveis/string
	char cpf[40]; 
	char conteudo[200]; 
	// Final da criação de variáveis/string
	
	printf("Digite o CPF a ser consultado: "); // Responsável por trazer o texto para o usuário 
	scanf("%s",cpf); // Responsável por coletar informações do usuário 
	
	FILE *file; // Responsável por cria o arquivo no bando de dados (computador) 
	file = fopen(cpf,"r"); // Responsável por ler o arquivo na pasta onde salvo o sistema 
	
	if(file == NULL) // if significa (se) // == significa comparação // NULL significa nulo
	{
		printf("Não foi possivel abrir o arquivo, não localizado!.\n"); // Responsável por trazer o texto para o usuário 
	}
	
	while(fgets(conteudo, 200, file) != NULL) // sigficica enquanto 
	{
		printf("\nEssas são as informações do usuário: "); // Responsável por trazer o texto para o usuário 
		printf("%s", conteudo); // Responsável por mostra a informação para o usuário 
		printf("\n\n"); // Responsável por trazer o texto para o usuário
	}
	
	system("pause"); // Responsavel por pausa o sistema até o usuário decidir 
}

int deletar() // Função responsavel por deletar os usuários no sistema
{ 
	// Inicio da criação de variáveis/string
	char cpf[40]; 
	// Final da criação de variáveis/string
	
	printf("Digite o CPF do usuário a ser deletado: "); // Responsável por trazer o texto para o usuário 
	scanf("%s",cpf); // significa coletar informações do usuário 
	
	remove(cpf); // Responsável por deletar arquivo cpf 
	
	FILE *file; // Responsável por cria o arquivo no bando de dados (computador) 
	file = fopen(cpf,"r"); // Responsável por ler o arquivo na pasta onde salvo o sistema 
	
	if(file == NULL) // if significa (se) // == significa comparação // NULL significa nulo
	{
		printf("O usuário não se encontra no sistema!.\n"); // Responsável por trazer o texto para o usuário 
		system("pause"); // Responsavel por pausa o sistema até o usuário decidir 
	}
}	

int main() // Função principal, onde vai está rodando o núcleo do projeto 
{ 
	// Inicio da criação de variáveis
	int opcao=0;  
	int laco=1;  
	// Final da criação de variáveis
	
	for(laco=1;laco=1;) // Responsavel por fazer/repetir quantas vezes pedir 
	{
		
		system("cls"); // Responsavel por limpar 
	
	    setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
		
		// Inicio do menu
	    printf("### Cartório da EBAC ###\n\n"); 
	    printf("Escolha a opção desejada do menu:\n\n"); 
	    printf("\t1 - Registrar nomes\n");  
	    printf("\t2 - Consultar nomes\n"); 
	    printf("\t3 - Deletar nomes\n\n"); 
	    printf("\t4 - Sair do sistema\n\n");
	    printf("Opção: ");
		// Fim do menu 
	
	    scanf("%d", &opcao); // Responsavel por armazenar a escolha do usuário 
	
	    system("cls"); // Responsavel por limpar 
	
	    switch(opcao) // Inicio da seleção do menu 
		{
			case 1: // significa caso 
			registro(); // Responsavel pela chamada da função
		    break; // significa quebra 
		    
		    case 2: //: significa caso 
		    consulta(); // Responsavel pela chamada da função
		    break; // significa quebra
		    
		    case 3: // significa caso 
		    deletar(); // Responsavel pela chamada da funçãos 
		    break; // significa quebra 
		    
		    case 4: // significa caso 
		    printf("Obrigado por ultilizar o sistema!\n"); // Responsavel por trazer o texto para o usuário
		    return 0; // Responsavel por retorna o valor zero e sair do sistema                                                              
		    break; // significa quebra
		     
		    default: // default caso nemhuma conparação case seja verdadeira a estrutura executará a cláusula default 
		    printf("Essa opção não está disponivel!\n"); // Responsavel por trazer o texto para o usuário 
		    system("pause"); // responsavel por pausa o sistema até o usuário decidir 
		    break; // significa quebra 
		}
    }
}

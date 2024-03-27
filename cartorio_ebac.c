#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> // biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro() //função responsável por cadastrar usuários no sistema
{
	//inicio criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final criação de variáveis/string

	printf("Digite o CPF a ser cadastrado: "); //coletando informações do usuário
	scanf("%s", cpf); //%s refere-se a string (salvar a string)
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file, cpf); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo e o "a" significa atualizar o arquivo existente
	fprintf(file,","); //salvar dentro do arquivo e "," serve para dar um espaço
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //coletando informação do usuário
	scanf("%s",nome); //%s refere-se a string (salvar string)
	
	file = fopen(arquivo, "a"); //abre o arquivo e o "a" significa atualizar 
	fprintf(file,nome); //salva o valor da variável
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //coleta infromação do usuário
	scanf("%s",sobrenome); //%s refere-se a string (salvar a string)
	
	file = fopen(arquivo, "a"); //abre o arquivo e o "a" signifca atualizar o arquivo existente
	fprintf(file,sobrenome); //salva o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo e o "a" signifca atualizar o arquivo existente 
	fprintf(file,","); //salvar dentro do arquivo e "," serve para dar um espaço
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //coleta informações do usuário
	scanf("%s",cargo); //%s refere-se a string (salvar a string)
 	
	file = fopen(arquivo, "a"); //abre o arquivo e o "a" significa atualizar
	fprintf(file,cargo); //salva o valor da variávle
	fclose(file); //fecha o arquivo
	
	system("pause"); //pausa o sistema na tela desejada
	
	
	
}


int consulta() //responsável pela consulta dos usuários no sistema
{
	
	setlocale(LC_ALL, "Portuguese"); //definição de Linguagem
	
	//criação de variáveis/strings
	char cpf[40];
	char conteudo[200];
	//final da criação de variáveis/strings
	
	printf("Digite o CPF a ser consultado: "); //coletando informação do usuário
	scanf("%s",cpf); //%s refere-se a string (salvar a string)
	
	FILE *file;
	file = fopen(cpf,"r");
	
	
	if(file == NULL)
	{
		printf("Não foi possível abrir o arquivo, não localizado! .\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	fclose(file);
	
}


int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!.\n");
		system("pause");
	}
	
}


int main()
   {
    int opcao=0; //Definindo variáveis
    int laco=1;
    
    for(laco=1;laco=1;)
    {
	
	 system("cls"); //responsável por limpar a tela
	
    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
    
    printf("##  Cartório da EBAC  ##\n\n"); //inicio do menu
    printf("Escolha a opção desejada do menu\n\n");
    printf("\t1 - Registrar Nomes\n");
    printf("\t2 - Consultar Nomes\n");
    printf("\t3 - Deletar Nomes\n");
    printf("Opção:"); //fim do menu
    
    scanf("%d", &opcao); //armazenando a escolha do usuário
    
    system("cls");
    
    
    switch(opcao) //inicio da seleção
    {
    case 1:
    		registro(); //chamada de funções
    	break;
	
	case 2:
	        consulta();
    	break;
	
	case 3:
		    deletar();
		break;
			
	default:
		printf("Essa opção não está disponível!\n");
		system("pause");
		break; //final da seleção
		
	
	}    
  }
}


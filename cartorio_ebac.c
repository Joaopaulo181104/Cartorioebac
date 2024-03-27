#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> // biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro() //fun��o respons�vel por cadastrar usu�rios no sistema
{
	//inicio cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final cria��o de vari�veis/string

	printf("Digite o CPF a ser cadastrado: "); //coletando informa��es do usu�rio
	scanf("%s", cpf); //%s refere-se a string (salvar a string)
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file, cpf); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo e o "a" significa atualizar o arquivo existente
	fprintf(file,","); //salvar dentro do arquivo e "," serve para dar um espa�o
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s",nome); //%s refere-se a string (salvar string)
	
	file = fopen(arquivo, "a"); //abre o arquivo e o "a" significa atualizar 
	fprintf(file,nome); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //coleta infroma��o do usu�rio
	scanf("%s",sobrenome); //%s refere-se a string (salvar a string)
	
	file = fopen(arquivo, "a"); //abre o arquivo e o "a" signifca atualizar o arquivo existente
	fprintf(file,sobrenome); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo e o "a" signifca atualizar o arquivo existente 
	fprintf(file,","); //salvar dentro do arquivo e "," serve para dar um espa�o
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //coleta informa��es do usu�rio
	scanf("%s",cargo); //%s refere-se a string (salvar a string)
 	
	file = fopen(arquivo, "a"); //abre o arquivo e o "a" significa atualizar
	fprintf(file,cargo); //salva o valor da vari�vle
	fclose(file); //fecha o arquivo
	
	system("pause"); //pausa o sistema na tela desejada
	
	
	
}


int consulta() //respons�vel pela consulta dos usu�rios no sistema
{
	
	setlocale(LC_ALL, "Portuguese"); //defini��o de Linguagem
	
	//cria��o de vari�veis/strings
	char cpf[40];
	char conteudo[200];
	//final da cria��o de vari�veis/strings
	
	printf("Digite o CPF a ser consultado: "); //coletando informa��o do usu�rio
	scanf("%s",cpf); //%s refere-se a string (salvar a string)
	
	FILE *file;
	file = fopen(cpf,"r");
	
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado! .\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
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
		printf("O usu�rio n�o se encontra no sistema!.\n");
		system("pause");
	}
	
}


int main()
   {
    int opcao=0; //Definindo vari�veis
    int laco=1;
    
    for(laco=1;laco=1;)
    {
	
	 system("cls"); //respons�vel por limpar a tela
	
    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
    
    printf("##  Cart�rio da EBAC  ##\n\n"); //inicio do menu
    printf("Escolha a op��o desejada do menu\n\n");
    printf("\t1 - Registrar Nomes\n");
    printf("\t2 - Consultar Nomes\n");
    printf("\t3 - Deletar Nomes\n");
    printf("Op��o:"); //fim do menu
    
    scanf("%d", &opcao); //armazenando a escolha do usu�rio
    
    system("cls");
    
    
    switch(opcao) //inicio da sele��o
    {
    case 1:
    		registro(); //chamada de fun��es
    	break;
	
	case 2:
	        consulta();
    	break;
	
	case 3:
		    deletar();
		break;
			
	default:
		printf("Essa op��o n�o est� dispon�vel!\n");
		system("pause");
		break; //final da sele��o
		
	
	}    
  }
}


#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{	
	//In�cio cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a string

	strcpy(arquivo, cpf); //respons�vel por copiar valores das string

	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file,"CPF: ");
	fprintf(file,cpf); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",\nNOME: ");
	fclose(file);
	
	printf("Digite o NOME a ser cadastrado: ");
	scanf("%s", nome);
	
	file =fopen(arquivo,"a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",\nSOBRENOME: ");
	fclose(file);
	
	printf("Digite o SOBRENOME a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",\nCARGO: ");
	fclose(file);
	
	printf("Digite o CARGO a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fprintf(file, ".\n\n");
	fclose(file);
	
	system("pause");
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //definindo linguagem
	
	char cpf[40];
	char conteudo[200];

	printf("Digite o CPF que deseja consultar: ");
	scanf("%s",cpf); //armazena a vari�vel cpfuyilizando a fun��o string "%s"
	printf("\n");
	
	FILE *file;
	file = fopen(cpf,"r"); //abre o arquivo e l� as informa��es
	
	if(file == NULL)
	{
		printf("Usu�rio n�o cadastrado, arquivo n�o localizado!.\n\n");
	}
	
	else
	{
		printf("\nEssas s�o as informa��ess do usu�rio: \n\n"); //informa��o a aparecer antes dos dados 
	}
	
	
	
	while(fgets(conteudo, 200, file) != NULL) // emquanto tiver informa��o, armazene em conteudo se for diferente de nulo
	{
		printf("%s", conteudo);
	}
	
  	system("pause");
	fclose(file);
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio que deseja deletar: ");
	scanf("%s", cpf);

	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra em sistema!\n");
		system("pause");
	}
	
		else
	{
		printf("\t\nUsu�rio removido com sucesso!\n\n");
		system("pause");
	}
	
	fclose(file);
	remove(cpf);
}

int main ()
{
	int opcao=0; //definindo vari�veis
	int looping=1;
	
	for(looping=1;looping=1;)
	{
	
		system("cls");
	
		setlocale(LC_ALL, "Portuguese"); //definindo linguagem
	
		printf("\t\tCart�rio da EBAC\n\n"); //in�cio do menu
		printf("Bem vindo! Escolha a op��o desejada no menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n"),
		printf("\t3 - Deleter  nomes\n"); 
		printf("\t4 - Sair do sistema\n\n");
		printf("\tOpc�o: "); //fim do menu

		scanf("%d",&opcao); //armazenando a escolha do usu�rio
	
		system("cls"); //respons�vel por limpar a tela
	
		switch(opcao) //in�cio da sele��o
		{
			case 1:
			registro(); //chamada de fun��es
			break;
			
			case 2:
			consulta(); //chamada de fun��es
			break;
			
			case 3:
			deletar(); //chamada de fun��es
			break;
			
			case 4:
			printf("\tObrigado por utilizar o sistema!\n\n");
			return 0;
			break;
			
			default:
			printf("\t\tEst� op��o n�o est� dispon�vel!\n");
			system("pause");
			break;
			
		} //fim da sele��o
		
	}
	
}

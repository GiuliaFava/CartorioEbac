#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro() //Função responsável por cadastrar os usuários no sistema
{	
	//Início criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", cpf); //%s refere-se a string

	strcpy(arquivo, cpf); //responsável por copiar valores das string

	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file,"CPF: ");
	fprintf(file,cpf); //salva o valor da variável
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
	scanf("%s",cpf); //armazena a variável cpfuyilizando a função string "%s"
	printf("\n");
	
	FILE *file;
	file = fopen(cpf,"r"); //abre o arquivo e lê as informações
	
	if(file == NULL)
	{
		printf("Usuário não cadastrado, arquivo não localizado!.\n\n");
	}
	
	else
	{
		printf("\nEssas são as informaçõess do usuário: \n\n"); //informação a aparecer antes dos dados 
	}
	
	
	
	while(fgets(conteudo, 200, file) != NULL) // emquanto tiver informação, armazene em conteudo se for diferente de nulo
	{
		printf("%s", conteudo);
	}
	
  	system("pause");
	fclose(file);
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário que deseja deletar: ");
	scanf("%s", cpf);

	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra em sistema!\n");
		system("pause");
	}
	
		else
	{
		printf("\t\nUsuário removido com sucesso!\n\n");
		system("pause");
	}
	
	fclose(file);
	remove(cpf);
}

int main ()
{
	int opcao=0; //definindo variáveis
	int looping=1;
	
	for(looping=1;looping=1;)
	{
	
		system("cls");
	
		setlocale(LC_ALL, "Portuguese"); //definindo linguagem
	
		printf("\t\tCartório da EBAC\n\n"); //início do menu
		printf("Bem vindo! Escolha a opção desejada no menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n"),
		printf("\t3 - Deleter  nomes\n"); 
		printf("\t4 - Sair do sistema\n\n");
		printf("\tOpcão: "); //fim do menu

		scanf("%d",&opcao); //armazenando a escolha do usuário
	
		system("cls"); //responsável por limpar a tela
	
		switch(opcao) //início da seleção
		{
			case 1:
			registro(); //chamada de funções
			break;
			
			case 2:
			consulta(); //chamada de funções
			break;
			
			case 3:
			deletar(); //chamada de funções
			break;
			
			case 4:
			printf("\tObrigado por utilizar o sistema!\n\n");
			return 0;
			break;
			
			default:
			printf("\t\tEstá opção não está disponível!\n");
			system("pause");
			break;
			
		} //fim da seleção
		
	}
	
}

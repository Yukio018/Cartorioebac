#include <stdio.h>  //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o de mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respos�vel por cuidar das strings

int registro()  //Fun��o que criar os cadastros no sistema
{
	//inicio da cria��o das variav�is/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: \n"); //coletando informa��es do usu�rio
	scanf("%s", cpf); //%s se refere a string
	
	strcpy(arquivo, cpf); //respos�vel por criar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w");  //"w" � para gravar o arquivo (escrever)
	fprintf(file, cpf); //salvo o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	
	file = fopen(arquivo, "a"); //"a" � para abrir o arquivo
	fprintf(file, "\n");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, "Nome:");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, "\n");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen (arquivo, "a");
	fprintf(file, "Sobrenome:");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, "\n");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen (arquivo, "a");
	fprintf(file, "Cargo:");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
}


int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); //"r" � para ler o arquivo
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel consultar o CPF, arquivo n�o localizado!. \n ");
		
	}
	
	printf("\n Essas s�o as informa��es do usu�rio: ");
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	fclose(file);	
	system("pause");
}


int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s", cpf);
	
	
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O CPF n�o se encontra no sistema! \n");
		
		system("pause");		
	}
	
	fclose(file);
	
	if (file != NULL){
			remove(cpf);
			printf("Usu�rio deletado com sucesso! \n");
			system("pause");
		}
		
}


int main()
{
	int opcao = 0;  //definindo vari�veis
	int x = 1;
	
	for(x = 1; x = 1;)
	{
		
		system("cls");
	
	
		setlocale(LC_ALL, "Portuguese"); // definindo linguagem
	
		printf("---Registro de Alunos EBAC--- \n\n");
		printf("Escolha a op��o desejada do menu: \n\n");
		printf("\t 1- Registrar Usu�rio \n");               // \t indica um espa�o de par�grafo
		printf("\t 2- Consultar Usu�rio \n");
		printf("\t 3- Deletar Usu�rio \n\n\n\n");
		printf("Op��o:");
		
		scanf("%d", &opcao); //armazenando a escolha do usu�rio
		
		system("cls"); //respons�vel por limpar a tela
		
		
		switch(opcao) //inicio da sele��o menu
		{
			case 1:
				registro();  //chamada de fun��es
				break;
				
			case 2:
				consulta();
				break;
				
			case 3:
				deletar();
				break;
				
			default:
				printf("Op��o n�o dispon�vel \n");
				system("pause");
				break;
				
		}   //fim da sele��o
		
		
		//outra op��o com mais "ifs", � menos usado pois pode exigir mais do processamento em grandes sistemas
	 /*	if(opcao == 1) //inicio sele��o 
		{
			printf("Registrar Aluno Selecionado \n");
			system("pause"); //serve para aprecer a mensagem para o usu�rio at� o mesmo n�o querer mais 
		}
		
		if(opcao == 2)
		{
			printf("Consultar Aluno Selecionado \n");
			system("pause");	
		}
		
		if(opcao == 3)
		{
			printf("Deletar Aluno Selecionado \n");
			system("pause");
		}
		
		if(opcao >= 4 || opcao <=0 )
		{
			printf("Op��o n�o dispon�vel \n");
			system("pause");
		}
		*/
	
	}	
	

	//printf("Esse Software pertence a Gustavo Yukio Assaoka\n");
}

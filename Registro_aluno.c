#include <stdio.h>  //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço de memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca resposável por cuidar das strings

int registro()  //Função que criar os cadastros no sistema
{
	//inicio da criação das variavéis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: \n"); //coletando informações do usuário
	scanf("%s", cpf); //%s se refere a string
	
	strcpy(arquivo, cpf); //resposável por criar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w");  //"w" é para gravar o arquivo (escrever)
	fprintf(file, cpf); //salvo o valor da variável
	fclose(file); //fecha o arquivo
	
	
	file = fopen(arquivo, "a"); //"a" é para abrir o arquivo
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
	file = fopen(cpf, "r"); //"r" é para ler o arquivo
	
	if(file == NULL)
	{
		printf("Não foi possível consultar o CPF, arquivo não localizado!. \n ");
		
	}
	
	printf("\n Essas são as informações do usuário: ");
	
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
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf);
	
	
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O CPF não se encontra no sistema! \n");
		
		system("pause");		
	}
	
	fclose(file);
	
	if (file != NULL){
			remove(cpf);
			printf("Usuário deletado com sucesso! \n");
			system("pause");
		}
		
}


int main()
{
	int opcao = 0;  //definindo variáveis
	int x = 1;
	
	for(x = 1; x = 1;)
	{
		
		system("cls");
	
	
		setlocale(LC_ALL, "Portuguese"); // definindo linguagem
	
		printf("---Registro de Alunos EBAC--- \n\n");
		printf("Escolha a opção desejada do menu: \n\n");
		printf("\t 1- Registrar Usuário \n");               // \t indica um espaço de parágrafo
		printf("\t 2- Consultar Usuário \n");
		printf("\t 3- Deletar Usuário \n\n\n\n");
		printf("Opção:");
		
		scanf("%d", &opcao); //armazenando a escolha do usuário
		
		system("cls"); //responsável por limpar a tela
		
		
		switch(opcao) //inicio da seleção menu
		{
			case 1:
				registro();  //chamada de funções
				break;
				
			case 2:
				consulta();
				break;
				
			case 3:
				deletar();
				break;
				
			default:
				printf("Opção não disponível \n");
				system("pause");
				break;
				
		}   //fim da seleção
		
		
		//outra opção com mais "ifs", é menos usado pois pode exigir mais do processamento em grandes sistemas
	 /*	if(opcao == 1) //inicio seleção 
		{
			printf("Registrar Aluno Selecionado \n");
			system("pause"); //serve para aprecer a mensagem para o usuário até o mesmo não querer mais 
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
			printf("Opção não disponível \n");
			system("pause");
		}
		*/
	
	}	
	

	//printf("Esse Software pertence a Gustavo Yukio Assaoka\n");
}

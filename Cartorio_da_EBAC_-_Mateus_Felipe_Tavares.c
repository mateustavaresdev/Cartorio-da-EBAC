#include <stdio.h> //biblioteca de comunica��o de usu�rios
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de teto por regi�o
#include <string.h> //biblioteca respons�vel pelas strings

int registro() //fun��o respons�vel pelo cadastro de usu�rios no sistema

{
	
	//in�cio da cria��o de vari�veis/strings
	char arquivo [40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/strings
	printf("Digite o CPF:\n"); //coletando informa��es de usu�rios
	scanf("%s", cpf); //%s refere-se a strings
	
	strcpy(arquivo, cpf); //respons�vel por copiar os valores das strings
	
	FILE *file; //cria o arquivo com os dados
	file = fopen(arquivo, "w"); //cria o arquivo com os dados, "W" = "Escrever"
	fprintf(file,cpf); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo,"a"); //acrescenta informa��es ao arquivo
	fprintf(file,","); //insere a v�rgula na parte desejada
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome: "); //coletando informa��o de nome
	scanf("%s", nome); //refere-se a string
	
	file = fopen (arquivo,"a"); //acrescenta informa��es ao arquivo
	fprintf(file,nome); //insere o nome do usu�rio no aqruivo
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo,"a"); //acrescenta informa��es ao arquivo
	fprintf(file,","); //insere a v�rgula ap�s o nome do usu�rio
	fclose(file); //fecha o arquivo
	
	printf("Digite o Sobrenome: "); //coletando dados do usu�rio
	scanf("%s", sobrenome); //refere-se a string (vari�vel)
	
	file = fopen(arquivo,"a"); //acrescenta informa��es ao arquivo
	fprintf(file,sobrenome); //insere o sobrenome do usu�rio no arquivo
	fclose(file); //fecha o arquivo

	file = fopen(arquivo,"a"); //abre o arquivo para acrescentar informa��es
	fprintf(file,","); //insere a v�rgula ap�s o sobrenome
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo: "); //coletando informa��es do usu�rio
	scanf("%s", cargo); //refere=se a string (vari�vel)
	
	file = fopen(arquivo,"a"); //acrescenta informa��es ao arquivo
	fprintf(file,cargo); //adiciona o cargo do usu�rio no arquivo
	fclose(file); //fecha o arquivo
}

int consulta() //respons�vel pela consulta de cadastro de usu�rios

{
	setlocale(LC_ALL,"portuguese"); //permite a leitura da l�ngua portuguesa
	
	//in�cio da cria��o de strings
	char cpf[40];
	char conteudo[200];
	//fim da cria��o de strings
	
	printf("Digite o N�mero do CPF: "); //solitica o n�mero do CPF j� cadastrado
	scanf("%s",cpf); //refere-se a string (vari�vel)
	
	FILE *file; //acessa o arquivo do CPF digitado
	file = fopen(cpf,"r"); //l� o arquivo
	
	if(file == NULL) //cria uma fun��o condicionada
	{
		printf("Arquivo n�o localizado."); //aparecer� caso a resposta for incompat�vel
	}
	
	while(fgets(conteudo, 200, file) != NULL) //permite o aparecimento do cadastro do usu�rio sendo n�mero do CPF compat�vel
	{
		printf("\n Informa��es do Usu�rio:"); //antecede as informa��es do usu�rio
		printf("%s", conteudo); //mostra o usu�rio cadastrado
		printf("\n\n"); //cria afastamento de linha
	}
	
	system("pause"); //segura a tela das informa��es na tela
}

int deletar() //respons�vel pela exclus�o de cadastros

{
	char cpf[40]; //string/vari�vel a ser consultada
	
	printf("Digite o CPF: "); //solicita o CPF do cadastro a ser deletado
	scanf("%s", cpf); //refere-se � vari�vel
	
	remove(cpf); //apaga o CPF caso ele seja compat�vel
	
	FILE*file; //busca o arquivo do cadastro
	file = fopen(cpf,"r"); //abre o arquivo para leitura e para o apagar
	
	if(file == NULL) //cria um fun��o para caso o CPF seja apagado
	{
		printf("Usu�rio n�o Encontrado.\n\n"); //mensagem mostra quando o arquivo n�o existe ou � apagado
		system("pause"); //pausa a tela com a informa��o acima
	}
	
}

int main() //respons�vel pela cria��o do menu
{
	int opcao=0; //Definindo vari�veis
	int laco=1; //Definindo la�o
	
	for(laco=1;laco=1;) //cria o la�o de repti��o
	{
		system("cls"); //limpa a tela
			
		setlocale(LC_ALL,"portuguese"); //l� o portugu�s
	
		printf("### Cart�rio da EBAC ###\n\n"); //in�cio do menu
		printf("### Escolha a op�ao desejada do menu ###:\n\n"); //comando para o usu�rio do app
		printf("\t1 - Registrar Nomes\n"); //apresenta a op��o de registro ao usu�rio
		printf("\t2 - Consultar Nomes\n"); //apresenta a op��o de consulta ao usu�rio
		printf("\t3 - Deletar Nomes\n"); //apresenta a op��o de apagar cadastro da escola
		printf("\t4 - Sair do Sistema\n\n"); //apresenta a op��o de sair do sistema
		printf("Op��o:"); //fim do menu
	
		scanf("%d", &opcao); //armazenando a escolha do usu�rio
	
		system("cls"); //respons�vel por limpar a tela
	
		switch(opcao) //inicio das op��es do menu
	{
			case 1: //refere-se � op��o 1 acima
			registro(); //chamada de fun��es
			break; //finaliza a op��o
			
			case 2: //refere-se � segunda op��o
			consulta(); //chamada de fun��es
			break; //finaliza a op��o
			
			case 3: //refere-se � terceira op��o
			deletar(); //chamado de fun��es
			break; //finaliza a op��o
			
			case 4: //refere-se � quarta op��o
			printf("Obrigado por Utilizar o Sistema!\n\n"); //apresenta a frase de fechamento
			return 0; //realiza a opera��o de fechar o sistema
			break; //fecha a op��o 4
			
			default: //mostra a mensagem padr�o para op��o incompat�vel
			printf("Essa op��o n�o est� dispon�vel.\n\n"); //apresenta que o cadastro n�o foi encontrado
			system("pause"); //pausa na tela at� um novo comando
			break; //finaliza a op��o
			
	}
	}	
}
	

	

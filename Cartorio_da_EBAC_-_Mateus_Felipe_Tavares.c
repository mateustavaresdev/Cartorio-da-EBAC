#include <stdio.h> //biblioteca de comunicação de usuários
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de teto por região
#include <string.h> //biblioteca responsável pelas strings

int registro() //função responsável pelo cadastro de usuários no sistema

{
	
	//início da criação de variáveis/strings
	char arquivo [40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/strings
	printf("Digite o CPF:\n"); //coletando informações de usuários
	scanf("%s", cpf); //%s refere-se a strings
	
	strcpy(arquivo, cpf); //responsável por copiar os valores das strings
	
	FILE *file; //cria o arquivo com os dados
	file = fopen(arquivo, "w"); //cria o arquivo com os dados, "W" = "Escrever"
	fprintf(file,cpf); //salva o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo,"a"); //acrescenta informações ao arquivo
	fprintf(file,","); //insere a vírgula na parte desejada
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome: "); //coletando informação de nome
	scanf("%s", nome); //refere-se a string
	
	file = fopen (arquivo,"a"); //acrescenta informações ao arquivo
	fprintf(file,nome); //insere o nome do usuário no aqruivo
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo,"a"); //acrescenta informações ao arquivo
	fprintf(file,","); //insere a vírgula após o nome do usuário
	fclose(file); //fecha o arquivo
	
	printf("Digite o Sobrenome: "); //coletando dados do usuário
	scanf("%s", sobrenome); //refere-se a string (variável)
	
	file = fopen(arquivo,"a"); //acrescenta informações ao arquivo
	fprintf(file,sobrenome); //insere o sobrenome do usuário no arquivo
	fclose(file); //fecha o arquivo

	file = fopen(arquivo,"a"); //abre o arquivo para acrescentar informações
	fprintf(file,","); //insere a vírgula após o sobrenome
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo: "); //coletando informações do usuário
	scanf("%s", cargo); //refere=se a string (variável)
	
	file = fopen(arquivo,"a"); //acrescenta informações ao arquivo
	fprintf(file,cargo); //adiciona o cargo do usuário no arquivo
	fclose(file); //fecha o arquivo
}

int consulta() //responsável pela consulta de cadastro de usuários

{
	setlocale(LC_ALL,"portuguese"); //permite a leitura da língua portuguesa
	
	//início da criação de strings
	char cpf[40];
	char conteudo[200];
	//fim da criação de strings
	
	printf("Digite o Número do CPF: "); //solitica o número do CPF já cadastrado
	scanf("%s",cpf); //refere-se a string (variável)
	
	FILE *file; //acessa o arquivo do CPF digitado
	file = fopen(cpf,"r"); //lê o arquivo
	
	if(file == NULL) //cria uma função condicionada
	{
		printf("Arquivo não localizado."); //aparecerá caso a resposta for incompatível
	}
	
	while(fgets(conteudo, 200, file) != NULL) //permite o aparecimento do cadastro do usuário sendo número do CPF compatível
	{
		printf("\n Informações do Usuário:"); //antecede as informações do usuário
		printf("%s", conteudo); //mostra o usuário cadastrado
		printf("\n\n"); //cria afastamento de linha
	}
	
	system("pause"); //segura a tela das informações na tela
}

int deletar() //responsável pela exclusão de cadastros

{
	char cpf[40]; //string/variável a ser consultada
	
	printf("Digite o CPF: "); //solicita o CPF do cadastro a ser deletado
	scanf("%s", cpf); //refere-se à variável
	
	remove(cpf); //apaga o CPF caso ele seja compatível
	
	FILE*file; //busca o arquivo do cadastro
	file = fopen(cpf,"r"); //abre o arquivo para leitura e para o apagar
	
	if(file == NULL) //cria um função para caso o CPF seja apagado
	{
		printf("Usuário não Encontrado.\n\n"); //mensagem mostra quando o arquivo não existe ou é apagado
		system("pause"); //pausa a tela com a informação acima
	}
	
}

int main() //responsável pela criação do menu
{
	int opcao=0; //Definindo variáveis
	int laco=1; //Definindo laço
	
	for(laco=1;laco=1;) //cria o laço de reptição
	{
		system("cls"); //limpa a tela
			
		setlocale(LC_ALL,"portuguese"); //lê o português
	
		printf("### Cartório da EBAC ###\n\n"); //início do menu
		printf("### Escolha a opçao desejada do menu ###:\n\n"); //comando para o usuário do app
		printf("\t1 - Registrar Nomes\n"); //apresenta a opção de registro ao usuário
		printf("\t2 - Consultar Nomes\n"); //apresenta a opção de consulta ao usuário
		printf("\t3 - Deletar Nomes\n"); //apresenta a opção de apagar cadastro da escola
		printf("\t4 - Sair do Sistema\n\n"); //apresenta a opção de sair do sistema
		printf("Opção:"); //fim do menu
	
		scanf("%d", &opcao); //armazenando a escolha do usuário
	
		system("cls"); //responsável por limpar a tela
	
		switch(opcao) //inicio das opções do menu
	{
			case 1: //refere-se à opção 1 acima
			registro(); //chamada de funções
			break; //finaliza a opção
			
			case 2: //refere-se à segunda opção
			consulta(); //chamada de funções
			break; //finaliza a opção
			
			case 3: //refere-se à terceira opção
			deletar(); //chamado de funções
			break; //finaliza a opção
			
			case 4: //refere-se à quarta opção
			printf("Obrigado por Utilizar o Sistema!\n\n"); //apresenta a frase de fechamento
			return 0; //realiza a operação de fechar o sistema
			break; //fecha a opção 4
			
			default: //mostra a mensagem padrão para opção incompatível
			printf("Essa opção não está disponível.\n\n"); //apresenta que o cadastro não foi encontrado
			system("pause"); //pausa na tela até um novo comando
			break; //finaliza a opção
			
	}
	}	
}
	

	

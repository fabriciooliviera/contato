#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_AGENDA 50

typedef struct {
	char nome[50];
	int contato;
} registro;

void imprimeMenu() {
	system("cls");
	printf("\n");
	printf("\n");
	printf("\t\t***********************\n");
	puts("\t\t* Agenda eletronica   *");
	puts("\t\t***********************");
	puts("\t\t*  1 - Novo Contato   *");
	puts("\t\t*  2 - Lista Contatos *");
	puts("\t\t*  S - Sair           *");
	printf("\t\t*  Escolha uma opcao: * \n");
	printf("\t\t***********************\n");
	
}

void criaContato(registro r[], int *tamanho) {
	int indice = *tamanho;
	system("cls");
	printf("\n");
	printf("\n");
	printf("\t\t Digite o nome: ");
	scanf("%s", r[indice].nome);
	printf("\t\t Digite o contato : ");
	scanf("%d", &r[indice].contato);
	*tamanho = *tamanho + 1;
	
}

void listaContatos(registro r[], int *tamanho) {
	int tam = *tamanho;
	system("cls");
	printf("\t\t************************\n");
	puts("\t\t*  Lista de Contatos   *");
	printf("\t\t************************\n");
	puts("Nome\tIdade\n");
	
	for (int i = 0; i < tam; i++) {
		printf("%s\t%d\n", r[i].nome, r[i].contato);
	}
	system("pause");
}

void processaOpcao(int opcao, registro r[], int *tamanho) {
	switch(opcao) {
		case '1':
			criaContato(r, tamanho);
			break;
		case '2':
			listaContatos(r, tamanho);
			break;
		case 's':
			puts("Encerrando...\n");
			break;
		default:
			puts("Opção inválida!\n");
			break;
	}
}

int main() {
	FILE *arquivo;
	char *nome_arquivo = "teste.txt";
	char op;

	registro agenda[MAX_AGENDA];

	int tamanho = 0;
	// lê o arquivo e carrega seu conteúdo para o vetor "agenda", se existir
	arquivo = fopen(nome_arquivo, "rb");
	if (arquivo != NULL) {
		fread(&tamanho, sizeof(int), 1, arquivo);
		fread(agenda, sizeof(registro), MAX_AGENDA, arquivo);
		fclose(arquivo);
	
	
	} else {
		puts("Sem arquivo!"); 
		system("pause");
	}
	do {
	
		imprimeMenu();
		op = tolower(getchar());
		processaOpcao(op, agenda, &tamanho);
		fflush(stdin); // limpa o buffer do teclado (para remover lixos)
	} while (op != 's');

	// grava o arquivo, com o conteúdo do vetor, ao sair
	arquivo = fopen(nome_arquivo, "wb");
	fwrite(&tamanho, sizeof(int), 1, arquivo);
	fwrite(agenda, sizeof(registro), MAX_AGENDA, arquivo);
	fclose(arquivo);

	return 0;
}

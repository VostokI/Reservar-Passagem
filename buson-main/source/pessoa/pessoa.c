#include "pessoa.h"
#include "../../source/tools/tools.h"

#include <stdlib.h>
#include <string.h>
#include <time.h>

Pessoa * alocarPessoaVazia(int cpf, char * nome)//copia id para id nome para nome
{
        Pessoa * p = calloc(sizeof(Pessoa), 1);
        char status;
        //p-> cpf = cpf;
        //p-> nome = copiaAlocaString(nome);
        return p;
}

Pessoa * alocarVetorPessoasVazias(int qtd) //Retorna um ponteiro para um vetor de pessoas de tamanho qtd
{
        Pessoa * p = calloc(sizeof(Pessoa), qtd);
        return p;
}

void desalocarPessoa_s(Pessoa * pe)//desaloca uma Pessoa ou um vetor de pessoas,
{
        //free(pe->nome);
        //desalocarPedido( pe->vetPedidos);
        free(pe);
}

void lerPessoaJaAlocada(Pessoa * pe)//le Pessoa da tela
{
        printf("Informe o nome: \n");
        scanf("%s",pe->nome);
        printf("informe o CPF: \n");
        scanf("%lld",&(pe->cpf));
}

void preenchePessoaJaAlocada(Pessoa * pe, char * msg)//apenas preenche com dados aleatórios
{
        //printf("Informe o nome: \n");
        //scanf("%s",pe->nome);
        //printf("informe o CPF: \n");
		if (pe == NULL)
			return;
		char * aleat = randstring(rand()%10+5);
		strcpy(pe->nome, aleat);
		pe->cpf = rand()%99999999999;
		
        //scanf("%d",&(pe->cpf));
}
void imprimePessoaTab(Pessoa * pe)
{
	printf("%s\t", pe->nome);
    printf("%lld\t", pe->cpf);
	if (pe->status == ativo)
		printf("Ativo\t");
	if (pe->status == inativo)
		printf("Inativo\t");
	if (pe->status == deletado)
		printf("Deletado\t");
	printf("\n");
}
void imprimirPessoa(Pessoa * pe)//imprime Pessoa na tela
{
        printf("Nome do cliente: \t%s\n", pe->nome);
        printf("CPF do cliente: \t%lld\n", pe->cpf);
		printf("Status:\t");
		if (pe->status == ativo)
			printf("Ativo");
		if (pe->status == inativo)
			printf("Inativo");
		if (pe->status == deletado)
			printf("Deletado");
		printf("\n");
}

void lerPessoaBin(Pessoa * pe, FILE * bin)//le Pessoa de um arquivo bin
{
        fread(pe, 1, sizeof(Pessoa), bin);
}

void escreverPessoaBin(Pessoa * pe, FILE * bin)//imprime Pessoa de um arquivo bin
{
        fwrite(pe, 1, sizeof(Pessoa), bin);
}


void lerVariasPessoaBin(Pessoa * pe, FILE * bin, int qtd)//le vetor de pessoas 
{
        fread(pe, qtd, sizeof(Pessoa), bin);
}

void escreverVariasPessoaBin(Pessoa * pe, FILE * bin, int qtd)//escrever vetor de pessoas
{
        fwrite(pe, qtd, sizeof(Pessoa), bin);
}


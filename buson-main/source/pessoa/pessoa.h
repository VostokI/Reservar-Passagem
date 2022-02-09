#ifndef PESSOA_INCLUDED
#define PESSOA_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "../../source/bd/bd.h"

/*


gcc testes/pessoa/teste-pessoa.c source/pessoa/pessoa.c source/vendor/conio-master/conio.c source/tools/tools.c*/

typedef struct _Pessoa{
    char nome[sizeof("Pedro de Alcântara Francisco Antônio João Carlos Xavier de Paula Miguel Rafael Joaquim José Gonzaga Pascoal Cipriano Serafim de Bragança e Bourbon")];//
    size_t id;
	unsigned long long int cpf;
    enum status_possiveis {ativo = 0,inativo,deletado} status;//por padrao a pessoa ;e inserida como ativa, já que ativo = 0
    //Pedido * vetPedidos;
    //int nPedidos;
}Pessoa;

Pessoa * alocarPessoaVazia(int cpf, char * nome);//copia id para id nome para nome
Pessoa * alocarVetorPessoasVazias(int n); //Retorna um ponteiro de viacoes
void desalocarPessoa_s(Pessoa * pe);//dessaloca uma Pessoa, e os vetores que ali estao alocados
void lerPessoaJaAlocada(Pessoa * pe);//le Pessoa da tela
void imprimirPessoa(Pessoa * pe);//imprime Pessoa na tela

void imprimePessoaTab(Pessoa * pe);
void lerPessoaBin(Pessoa * pe, FILE * bin);//le Pessoa de um arquivo bin
void escreverPessoaBin(Pessoa * pe, FILE * bin);//imprime Pessoa de um arquivo bin
void lerVariasPessoaBin(Pessoa * pe, FILE * bin, int qtd);
void escreverVariasPessoaBin(Pessoa * pe, FILE * bin, int qtd);
void preenchePessoaJaAlocada(Pessoa * pe, char *msg);



#endif // !Pessoa  

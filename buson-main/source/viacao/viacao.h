#ifndef VIACAO
#define VIACAO

#include <stdio.h>
#include <stdlib.h>
#include "../onibus/onibus.h"

//Dado um vetor de viacoes: 
//salvar e recuperar do arquivo
//ID qtd_onibus nome\n
typedef struct _viacao{
    char * nome;
    int id;
    Onibus * vetBus;
    int qtdOnibus;
}Viacao;



Viacao * alocarViacao(int id, char * nome);//copia id para id nome para nome
Viacao * alocarViacoes(int n); //Retorna um vetor  de viacoes
void desalocarViacao(Viacao * via);//dessaloca uma viacao, e os vetores que ali estao alocados
void lerViacao(Viacao * via);//le viacao da tela
void imprimirViacao(Viacao * via);//imprime viacao na tela
void lerViacaoBin(Viacao * via, FILE * bin);//le viacao de um arquivo bin
void imprimirViacaoBin(Viacao * via, FILE * bin);//imprime viacao de um arquivo bin
#endif // !VIACAO  

#ifndef ONIBUS
#define ONIBUS

#include <stdio.h>
#include <stdlib.h>
#include "../poltrona/poltrona.h"

//salvar e recuperar do arquivoÇ
//ID numero de poltronas e nome da linha\n 
typedef struct _Onibus{
    char * NomeDaLinha;
    int id;
    Poltrona * VetPoltronas;
    int NPoltronas;
    /*
    int NPoltronasPedidodas;
    int NPoltronasVendidas;
    int nLinhas;
    int nColunas;
    */
}Onibus;



Onibus * alocarOnibus(int id, int n_poltronas, char * NomeDaLinha /*, int linhas, int colunas*/);//copia id para id nome para nome
Onibus * alocarVariosOnibus(int n); //Retorna um ponteiro de viacoes
void desalocarOnibus(Onibus * via);//dessaloca uma Onibus, e os vetores que ali estao alocados
void lerOnibus(Onibus * via);//le Onibus da tela
void imprimirOnibus(Onibus * via);//imprime Onibus na tela
void lerOnibusBin(Onibus * via, FILE * bin);//le Onibus de um arquivo bin
void imprimirOnibusBin(Onibus * via, FILE * bin);//imprime Onibus de um arquivo bin
#endif // !Onibus  

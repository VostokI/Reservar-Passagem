#include "onibus.h"


/*

typedef struct _Onibus{
    char * NomeDaLinha;
    int id;
    Poltrona * VetPoltronas;
    int NPoltronas;
    int NPoltronasPedidodas;
    int NPoltronasVendidas;
    int nLinhas;
    int nColunas;
}Onibus;

*/

Onibus * alocarOnibus(int id, int n_poltronas, char * NomeDaLinha, int linhas, int colunas)//copia id para id nome para nome
{
    Onibus * bus = malloc(sizeof(Onibus));
    bus->id = id;
    //bus->nColunas = colunas;
    //bus->nLinhas = linhas;
    bus->NomeDaLinha = copiaAlocaString(NomeDaLinha);
    bus->NPoltronas = n_poltronas;
    return bus;
}


Onibus * alocarVariosOnibus(int n) //Retorna um ponteiro de viacoes
{
    char *nome = malloc(sizeof(char)*10);
    nome = "Empresa ";
    Onibus * bus = calloc(sizeof(Onibus),n);
    for (int i = 0; i < n; i++)
    {
        bus[i].id=i;
        bus[i].NomeDaLinha = copiaAlocaInteiroParaString(i,nome);
           
    }
    free(nome);
    return bus;
}


void desalocarOnibus(Onibus * via)//dessaloca uma Onibus, e os vetores que ali estao alocados
{   
    free(via->NomeDaLinha);
    free(via);

}


void lerOnibus(Onibus * via)//le Onibus da tela
{
    printf("Escreva o id do Onibus\n",via->id);
    //printf("Escreva o numero de colunas\n",via->nColunas);
    //printf("Escreva o numero de linhas\n",via->nLinhas);
    printf("Escreva o nome da linha do Onibus\n",via->NomeDaLinha);
    printf("Escreva o numero de poltronas do Onibus\n",via->NPoltronas);
}


void imprimirOnibus(Onibus * via)//imprime Onibus na tela
{
    printf("Escreva o id do Onibus\n");printf("Escreva o numero de colunas\n");

    printf("Escreva o numero de linhas\n");
    
    printf("Escreva o nome da Linha do Onibus\n");
    
    printf("Escreva o numero de poltronas do Onibus\n");
}


void lerOnibusBin(Onibus * via, FILE * bin)//le Onibus de um arquivo bin
{

}


void imprimirOnibusBin(Onibus * via, FILE * bin)//imprime Onibus de um arquivo bin
{


}


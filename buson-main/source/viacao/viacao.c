#include <stdio.h>
#include <string.h>
#include "viacao.h"
#include "../tools/tools.h"

Viacao * alocarViacao(int id, char * nome)
{
    Viacao * via = (Viacao * ) malloc(sizeof(Viacao));
    if (via == NULL)
        return NULL;
    via->id = id;
    via->nome = copiaAlocaString(nome);
    return via;
}


Viacao * alocarViacoes(int n)
{   
    char *nome = malloc(sizeof(char)*10);
    nome = "Empresa ";
    Viacao * via = (Viacao * ) malloc(sizeof(Viacao) * n);
    for (int i = 0; i < n; i++)
    {
        via[i].id = i;
        via[i].nome = copiaAlocaInteiroParaString(i, "");
    }
    free(nome);
} 

void desalocarViacao(Viacao * via)
{
    free(via->nome);
    free(via);

}


void lerViacao(Viacao * via)
{   printf("Escreva o id da Viacao\n");
    scanf("%d",&(via->id));
    printf("Escreva o nome da Viacao\n");
    scanf("%s",via->nome);
}


void imprimirViacao(Viacao * via)
{
    printf("Viacao:\t%s \tid:\t %d\n",via->nome,via->id);
}


void lerViacaoBin(Viacao * via, FILE * bin)
{

}


void imprimirViacaoBin(Viacao * via, FILE * bin)
{

}


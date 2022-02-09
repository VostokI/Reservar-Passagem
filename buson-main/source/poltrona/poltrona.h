#ifndef POLTRONA
#define POLTRONA

#include <stdio.h>
#include <stdlib.h>
#include "../pessoa/pessoa.h"


typedef struct _Poltrona{ 
    int id;
    char status[3];//2 caracteres + \n
}Poltrona;



Poltrona * alocarPoltrona(int id);//copia id para id nome para nome
Poltrona * alocarVariasPoltrona(int n); //Retorna um ponteiro de viacoes
void desalocarPoltrona(Poltrona * pol);//dessaloca uma Poltrona, e os vetores que ali estao alocados
void lerPoltrona(Poltrona * pol);//le Poltrona da tela
void imprimirPoltrona(Poltrona * pol);//imprime Poltrona na tela
#endif // !Poltrona  

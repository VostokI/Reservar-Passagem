#include <stdio.h>
#include "pedido.h"

/*

typedef struct _Pedido{
    int poltrona;//numero da poltrona em um onibus
    int idOnibus;//Id do onibus
    int cpf;//CPF do cliente
}Pedido;

*/

Pedido * alocarPedidoVazio()
{
    return calloc(sizeof(Pedido), 1);
}

Pedido * alocarVariasPedidos(int n)
{
    Pedido * r = calloc(sizeof(Pedido), n);
    return r;
}

void desalocarPedido(Pedido * re)
{
    free(re);
}

void lerPedido(Pedido * re)
{
    printf("Digite seu id de cliente:\t");
    scanf("%d", &(re->idCliente));
	printf("Digite sua poltrona:\t");
    scanf("%d", &(re->NumeroPoltrona));
	re->status = reservado;
    /*
	printf("Digite o ID do Onibus:\t");
    scanf("%d", &(re->idOnibus));
    printf("Digite o ID da Viacão:\t");
    scanf("%d", &(re->idViacao));
	*/
}

void imprimirTablePedido(Pedido * re)
{
    printf("%d\t", (re->NumeroPoltrona));
	printf("%d\t", (re->idCliente));
	//printf("Status:\t");
	if (re->status == livre)
	{
		printf("livre");
	}
	else if (reservado)
	{
		printf("reservado");
	}
	else if (vendido)
	{
		printf("vendido");
	}
	else if (cancelado)
	{
		printf("cancelado");
	}
	printf("\n");
}
void imprimirPedido(Pedido * re)
{
    printf("ID Cliente:\t%d\n", (re->idCliente));
	printf("Numero da Poltrona:\t%d\n", (re->NumeroPoltrona));
	printf("Status:\t");
	if (re->status == livre)
	{
		printf("livre");
	}
	else if (reservado)
	{
		printf("reservado");
	}
	else if (vendido)
	{
		printf("vendido");
	}
	else if (cancelado)
	{
		printf("cancelado");
	}
	printf("\n");
}



void lerPedidoBin(Pedido * re, FILE * bin)
{
    fread(re, 1, sizeof(Pedido), bin);
}

void imprimirPedidoBin(Pedido * re, FILE * bin)
{
    
}
void imprimeVaiosPedidosBin(Pedido * re, FILE * bin, int tamanho)
{

}

void LerVariosPedidosBin(Pedido * re, FILE * bin, int tamanho)
{
    fread(re, tamanho, sizeof(Pedido), bin);
}
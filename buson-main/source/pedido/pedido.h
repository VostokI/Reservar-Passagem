#ifndef PEDIDO_INCLUDED
#define PEDIDO_INCLUDED

#include <stdio.h>
#include <stdlib.h>


typedef struct _Pedido{
    int NumeroPoltrona;//numero da poltrona em um onibus
    //int idOnibus;//Id do onibus
    //int idViacao;
    int idCliente;//ID do cliente
    //int idPedido;
	enum status_pedidos {livre, reservado, vendido, cancelado} status;
}Pedido;

Pedido * alocarPedidoVazio();//copia id para id nome para nome
Pedido * alocarVariosPedidos(int n); //Retorna um ponteiro de viacoes

void imprimirTablePedido(Pedido * re);
void desalocarPedido(Pedido * re);//dessaloca uma Pedido, e os vetores que ali estao alocados
void lerPedido(Pedido * re);//le Pedido da tela
void imprimirPedido(Pedido * re);//imprime Pedido na tela
void lerPedidoBin(Pedido * re, FILE * bin);//le Pedido de um arquivo bin
void imprimirPedidoBin(Pedido * re, FILE * bin);//imprime Pedido de um arquivo bin
#endif // !Pedido  

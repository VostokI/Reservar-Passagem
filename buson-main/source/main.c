#include <stdio.h>

#include "bd/bd.h"

#include "pessoa/pessoa.h"

#include "pedido/pedido.h"
#include "onibus/onibus.h"
#include "viacao/viacao.h"
#include "tools/tools.h"
#include "vendor/conio-master/conio.h"




void listarPoltronas(int NumeroPoltronas, Table * pedidos, char * msg )
{
	int i=0;
	int sel = 0;
	Pedido * aux = malloc(sizeof(Pedido));
	for (i=0; i<NumeroPoltronas; i++)
	{
		
		
		if (readLineInTable(pedidos,aux, i, msg))
		{
			c_textcolor(GREEN);
			printf("%.2d", i);
		}
		else{
			switch (aux->status)
			{
				case reservado:
				{
					c_textcolor(YELLOW);
					printf("AR");
					break;
				}
				case vendido: 
				{
					c_textcolor(RED);
					printf("AV");
					break;
				}
				case livre:
				{
					c_textcolor(GREEN);
					printf("%.2d", i+1);
					break;
				}
				case cancelado:
				{
					
				}
				default:
				{
					c_textcolor(GREEN);
					printf("%.2d", i);
					break;
				}
			}
			
		}
		if ((1+i)%4 == 0)
			printf("\n\n");
		else{
			printf("\t");
		}
		
	}
	c_textcolor(WHITE);
	tecla();
}
int menuPoltronas(Table * clientes, Table * pedidos, char * msg)
{
	char * strPoltronas[] = {"Listar poltronas", "Voltar"};
	int selecao = menu(strPoltronas,2);

	switch (selecao)
	{
	case 0://new
		listarPoltronas(40, pedidos, msg);
		break;
	default:
		return 0;
	}

}

int menuClientes(Table * clientes, char * msg)
{
	char * strClientes[6] = {"Novo Cliente", "Consultar Cliente", "Atualizar Cliente", "Inativar Cliente", "Listar Clientes", "Voltar"};
	char * strTableClientes [] = {"Nome",  "CPF"};
	int selecao = menu(strClientes,6);
	Pessoa * aux = malloc(sizeof(Pessoa));
	int id_aux = 0;

	switch (selecao)
	{
	case 0://new
		lerPessoaJaAlocada(aux);
		if (createLineInTable(clientes, aux, msg))//em caso de erro
		{
			printf("%s", msg);
		}
		else{
			//return 0;
		}
			
		break;
	case 1://read
		printf("Digite o ID que deseja consultar:");
		scanf("%d", &id_aux);
		if (readLineInTable(clientes, aux, id_aux, msg))//em caso de erro
		{
			printf("%s", msg);
		}
		else{
			imprimirPessoa(aux);
			//return 0;
		}
		tecla();
		tecla();
		break;
	case 2://update
		printf("Digite o ID que deseja atualizar:");
		scanf("%d", &id_aux);
		lerPessoaJaAlocada(aux);
		if (updateLineInTable(clientes, aux, id_aux, msg))//em caso de erro
		{
			printf("%s", msg);
		}
		else{
			//return 0;
		}
		break;
	case 3://delete
		printf("Digite o ID que deseja atualizar:");
		scanf("%d", &id_aux);
		lerPessoaJaAlocada(aux);
		if (inactiveLineInTable(clientes, id_aux, msg))//em caso de erro
		{
			printf("%s", msg);
		}
		else{
			//return 1;
		}
		break;
	case 4://list
		if (listTable(clientes, strTableClientes, 2, msg))
		{
			printf("%s", msg);
		}
		tecla();
		
		tecla();
		break;
	default:
		return 0;
		break;
	}

	free(aux);
}


int menuPedidos(Table * pedidos, char * msg)
{
	char * strPedidos[6] = {"Novo Pedido", "Consultar Pedido", "Atualizar Pedido", "Cancelar Pedido", "Listar Pedidos", "Voltar"};
	char * strTablePedidos[] = { "n_pol", "id_cliente", "status"};
	int selecao;
	Pedido * aux = malloc(sizeof(Pedido));
	int id_aux = 0;

	while(1)
	{
		
	selecao = menu(strPedidos,6);
	switch (selecao)
	{
		case 0://new
			lerPedido(aux);
			if (createLineInTable(pedidos, aux, msg))//em caso de erro
			{
				printf("%s", msg);
			}
			else{
				return 0;
			}
				
			break;
		case 1://read
			printf("Digite o ID do pedido que deseja consultar:");
			scanf("%d", &id_aux);
			if (readLineInTable(pedidos, aux, id_aux, msg))//em caso de erro
			{
				printf("%s", msg);
			}
			else{
				imprimirPedido(aux);
				return 0;
			}
			tecla();
			break;
		case 2://update
			printf("Digite o ID do pedido que deseja atualizar:");
			scanf("%d", &id_aux);
			lerPedido(aux);
			if (updateLineInTable(pedidos, aux, id_aux, msg))//em caso de erro
			{
				printf("%s", msg);
			}
			else{
				return 0;
			}
			break;
		case 3://delete
			printf("Digite o ID do pedido que deseja cancelar:");
			scanf("%d", &id_aux);
			if (inactiveLineInTable(pedidos, id_aux, msg))//em caso de erro
			{
				printf("%s", msg);
			}
			else{
				return 1;
			}
			break;
		case 4://list

			if (listTable(pedidos,strTablePedidos, 3, msg ))
			{
				printf("%s", msg);
			}
			tecla();
			break;
		default:

			free(aux);
			return 0;
			break;
		}
		//tecla();
	}

	free(aux);
}


int menuPrincipal(Table * clientes, Table * pedidos, char * msg)
{
	while(1)
	{
		char * strPrincipal[4] = {"Clientes", "Pedidos", "Poltronas Livres", "Sair"};
		int selecao = menu(strPrincipal,4);

		switch (selecao)
		{
			case 0://Clientes
				menuClientes(clientes, msg);
				break;
			case 1://Pedidos
				menuPedidos(pedidos, msg);
				break;
			case 2://Pedidos
				menuPoltronas(clientes, pedidos, msg);
				break;
			case 3://sair
				return 0;
				break;
		}

	}
}

int main()
{

	Pessoa * aux = malloc(sizeof(Pessoa));

	char * msg = malloc(sizeof(char) * 1024);//para armazenar eventuais erros

    Table clientes;

	clientes.printer =  imprimePessoaTab;

	Table pedidos;
	pedidos.printer = imprimirTablePedido;

	if (createTable("clientes.bin",sizeof(Pessoa),  msg, &clientes))
	{
		printf("%s", msg);
		return -1;
	}
	if (createTable("poltrona.bin",sizeof(Pedido),  msg, &pedidos))
	{
		printf("%s", msg);
		return -1;
	}
	
	menuPrincipal(&clientes, &pedidos, msg);
	free(aux);
}
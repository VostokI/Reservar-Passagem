#include <stdio.h>
#include <stdlib.h>
#include "bd.h"
#include <time.h>
#include "../tools/tools.h"
#include <string.h>

char abreTabelaRW(Table * tab, char * msg, FILE ** arq)
{	
	*arq = fopen(tab->nome_arquivo, "r+b");
	if (*arq == NULL)
	{
		msg = "Erro ao abrir o arquivo.\n";
		return 1;
	}
	else{
		//msg = "Arquivo aberto com sucesso\n";
	}
	return 0;
}





char createTable(char * caminho_tabela, size_t sizeOfObj, char * msg, Table * tab)//sobrescreve se ja existir 
{
	srand(time(NULL));
	strcpy(tab->nome_arquivo, caminho_tabela);
	FILE * tabela = fopen(tab->nome_arquivo, "rb");
	if (tabela)
	{
		strcpy(msg, "Tabela acessada com sucesso\n");
		
		tab->sizeOfObj = sizeOfObj;
		fclose(tabela);
		return 0;
	}
	
    tabela = fopen(tab->nome_arquivo, "wb");
    if (tabela == NULL)
    {
        strcpy(msg, "nao foi possivel criar tabela\n");
        return 1;
    }
	strcpy(msg, "Tabela criada com sucesso\n");
	tab->sizeOfObj = sizeOfObj;
    fclose(tabela);
    return 0;
}


/*ptrObj já deve estar alocado, o conteúdo dele será escrito na tabela
*/

char createLineInTable(Table * tab, void * ptrObj, char * msg)
{
	FILE * arq;
	if (abreTabelaRW(tab, msg, &arq))
	{
		//printf("%s", msg);
		return 1;
	}
	if (arq == NULL)//caso tabela n aberta
		return 1;
	fseek(arq, 0, SEEK_END);//posiciona deslocado 0 em relação ao final do arquivo
	fwrite(ptrObj, tab->sizeOfObj, 1,arq);
	fclose(arq);
	return 0;
}

char updateLineInTable(Table * tab,  void * ptrObj,  size_t posicao , char * msg)
{
	FILE * arq;
	if (abreTabelaRW(tab, msg, &arq))
	{
		printf("%s", msg);
		return 1;
	}
	if (arq == NULL)//caso tabela n aberta
	{
		strcpy(msg, "Nao foi possivel abrir o arquivo");
		return 1;
	}
	fseek(arq, posicao * tab->sizeOfObj, SEEK_SET);//posiciona deslocado sizeof * pos em relacao ao inicio do arquivo
	fwrite(ptrObj, tab->sizeOfObj, 1,arq);
	fclose(arq);
	return 0;
}

char updateLineInTableWhere(Table * tab,  char * msg)
{

}

/*
ptrObj já deve estar alocado, o conteúdo do arquivo irá para ele.
*/
char readLineInTable(Table * tab, void * ptrObj,  size_t posicao , char * msg)
{
	FILE * arq;
	if (abreTabelaRW(tab, msg, &arq))
	{
		printf("%s", msg);
		return 0;
	}
	if (arq == NULL)//caso tabela n aberta
		return 1;
	
	fseek(arq, posicao * tab->sizeOfObj, SEEK_SET);//posiciona deslocado x*tamanho em relação ao inicio do arquivo
	fread(ptrObj, tab->sizeOfObj, 1,arq);
	if (feof(arq))
	{
		fclose(arq);
		return 0;
	}

	fclose(arq);
	return 1;
}

char inactiveLineInTable(Table * tab,  size_t posicao , char * msg)
{
	return 0;
}
char listTable(Table * tab, char * att[], int qtd, char * msg)
{	
	FILE * arq;
	
	if (abreTabelaRW(tab, msg, &arq))
	{
		printf("%s", msg);
		return 1;
	}
	if (arq == NULL)//caso tabela n aberta
		return 1;
	int i=0;
	for (i=0; i<qtd; i++)
		printf("%s\t", att[i]);
	printf("\n");
	void * aux = malloc(sizeof(char) * tab->sizeOfObj);
	
	for(i=0; readLineInTable(tab, aux, i, msg); i++)
	{
		tab->printer(aux);
	}
	
	tecla();
	return 0;
}
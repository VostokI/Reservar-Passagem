#ifndef BD_INCLUDED
#define BD_INCLUDED


typedef struct _table_bd
{
	char nome_arquivo[300];
	size_t sizeOfObj;//tamanho em bytes do objeto a ser armazenado
	void (*printer)( const void* obj);
}Table;


//char qtd(Table * tab,  void * ptrObj, size_t posicao , char * msg);
//char search(Table * tab, size_t * posicao, void * referencia,int (*compar)(const void* a,const void* b));
char updateLineInTable(Table * tab,  void * ptrObj, size_t posicao , char * msg);
char updateLineInTableWhere(Table * tab, char * msg);
/*
ptrObj já deve estar alocado, o conteúdo do arquivo irá para ele.
*/
char readLineInTable(Table * tab, void * ptrObj, size_t posicao , char * msg);

char inactiveLineInTable(Table * tab, size_t posicao , char * msg);

char createLineInTable(Table * tab, void * ptrObj, char * msg);

char abreTabelaRW(Table * tab, char * msg, FILE ** arq);
char createTable(char * caminho_tabela, size_t sizeOfObj, char * msg, Table * tab);

char listTable(Table * tab, char * att[], int qtd, char * msg);

/*ptrObj já deve estar alocado, o conteúdo dele será escrito na tabela
*/
#endif // !BD_INCLUDED
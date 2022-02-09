#ifndef TOOLS
#define TOOLS


#include <stdlib.h>



int tecla();
char * copiaAlocaString(char * str);

char * copiaAlocaInteiroParaString(int a, char * nome);

char *randstring(size_t length);

int menu(char * str[], int n);


void imprimeLento(char * str, int tempo);
#endif // !TOOLS
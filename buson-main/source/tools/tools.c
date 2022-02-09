#include "tools.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../vendor/conio-master/conio.h"
#include "../vendor/outro/delay.h"


#define ENTER 10
#define BAIXO 'B'
#define CIMA 'A'


char *randstring(size_t length) {

    static char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789       ";        
    char *randomString = NULL;
    if (length<1)
        return NULL;
    if (length) {
        randomString = malloc(sizeof(char) * (length +1));

        if (randomString) {            
            for (int n = 0;n < length;n++) {            
                int key = rand() % (int)(sizeof(charset) -1);
                randomString[n] = charset[key];
            }

            randomString[length] = '\0';
        }
    }

    return randomString;
}



char * copiaAlocaString(char * str)
{
    char * s = (char * ) malloc(sizeof(char) * strlen(str) +1 );
    strcpy(s, str);
    return s;
}


char * copiaAlocaInteiroParaString(int a, char *nome)
{
    char * s = malloc(sizeof(char) * 11 + 7);
    sprintf(s, "%s%d",nome,a);
    s = (char *) realloc (s,  sizeof(char) * ( (strlen(s))  +1 ));
    return s;
}


int tecla()
{
    char te;
    do {
        te = c_getch();//(stdin);
            //printf("%d\t", te);
        } while (te == -32);
    
    return te;
}



void limparTela()
{	
	system("clear || cls");
}

void ImprimeMenu(char * str[], int selec, int n, char * format)
{
	
	
	limparTela();
	
	//scanf("%*c");
    int i=0;
    for (i=0; i<n; i++)
    {
        printf(format, (selec == i) ? 'X' : ' ' ,   str[i]);
    }
}

void delay(int i)
{
    //sleep_ms(i);
}

void imprimeLento(char * str, int tempo)
{
    int i=0;
    for (i=0; str[i]!='\0'; i++)
    {
        printf("%c", str[i]);
        delay(tempo);
        
        fflush(stdout);
    }
}

int menu(char * str[], int n)
{
    int i=0;
    int s = 0; //selecao
    int te=0;
	//te = tecla();
    do {
        ImprimeMenu(str, s, n, "[%c] - %s\n");
        te = tecla();
        if (te == BAIXO && s<(n-1))
        {
            s++;
        }
        if (te == CIMA && s>0)
        {
            s--;
        }
    }
    while(te!=ENTER);
    return s;
}



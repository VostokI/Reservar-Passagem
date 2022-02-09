#include <stdio.h>
#include "poltrona.h"


// li livre
//vr pedidodo
// vendido
Poltrona * alocarPoltrona(int id)
{

    Poltrona * p;
    p->id = id;
    strcpy(p->status, "li");
    return p;
}


Poltrona * alocarVariasPoltrona(int n)
{
    int i=0;
    Poltrona * p = malloc(sizeof(Poltrona) * n);
    
    for (i=0; i<n; i++)
    {
        p[i].id = i;
        strcpy(p[i].status, "li");
    }
    
    return p;
}


void desalocarPoltrona(Poltrona * pol)
{
    free(pol);
}


void lerPoltrona(Poltrona * pol)
{
    printf("Escreva o id da Poltrona");
    scanf("%d",&(pol->id));
    printf("Escreva o status da poltrona");
    scanf("%s",pol->status);
}


void imprimirPoltrona(Poltrona * pol)
{
    printf("Id da Poltrona:\t%d\tStatus da Poltrona:\t%s\n",pol->id,pol->status);
}




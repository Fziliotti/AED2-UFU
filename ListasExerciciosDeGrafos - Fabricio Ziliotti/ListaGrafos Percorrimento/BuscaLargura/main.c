#include <stdio.h>
#include <stdlib.h>
#include "Grafo.h"
int main(){
    int eh_digrafo = 1; // grafo direcionado
   
    Grafo* gr = cria_Grafo(8, 8, 0);

    insereAresta(gr, 1, 4, !eh_digrafo, 0);
    insereAresta(gr, 2, 2, !eh_digrafo, 0);
    insereAresta(gr, 3, 6, !eh_digrafo, 0);
    insereAresta(gr, 1, 3, !eh_digrafo, 0);
    insereAresta(gr, 2, 5, !eh_digrafo, 0);
    insereAresta(gr, 4, 2, !eh_digrafo, 0);
    insereAresta(gr, 6, 1, !eh_digrafo, 0);
    insereAresta(gr, 5, 7, !eh_digrafo, 0);
    insereAresta(gr, 8, 1, !eh_digrafo, 0);
    insereAresta(gr, 5, 8, !eh_digrafo, 0);

    imprime_Grafo(gr);
    printf("\nBusca \n");
    int i,vis[8],ant[8];
    float dist[8];
    buscaLargura_Grafo(gr, 0, vis);
    for(i=0; i<8; i++)
        printf("%d: %d - %f\n",i,ant[i],dist[i]);

    printf("visitados: ");
    for(i=0; i<8; i++){
        printf("%d, ",i,ant[i],dist[i]);
    }

    libera_Grafo(gr);

    return 0;
}

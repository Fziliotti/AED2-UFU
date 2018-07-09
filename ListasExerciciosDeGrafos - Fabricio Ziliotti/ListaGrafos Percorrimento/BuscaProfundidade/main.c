#include <stdio.h>
#include <stdlib.h>
#include "Grafo.h"
int main(){
    int eh_digrafo = 1;
    Grafo* gr = cria_Grafo(8, 8, 0);

    insereAresta(gr, 1, 2, !eh_digrafo, 0);
    insereAresta(gr, 1, 3, !eh_digrafo, 0);
    insereAresta(gr, 2, 4, !eh_digrafo, 0);
    insereAresta(gr, 2, 5, !eh_digrafo, 0);
    insereAresta(gr, 3, 4, !eh_digrafo, 0);
    insereAresta(gr, 4, 5, !eh_digrafo, 0);
    insereAresta(gr, 4, 6, !eh_digrafo, 0);
    insereAresta(gr, 6, 7, !eh_digrafo, 0);
    insereAresta(gr, 6, 8, !eh_digrafo, 0);
    insereAresta(gr, 7, 8, !eh_digrafo, 0);

    imprime_Grafo(gr);
    printf("\nBusca \n");
    int i,vis[8],ant[8];
    float dist[8];
    buscaProfundidade_Grafo(gr, 0, vis);
    for(i=0; i<8; i++)
        printf("%d: %d -> %f\n",i,ant[i],dist[i]);

    printf("visitados: ");
    for(i=0; i<8; i++){
        printf("%d, ",i,ant[i],dist[i]);
    }

    libera_Grafo(gr);

    return 0;
}

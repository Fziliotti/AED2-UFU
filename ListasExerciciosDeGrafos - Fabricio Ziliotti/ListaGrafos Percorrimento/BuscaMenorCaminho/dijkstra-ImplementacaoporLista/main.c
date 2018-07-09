#include <stdio.h>
#include <stdlib.h>
#include "Grafo.h"
int main(){
    int eh_digrafo = 1;
    Grafo* gr = cria_Grafo(7, 7, 0);

    insereAresta(gr, 3, 4, !eh_digrafo, 0);
    insereAresta(gr, 1, 3, !eh_digrafo, 0);
    insereAresta(gr, 2, 5, !eh_digrafo, 0);
    insereAresta(gr, 2, 6, !eh_digrafo, 0);
    insereAresta(gr, 3, 2, !eh_digrafo, 0);
    insereAresta(gr, 4, 5, !eh_digrafo, 0);
    insereAresta(gr, 4, 6, !eh_digrafo, 0);
    insereAresta(gr, 5, 2, !eh_digrafo, 0);
    insereAresta(gr, 6, 1, !eh_digrafo, 0);

    imprime_Grafo(gr);
    printf("\nBusca \n");
    int i,vis[8],ant[8];
    float dist[8];
    menorCaminho_Grafo(gr, 0, ant, dist);
    for(i=0; i<8; i++) printf("%d: %d - %f\n",i,ant[i],dist[i]);

    printf("Visitados: ");
    for(i=0; i<8; i++) printf("%d, ",i,ant[i],dist[i]);
    

    libera_Grafo(gr);

    return 0;
}

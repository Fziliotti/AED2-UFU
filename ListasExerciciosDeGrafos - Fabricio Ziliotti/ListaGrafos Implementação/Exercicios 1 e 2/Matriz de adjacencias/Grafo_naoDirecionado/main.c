#include <stdio.h>
#include <stdlib.h>
#include "Grafo.h"
int main()
{
    //grafico com os vertices 0,1.2.3.4.5
    Grafo *G = cria_grafo(6);
    insere_aresta(G, 0, 1, 1);
    insere_aresta(G, 0, 2, 1);
    insere_aresta(G, 1, 2, 1);
    insere_aresta(G, 4, 5, 1);

    printf("GRAFO NAO DIRECIONADO PONDERADO\n\n");
    //MOSTRA NA FORMA DE MATRIZ DE ADJACENCIA
    mostra_grafo2(G);

    printf("\n\nGRAU DOS VERTICES DO GRAFO\n");
    mostra_grau(G);
    return 0;
}

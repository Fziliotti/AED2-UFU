#include <stdio.h>
#include <stdlib.h>
#include "Grafo.h"

int main(){
    int i,*P = malloc(sizeof(int));
    Grafo *g = cria_grafo(4,0);

    insere_aresta(g, 0, 1, 1);
    insere_aresta(g,0,2,4);

    verifica_aresta(g,1,0);
    insere_aresta(g,2,1,7);

    mostrar_grafo(g);
    libera_grafo(g);

    return 0;
}

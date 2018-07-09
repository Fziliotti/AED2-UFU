#include "grafoLista.h"
#include<stdio.h>
#include<stdlib.h>

struct grafo
{
    int qtde_vertices, qtde_arestas;
    int *grau;
    int **arestas;
};

Grafo* cria_grafo(int nro_vertices)
{
    if(nro_vertices <= 0) return NULL;

    Grafo *G = (Grafo*) malloc (sizeof(Grafo));
    if(G == NULL) return NULL;

    G->qtde_vertices = nro_vertices;
    G->qtde_arestas = 0;


    G->grau = (int*) calloc (nro_vertices, sizeof(int));
    if(G->grau == NULL)
    {
        free(G);
        return NULL;
    }

    G->arestas = (int **) malloc(nro_vertices *sizeof(int*));
    if(G->arestas == NULL)
    {
        free(G->grau);
        free(G);
        return NULL;
    }

    int i, k;
    for(i=0; i<nro_vertices; i++)
    {
        G->arestas[i]= (int*) calloc (nro_vertices, sizeof(int));
        if(G->arestas[i] == NULL)
        {
            for(k=0; k<i; k++) free (G->arestas[k]);
            free(G->arestas);
            free(G->grau);
            free(G);
            return NULL;
        }
    }
    return G;
}

int insere_aresta(Grafo *G, int V1, int V2, int P)
{
    if(G == NULL || V1<0 || V1 > G->qtde_vertices || V2<0 || V2 > G->qtde_vertices)
    {
        return -1;
    }
    if(G->arestas[V1][V2] != 0)
    {
        return 0;
    }

    G->arestas[V1][V2] = P;
    G->qtde_arestas++;
    G->grau[V1]++;
    G->grau[V2]++;
    return 1;
}

int verifica_aresta(Grafo *G, int V1, int V2)
{
    if(G == NULL || V1<0 || V1 > G->qtde_vertices || V2<0 || V2 > G->qtde_vertices)
    {
        return -1;
    }

    if(G->arestas[V1][V2] == 0) return 0;
    return 1;
}

int remove_aresta(Grafo *G, int V1, int V2)
{
    if(G == NULL || V1<0 || V1 > G->qtde_vertices || V2<0 || V2 > G->qtde_vertices)
    {
        return -1;
    }

    if(G->arestas[V1][V2] == 0)
    {
        return 0;
    }
    G->arestas[V1][V2] =0;
    G->qtde_arestas--;
    G->grau[V1]--;
    G->grau[V2]--;
    return 1;
}

int consulta_aresta(Grafo *G, int V1, int V2, int P)
{
    if(G == NULL || V1<0 || V1 > G->qtde_vertices || V2<0 || V2 > G->qtde_vertices)
    {
        return -1;
    }

    if(G->arestas[V1][V2] == 0) return 0;
    P = G->arestas[V1][V2];
    return 1;
}

void libera_grafo(Grafo *G)
{
    int k;
    int i = G->qtde_arestas;
    for (k = 0; k<i; k++)free(G->arestas[k]);
    free(G->arestas);
    free(G->grau);
    free(G);
    G = NULL;

}


void mostra_grafo (Grafo *G)
{
    if (G==NULL) printf("Grafo Inexistente!\n");
    else if ( G->qtde_arestas ==0) printf("Grafo vazio!\n");
    else
    {
        int i;
        for (i = 0; i < G->qtde_vertices; i++)
        {
            printf("Vertice %d: \n",i );
            mostra_adjacentes(G,i);
        }
    }
}

void mostra_grafo2 (Grafo *G)
{
    if (G==NULL) printf("Grafo Inexistente!\n");
    else if ( G->qtde_arestas ==0) printf("Grafo vazio!\n");
    else
    {
        int i,j;
        for (i = 0; i < G->qtde_vertices; i++)
        {
           for(j=0;j<G->qtde_vertices;j++){
            printf("  %d  ", G->arestas[i][j] );
           }
           printf("\n");
        }
    }
}

void mostra_adjacentes(Grafo *G, int V)
{

    if (G==NULL || V<0 || V > G->qtde_vertices) printf("Grafo Inexistente ou vertice errado!\n");
    else
    {
        int cont =0;
        int i;
        for(i=0; i<G->qtde_vertices; i++)
        {
            if(G->arestas[V][i]!=0)
            {
                printf("%d -> %d = %.1f\n", V, i, G->arestas[V][i]);
                cont++;
            }
        }
        if(!cont) printf("O vertice %d nao possui vertices adjacentes\n", V);
    }
}

void mostra_grau( Grafo *G){
    if (G==NULL) printf("Grafo Inexistente!\n");
    else{
        int i;
        for(i=0;i<G->qtde_vertices;i++){
            printf(" Vertice %d tem grau %d\n", i, G->grau[i]);
        }
    }
}




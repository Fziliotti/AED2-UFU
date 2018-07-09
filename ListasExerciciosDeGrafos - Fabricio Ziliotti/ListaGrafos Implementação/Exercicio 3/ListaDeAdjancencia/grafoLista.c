#include <stdio.h>
#include <stdlib.h>
#include "grafoLista.h"

struct no {
    int vertice;
    int peso;
    struct no *prox;
};

//ARRANJO QUE TEM O PONTEIRO PARA A LISTA LIGADA
//ESSA LISTA TERA O Vertice COM O PESO (OPCIONAL)

struct vertice {
    int grau;
    No * cabeca;
    //No* aresta; mesma coisa
};

struct grafo{
    int qtde_vertices;
    int qtde_arestas;
    Vertice * ListaVertices; // arranjo de vertices
    //Vertice * prox; mesma coisa
};


Grafo *criaGrafo (int nro_vertices){
    if (nro_vertices <= 0) return NULL;
    Grafo *G = (Grafo *) malloc(sizeof(Grafo));
    if(G == NULL) return NULL;

    G->qtde_vertices = nro_vertices;
    G->qtde_arestas = 0;

    G->ListaVertices = (Vertice *) malloc(nro_vertices* sizeof(Vertice));
    if(G->ListaVertices == NULL) return NULL;

    int i;
    for(i=0; i<nro_vertices;i++) G->ListaVertices[i].cabeca = NULL;
    return(G);
}

No* criaAdjacencia(int v, int peso){
    No *temp = (No *) malloc(sizeof(No));
    temp->vertice = v;
    temp->peso = peso;
    temp->prox = NULL;
    return temp;
}

int insere_aresta(Grafo *G, int V1, int V2, int P){
    if(G == NULL || V1<0 || V2<0 || V1 >= G->qtde_vertices || V2 >= G->qtde_vertices) return 0;
    No * novo = criaAdjacencia(V2,P);
    novo->prox = G->ListaVertices[V1].cabeca;
    G->ListaVertices[V1].cabeca = novo;
    G->qtde_arestas++;
    return 1;
}

void imprimeGrafo (Grafo *G){
    printf("Vertice: %d. Arestas: %d. \n", G->qtde_vertices, G->qtde_arestas);
    int i;
    for(i=0; i < G->qtde_vertices;i++){
        printf("v%d: ",i);
        No* ad = G->ListaVertices[i].cabeca;
        while(ad != NULL){
            printf("v%d(%d) ", ad->vertice, ad->peso);
            ad = ad->prox;
        }
        printf("\n");
    }
}

//void libera_grafo(Grafo* G){
//
//}

//void libera_grafo(Grafo* G){
//
//}


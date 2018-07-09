#include <stdio.h>
#include <stdlib.h>
#include "Grafo.h"

struct no{
    int vertice;
    int peso;
    struct no *prox;
};

struct grafo{
    int n_vertice,n_aresta;
    int *grau;
    int eh_digrafo;
    struct no **aresta;
};

Grafo *cria_grafo(int n_vertice,int eh_digrafo){
    int i;
    if(n_vertice < 1 || eh_digrafo < 0 || eh_digrafo > 1)return NULL;
    Grafo *g = (Grafo *)malloc(sizeof(Grafo));
    if(g != NULL){
        g->n_vertice = n_vertice;
        g->n_aresta = 0;
        g->eh_digrafo = eh_digrafo;
        g->grau = (int *)malloc(n_vertice*sizeof(int));
        for(i=0; i<n_vertice;i++){
            g->grau[i] = 0;
        }
        g->aresta = (struct no **)malloc(n_vertice*sizeof(struct no*));
        if(g->aresta != NULL){
            for(i=0;i<n_vertice;i++){
                g->aresta[i] = NULL;
            }
        }
    }
    return g;
}

int insere_aresta(Grafo *g,int v1,int v2,int P){
    //-1 grafo é inconsistente
    if(g == NULL || v1<0 || v1>=g->n_vertice || v2<0 || v2>=g->n_vertice)return -1;


    struct no *aux;
    aux = g->aresta[v1];
    while(aux != NULL && aux->vertice != v2){
        aux = aux->prox;
    }
    //aux aponta pro ultimo elemento da lista encadeada

    //nao permite laço em nao direcionado
    if(g->eh_digrafo == 0){
            if(v1 == v2)return 0;
    }
    if(aux != NULL)return 0;


    struct no *n;
    n = (No *)malloc(sizeof(struct no));
    if(n != NULL){
        n->vertice = v2;
        n->peso = P;
        n->prox = g->aresta[v1];
        g->aresta[v1] = n;
    }
    g->n_aresta++;
    g->grau[v1]++;
    g->grau[v2]++;

    if(g->eh_digrafo == 0 && conferirExistencia(g,v2,v1) == 0){
        g->n_aresta--;
        g->grau[v1]--;
        g->grau[v2]--;
        insere_aresta(g,v2,v1,P);
    }
    return 1;
}

int verifica_aresta(Grafo *g,int v1,int v2){
    if(g == NULL || v1<0 || v1>=g->n_vertice || v2<0 || v2>=g->n_vertice)return -1;
    struct no *aux;
    aux = g->aresta[v1];
    while(aux != NULL && aux->vertice != v2){
        aux = aux->prox;
    }
    if(aux == NULL)return 0;
    else return 1;
}

int remove_aresta(Grafo *g,int v1,int v2){
    if(g == NULL || v1<0 || v1>=(g->n_vertice) || v2<0 || v2>=(g->n_vertice))return -1;
    struct no *aux;
    struct no *ant;
    aux = g->aresta[v1];
    ant = NULL;
    while(aux != NULL && aux->vertice != v2){
        ant = aux;
        aux = aux->prox;
    }
    if(aux == NULL)return 0;
    if(ant == NULL) g->aresta[v1] = aux->prox;
    else {
        ant->prox = aux->prox;
    }
    free(aux);
    g->n_aresta--;
    g->grau[v1]--;
    g->grau[v2]--;
    if(g->eh_digrafo == 0 && conferirExistencia(g,v2,v1) == 1){
        g->n_aresta++;
        g->grau[v1]++;
        g->grau[v2]++;
        remove_aresta(g,v2,v1);
    }
    return 1;
}

int consulta_aresta(Grafo *g,int v1,int v2,int *P){
    if(g == NULL || v1<0 || v1>=(g->n_vertice) || v2<0 || v2>=(g->n_vertice))return -1;
    struct no *aux;
    aux = g->aresta[v1];
    while(aux != NULL && aux->vertice != v2){
        aux = aux->prox;
    }
    if(aux == NULL)return 0;
    P = aux->peso;
    return 1;
}

void libera_grafo(Grafo *g){
    int i;
    struct no *aux,*ant;
    for(i=0;i<g->n_vertice;i++){
        aux = g->aresta[i];
        while(aux != NULL){
            ant = aux;
            aux = aux->prox;
            free(ant);
        }
    }
    free(g->aresta);
    free(g->grau);
    free(g);
}

void mostrar_adjacente(Grafo *g,int v){
    if(g == NULL || v<0 || v>=(g->n_vertice)){
        printf("Grafo inexistente ou vertice incorreto\n");
        return;
    }
    struct no *aux;
    aux = g->aresta[v];
    if(aux == NULL)printf("O vertice %d nao tem vertices vizinhos\n",v);
    while(aux != NULL){
        printf("%d - %d  (peso %d) \n",v,aux->vertice,aux->peso);
        aux = aux->prox;
    }
}

void mostrar_grafo(Grafo *g){
    if(g == NULL){
        printf("Grafo inexistente");
        return;
    }
    int i;
    if(g->eh_digrafo == 0)printf("Grafo nao direcionado usando lista de adjacencias\n");
    else printf("Grafo direcionado usando lista de adjacencias\n");

    for(i=0;i<g->n_vertice;i++){
        printf("\nVertice: %d\n",i);
        mostrar_adjacente(g,i);
    }
}

int conferirExistencia(Grafo *g,int v1,int v2){
    struct no *aux;
    aux = g->aresta[v1];
    while(aux != NULL && aux->vertice != v2){
        aux = aux->prox;
    }
    if(aux == NULL)return 0;
    return 1;
}

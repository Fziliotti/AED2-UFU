#include "Grafo.h"
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define INF 1000000000.00

struct grafo {
        int qtde_vertices, qtde_arestas;
        int *grau;
        float **arestas;
};

Grafo* cria_grafo(int nro_vertices){
    if(nro_vertices <= 0) return NULL;

    Grafo *G = (Grafo*) malloc (sizeof(Grafo));
    if(G == NULL) return NULL;

    G->qtde_vertices = nro_vertices;
    G->qtde_arestas = 0;


    G->grau = (int*) calloc (nro_vertices, sizeof(int));
    if(G->grau == NULL){
		free(G);
		return NULL;
    }

    G->arestas = (float **) malloc(nro_vertices *sizeof(float*));
    if(G->arestas == NULL){
        free(G->grau); free(G); return NULL;
    }


    int i, k;

    for(i=0; i<nro_vertices; i++){
        G->arestas[i]= (float*) calloc (nro_vertices, sizeof(float));
        if(G->arestas[i] == NULL){
            for(k=0; k<i; k++) free (G->arestas[k]);
            free(G->arestas); free(G->grau); free(G); return NULL;
        }
    }
    return G;
}

int insere_aresta(Grafo *G, int V1, int V2, int P){
    if(G == NULL || V1<0 || V1 > G->qtde_vertices || V2<0 || V2 > G->qtde_vertices){
        return -1;
    }
    if(G->arestas[V1][V2] != 0){
        return 0;
    }

    G->arestas[V1][V2] = P;
    G->arestas[V2][V1] = P;
    G->qtde_arestas++;
    G->grau[V1]++;
    G->grau[V2]++;
    return 1;
}

int verifica_aresta(Grafo *G, int V1, int V2){
    if(G == NULL || V1<0 || V1 > G->qtde_vertices || V2<0 || V2 > G->qtde_vertices){
        return -1;
    }

    if(G->arestas[V1][V2] == 0) return 0;
    return 1;
}

int remove_aresta(Grafo *G, int V1, int V2){
    if(G == NULL || V1<0 || V1 > G->qtde_vertices || V2<0 || V2 > G->qtde_vertices){
        return -1;
    }

    if(G->arestas[V1][V2] == 0){
        return 0;
    }
    G->arestas[V1][V2] =0;
    G->qtde_arestas--;
    G->grau[V1]--;
    G->grau[V2]--;
    return 1;
}

int consulta_aresta(Grafo *G, int V1, int V2, int P){
    if(G == NULL || V1<0 || V1 > G->qtde_vertices || V2<0 || V2 > G->qtde_vertices){
        return -1;
    }

    if(G->arestas[V1][V2] == 0) return 0;
    P = G->arestas[V1][V2];
}

void libera_grafo(Grafo *G){
 int k;
 int i = G->qtde_arestas;
 for (k = 0; k<i; k++)free(G->arestas[k]);
 free(G->arestas);
 free(G->grau);
 free(G);
 G = NULL;

}


void mostra_grafo (Grafo *G){
 if (G==NULL) printf("Grafo Inexistente!\n");
 else{
    int i;
  for (i = 0; i < G->qtde_vertices; ++i)
  {
   printf("Vertice %d: \n",i );
   mostra_adjacentes(G,i);
  }
 }
}

void mostra_adjacentes(Grafo *G, int V){

    if (G==NULL || V<0 || V > G->qtde_vertices) printf("Grafo Inexistente ou vertices incorretos!\n");
    else{
    int cont =0;
    int i;
    for(i=0; i<G->qtde_vertices; i++){
        if(G->arestas[V][i]!=0){
                printf("%d -> %d = %.1f\n", V, i, G->arestas[V][i]);
                cont++;
        }
    }
    if(!cont) printf("O vertice %d nao possui vertices adjacentes\n", V);
    }
}

int numVertices(Grafo *g){
    if(g== NULL) return -1;
    return g->qtde_vertices;
}

 int grauVertice(Grafo *g, int v){
    if(g==NULL) return -1;
    if(v<0 || v>g->qtde_vertices) return -1;
    return g->grau[v];
 }

 int ehAdjacente(Grafo *g, int v1, int v2){
    if(g==NULL) return -1;
    if(v1<0 || v1>g->qtde_vertices || v2<0 || v2>g->qtde_vertices) return -1;
    if(g->arestas[v1][v2]>0) return 1;
    return 0;
 }

void dijkstra(Grafo *G, int v0, int *A, float *D){
    int NV = G->qtde_vertices;
    int *S = (int *) calloc (NV , sizeof(int));
    int i, j;
    for(i=0; i<NV; i++){
        A[i]=-1;
        D[i]=-1;
    }
    S[v0] = 1;
    D[v0] = 0;
    for(i=0; i<NV; i++){
        if(S[i] ==0)
        if(G->arestas[v0][i] != 0){
            D[i] = G->arestas[v0][i];
            A[i] = v0;
        }
    }
    for(i=1; i<NV; i++){

        int maior = -1, aux= 0;
        for(j=0; j<NV; j++){
            if(S[j] ==0){
                if(D[j] > maior){
                    maior = D[j];
                    aux = j;
                }
            }
        }
        S[aux] = 1;
        for(j=0; j<NV; j++){
            if(S[j] == 0){
                if(G->arestas[aux][j]){
                    float DistNova = D[aux] + G->arestas[aux][j];

                    if(DistNova > D[j]){
                        D[j] = DistNova;
                        A[j] = aux;
                    }
                }
            }
        }
    }
}
void mostra_caminho (int Vini, int Vfim, int *A, Ponto *pontos){
    if(Vini == Vfim) printf(" %s -", pontos[Vini].nome);
    else if(A[Vfim] == -1) printf("Nao existe rota entre %s e %s", pontos[Vini].nome, pontos[Vfim].nome);
    else {
        mostra_caminho(Vini, A[Vfim], A, pontos);
        printf(" %s -", pontos[Vfim].nome);
    }
}
int contaPontos (int Vini, int Vfim, int *A, Ponto *pontos){
    if(Vini == Vfim) {
            return 1;

    }
    else if(A[Vfim] == -1) return 0;
    else {
        return (1 + contaPontos(Vini, A[Vfim], A, pontos));

    }
}

void caminhoMaisRapido(Grafo *G, Ponto *pontos, int origem, int destino, int tam){
    float dist[27];
    int ant[27];
    dijkstra(G, origem, ant, dist);
    float tempo;
    tempo = dist[destino]/tam;
    printf("------TRANSFERENCIA DE ARQUIVO------\n");
    printf("ORIGEM: %s\n", pontos[origem].nome);
    printf("DESTINO: %s\n", pontos[destino].nome);
    printf("TAMANHO: %dMB/s\n", tam);
    printf("VELOCIDADE DA CONEXAO: %.2fMB/s\n", dist[destino]);
    printf("TEMPO TOTAL: %.2fs\n\n", tempo);
    printf("TRAJETO: ");
    mostra_caminho(origem, destino, ant, pontos);
    printf("\n------------------------------\n");

}

void excedeTempo(Grafo *G, Ponto *pontos, int origem, int tam, float tempo){
    float dist[27], tempoTotal;
    int ant[27], i;
    dijkstra(G, origem, ant, dist);
    printf("------REQUISICAO DE TRANSFERENCIA DE ARQUIVO------\n");
    printf("ORIGEM: %s\n", pontos[origem].nome);
    printf("TAMANHO: %dMB/s\n", tam);
    printf("TEMPO MAXIMO ACEITAVEL: %.2fs\n", tempo);
    printf("PONTOS POSSIVEIS: ");
    for(i=0; i<27; i++){
        tempoTotal = dist[i]/tam;
        if(tempoTotal <= tempo){
            printf("\n%s - ", pontos[i].nome);
            printf("%.2f s", tempoTotal);
        }
    }

}

void coberturaEnvio(Grafo *G, Ponto *pontos, int origem, int quant){
    float dist[27], pontosTotais;
    int ant[27], i;
    dijkstra(G, origem, ant, dist);
    printf("------REQUISICAO DE TRANSFERENCIA DE ARQUIVO------\n");
    printf("ORIGEM: %s\n", pontos[origem].nome);
    printf("QUANTIDADE MAXIMA DE PONTOS INTERMEDIARIOS: %d pontos\n", quant);
    printf("PONTOS POSSIVEIS: ");
    for(i=0; i<27; i++){
        pontosTotais = contaPontos(origem, i, ant, pontos);
        if(pontosTotais <= quant){
            printf("\n %s ", pontos[i].nome);
        }
    }
}

#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED


typedef struct grafo Grafo;
typedef struct ponto{
  int cod;
  char nome[40];
  float x, y;

}Ponto;

Grafo* cria_grafo(int nro_vertices);
int insere_aresta(Grafo *G, int V1, int V2, int P);

int verifica_aresta(Grafo *G, int V1, int V2);

int remove_aresta(Grafo *G, int V1, int V2);

int consulta_aresta(Grafo *G, int V1, int V2, int P);

void libera_grafo(Grafo *G);

void mostra_adjacentes(Grafo *G, int V);

void mostra_grafo (Grafo *G);

int numVertices(Grafo *g);

int grauVertice(Grafo *g, int v);

int ehAdjacente(Grafo *g, int v1, int v2);

int procuraMenorDistancia (float *dist, int *visitado, int NV);

void dijkstra(Grafo *G, int v0, int *ant, float *dist);

void caminhoMaisRapido(Grafo *G, Ponto *pontos, int origem, int destino, int tam);

void nomePonto(int num);

void mostra_caminho (int Vini, int Vfim, int *A, Ponto *pontos);

void excedeTempo(Grafo *G, Ponto *pontos, int origem, int tam, float tempo);

void coberturaEnvio(Grafo *G, Ponto *pontos, int origem, int quant);

int contaPontos (int Vini, int Vfim, int *A, Ponto *pontos);

#endif // GRAFO_H_INCLUDED

#ifndef GRAFOLISTA_H_INCLUDED
#define GRAFOLISTA_H_INCLUDED

typedef struct no No;
typedef struct vertice Vertice;
typedef struct grafo Grafo;
Grafo *criaGrafo (int nro_vertices);
No* criaAdjacencia(int v, int peso);
int insere_aresta(Grafo *G, int V1, int V2, int P);
void imprimeGrafo (Grafo *G);

void libera_grafo(Grafo *g);
void mostrar_adjacente(Grafo *g,int v);
int verifica_aresta(Grafo *g,int v1,int v2);
int conferirExistencia(Grafo *g,int v1,int v2);
int consulta_aresta(Grafo *g,int v1,int v2,int *P);

#endif // GRAFOLISTA_H_INCLUDED

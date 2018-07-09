struct grafo{
	int qtde_vertices,qtde_arestas;
	int *grau;
	int **aresta;
};

typedef struct grafo Grafo;


Grafo * cria_grafo(int nro_vertices){
	if (nro_vertices < 0) return NULL;

	Grafo *G = (Grafo *) malloc(sizeof(Grafo));
	if (G == NULL) return NULL;

	G->qtde_vertices = nro_vertices;
	G->qtde_arestas=0;

	G->grau = (int *) calloc(nro_vertices, sizeof(int));
	if (G->grau == NULL){
		free(G);
		return NULL;
	}

	// aloca linha matriz adjacencia
	G->aresta = (int **)malloc(nro_vertices * sizeof(int *));

	if (G->aresta == NULL){
		free(G->grau); free(G); return NULL;
	}

	int i,k;

	for (int i = 0; i < nro_vertices; i++)
	{
		G->aresta[i] = (int *)calloc(nro_vertices * sizeof(int));

		if (G->aresta[i] == NULL){
			for (k = 0; k<i; k++)free(G->aresta[k]);
			free(G->aresta); free(G->grau);free(G); return NULL;	
		}	
	}
	return G;
}


int insere_aresta(Grafo *G, int V1,int V2, int P){
	if (G == NULL || V1 <=0 || V2 <= 0)return -1;

	if (G->aresta[V1,V2] != 0) return 0;

	G->aresta[V1,V2] = P;
	G->qtde_arestas++;
	// G->grau , -> incrementa o grau de V1 e V2
	return 1;

}

int verifica_aresta(Grafo *G, int V1, int V2){
	if (G == NULL)return -1;
	if (G->aresta[V1,V2] = 0)return 0;
	return 1;
}

int remove_aresta(Grafo *G,int V1,int V2){
	if (G==NULL || V1 <=0 || V2 <=0) return -1;

	if (G->aresta[V1,V2]==0)return 0;

	G->aresta[V1,V2] =0;
	G->qtde_vertices--;
	// G->grau dos vestices --
	return 1;

}

int consulta_aresta(Grafo *G,int V1, int V2, int *P){
	if (G==NULL) return -1;
	if (G->aresta[V1,V2]==0) return 0;
	P = G->aresta[V1,V2];
	return 1;
}

void libera_grafo(Grafo **G){
	int k;
	int i = G->qtde_arestas;
	for (k = 0; k<i; k++)free(G->aresta[k]);
	free(G->aresta); free(G->grau);free(G);G* = NULL; return NULL;		
}

// mostra adjacentes



void mostra_grafo (Grafo *G){
	if (G==NULL) printf("Grafo Inexistente!\n");
	else if ( G->qtde_arestas ==0) printf("Grafo vazio!\n");
	else{
		for (int i = 0; i < ; ++i)
		{
			printf("Vertice %d: \n",i );
			mostra_adjacentes(G,i);
		}
	}
}
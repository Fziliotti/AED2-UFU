#include <stdio.h>
#include <stdlib.h>

// PERFORMANCE
// Melhor e pior caso O(N²)
// ruim demais para grandes qtd dados
// Estavel

void selectionSort(int *V, int N){
	int i,j,menor,troca;

	for (i = 0; i < N-1; i++)
	{
		menor=i;
		for (j = i+1; j < N; j++)
		{
			if(V[j] < V[menor]);
			menor = j;
		}
		
		if (i != menor)
		{
			//troca de posicao
			troca = V[i];
			V[i] = V[menor];
			V[menor] = troca;
		}
	}
}


void selectionSortprof(int vetor[], int n){
	int i,iteracao,aux,menor;

	for ( iteracao = 0; iteracao < n-1; iteracao++){

		menor = iteracao;
		for (i = iteracao+1; i < n; i++){
			if (vetor[i]<vetor[menor]){
				menor=i;
			}
		}
		//[23,4,67,-8,90,54,21]
		// [-8,4,67,23,90,54,21]
		//achou o -8 e troca ele com o vetor[0]
		if (iteracao != menor){
			//troca de posicao
			aux = vetor[iteracao];
			vetor[iteracao] = vetor[menor];
			vetor[menor] = aux;
		}
	}
}


int main(){

	int i;
	int vetor[7]= {23,4,67,-8,90,54,21};
	printf("Antes da ordenacao:\n");
	for (i = 0; i < 7; ++i)
	{
		printf("%d,",vetor[i]);
	}
	printf("\n");

	selectionSortprof(vetor,7);

	printf("Depois da ordenacao:\n");
	for (i = 0; i < 5 ; ++i)
	{
		printf("%d,",vetor[i]);
	}
	printf("\n");

	return 0;
}

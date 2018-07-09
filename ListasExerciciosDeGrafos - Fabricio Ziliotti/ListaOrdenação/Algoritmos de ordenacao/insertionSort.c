#include <stdio.h>
#include <stdlib.h>

// PERFORMANCE
// Melhor perfomance: O(N)
// Pior Caso: O(N²)
// Bom para pequenos dados e capaz de ordenar em tempo real
// É estavel, se tiver dois numeros iguais ele nao muda a ordem
void insertionSort(int *V, int N){
	int i,j,aux;

	for (int i = 1; i < N; i++){
		aux = V[i];
		for (j= i; (j > 0) && (aux < V[j-1]); j--){
			V[j] = V[j-1];
		}
		V[j] = aux;
	}
}

void insertionSortprof(int vetor[], int n){
	int i,iteracao,aux,elem;

	// controle do numero de iteracoes
	for (iteracao = 1; iteracao < n; iteracao++){
		// busca posicao do elemento
		elem = vetor[iteracao];
		i = iteracao-1;

		while(i>= 0 && vetor[i]>elem){
			vetor[i+1] = vetor[i];
			i--;
		}
		//posiciona elemento
		vetor[i+1]= elem;
	}
}



int main(){

	int vetor[]= {3,6,9,8,6,15,23,45};
	printf("Antes da ordenacao:\n");
	for (int i = 0; i < 7; ++i){
		printf("%d,",vetor[i]);
	}
	printf("\n");

	insertionSortprof(vetor,8);

	printf("Depois da ordenacao:\n");
	for (int i = 0; i < 7 ; ++i)
		printf("%d,",vetor[i]);
	printf("\n");

	return 0;
}

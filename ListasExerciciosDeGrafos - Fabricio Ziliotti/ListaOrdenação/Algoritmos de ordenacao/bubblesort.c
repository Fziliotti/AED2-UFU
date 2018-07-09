#include <stdio.h>
#include <stdlib.h>

// bubblesort: compara pares de elementos adjacentes e 
// os troca de lugar se estiverem na ordem errada

// Performance:
// Melhor caso: 0(N)
// Pior Caso: O(N²)
// Nao recomendado para muitos dados



void bubblesortProf(int vetor[],int n){
	int i,iteracao,aux;
	for (iteracao = 0; iteracao < n-1 ; iteracao++){
		for ( i = 0; i < n-1; i++){
			if (vetor[i]> vetor[i+1] ){
				aux = vetor[i];
				vetor[i] = vetor[i+1];
				vetor[i+1] = aux;
			}
		}
	}
}

void bubblesort(int *V, int N){

	int i, continua, aux, fim =N;

	do{
		continua = 0;
		for (int i = 0; i < fim-1; i++)
		{
			if (V[i] > V[i+1])
			{
				aux = V[i];
				V[i] = V[i+1];
				V[i+1]= aux;
				continua = i;
			}
		}
		fim--;
	}while(continua != 0);

// RESUMO: voce coloca o maior elemento sempre no final, e diminui o tamanho
	// do vetor na proxima iteração com fimrecebendo--

}

int main(){

	int vetor[5]= {12,32,54,12,32};
	printf("Antes da ordenacao:\n");
	for (int i = 0; i < 5; ++i)
	{
		printf("%d,",vetor[i]);
	}
	printf("\n");

	bubblesortProf(vetor,5);

	printf("Depois da ordenacao:\n");
	for (int i = 0; i < 5 ; ++i)
	{
		printf("%d,",vetor[i]);
	}
	printf("\n");

	return 0;
}
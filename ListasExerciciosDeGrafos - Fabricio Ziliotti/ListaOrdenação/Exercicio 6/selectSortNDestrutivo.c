#include <stdio.h>
#include <stdlib.h>

// PERFORMANCE
// Melhor e pior caso O(N²)
// ruim demais para grandes qtd dados
// Estavel



int * selectionNaoDestrutivo(int vetor[], int n){
	// CRIACAO DA TABELA AUXILIAR PEDIDA NO EXERCICIO

	int j;
    int * auxTable = (int *) malloc (n *sizeof (int));
	for (j = 0; j < n; j++)
	{
		auxTable[j] = vetor[j];
	}

	int i,iteracao,aux,menor;
	for ( iteracao = 0; iteracao < n-1; iteracao++){

		menor = iteracao;
		for (i = iteracao+1; i < n; i++){
			if (auxTable[i]<auxTable[menor]){
				menor=i;
			}
		}
		//[23,4,67,-8,90,54,21]
		// [-8,4,67,23,90,54,21]
		//achou o -8 e troca ele com o auxTable[0]
		if (iteracao != menor){
			//troca de posicao
			aux = auxTable[iteracao];
			auxTable[iteracao] = auxTable[menor];
			auxTable[menor] = aux;
		}
	}
	return auxTable;
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

	int * T = selectionNaoDestrutivo(vetor,7);

	printf("Depois da ordenacao:\n");
	for (i = 0; i < 7 ; ++i)
	{
		printf("%d,", T[i]);
	}
	printf("\n");

	return 0;
}

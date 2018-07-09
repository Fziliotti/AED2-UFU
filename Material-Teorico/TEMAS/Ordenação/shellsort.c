#include <stdio.h>
#include <stdlib.h>

// SHELL SORT NAO É ESTAVEL


void shellSort(int *vet, int size) {
    int i , j , value;
    int gap = 1;
    while(gap < size) {
        gap = 3*gap+1;
    }
    while ( gap > 1) {
        gap /= 3;
        for(i = gap; i < size; i++) {
            value = vet[i];
            j = i - gap;
            while (j >= 0 && value < vet[j]) {
                vet [j + gap] = vet[j];
                j -= gap;
            }
            vet [j + gap] = value;
        }
    }
}




int main(){

	int vetor[]= {1,5,3,4,6,8,12,321,43,1,2,3};
	printf("Antes da ordenacao:\n");
	for (int i = 0; i < 12; ++i){
		printf("%d,",vetor[i]);
	}
	printf("\n");

	shellSort(vetor,12);

	printf("Depois da ordenacao:\n");
	for (int i = 0; i < 12 ; ++i)
		printf("%d,",vetor[i]);
	printf("\n");

	return 0;
}

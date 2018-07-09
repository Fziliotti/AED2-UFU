#include <stdio.h>

// usando 3 argumentos para controlar as iteracoes com o valor de i
void selectionSort(int arr[], int i, int n){
    int j, min = i;

    for (j = i + 1; j < n; j++){
        if (arr[j] < arr[min])
            min = j;    // atualiza o indice do menor
    }
    // faz a troca 
    int temp = arr[min];
    arr[min] = arr[i];
    arr[i] = temp;

    if (i + 1 < n)selectionSort(arr, i + 1, n);
}


int main(){
    int arr[] = {23,4,67,-8,90,54,21};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Antes de ordenar:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    selectionSort(arr, 0, n);
    
    printf("Depois de ordenar:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
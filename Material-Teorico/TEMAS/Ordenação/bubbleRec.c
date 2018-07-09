#include <stdio.h>
#include <stdlib.h>


// A function to implement bubble sort
void bubbleSort(int arr[], int n)
{
    int i;
    // int aux;
    //Caso base
    if (n == 1)return;
    
    for (i=0; i<n-1; i++){
        if (arr[i] > arr[i+1]){
            int aux = arr[i];
            arr[i] = arr[i+1];
            arr[i+1]= aux;
        }
    }

    bubbleSort(arr, n-1); // fazer a iteracao para o restante do array sem o maior elemento da iteracao anterior
}
 
void printArray(int arr[], int n)
{
    int i;
    for (i=0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
 
int main()
{
    int arr[] = {12, 14, 25, 10, 2, 1, 5};
    int n = sizeof(arr)/sizeof(arr[0]); //pegar tamanho do array
    bubbleSort(arr, n);
    printf("Array ordenado: \n");
    printArray(arr, n);
    return 0;
}
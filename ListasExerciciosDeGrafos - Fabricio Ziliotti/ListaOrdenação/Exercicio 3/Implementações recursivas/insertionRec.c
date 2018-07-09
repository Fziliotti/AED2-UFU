#include <stdio.h>
#include <stdlib.h>


void insertionSortRecursive(int arr[], int n){
   
    if (n <= 1)
        return;
    insertionSortRecursive( arr, n-1 );
 
    int last = arr[n-1];
    int j = n-2;
 
    while (j >= 0 && arr[j] > last)
    {
        arr[j+1] = arr[j];
        j--;
    }
    arr[j+1] = last;
}
 

 

 
/* Driver program to test insertion sort */
int main()
{
    int arr[] = {12, 11, 13, 5, 6};
    int i,n = sizeof(arr)/sizeof(arr[0]);
    printf("Antes de ordenar:\n"); 
    for (i=0; i < n; i++)
        printf("%d,",arr[i] );
    printf("\n");

    insertionSortRecursive(arr, n);

    printf("Depois de ordenar: \n");
    for (i=0; i < n; i++)
        printf("%d,",arr[i] );
    printf("\n");
 
    return 0;
}
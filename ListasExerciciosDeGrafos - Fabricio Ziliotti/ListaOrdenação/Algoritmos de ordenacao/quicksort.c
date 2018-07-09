#include <stdio.h>
#include <stdlib.h>


int quicksort (int a[], int p, int r){
    int t;
    if (p<r){
        int v = (rand() % (r-p)) +p;
        int pivo = a[v];
        a[v]= a[r];
        a[r] = pivo;

        int i = p-1;
        int j=r;

        do{
            do{i++;}while (a[i] <pivo);
            do{j--;}while ((a[j]>pivo) && (j>p));
            if (i<j){
                t=a[i];
                a[i] = a[j];
                a[j]=t;
            }
            }while (i<j);
            a[r]=a[i];
            a[i]=pivo;

            quicksort(a,p,i-1);
            quicksort(a,i+1,r);
        }
    }


    int main(){

        int vetor[5]= {12,32,54,12,32};
        printf("Antes da ordenacao:\n");
        for (int i = 0; i < 5; ++i)
        {
            printf("%d,",vetor[i]);
        }
        printf("\n");

        quicksort(vetor,0,4);

        printf("Depois da ordenacao:\n");
        for (int i = 0; i < 5 ; ++i)
        {
            printf("%d,",vetor[i]);
        }
        printf("\n");

        return 0;
    }
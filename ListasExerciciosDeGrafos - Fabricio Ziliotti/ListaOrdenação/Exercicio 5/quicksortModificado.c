#include <stdio.h>
#include <stdlib.h>
#define s 100

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

//s é o tamanho
int quicksort (int a[], int p, int r){
    int t;
    // se a variavel r for menor que s+1 (numero de elementos)
    if (r <= s+1){
        printf("Usando Insertion pois r <= s+1\n");
        insertionSortprof(a,r+1);
    }else{
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
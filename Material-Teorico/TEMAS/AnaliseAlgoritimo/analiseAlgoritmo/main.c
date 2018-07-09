#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int Max(int *A, int n){
    int i,temp;
    temp = A[0]; //ACESSO + ATRIBUIÇÃO

    for(i=1;i<n;i++){ //ATRIBUICAO + COMPARACAO ,   + INCREMENTO + COMPARAÇÃO (ITERACAO DO FOR)
        if (temp < A[i]){
            temp = A[i];
        }
    }
    return temp; //+ UMA INSTRUCAO
}



//NA ANALISE, PODEMOS FOCAR NAS OPERACOES DOMINANTES (LOOPS E SEUS ANINHAMENTOS), POIS É OQ IMPORTA

int main (void) {
    time_t t1, t2, total;
    t1 = time(NULL); // retorna hora atual do sistema

    int A[] = {1,2,3,2,1,232,4,6,7324,8,9,0,12,32,43,12,43,67,78,53,1,23,1212};
    int teste = Max(A,23);
    printf("%d",teste);


    printf("\n%d\n", sizeof(A)/sizeof(int));


    t2 = time(NULL);
    total = difftime(t2,t1); // retorna a diferença t2-t1
    printf("\n\nTotal: %ld seg.\n", total);

    return 0;
}




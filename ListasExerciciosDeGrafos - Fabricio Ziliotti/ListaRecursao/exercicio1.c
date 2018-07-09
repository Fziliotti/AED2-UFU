#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int Fib_rec(int n) {
    if (n < 2) // caso base
    return n;
    else // passo recursivo
    return (fib(n-1) + fib(n-2));
}

int Fib_iter(int n) {
    int k, i = 1, F = 0;
    for (k = 1; k <= n; k++) {
        F = F + i;
        i = F - i;
    }
    return F;
}


int main (void) {
    time_t t1, t2, t3, t4, total, total1;
    int x;
    //CASOS DE TESTE = x=5,x=10,x=20,x=30

    printf("Digite o numero para calcular o fib_iterativo:");
    // printf("Digite o numero para calcular o fib_recursivo:");
    scanf("%d", &x);

    t1 = time(NULL);

    int result = Fib_iter(x);
    //  int result = Fib_rec(x);
    printf("Resultado: %d", result);

    t2 = time(NULL);

    total = difftime(t2,t1);
    printf("Tempo para calcular Fib de %d eh de: %ld\n", x , total);



    return 0;
}




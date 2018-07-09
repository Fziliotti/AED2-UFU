#include <stdio.h>
#include <stdlib.h>
#include "arvoreABB.h"

int main()
{
    Arv arvore1 = cria_arvore();
    Reg A, B, C, D, E, F, G, H;
    A = cria_Reg(50, "Guilherme Raimondi", 20, 1600.00);
    B = cria_Reg(10, "Harry Victor", 19, 1200.00);
    C = cria_Reg(69, "Fabricio Ziliotti", 20 , 1600.00);
    D = cria_Reg(5,  "Joao cleber", 10 ,1800.00);
    E = cria_Reg(30, "Ibrahimovic", 12, 300.00);
    F = cria_Reg(80, "HURRICANE", 25,1620.00);
    G = cria_Reg(25, "MENNINO JESUS", 15,30000.00);
    H = cria_Reg(45, "Coutinho", 17, 3200.00);

    insere_ord(&arvore1, A);
    insere_ord(&arvore1, B);
    insere_ord(&arvore1, C);
    insere_ord(&arvore1, D);
    insere_ord(&arvore1, E);
    insere_ord(&arvore1, F);
    insere_ord(&arvore1, G);
    insere_ord(&arvore1, H);

    printf("Arvore Binaria Lista de exercicios ---------- \n");
    exibe_arvore(arvore1);

    printf("\nArvore ordenada----\n");
    exibe_ordenado(arvore1);

    libera_arvore(&arvore1);

    arvore1 ? printf("\nArvore Nao liberada") : printf("\nArvore Liberada!");








    return 0;
}

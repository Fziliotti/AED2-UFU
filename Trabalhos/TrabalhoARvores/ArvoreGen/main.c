
#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include "arvoreGen.h"
int main()
{

    //EXEMPLO DE ARVORE GENERICA, IMPLEMENTACAO SEMELHANTE A DO TRABALHO
    //COM MAIS FUNCOES DO QUE O PEDIDO NO EXERCICIO DE IMPLEMENTACAO
    Arv A = cria_arvore(1);
    Arv B = cria_arvore(2);
    Arv C = cria_arvore(3);
    Arv D = cria_arvore(4);
    Arv E = cria_arvore(5);
    Arv F = cria_arvore(6);
    Arv G = cria_arvore(7);
    Arv H = cria_arvore(8);
    Arv I = cria_arvore(9);

    insere(F,I);
    insere(F,H);
    insere(C,F);
    insere(C,E);
    insere(D,G);
    insere(A,D);
    insere(A,C);
    insere(A,B);

    printf("------Exibicao da arvore: \n");
    exibe_arvore(A);

    printf("\n\n-------Buscas na arvore: \n");
    printf("\n%d\n", busca(A, 2));
    printf("\n%d\n", busca(A, 7));
    printf("\n%d\n", busca(A, 4));




    return 0;
}

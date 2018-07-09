#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"
int main()
{
    //Criação da arvore de baixo para cima

    //Nos FOLHAS
    Arv A9 = cria_arvore(9, NULL,NULL);
    Arv A8 = cria_arvore(8, NULL,NULL);


    Arv A7 = cria_arvore(7, NULL,A8);
    Arv A6 = cria_arvore(6, NULL,NULL);
    Arv A5 = cria_arvore(5, NULL,NULL);
    Arv A4 = cria_arvore(4, A9,NULL);
    Arv A3 = cria_arvore(3, A4,A5);
    Arv A2 = cria_arvore(2, A6,A7);
    Arv A1 = cria_arvore(1, A2,A3);


    exibe_arvore(A1);
    printf("\n");

    if(busca(A1,5))printf("O numero 5 estA n arvore!\n");
    else printf("nao achou o numero 5!\n");


    printf("\nA altura de A1 eh %d\n", altura(&A1));

    printf("\nTotal de nos da A1 eh %d\n", totalNo_arv(&A1));
    printf("\nqtd de nos da A1 eh %d\n", qtdNos(&A1));

    printf("\nPreOrdem:\n");
    preOrdem_Arv(&A1);

    printf("\nEmOrdem:\n");
    emOrdem_Arv(&A1);

    printf("\nPosOrdem:\n");
    posOrdem_Arv(&A1);

    printf("\nAS folhas da arvore sao:");
    imprime_folhas(A1);

    printf("\nO numero de ocorrencias do numero 5 na arvore eh : %d\n", ocorrencias_x(A1,5));

    printf("\nO numero de folhas na arvore eh : %d\n", folhas(A1));

    printf("A soma dos nos resulta em: %d", somaNos(A1));



    //Testando libera_arvore
    A1 ?  printf("\nExiste arvore!") : printf("\nNao existe arvore mais!");
    libera_arvore(&A1);
    A1 ?  printf("\nExiste arvore!") : printf("\nNao existe arvore mais!");


    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include "arvore_avl.h"
int main()
{
    Arv arv = cria_arvore();
    Reg A= cria_reg(50, 70, "PontoA", "LocalizacaoA");
    Reg B= cria_reg(10, 10, "PontoB", "LocalizacaoB");
    Reg C= cria_reg(69, 76, "PontoC", "LocalizacaoC");
    Reg D= cria_reg(5, 30,  "PontoD", "LocalizacaoD");
    Reg E= cria_reg(30, 60, "PontoE", "LocalizacaoE");
    Reg F= cria_reg(80, 80, "PontoF", "LocalizacaoF");
    Reg G= cria_reg(15, 40, "PontoG", "LocalizacaoG");
    Reg H= cria_reg(45, 45, "PontoH", "LocalizacaoH");
    int *x = 0;
    insere_AVL(&arv, A, &x); insere_AVL(&arv, B, &x); insere_AVL(&arv, C, &x);
    insere_AVL(&arv, D, &x); insere_AVL(&arv, E, &x); insere_AVL(&arv, F, &x);
    insere_AVL(&arv, G, &x); insere_AVL(&arv, H, &x);


    exibe_ordenado(arv);
    puts("");
    exibe_arvore(arv);
    puts("");
    printf("Qtde Ocioso: %d\n", qtde_ocioso(arv));
    Reg* menor= menor_trafego(arv);
    printf("Menor trafego: %d\n", (*menor).chave);

    return 0;

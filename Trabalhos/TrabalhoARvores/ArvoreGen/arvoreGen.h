#ifndef ARVOREGEN_H_INCLUDED
#define ARVOREGEN_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
struct no{
    int info;
    struct no *esq;
    struct no *dir;
};
typedef struct no *Arv;

Arv cria_arvore(int elem);
int insere (Arv A, Arv sa);
void exibe_arvore(Arv a);
int busca (Arv A, int elem);
Arv retornaElem (Arv A, int elem);
void libera_arvore(Arv *A);
void preorder (Arv A);
void postorder (Arv A);
void percorre_nivel(Arv A);
void percorre_direita(Arv A);
int nro_folha(Arv A);
int grau_arv(Arv A);
int qtde_nos(Arv A, int grau);
int altura_no(Arv A, int elem);
int calculaAltura(Arv a);
#endif // ARVOREGEN_H_INCLUDED

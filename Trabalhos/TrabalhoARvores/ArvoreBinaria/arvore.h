#ifndef ARVORE_H_INCLUDED
#define ARVORE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef struct no *Arv;

Arv cria_arvore(int elem, Arv esq, Arv dir);
int arvore_vazia (Arv A);
Arv cria_vazia();
void libera_arvore( Arv *A);
int busca(Arv A, int elem);
void exibe_arvore(Arv A);
void preOrdem_Arv(Arv *A);
void emOrdem_Arv(Arv *A);
void posOrdem_Arv(Arv *A);
int totalNo_arv(Arv *A);

//Exercicios
Arv buscaPai(Arv A, int elem);
int altura (Arv *A);



#endif // ARVORE_H_INCLUDED

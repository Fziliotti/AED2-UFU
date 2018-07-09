#ifndef ARVORE_BINARIA_BUSCA_H_INCLUDED
#define ARVORE_BINARIA_BUSCA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

struct registro{
    int chave;
    char nome[100];
    int idade;
    double salario;
};
typedef struct registro Reg;
typedef struct no *Arv;

Arv cria_arvore();
int arvore_vazia(Arv A);
void libera_arvore(Arv *A);
void exibe_arvore (Arv A);
void exibe_ordenado(Arv A);
int insere_ord(Arv *A, Reg elem);
int remove_ord(Arv *A, int chave);
Arv busca_bin(Arv A, int chave);
Reg cria_Reg(int chave, char* nome, int idade,double salario);





#endif // ARVORE_BINARIA_BUSCA_H_INCLUDED

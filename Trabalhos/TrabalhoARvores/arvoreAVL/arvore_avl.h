#ifndef ARVORE_AVL_H_INCLUDED
#define ARVORE_AVL_H_INCLUDED


#include <stdio.h>

typedef struct registro{
    int chave; //trafego
    int capacidade;
    char pontoDeRede[100];
    char localizacao[50];
}Reg;

typedef struct no *Arv;

Arv cria_arvore(void);
Reg cria_reg(int chave, int capacidade, char* pontoDeRede, char* localizacao);
int arvore_vazia(Arv A);
void libera_arvore(Arv *A);
void exibe_arvore (Arv A);
void exibe_ordenado(Arv A);
int insere_ord(Arv *A, Reg elem);
int remove_ord(Arv *A, int chave);
Arv busca_bin(Arv A, int chave);
int rot_dir(Arv* pai);
int rot_esq(Arv* pai);
int balancear_esq(Arv* A);
int balancear_dir(Arv* A);
int rot_dir_esq(Arv* pai);
int rot_esq_dir(Arv* pai);
int insere_AVL(Arv *A, Reg elem, int* Bal);
int remove_AVL(Arv *A, Reg elem, int* Bal);

// funcoes do trabalho
Reg* menor_trafego(Arv atual);
int qtde_ocioso(Arv A);
int nro_nos_de_derivacao(Arv A);
int cheia(Arv A);
int nivel_no(Arv A, Reg elem);
int iguais(Arv A1, Arv A2);



#endif // ARVORE_AVL_H_INCLUDED

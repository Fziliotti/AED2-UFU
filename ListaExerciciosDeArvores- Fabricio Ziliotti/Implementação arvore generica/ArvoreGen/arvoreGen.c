#include "arvoreGen.h"

Arv cria_arvore(int elem){
    Arv novo = (Arv) malloc(sizeof(struct no));
    if(novo == NULL) return NULL;
    novo->info = elem;
    novo->esq = NULL;
    novo->dir = NULL;

    return novo;
}

int insere (Arv A, Arv sa){
    if(A==NULL ) return 0;
    sa->dir = A->esq;
    A->esq = sa;
    return 1;
}

void exibe_arvore(Arv a){

    if(a==NULL) printf("<>");
    else{
        printf("<");

        printf("%d", a->info);
        exibe_arvore(a->esq);
        printf(">");
        exibe_arvore(a->dir);
    }
}

int busca (Arv A, int elem){

    if (A==NULL) return 0;
    if(A->info == elem) return 1;

    if(busca(A->esq, elem)) return 1;
    if(busca(A->dir, elem)) return 1;
    return 0;
}

void libera_arvore(Arv *A){
    if(*A!=NULL){
        libera_arvore(&(*A)->esq);
        libera_arvore(&(*A)->dir);
        free(*A);
        *A=NULL;
    }
}

void preorder(Arv A){
    if(A!=NULL){
        printf("- %d -",A->info);
        preorder(A->esq);
        preorder(A->dir);
    }
}


void posorder(Arv A){
    if(A!=NULL){
        posorder(A->esq);
        posorder(A->dir);
        printf("- %d -",A->info);
    }
}
void percorre_direita(Arv A){
    if(A!=NULL){
    printf(" - %d - ", A->info);
    percorre_direita(A->dir);
    }
}

void percorre_nivel(Arv A){
    if(A!=NULL){
        percorre_direita(A);
        percorre_nivel(A->esq);
    }
}

int nro_folha(Arv A){
    if(A!=NULL){
    if(A->esq == NULL) return 1 + nro_folha(A->dir);
    return nro_folha(A->esq) + nro_folha(A->dir);
    }
    return 0;
}

int grau_arv(Arv A){
    if(A!=NULL){
        if(A->esq==NULL) return 0;
        return percorre_filhos(A->esq);
    }
    return 0;
}
int percorre_filhos(Arv A){
    if(A->dir == NULL) return 1;
    return 1 + percorre_filhos(A->dir);
}

int qtde_nos(Arv A, int grau){
    if(A!=NULL){
        if(grau_arv(A) == grau) return 1 + qtde_nos(A->esq, grau) + qtde_nos(A->dir, grau);
        return qtde_nos(A->esq, grau) + qtde_nos(A->dir, grau);
    }
    return 0;
}
Arv retornaElem (Arv A, int elem){
    if (A==NULL) return NULL;
    if(A->info == elem) return A;
    if(retornaElem(A->esq, elem) !=NULL) return  retornaElem(A->esq, elem);
    if(retornaElem(A->dir, elem) !=NULL) return  retornaElem(A->dir, elem);
    return NULL;

}

int altura_no(Arv A, int elem){
    Arv no = retornaElem(A, elem);
    return calculaAltura(no);
}

int calculaAltura(Arv A){
    if(A == NULL) return -1;

    int n = grau_arv(A);
    int max = -1;
    int alturaEsq = calculaAltura(A->esq);
    if(alturaEsq > max) max = alturaEsq;
    while(n--){
        int alturaIrmao = calculaAltura(A->esq->dir);
        if( alturaIrmao> max) max = alturaIrmao;
    }
    return 1 + max;
}

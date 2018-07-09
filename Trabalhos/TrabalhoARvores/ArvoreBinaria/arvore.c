#include "arvore.h"

typedef struct no {
    int info;
    struct no *sae;
    struct no *sad;
}no;

Arv cria_vazia(){
    return NULL;
}

Arv cria_arvore(int elem, Arv esq, Arv dir){
    Arv arvore = (no*) malloc(sizeof(no));
    if (arvore ==NULL) return NULL;
    arvore->info = elem;
    arvore->sae = esq;
    arvore->sad = dir;
    return arvore;
}

int arvore_vazia (Arv A){
    if (A==NULL)return 1;
    else return 0;
}

//RECEBE O ENDERECO DA ARVORE
//PEGA A REFERENCIA PARA QUE NO FIM POSSAMOS FAZER *A = NULL
//RECEBE o ENDERECO DO PONTEIRO PARA O NO RAIZ
void libera_arvore( Arv *A){
    if(*A != NULL){
            //libera a arvore eh PosOrdem
        libera_arvore(&((*A)->sae));
        libera_arvore(&((*A)->sad));
        free(*A);
        *A = NULL;
    }
}


//
int busca(Arv A, int elem){

    if (A == NULL) return 0;
    if (A->info == elem) return 1;
    if (busca(A->sae, elem)) return 1;
    if (busca(A->sad, elem)) return 1;

    return 0;
}



void exibe_arvore(Arv A){
    if (A == NULL) printf("<>");
    else{
    printf("<");
    printf("%d", A->info);

    exibe_arvore(A->sae);
    exibe_arvore(A->sad);

    printf(">");
    }
}

int totalNo_arv(Arv *A){
    if (A== NULL)return 0; //arvore nao criada
    if (*A == NULL) return 0; //arvore vazia
    int nos_esq = totalNo_arv(&((*A)->sae));
    int nos_dir = totalNo_arv(&((*A)->sad));
    //ao chegar nos nos folhas conta 0+0 = 0 + 1
    return (nos_esq + nos_dir+1);
}

int qtdNos(Arv *A){
    if (A == NULL) return -1;
    if (*A)return 1 + qtdNos(&((*A)->sae)) + qtdNos(&((*A)->sad));
    else return 0;
}

void preOrdem_Arv(Arv *A){
    if (A==NULL)return;
    if(*A != NULL){
        printf("%d\n", (*A)->info);
        preOrdem_Arv(&((*A)->sae));
        preOrdem_Arv(&((*A)->sad));
    }
}

void emOrdem_Arv(Arv *A){
    if (A==NULL)return;
    if(*A != NULL){
        preOrdem_Arv(&((*A)->sae));
        printf("%d\n", (*A)->info);
        preOrdem_Arv(&((*A)->sad));
    }
}

void posOrdem_Arv(Arv *A){
    if (A==NULL)return;
    if(*A != NULL){
        preOrdem_Arv(&((*A)->sae));
        preOrdem_Arv(&((*A)->sad));
        printf("%d\n", (*A)->info);
    }
}


//ainda falta arrumar a recursao
int ocorrencias_x (Arv a, int x){
    if (a==NULL) return 0;
    if (a->info == x) return 1 + ocorrencias_x(a->sad, x);
    if (a->info < x) return ocorrencias_x(a->sad, x);
    return ocorrencias_x(a->sae, x);
}



void imprime_folhas (Arv a){
    if (a==NULL) return ;
    if ( (a->sae == NULL) && (a->sad == NULL))printf(" %d - ",a->info);
    imprime_folhas(a->sae);
    imprime_folhas(a->sad);
}

int folhas (Arv a){
    if (arvore_vazia(a->sae) && arvore_vazia(a->sad)) return 1;
    else if (!arvore_vazia(a->sae) && arvore_vazia(a->sad)) return folhas(a->sae);
    else if (arvore_vazia(a->sae) && !arvore_vazia(a->sad)) return folhas(a->sad);
    return folhas(a->sae) + folhas(a->sad);
}

int folhas2(Arv A){
    if (!A) return 0;
    if(A->sae == NULL && A->sad == NULL)
        return 1 + folhas2(A->sad) + folhas2(A->sae);
    else
        return 0 + folhas2(A->sad) + folhas2(A->sae);

}

int somaNos (Arv A){
    if (A) return A->info + somaNos(A->sae) + somaNos(A->sad);
    else return 0;
}

//EXERCICIOS DA LISTA ABAIXO
//EXERCICIO 1
Arv buscaPai(Arv A, int elem){

    if (A == NULL) return NULL;
    if (A->sae-> info == elem)  return A;
    if (A->sad-> info == elem)  return A;
    if (buscaPai(A->sae, elem) != NULL) return A;
    if (buscaPai(A->sad, elem) != NULL) return A;
    return NULL;
}

//EXERCICIO 2
int altura(Arv *A){
    if (A == NULL) return -1;
    if (*A == NULL) return -1;

    int altura_sae = altura(&((*A)->sae));
    int altura_sad = altura(&((*A)->sad));

    if (altura_sae > altura_sad) return altura_sae +1;
    else return altura_sad +1;

}

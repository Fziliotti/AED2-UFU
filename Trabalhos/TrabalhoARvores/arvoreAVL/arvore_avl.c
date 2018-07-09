#include "arvore_avl.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct no{
    Reg info;
    struct no *sae;
    struct no *sad;
    int fb;
};

Arv cria_arvore(){
    return NULL;
}


Reg cria_reg(int chave, int capacidade, char *pontoDeRede, char *localizacao){
    Reg registro;
    registro.capacidade = capacidade;
    registro.chave = chave;
    strcpy(registro.pontoDeRede, pontoDeRede);
    strcpy(registro.localizacao, localizacao);
    return registro;

}

int arvore_vazia(Arv A){
    return (A==NULL?1:0);
}

void libera_arvore(Arv *A){
    if(*A!=NULL){
        libera_arvore(&(*A)->sae);
        libera_arvore(&(*A)->sad);
        free(*A);
        *A=NULL;
    }
}

void exibe_arvore (Arv A){
    if(A==NULL) printf("<>");
    else{
        printf("<");

        printf("%d", A->info.chave);
        exibe_arvore(A->sae);
        exibe_arvore(A->sad);
        printf(">");
    }
}

void exibe_ordenado(Arv A){

    if(A!=NULL){
        exibe_ordenado(A->sae);
        printf("%d", A->info.chave);
        exibe_ordenado(A->sad);
    }
}

int insere_ord(Arv *A, Reg elem){
    if(A==NULL) return 0;

    if(*A==NULL){
        Arv novo = (Arv) malloc (sizeof(struct no));
        if(novo == NULL) return 0;
        novo->info = elem;
        novo->sae = NULL;
        novo->sad = NULL;
        *A = novo;
        return 1;
    }

    if(elem.chave > (*A)->info.chave){
        return insere_ord(&(*A)->sad, elem);
    }
    else return insere_ord(&(*A)->sae, elem);
}


int remove_ord(Arv *A, int chave){

    if(A == NULL || arvore_vazia(*A)){
        return 0;
    }

    if(chave > (*A)->info.chave) return remove_ord(&(*A)->sae, chave);
    else if (chave < (*A)->info.chave) return remove_ord(&(*A)->sad, chave);
    // encontrou o no (chave = chave da raiz)
    else{
        // no eh folha
        if((*A)->sae == NULL && (*A)->sad == NULL){
            free(*A);
            *A=NULL;
            return 1;
        }
        // no tem 1 filho a esq
        else if((*A)->sae !=NULL && (*A)->sad ==NULL){
            Arv aux = *A;
            *A = (*A)->sae;
            free(aux);
            return 1;
        }
        // no tem 1 filho a dir
        else if((*A)->sae == NULL && (*A)->sad!=NULL){
            Arv aux = *A;
            *A = (*A)->sad;
            free(aux);
            return 1;
        }
        // no tem 2 filhos
        else{
            // localiza a maior chave da SAE (no mais a direita)
            Arv aux = (*A)->sae;
            while(aux->sad !=NULL){
                aux = aux->sad;
            }

            // troca de conteudo entre aux e no a remover
            Reg temp = (*A)->info;
            (*A)->info = aux->info;
            aux->info = temp;
            return remove_ord(&(*A)->sad, chave);
        }
    }
}

Arv busca_bin(Arv A, int chave){
    if(arvore_vazia(A)){
        return NULL;
    }
    if(chave == A->info.chave){
        return A;
    } else if(chave > A->info.chave){
        return busca_bin(A->sad, chave);
    } else{
        return busca_bin(A->sae, chave);
    }
}

int altura_arvore(Arv A){
    if(arvore_vazia(A)){
        return -1;
    }
    int altura_sae = altura_arvore(A->sae);
    int altura_sad = altura_arvore(A->sad);

    if(altura_sae > altura_sad){
        return altura_sae + 1;
    } else{
        return altura_sad + 1;
    }
}

// FUNCOES AVL
int rot_dir(Arv* pai){
    // pai = raiz da subarvore ou arv que esta desbalanceada
    if(*pai != NULL && (*pai)->sae != NULL){
        Arv temp = (*pai)->sae; //temp = sae1
        (*pai)->sae = temp->sad; //sae1 = sad2
        temp->sad = *pai; //sad2 = raiz
        (*pai)->fb = 0;
        temp->fb = 0;
        *pai = temp; //raiz = sae1
        return 1;
    }
    return 0;
}

int rot_esq(Arv* pai){
    // pai = raiz da subarvore ou arv que esta desbalanceada
    if(*pai != NULL && (*pai)->sad != NULL){
        Arv temp = (*pai)->sad; //temp = sad1
        (*pai)->sad = temp->sae; //sad1 = sae2
        temp->sae = *pai; //sae2 = raiz
        (*pai)->fb = 0;
        temp->fb = 0;
        *pai = temp; //raiz = sad1
        return 1;
    }
    return 0;
}

int rot_dir_esq(Arv* pai){
    if(*pai != NULL && (*pai)->sae != NULL){
        // rotacao a direita a partir da raiz da arv
        Arv filho_esq = (*pai)->sae;

        // rotacao a esquerda a paertir da raiz de sae (filho_esq)
        Arv neto_dir = filho_esq->sad;
        filho_esq->sad = neto_dir->sae;
        neto_dir->sae = filho_esq;
        (*pai)->sae = neto_dir->sad;
        neto_dir->sad = *pai;

        // ajuste dos fatores de balanceamento (fb)
        if(neto_dir->fb == -1){
            (*pai)->fb = 0;
            filho_esq->fb = 1;
        } else if(neto_dir->fb == 1){
            (*pai)->fb = -1;
            filho_esq->fb = 1;
        }else{ // neto_dir->fb == 0
            (*pai)->fb = 0;
            filho_esq->fb = 0;
        }
        neto_dir->fb = 0;
        *pai = neto_dir;
        return 1;
    }
    return 0;
}

int rot_esq_dir(Arv* pai){
    if(*pai != NULL && (*pai)->sad != NULL){
        // rotacao a esquerda a partir da raiz da arv
        Arv filho_dir = (*pai)->sad;

        // rotacao a esquerda a paertir da raiz de sad (filho_dir)
        Arv neto_esq = filho_dir->sae;
        filho_dir->sae = neto_esq->sad;
        neto_esq->sad = filho_dir;
        (*pai)->sad = neto_esq->sae;
        neto_esq->sae = *pai;

        // ajuste dos fatores de balanceamento (fb)
        if(neto_esq->fb == -1){
            (*pai)->fb = 1;
            filho_dir->fb = 0;
        } else if(neto_esq->fb == 1){
            (*pai)->fb = 0;
            filho_dir->fb = -1;
        }else{ // neto_dir->fb == 0
            (*pai)->fb = 0;
            filho_dir->fb = 0;
        }
        neto_esq->fb = 0;
        *pai = neto_esq;
        return 1;
    }
    return 0;
}

int balancear_esq(Arv* A){
    if ((*A)->sae->fb > 0){
        return rot_dir(A);
    } else{
        return rot_dir_esq(A);
    }
}

int balancear_dir(Arv* A){
    if ((*A)->sae->fb < 0){
        return rot_esq(A);
    } else{
        return rot_esq_dir(A);
    }
}

int insere_AVL(Arv *A, Reg elem, int* Bal){ // Bal = balanceamento
    if(A == NULL){
        return 0;
    }
    if(*A == NULL){
        Arv novo = (Arv) malloc (sizeof(struct no));
        if(novo == NULL){
            return 0;
        }
        novo->info = elem;
        novo->sae = NULL;
        novo->sad = NULL;
        novo->fb = 0;
        *A = novo;
        *Bal = 1; //ativa verificacao de balanceamento

    } else if(elem.chave <= (*A)->info.chave){
        insere_AVL(&(*A)->sae, elem, Bal);
        if(*Bal == 1){ // verifica a necessidade de balanceamento
            if((*A)->fb == 1){
                balancear_esq(A);
                Bal = 0; // arvore balanceada
            } else if ((*A)->fb == 0){
                (*A)->fb = 1;
            } else{ // campo fb da raiz = -1
                (*A)->fb = 0;
                Bal = 0;
            }
        }
    } else{ // chave do elem > chave da raiz
        insere_AVL(&(*A)->sad, elem, Bal);
        if(*Bal == 1){ // verifica a necessidade de balanceamento
            if((*A)->fb == -1){
                balancear_dir(A);
                Bal = 0; // arvore balanceada
            } else if ((*A)->fb == 0){
                (*A)->fb = -1;
            } else{ // campo fb da raiz = 1
                (*A)->fb = 0;
                Bal = 0;
            }
        }
    }
    return 1;
}

// remover de uma subarvore = inserir na outra subarvore
int remove_AVL(Arv *A, Reg elem, int* Bal){ // Bal = balanceamento
    if(A == NULL || *A == NULL){
        return 0;
    }
    *Bal = 1;
    if(elem.chave <= (*A)->info.chave){
        remove_AVL(&(*A)->sae, elem, Bal);
        if(*Bal == 1){ // verifica a necessidade de balanceamento
            if((*A)->fb == 1){
                balancear_dir(A);
                Bal = 0; // arvore balanceada
            } else if ((*A)->fb == 0){
                (*A)->fb = 1;
            } else{ // campo fb da raiz = -1
                (*A)->fb = 0;
                Bal = 0;
            }
        }
    } else{ // chave do elem > chave da raiz
        remove_AVL(&(*A)->sad, elem, Bal);
        if(*Bal == 1){ // verifica a necessidade de balanceamento
            if((*A)->fb == -1){
                balancear_esq(A);
                Bal = 0; // arvore balanceada
            } else if ((*A)->fb == 0){
                (*A)->fb = -1;
            } else{ // campo fb da raiz = 1
                (*A)->fb = 0;
                Bal = 0;
            }
        }
    }
    return 1;
}

// FUNCOES DO TRABALHO

Reg* menor_trafego(Arv atual){
    if(arvore_vazia(atual)){
        return NULL;
    }
    Arv no1 = atual;
    Arv no2 = atual->sae;
    while(no2 != NULL){
        no1 = no2;
        no2 = no2->sae;
    }
    return &no1->info;
}

int qtde_ocioso(Arv A){
    if (arvore_vazia(A)) {
        return 0;
    }
    int num_ociosos = 0;
    if(A->info.chave < (A->info.capacidade)/2){
        num_ociosos++;
    }
    num_ociosos += qtde_ocioso(A->sae);
    num_ociosos += qtde_ocioso(A->sad);

    return num_ociosos;
}

int nro_nos_de_derivacao(Arv A){
    if (arvore_vazia(A)) {
        return 0;
    }
    int nosDeDerivacao = 0;
    if(A->sae != NULL || A->sad != NULL){
        nosDeDerivacao++;
    }
    nosDeDerivacao += nro_nos_de_derivacao(A->sae);
    nosDeDerivacao += nro_nos_de_derivacao(A->sad);

    return nosDeDerivacao;
}

int Reg_iguais(Reg reg1, Reg reg2){
    if (reg1.chave != reg2.chave ||
        reg1.capacidade != reg2.capacidade ||
        (strcmp(reg1.pontoDeRede, reg2.pontoDeRede) != 0) ||
        (strcmp(reg1.localizacao, reg2.localizacao) != 0)){
        return 0;
    }
    return 1;
}

int iguais(Arv A1, Arv A2){
    if (arvore_vazia(A1) && arvore_vazia(A2)) {
        return 1;
    }
    if((arvore_vazia(A1) && !arvore_vazia(A2)) ||
       (!arvore_vazia(A1) && arvore_vazia(A2))){
        return 0;
    }
    return (Reg_iguais(A1->info, A2->info) && iguais(A1->sae, A2->sae) && iguais(A1->sad, A2->sad));
}

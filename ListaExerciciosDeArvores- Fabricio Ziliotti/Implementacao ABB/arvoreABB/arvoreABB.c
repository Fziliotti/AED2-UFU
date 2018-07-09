
#include "arvoreABB.h"
#include "string.h"



struct no{
    Reg info;
    struct no *sae;
    struct no *sad;
};

Arv cria_arvore(){
    return NULL;
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
        printf("%d -", A->info.chave);
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

    if(A == NULL){
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
            return remove_ord(&(*A)->sae, chave);
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

int de_maior(Arv A){
    if(arvore_vazia(A)){
        return 0;
    }
    int maiores = 0;
    if(A->info.chave >= 18){
        maiores += 1;
    }
    maiores += de_maior(A->sae);
    maiores += de_maior(A->sad);

    return maiores;
}

int qtde_alunos_entreXY(Arv A, int ini, int fim){
    if(arvore_vazia(A)){
        return 0;
    }
    int entreXY = 0;
    if(A->info.chave >= ini && A->info.chave <= fim){
        entreXY += 1;
    }
    entreXY += qtde_alunos_entreXY(A->sae, ini, fim);
    entreXY += qtde_alunos_entreXY(A->sad, ini, fim);

    return entreXY;
}

int um_filho(Arv A){
    if(arvore_vazia(A)){
        return 0;
    }
    int qtdeUmFilho = 0;
    if(A->sae == NULL && A->sad != NULL){
        qtdeUmFilho += 1;
    } else if(A->sae != NULL && A->sad == NULL){
        qtdeUmFilho += 1;
    }
    qtdeUmFilho += um_filho(A->sae);
    qtdeUmFilho += um_filho(A->sad);

    return qtdeUmFilho;
}

Arv percorreInserindo(Arv A1, Arv A2){
    if(A1!=NULL){
        insere_ord(&(A2), A1->info);
        percorreInserindo(A1->sae, A2);
        percorreInserindo(A1->sad, A2);
        return A2;
    }
    return NULL;
}

//percorre a arvNova inserindo a A1 e A2
Arv juntar(Arv A1, Arv A2){
    Arv arvNova = cria_arvore();
    arvNova = percorreInserindo(A1, arvNova);
    arvNova = percorreInserindo(A2, arvNova);
    return arvNova;
}


Reg cria_Reg(int chave, char* nome, int idade,double salario){
    Reg reg;
    reg.chave = chave;
    strcpy(reg.nome,nome);
    reg.idade = idade;
    reg.salario = salario;
    return reg;
}



//verifica se a arvore so possui nós intermediarios com o maximo de filhos
int verificaIntermediarios(Arv A){
    if(A!=NULL){
        //se for no folha, ou se tiver dois filhos
        return (((A->sae == NULL && A->sad == NULL) || (A->sae !=NULL && A->sad !=NULL))
                && verificaIntermediarios(A->sae)
                && verificaIntermediarios(A->sad));
    }
    return 1;
}



int verificaDifAltura(Arv A){
    if(arvore_vazia(A)){
        return -1;
    }
    int altura_sae = altura_arvore(A->sae);
    int altura_sad = altura_arvore(A->sad);
    int difAltura = altura_sae - altura_sad;

    if(difAltura == 1 || difAltura == -1 || difAltura == 0)return 1;
    return 0;
}

//aux eh a variavel para verificar se a diferenca é maior que 1 ou nao
int completa(Arv A){
    return (verificaIntermediarios(A) && verificaDifAltura(A));

}

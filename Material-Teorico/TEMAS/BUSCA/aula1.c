// TAD DICIONARIO

struct registro{
	int chave;
	char nome[100];
};
typedef struct registro Registro;

#define MAX 10

//arquivo é um conjunto de dicionarios
struct arquivo{
	Registro itens[MAX];
	int tamanho;
};
typedef struct arquivo Arq;

// INICIA O TAD ARQUIVO

Arq * iniciaArquivo (){
	Arq * arq = (Arq *) malloc(sizeof(Arq));
	if(arq != NULL) arq->tamanho =0;
	return arq;
}

int arq_cheio(Arq* arq){
	if (arq->tamanho == MAX) return 0;
	return 1;
}

int insere_registro (Arq* arq, Registro Elem){
	if(arq_cheio(arq)) return 0;
	//insere no final do vetor dentro do arquivo
	arq->itens[arq->tamanho] = Elem;
	arq->tamanho++;
	return 1;
}

int remove_registro (Arq* arq, int chave){
	//verificacoes
	// if(arq == NULL) return 0;
	if(arq->tamanho == 0) return 0;
	int x, posicao = busca_seq(arq,chave); //essa parte deve variar
	if(posicao == -1) return 0; //verifica se a pesquisa nao deu certo
	for(x=posicao; x < arq->tamanho; x++){
		arq->itens[x] = arq->itens[x+1];
	}
	arq->tamanho--;
	return 1;
}


int busca_seq (Arq* arq, int chave ){
	if (arq->tamanho ==0)return -1;
	int x=0;
	while(x< arq->tamanho && arq->itens[x].chave != chave)x++;
	if(x == arq->tamanho)return -1;
	return x; // chegou na posicao do elemento
}

// COLOCA UM SENTINELA, o elemento que eu quero procurar no fim do vetor, para eliminar uma das verificacoes, tem que mudar o tamanho para [MAX+1] dentro do Arquivo
int busca_seqOti (Arq* arq, int chave ){
	if (arq->tamanho ==0)return -1;
	// colocando o sentinela
	arq->itens[arq->tamanho].chave = chave;
	int x=0;
	while(arq->itens[x].chave != chave)x++;
	if(x == arq->tamanho)return -1;
	return x; // chegou na posicao do elemento
}
//O(N) no pior caso



//testando
int pesquisa_registro(Arq* arq, int chave){
	if(arq->tamanho == 0) return -1;
	int i;
	int tam = arq->tamanho;
	for (i = 0; i < tam ; i++){
		if(arq->itens[i].chave == chave) return i;
	}
	return -1;
}

//vetor tem que estar ordenado!
int busca_binaria(Arq* arq, int chave){
	if(arq->tamanho == 0) return -1;
	int meio, ini=0, fim = arq->tamanho-1;

	while(ini <= fim){
		meio = (ini +fim)/2;
		if(arq->itens[meio].chave == chave)return meio;
		else if (arq->itens[meio].chave>chave)fim = meio-1;
		else ini = meio+1;
	}
	return -1;
}

int main(){


	return 0;
}
#include <stdio.h>
#include <stdlib.h>

void soma_um (int n){
	n +=1;
	printf("dentro da funcao: x = %d\n",n );
}

// PASSAGEM POR VALOR, VAI SER UMA COPIA DO DADO PASSADO, NAO SERA
// O VALOR ORIGINAL EM SI
int main(){
	int x=5;
	printf("Antes da função: x = %d\n",x);

	soma_um(x);
	printf("Depois da funcao x = %d\n",x );
	return 0;
}
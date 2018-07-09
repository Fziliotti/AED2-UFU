#include <stdio.h>
#include <stdlib.h>

void soma_um (int *n){
	*n +=1;
	printf("dentro da funcao: x = %d\n",*n );
}

// PASSAGEM POR REFERENCIA passa endereco na chamada de funcao
int main(){
	int x=5;
	printf("Antes da função: x = %d\n",x);

	soma_um(&x);
	
	printf("Depois da funcao x = %d\n",x );
	return 0;
}
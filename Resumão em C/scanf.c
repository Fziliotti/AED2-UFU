#include <stdio.h>
#include <stdlib.h>

int main(){

	char letra;
	int numero;
	float numero2;

	scanf("%c", &letra);
	scanf("%d", &numero);
	scanf("%f", &numero2);

	printf("Os valores digitados foram:\n");
	printf("%c\n", letra);
	printf("%d\n", numero);
	printf("%f\n", numero2);

	system("pause");
	return 0;
}
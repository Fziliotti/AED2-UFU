#include <stdio.h>
#include <stdlib.h>

int main(){

	int x = 10;
	double y = 25.2;
	float z = 12;
	printf("%i\n%.2f \n%f", x, y, z);
	printf("\nSoma:\n%lf", x+y+z );

	system("pause");
	return 0;
}
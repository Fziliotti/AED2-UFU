#include <stdio.h>
#include <stdlib.h>


// int Max (int *A, int n){
// 	int i,temp;
// 	temp = A[0];
// 	for (int i = 1; i < n; i++)
// 	{
// 		if (temp < A[i]) temp = A[i];
// 	}
// 	return temp;
// }

int maiorElementoRec(int *A, int s)
{
       if (s==1) return (A[0]);
       else {
               int x;
               x = maiorElementoRec(A, s-1);
               if (x>A[s-1]) return (x);
               else return (A[s-1]);
       }
}

int main(){
	int A[] = {1,3,4,5,6,7,2,8,9,10,11};
	int x = maiorElementoRec(A,11);
	printf("%d\n", x);

	return 0;
}
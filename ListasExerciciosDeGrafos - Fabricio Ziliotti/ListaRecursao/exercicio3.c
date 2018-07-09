#include <stdio.h>
#include <stdlib.h>

void substring(char pl[30]){
    char aux[30], p2[30]; //auxiliares
    int n=0,i;

    //percore o vetor de caracteres ate a parada
    while(pl[n] != '\0'){
        for (i = 0; i <=n; i++){
            aux[i] = pl[i];
        }
        aux[i]='\0';
        printf("%s,",aux );
        n++;
    }


    i=1;
    //cria o vetor de caracteres menos o 1 elemento
    while(pl[i] != '\0'){
        p2[i-1] = pl[i];
        i++;
    }
    p2[i-1]= '\0';

    //RECURSAO
    if(p2[0] != '\0') substring(p2); //recursao para que repita o processo com a lista - o caractere
}

int main()
{
    char teste[] = "UFA";
    printf("Para a string %s temos: ", teste);
    substring(teste);
    return 0;
}

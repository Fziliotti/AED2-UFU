#include<stdio.h>
#include<stdlib.h>
#include "Grafo.h"
#include <string.h>
#include <conio.h>

int main()
{
    Ponto pontos[27];

    int i=0;
    FILE*arq;
    arq=fopen("vertices.txt","r");
    for(i=0;i<27 && !feof(arq);i++){

      fscanf(arq,"%d;%[^;]s",&pontos[i].cod,pontos[i].nome);
      fscanf(arq,";%f;%f",&pontos[i].x, &pontos[i].y);
    }
    Grafo *G = cria_grafo(27);
    FILE*arq2;
    arq2=fopen("arestas.txt","r");
    for(i=0;i<30 && !feof(arq2);i++){
        int ori, dest, peso;
        fscanf(arq2,"%d;%d;%d",&ori, &dest, &peso);
        insere_aresta(G, ori, dest, peso);
    }

    int aux = 0;
    do{
    int valor;

    printf("-------------------MENU-------------------\n");
    printf(" 1 - Verificar numero de vertices \n");
    printf(" 2 - Verificar grau do vertice \n");
    printf(" 3 - Verificar se v1 eh adjacente a v2 \n");
    printf(" 4 - Calcular caminho mais rapido entre dois PoPs\n");
    printf(" 5 - Verificar quais caminhos sao possiveis dado um tempo limite\n");
    printf(" 6 - Verificar quais caminhos sao possiveis dado pontos intermediarios maximos\n");
    printf(" 7 - Sair \n");
    printf ("Escolha uma opcao: ");
    scanf("%d", &valor);
    int vertice, vertice1, vertice2, tam, quant;
    float tempo;
    switch ( valor )
    {
    case 1 :
        //verifica numero de vertices
        printf("O numero de vertices do grafo eh: %d\n", numVertices(G) );
        break;

    case 2 :

        printf("\nDigite o  vertice para saber o grau:");
        scanf("%d", &vertice);
        printf("O grau do vertice %d eh: %d\n", vertice, grauVertice(G, vertice) );
        break;

    case 3 :

        printf("\nDigite os dois vertices para saber se sao adjacentes:\n");
        printf("Vertice 1: ");
        scanf("%d", &vertice1);
        printf("Vertice 2: ");
        scanf("%d",  &vertice2);
        if(ehAdjacente(G, vertice1,vertice2))printf("Os vertices digitados sao adjacentes");
        else printf("Nao sao adjacentes!");
        break;

    case 4 :

        printf("\nDigite os dois vertices para saber o caminho mais rapido entre eles\n");
        printf("Vertice 1: ");
        scanf("%d", &vertice1);
        printf("Vertice 2: ");
        scanf("%d",  &vertice2);
        printf("Digite o tamanho do arquivo: ");
        scanf("%d", &tam);
        caminhoMaisRapido(G, pontos, vertice1, vertice2, tam);
        break;

    case 5 :


        printf("\nDigite um vertice, um tamanho e um tempo maximo para saber quantos destinos sao possiveis\n");
        printf("Vertice: ");
        scanf("%d", &vertice);
        printf("Tamanho do arquivo: ");
        scanf("%d", &tam);
        printf("Tempo maximo: ");
        scanf("%f", &tempo);
        excedeTempo(G, pontos, vertice, tam, tempo);
        break;

    case 6 :

        printf("\nDigite um vertice e a quantidade maxima de pontos intermediarios: \n");
        printf("Vertice: ");
        scanf("%d", &vertice);
        printf("Quantidade maxima de pontos: ");
        scanf("%d", &quant);
        coberturaEnvio(G, pontos, vertice, quant);
        break;

    case 7 :
        aux=10;
        break;

    default :
        printf ("Valor invalido!\n");
    }
    if(aux!=10){
    int x = 2;
    while(x>1){
        printf("\nDeseja realizar voltar ao menu? 1- SIM / 0- NAO:  ");
        scanf("%d", &x);
        if(x==1){
            system("cls");
        }
        if(x==0){
            aux = 10;
        }
    }
    }
    }while(aux!=10);




return 0;

}

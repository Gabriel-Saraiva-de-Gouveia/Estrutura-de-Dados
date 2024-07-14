/* 
Autor: Gabriel Saraiva
Data: 19/12/2022
Objetivo: fazer um programa que aloca uma matriz de 3 dimensões 
e preenche cada elemento com a soma dos índices.
*/
#include <stdio.h>
#include <stdlib.h>
int main(){
    int ***mat;
    int i, j, k;
    int l, c, p; //l para linhas, c para colunas e p para profundidade  

    printf("Entre com o numero de linhas: ");
    scanf("%d",&l);
    printf("Entre com o numero de colunas: ");
    scanf("%d",&c);
    printf("Entre com o numero da profundidade: ");
    scanf("%d",&p);

    // aloca um vetor de l ponteiros para linhas 
    mat = malloc (l * sizeof(int*));

    // aloca cada uma das linhas (vetores de c inteiros)
    for(i = 0; i < l; i++){
        mat[i] = malloc (c * sizeof(int*));
    }
    for(j = 0; j < c; j++){
        mat[j] = malloc (p * sizeof(int));
    }

    //percorre a matriz 
    for(i = 0; i < l; i++){
        for(j = 0; j < c; j++){
            for(k = 0; k < p; k++){
                mat[i][j][k] = i + j + k;
                printf("%d",mat[i][j][k]);
                printf("\t");
            }
            printf("\n");
        }
        printf("\n");
    }
    for(i = 0; i < l; i++){
        free(mat[i]);
        for(j = 0; j < c; j++){
            free(mat[j]);
        }
    }
    free(mat);
}

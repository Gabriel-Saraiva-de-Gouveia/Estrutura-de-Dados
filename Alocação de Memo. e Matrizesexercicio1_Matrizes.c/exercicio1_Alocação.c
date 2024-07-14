/* 
Autor: Gabriel Saraiva
Data: 15/12/2022
Objetivo: fazer um programa que receba duas matrizes e calcule seu produto.
Utilizando aloção dinâmica 
*/
#include <stdio.h>
#include <stdlib.h>

// ---------- Utilizando Alocação Única ----------
#define LINHAS 3
#define COLUNAS 3
int main(){
    int *mat1;
    int *mat2;
    int *mat3;
    int i, j;
    //alocação de um vetor para as duas matrizes 
    mat1 = malloc (LINHAS * COLUNAS * sizeof(int));
    mat2 = malloc (LINHAS * COLUNAS * sizeof(int));
    mat3 = malloc (LINHAS * COLUNAS * sizeof(int));

    //laço que percorre a matriz 1 e guarda seus respectivos valores:
    for(i = 0; i < LINHAS; i++){
        for(j = 0; j < COLUNAS; j++){
            printf("Digite o valor da matriz 1 na posicao %d: ",mat1[i * COLUNAS + j]); 
            scanf("%d", &mat1[i * COLUNAS + j]);
        }
    }
    //---------- Percorre a matriz 2 --------
    for(i = 0; i < LINHAS; i++){
        for(j = 0; j < COLUNAS; j++){
            printf("Digite o valor da matriz 2 na posicao %d:",mat2[(i*COLUNAS)+ j]); 
            scanf("%d", &mat2[i * COLUNAS + j]);
        }
    }

    //----------- Calcula a matriz 3 ------------
    for(i = 0; i < LINHAS; i++){
        for(j = 0; j < COLUNAS; j++){
            mat3[i*COLUNAS+j] = mat1[i* COLUNAS+j] * mat2[(i*COLUNAS)+ j];
        }
    }

    //----------- Imprime a matriz 3 ------------
    for(i = 0; i < LINHAS; i++){
        for(j = 0; j < COLUNAS; j++){
            printf("%2d\t",mat3[(i*COLUNAS)+ j]);
        }
    }

    //Liberação da memória alocada
    free(mat1);
    free(mat2);
    free(mat3);
}

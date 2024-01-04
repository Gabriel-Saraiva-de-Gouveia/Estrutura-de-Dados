/* 
Autor: Gabriel Saraiva
Data: 19/12/2022
Objetivo: fazer um programa que aloca uma matriz de 3 dimensões 
e preenche cada elemento com a soma dos índices. Utilizar alocação unica 
*/
#include <stdio.h>
#include <stdlib.h>
int main(){
    int *mat;
    int i, j, k; 
    int linha, coluna, pfdade;

    printf("Entre com o numero de linhas: ");
    scanf("%d",&linha);
    printf("Entre com o numero de colunas: ");
    scanf("%d",&coluna);
    printf("Entre com o numero da profundidade: ");
    scanf("%d",&pfdade);

    mat = malloc (linha * coluna * pfdade * sizeof(int));

    //percorre a matriz 
    for(i = 0; i < linha; i++){
        for(j = 0; j < coluna; j++){
            for(k = 0; k < pfdade; k++){
                mat[(i*j*pfdade)+k] = i + k + j;
                printf("%d", mat[(i*j*pfdade)+k]);
                printf("\t");
            }
            printf("\t");
        }
        printf("\n");

    }
    free(mat);
    //Verificação: ok!
    //Revisão: ok!
}
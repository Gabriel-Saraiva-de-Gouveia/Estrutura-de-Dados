/* 
Autor: Gabriel Saraiva
Data: 19/12/2022
Objetivo: fazer um programa que encontre e imprima um quadrado mágico, ou seja, uma matriz
cuja soma dos elementos de cada linha, coluna e diagonal seja 15.
Utilizando aloção dinâmica
*/
#include <stdio.h>
#include <stdlib.h>
#define LIN 3
#define COL 3

int main(){
    //Primeiramente, alocar espaço para a matriz 
    //----- Utilizando alocação de um vetor de ponteiros ------
    int **mat;  //ponteiro de ponteiros 
    int i, j, soma;
    
    // aloca um vetor de LIN ponteiros para linhas 
    mat = malloc (LIN * sizeof (int*)); 

    // laço que aloca cada uma das linhas (vetores de COL inteiros)
    for(i = 0; i < LIN; i++){
        mat[i] = malloc (COL * sizeof(int));
    }

    // declaração das variáveis auxiliares 
    int soma_elementos_linhas;
    int soma_elementos_colunas;
    int soma_diagonal_principal;
    int soma_diagonal_secundaria;

    // laço que percorre a matriz e guarda os valores das posições 
    for(i = 0; i < LIN; i++){
        for(j = 0; j < COL; j++){
            printf("Digite o valor da matriz na posicao [%d][%d]: ",i,j);
            scanf("%d",&mat[i][j]);
        }
    }

// laço que calcula a soma dos elementos das linhas, colunas e da diagonal principal
    for(i = 0; i < LIN; i++){
        soma_elementos_linhas = 0;
        for(j = 0; j < COL; j++){
            soma_elementos_linhas = soma_elementos_linhas + mat[i][j];
            if(i == j){
                soma_diagonal_principal = soma_diagonal_principal + mat[i][j];
            }
        }
    }
    for(j = 0; j < COL; j++){
        soma_elementos_colunas = 0;
        for(i = 0; i < LIN; i++){
            soma_elementos_colunas = soma_elementos_colunas + mat[i][j];
        }
    }
// laço um pouco mais "intuitivo" que calcula a soma dos elementos da diagonal segundaria
    for(i = 0; i < LIN; i++){
        for(j = 2; j < COL; j++){
            soma_diagonal_secundaria = soma_diagonal_secundaria + mat[i][COL - 1 - j];
        }
    }
    /*
    //para conferir 
    printf("%d\n",soma_diagonal_principal);
    printf("%d\n",soma_diagonal_secundaria);
    printf("%d\n",soma_elementos_linhas);
    printf("%d\n",soma_elementos_colunas);
    */
    
    if(soma_diagonal_principal && soma_diagonal_secundaria &&
    soma_elementos_linhas && soma_elementos_colunas == 15){
        for(i = 0; i < LIN; i++){
            for(j = 0; j < COL; j++){
                printf("%d",mat[i][j]);
                printf("\t");
            }
        }
        printf("\nA matriz eh um quadrado magico!");
    }else{
        printf("\nA matriz nao eh um quadrado magico");
    }
    //liberar memória
    for(i = 0; i < LIN; i++){
        free(mat[i]);
    }
    free(mat);
}
//Verificação: ok!
//Revisão: ok!

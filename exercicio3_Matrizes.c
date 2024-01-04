/* 
Autor: Gabriel Saraiva
Data: 05/12/2022
Objetivo: ler uma matriz A e construir a matriz B, considerando
“Todo elemento de B deverá ser o quadrado do elemento de A correspondente”
*/
#include <stdio.h>
int main(){
    int A[15];
    int B[15];
    int i;
    // Ler os valores do vetor
    for(i = 0; i < 15; i++){
        printf("Digite o valor A[%d] no vetor.: ",i);
        scanf("%d", &A[i]);
    }
    //Atribui os valores de A para B
    for(i = 0; i < 15; i++){
        B[i] = A[i] * A[i];
        printf("Valor de B[%d]: %d\n",i,B[i]);
    }
}
//Verificação: ok!
//Revisão: ok!
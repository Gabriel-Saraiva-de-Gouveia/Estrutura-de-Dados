/* 
Autor: Gabriel Saraiva
Data: 05/12/2022
Objetivo: ler uma matriz A e apresentar a soma dos elementos de sua diagonal principal

*/
#include <stdio.h>
int main(){
    int A[6][6];
    int soma_diag_principal = 0;
    int x, y;

    for(x = 0; x < 6; x++){
        for(y = 0; y < 6; y++){
            printf("Entre com os elementos da matriz A[%d][%d]:",x,y);
            scanf("%d", &A[x][y]);
            if(x == y){
                soma_diag_principal = soma_diag_principal + A[x][y];
            }
        }
    }
    printf("A soma dos elementos da diagonal principal eh: %d",soma_diag_principal);
}
//Verificação: ok!
//Revisão: ok!
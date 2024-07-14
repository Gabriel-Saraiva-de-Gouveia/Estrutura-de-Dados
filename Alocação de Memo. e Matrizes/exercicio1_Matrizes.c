/* 
Autor: Gabriel Saraiva
Data: 05/12/2022
Objetivo: ler uma matriz A e apresentar os resultados, considerando o exercício proposto:
Ler uma matriz A de duas dimensões com 10 linhas e 7 colunas.
Ao final  apresentar o total de elementos pares e o total de elementos impares existentes dentro da matriz.
Apresentar também o percentual de elementos pares e impares  em  relação ao total de elementos da matriz. 
Supondo a existência de 20 elementos pares e 50 elementos impares, ter-se-ia 28,5% de elementos pares e 71,5% de elementos impares.
*/
#include <stdio.h>
int main(){
    int A[10][7];
    int elementos_pares = 0;
    int elementos_impares = 0;
    int i, j;
    float percentual_pares = 0;
    float percentual_impares = 0;

    for( i = 0; i < 10; i++){
        for( j = 0; j < 7; j++){
            printf("Entre com o elementos de A[%d][%d]:\n",i,j);
            scanf("%d", &A[i][j]);
            if(A[i][j] % 2 == 0){
                elementos_pares++;
            }else{
                elementos_impares++;
            }
        }
    }
    percentual_pares = (100 * (float)elementos_pares)/70;
    percentual_impares = (100 * (float)elementos_impares)/70;

    printf("O total de elementos pares eh: %d", elementos_pares);
    printf("\nO total de elementos impares eh: %d", elementos_impares);
    printf("\nO percentual de elementos pares e impares se da por:\n%f de elementos pares\n%f de elementos impares.",percentual_pares, percentual_impares);
    
    return 0;
}
//Verificação: ok!
//Revisão: ok!

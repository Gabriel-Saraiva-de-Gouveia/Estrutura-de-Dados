/*
Autor: Gabriel Saraiva
Data: 09/12/2022
Objetivo: utilizar ponteiros para resolver os problemas propostos
*/
#include <stdio.h>
//Função do exercício 4:
void troca_parametros(int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
}
//Função do exercício 5:
void troca_valores(int *w, int *z){
    int aux = *w;
    if(*z > *w){
        *w = *z;
        *z = aux;

    }
}

int main(){
//Exercício 1:
//Objetivo: fazer um programa que utilize ponteiros para mudar valores de uma determinada variável.
    int inteiro;
    float real;
    char charactere;
    int *pIinteiro;
    float *pReal;
    char *pChar;

    //Associação das variáveis aos ponteiros
    pIinteiro = &inteiro;
    pReal = &real;
    pChar = &charactere;

    //Modificação dos valores
    *pIinteiro = 18;
    *pReal = 18.5;
    *pChar = 'G';

    //Imprime os valores na tela.
    printf("A variavel int eh igual a: %d\nA variavel real eh igual a: %.1f\nA variavel char eh igual a: %c\n",*pIinteiro,*pReal,*pChar);
    //Verificação: ok
    //Revisão: ok 

//Exercício 2:
//Objetivo: comparar os endereços de duas variáveis e imprimir o maior endereço.
    int A = 2;
    int B = 3;
    //os valores atribuidos às variáveis não importam, pois necessita-se de analisar apenas os endereços das mesmas
    int *pA;
    int *pB;
    pA = &A;
    pB = &B;

    if(pA > pB){
        printf("Endereco de B eh maior: %d\n",pB);
    }else{
        printf("Endereco de A eh maior: %d\n",pA);
    }
    //Verificação: ok 
    //Revisão: ok 

//Exercício 3:
//Objetivo: comparar os endereços de duas variáveis inteiras, que serão recebidas, e imprimir o conteúdo do maior endeço

    int x;
    int y;
    int *px;
    int *py;
    px = &x;
    py = &y;
    printf("Entre com a primeira variavel inteira: ");
    scanf("%d",*px);
    printf("Entre com a segunda variavel inteira: ");
    scanf("%d",*py);

    if(px > py){
        printf("O maior endereco eh da primeira variavel.\nO conteudo da variavel eh: %d",*px);
    }else{
        printf("O maior endereco eh da segunda variavel.\nO conteudo da variavel eh: %d",*py);
    }
    //Verificação: O resultado não é o esperado. O programa está imprimindo o endereço não o conteúdo ;-;
    //Revisão: ok

//Exercício 4: 
//Objetivo: fazer um programa que vai ler duas variáveis e direcioná-las como parâmetros de uma função
    int primeiro_parametro;
    int segundo_parametro;
    int *pPrimeiro;
    int *pSegundo;
    pPrimeiro = &primeiro_parametro;
    pSegundo = &segundo_parametro;

    printf("Entre com os valores de A e B: ");
    scanf("%d%d",*pPrimeiro, *pSegundo);

    troca_parametros(&primeiro_parametro, &segundo_parametro);
    printf("\nOs valores de A e B sao respectivamente: %d %d\n",*pPrimeiro,*pSegundo);

//Exercício 5:
//Objetivo: fazer um programa que leia duas variáveis inteiras, e uma função que vai receber esses mesmos valores
    int w;
    int z;
    int *pw;
    int *pz;
    pw = &w;
    pz = &z;
    printf("Entre com os valores das duas variaveis: ");
    scanf("%d%d",*pw,*pz);
    troca_valores(&w, &z);
    printf("Primeira variavel: %d\nSegunda variavel: %d",*pw, *pz);

    //Verificação: o programa não executa
    //Revisão: ok

}

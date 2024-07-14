/*
Autor....: Gabriel Saraiva
Data.....: 02/12/2022
Objetivo: fazer um programa que atenda aos requisitos da prefeitura

1) A prefeitura de uma cidade fez uma pesquisa entre seus habitantes, 
coletando dados sobre o salário e número de filhos.
A prefeitura deseja saber:  
a) média do salário da população;
b) média do número de filhos;
c) maior salário;
d) percentual de pessoas com salário até R$100,00.
O final da leitura de dados se dará com a entrada de um salário negativo.
(Use o comando ENQUANTO-FAÇA) */

#include <stdio.h>
void main(){

    int filhos = 0;
    int num_pessoas = 0;
    int salarios_ate_100 = 0;

    float salario = 0;
    float media_salario = 0.0;
    float media_filhos = 0.0;
    float maior_salario = 0.0;
    float percentual_salarios_ate_100 = 0.0;
    //Prof, usei o FAÇA-ENQUANTO hehe
    do{
        printf("Digite o salario. Entre com salario -1  quando desejar terminar\n");
        scanf("%f", &salario);
        if (salario > 0){
            num_pessoas++; //variavel contadora que guarda o numero de pessoas
        }

        printf("Digite o numero de filhos:\n");
        scanf("%d", &filhos);

        if (salario > maior_salario)
        {
            maior_salario = salario; //if que encontra o maior salario
        }

        if (salario <= 100.00)
        {
            salarios_ate_100++; //variável contadora que armazena os salários acima de 100
        }
        media_salario = media_salario + salario; // variavel acumuladora que guarda o salário da população
        media_filhos = media_filhos + filhos; // variavel acumuladora que guarda o número de filhos

    }while(salario > 0);
    
    media_salario = media_salario / num_pessoas;
    media_filhos = media_filhos / num_pessoas;
    percentual_salarios_ate_100 = ((float)num_pessoas / salarios_ate_100) * 100;

    printf("A media do salario da populacao eh %.2f\n", media_salario);
    printf("A media do numero de filhos eh %.2f\n", media_filhos);
    printf("O maior salario eh %.2f\n", maior_salario);
    printf("O percentual de pessoas com salario ateh 100 reais eh de %.2f%%\n", percentual_salarios_ate_100);

}
//Verificação: ok!
//Revisão: ok!
//FUNCIONA!!

/*
Autor....: Gabriel Saraiva
Data.....: 02/12/2022
Objetivo: fazer um programa que calcule o resultado de uma eleiçaõ presidencial
considerando o seguinte problema:
2) Em uma eleição presidencial existem quatro candidatos. 
Os votos são informados através de códigos. 
Os dados utilizados para a contagem dos votos obedecem à seguinte codificação:  

- 1,2,3,4 = voto para os respectivos candidatos;
- 5 = voto nulo;
- 6 = voto em branco;

Elabore um algoritmo que leia o código do candidato em um voto. Calcule e escreva:

- total de votos para cada candidato;
- total de votos nulos;
- total de votos em branco;

Como finalizador do conjunto de votos, tem-se o valor 0.
*/

#include <stdio.h>

void main(){
    int voto = 1;
    int um = 0;
    int dois = 0;
    int tres = 0;
    int quatro = 0;
    int cinco = 0; 
    int seis = 0;
    while(voto != 0){
        printf("Entre com o voto do respectivo candidato, considerando: \n1 = candidato 1 \n2 = candidato 2 \n3 = candidato 3 \n4 = candidato 4 \n5 = voto branco \n6 = voto nulo\n");
        printf("Entre com o proximo voto, caso queira encerrar a sessao selecione 0: \n");
        scanf("%d", &voto);
        if (voto == 1){
            um = um +1;
        }
        if (voto == 2){
            dois = dois +1;
        }
        if (voto == 3){
            tres = tres +1;
        }
        if (voto == 4){
            quatro = quatro + 1;
        }
        if (voto == 5){
            cinco = cinco + 1;
        }
        if (voto == 6){
            seis = seis + 1;
        }
    }
    printf("%d  votos para o canditado 1\n", um);
    printf("%d  votos para o canditado 2\n", dois);
    printf("%d  votos para o canditado 3\n", tres);
    printf("%d  votos para o canditado 4\n", quatro);
    printf("%d  votos nulos\n", cinco);
    printf("%d  votos em branco\n", seis);

}
//Verificação: ok!
//Revisão: ok! poderia ter simplificado utilizando outras condições... tentarei novamente

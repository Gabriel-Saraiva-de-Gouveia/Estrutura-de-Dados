/*Faça um operação que verifique se uma lista L está com suas chaves em ordem crescente,
sendo L:
a) Uma lista ligada sem sentinela e não circular.
b) Duplamente ligada circular com sentinela.*/
#include <stdio.h>
#include <stdlib.h>

//a) lista ligada sem sentinela e não circular:

typedef struct tipo_item{
    int chave;
}itens;

typedef struct tipo_celula{
    struct tipo_celula *proximo;
    itens item;
}celula;

typedef struct tipo_lista{
    celula *primeiro;
    celula *ultimo;
}Lista;

void inicializa(Lista *lista){
    lista->primeiro=NULL;
    lista->ultimo=NULL;

}
int verifica_vazia(Lista *lista){
    if(lista->primeiro==NULL){
        return 1;
    }
    else{
        return 0;
    }
    /*ou return lista->primeiro==NULL */
}
int insere_inicio(Lista *lista, itens x){
    celula *novo;
    novo = (celula *)malloc(sizeof(celula));
    novo->item=x;
    if(verifica_vazia(lista)){
        lista->ultimo=novo;
    }
    novo->proximo = lista->primeiro;
    lista->primeiro = novo;
}

int insere_fim(Lista *lista, itens x){
    if(verifica_vazia(lista)){
        insere_inicio(lista,x);
    }
    else{
        celula *novo;
        novo = (celula *)malloc(sizeof(celula));
        novo->item=x;
        novo->proximo=NULL;
        lista->ultimo->proximo=novo;
        lista->ultimo=novo;
    }

}

int verifica_ordem_crescente (struct tipo_lista *list){

}
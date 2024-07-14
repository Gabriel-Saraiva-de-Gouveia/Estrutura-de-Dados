/*
    Objetivo: implementar um deque dinamico e operacoes, e a realizacao de um exercicio
    Gabriel Saraiva de Gouiveia RA: 129145
*/
#include <stdio.h>
#include <stdlib.h>

//====== Agregados Heterogeneos:======= //
struct tipo_item{
    int chave;
    // outros campos
};

struct tipo_celula{
    struct tipo_item item;
    struct tipo_celula *prox;
    struct tipo_celula *ant;
};

struct tipo_deque{
    struct tipo_celula *sentinela;
};
/* Exercício proposto 1: Implementar todas as operacoes em deques especificadas */
// Funcao que inicializa o deque:
void inicializa_deque(struct tipo_deque *deque){
    deque->sentinela = (struct tipo_celula *)malloc(sizeof(struct tipo_celula));
    deque->sentinela->prox = deque->sentinela;
    deque->sentinela->ant = deque->sentinela;
}

// Funcao que verifica se o deque est� vazio:
int verifica_vazio(struct tipo_deque *deque){
    return deque->sentinela->prox == deque->sentinela;
}

// Funcao que insere na extremidade direita:
void insere_extremidade_dir(struct tipo_deque *deq, struct tipo_item element){
    struct tipo_celula *novo;
    novo = (struct tipo_celula *)malloc(sizeof(struct tipo_celula));
    novo->item= element;
    novo->prox = deq->sentinela;
    novo->ant = deq->sentinela->ant;
    deq->sentinela->ant->prox = novo;
    deq->sentinela->ant = novo;
}

// Fun��o que insere na extremidade esquerda:
void insere_extremidade_esq(struct tipo_deque *deq, struct tipo_item element){
    struct tipo_celula *novo;
    novo = (struct tipo_celula *)malloc(sizeof(struct tipo_celula));
    novo->item = element;
    novo->ant = deq->sentinela;
    novo->prox = deq->sentinela->prox;
    deq->sentinela->prox->ant = novo;
    deq->sentinela->prox = novo;
}

// Fun��o que remove na extremidade direita:
int remove_extremidade_dir(struct tipo_deque *deq, struct tipo_item *element){
    struct tipo_celula *del;
    if(!verifica_vazio(deq)){
        del = deq->sentinela->ant;
        *element = del->item; //salvar o conte�do de del
        deq->sentinela->ant = del->ant;
        deq->sentinela->ant->prox = deq->sentinela;
        free(del);
        return 1;
    }else{
        return 0;
    }
}

//Fun��o que remove na extremidade esquerda:
int remove_extremidade_esq(struct tipo_deque *deq, struct tipo_item *element){
    struct tipo_celula *del;
    if(!verifica_vazio(deq)){
        del = deq->sentinela->prox;
        *element = del->item;
        deq->sentinela->prox = del->prox;
        del->prox->ant = deq->sentinela;
        free(del);
        return 1;
    }else{
        return 0;
    }
}

/* Exerc�cio proposto 2: Fazer um programa que permita ao usu�rio manipular um deque. A manipula��o
tamb�m conta com duas fun��es que imprimem os elementos da direita para a esquerda e o contr�rio*/

//Fun��es adicionais:

//Fun��o que imprime da direita para a esquerda
void imprime_dir_to_esq(struct tipo_deque *deq){
    printf("\nElementos do deque da direita para a esquerda:\n");
    struct tipo_celula *atual = deq->sentinela->ant;
    while(atual != deq->sentinela){
        printf("%d ", atual->item.chave);
        atual = atual->ant;
    }
    printf("\n");
}


//Fun��o que imprime da esquerda para a direita
void imprime_esq_to_dir(struct tipo_deque *deq){
    printf("\nElementos do deque da esquerda para a direita:\n");
    struct tipo_celula *atual = deq->sentinela->prox;
    while(atual != deq->sentinela){
        printf("%d ", atual->item.chave);
        atual = atual->prox;
    }
    printf("\n");
}

void executa_opcao(struct tipo_deque *d, int opcao){
    switch(opcao){
        case 1:
            printf("Entre com o elemento a ser inserido: ");
            struct tipo_item elemento;
            scanf("%d", &elemento.chave);
            insere_extremidade_dir(d, elemento);
            imprime_dir_to_esq(d);
            break;


        case 2:
            printf("Entre com o elemento a ser inserido: ");
            struct tipo_item element;
            scanf("%d", &elemento.chave);
            insere_extremidade_esq(d, elemento);
            imprime_esq_to_dir(d);
            break;

        case 3:
            remove_extremidade_dir(d, &element);
            printf("\nElemento removido da extremidade direita!\n");
            break;

        case 4:
            remove_extremidade_esq(d, &element);
            printf("\nElemento removido da extremidade esquerda!\n");
            break;

        case 5:
            imprime_dir_to_esq(d);
            break;

        case 6:
            imprime_esq_to_dir(d);
            break;

        case 7:
            free(d);
            printf("Programa encerrado!");
            exit(0); // encerra o programa
            break;

        default:
            printf("Opcao selecionada incorreta!");
            break;
    }
}

//Menu de op��es para que o usu�rio possa manipular o deque:
int main(){
    /*Testes a seguir:*/
    struct tipo_deque *d;
    d =(struct tipo_deque *)malloc(sizeof(struct tipo_deque));
    inicializa_deque(d);
    struct tipo_item x;
    x.chave = 7;
    insere_extremidade_dir(d,x);
    x.chave = 12;
    insere_extremidade_esq(d,x);
    x.chave = 8;
    insere_extremidade_dir(d,x);
    x.chave = 23;
    insere_extremidade_esq(d,x);
    x.chave = 16;
    insere_extremidade_dir(d,x);
    x.chave = 4;
    insere_extremidade_esq(d,x);

    int opcao;
    do{
        printf("======== Menu de Opcoes ========\n");
        printf(" 1. Inserir elemento na extremidade direita\n");
        printf(" 2. Inserir elemento na extremidade esquerda\n");
        printf(" 3. Remover elemento na extremidade direita\n");
        printf(" 4. Remover elemento na extremidade esquerda\n");
        printf(" 5. Mostrar elementos da direita para a esquerda\n");
        printf(" 6. Mostrar elementos da esquerda para a direita\n");
        printf(" 7. Encerrar programa.\n");
        printf("\nDigite a opcao desejada: ");
        scanf("%d", &opcao);
        executa_opcao(d, opcao);
    }while(opcao != 0 && opcao <= 7);
}

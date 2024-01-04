//Exercícios de revisão árvores:
#include <stdio.h>
#include <stdlib.h>

struct tipo_item {
    int valor;
};

struct tipo_no {
    struct tipo_no *esq;
    struct tipo_no *dir;
    struct tipo_item chave;
};

struct tipo_no* criar_no(int valor) {
    struct tipo_no* novo_no = (struct tipo_no*) malloc(sizeof(struct tipo_no));
    novo_no->esq = NULL;
    novo_no->dir = NULL;
    novo_no->chave.valor = valor;
    return novo_no;
}

struct tipo_no* inserir(struct tipo_no* raiz, int valor) {
    if (raiz == NULL) {
        return criar_no(valor);
    }

    if (valor < raiz->chave.valor) {
        raiz->esq = inserir(raiz->esq, valor);
    } else if (valor > raiz->chave.valor) {
        raiz->dir = inserir(raiz->dir, valor);
    }

    return raiz;
}

void imprimir_em_ordem(struct tipo_no* raiz) {
    if (raiz != NULL) {
        imprimir_em_ordem(raiz->esq);
        printf("%d ", raiz->chave.valor);
        imprimir_em_ordem(raiz->dir);
    }
}

//11.Faça um algoritmo que receba uma árvore binária e um valor inteiro N e conte quantos nós
//existem no nível N da árvore.
int contar_nos_niveis(struct tipo_no* raiz, int nivel_desejado) {
    if (raiz == NULL) {
        return 0;
    }
    if (nivel_desejado == 0) {
        return 1;
    }
    return contar_nos_niveis(raiz->esq, nivel_desejado - 1) + contar_nos_niveis(raiz->dir, nivel_desejado - 1);
}

//12.Faça um algoritmo que conte a quantidade de nós folha em uma árvore binária.
int contar_nos_folha(struct tipo_no* raiz) {
    if (raiz == NULL) {
        return 0;
    }
    if (raiz->esq == NULL && raiz->dir == NULL) {
        return 1;
    }
    return contar_nos_folha(raiz->esq) + contar_nos_folha(raiz->dir);
}

//13.Faça um algoritmo que receba uma árvore binária e retorne sua altura.
int calcula_altura_arvore(struct tipo_no* raiz){
    if(raiz == NULL){
        return 0;
    }else {
        int altura_esq = calcula_altura_arvore(raiz->esq); // altura da subárvore esquerda
        int altura_dir = caltura_altura_arvore(raiz->dir); // altura da subárvore direita
        return 1 + (altura_esq > altura_dir ? altura_esq : altura_dir); 
        //operador condicional ternário ? : para selecionar o maior valor entre as alturas das subárvores. 
        //Esse operador é uma forma mais concisa de escrever um if-else.
    }
}
//14.Faça um algoritmo que receba uma árvore binária e diga se ela é uma árvore completa ou não.
int completa(struct tipo_no *raiz, int profundidade, int altura) {
    // Se a árvore estiver vazia, é completa
    if (raiz == NULL) return 1;

    // Se apenas um filho estiver vazio, a árvore não é completa
    if ((raiz->esq == NULL && raiz->dir != NULL) || (raiz->esq != NULL && raiz->dir == NULL)) return 0;

    // Se a profundidade for igual à altura da árvore, o nó deve ser folha
    if (profundidade == altura) return 1;

    // Verifica se os filhos da raiz também são completos
    return completa(raiz->esq, profundidade+1, altura) && completa(raiz->dir, profundidade+1, altura);
}
/*
Dica: utilize as funções implementadas de contar número de nós em um determinado nível e
altura da árvore ou as funções implementadas para contar a quantidade de nós folha e
calcular a altura da árvore que foram previamente implementadas nesta lista.
*/

//15.Faça um algoritmo que receba uma árvore binária e conte quantos nós a árvore possui.
///podemos percorrer a árvore recursivamente e ir somando a cada nó visitado.
int contarNos(struct tipo_no *raiz) {
    if (raiz == NULL) { // caso base: nó nulo
        return 0;
    } else { // caso recursivo: somar 1 para o nó atual e percorrer os filhos
        return 1 + contarNos(raiz->esq) + contarNos(raiz->dir);
    }
}

/*16.Faça um algoritmo que receba uma árvore binária e retorne uma lista contendo quantos nós
existem em cada nível da árvore.
Dica: Use a função implementada no exercício 10.
int* contar_nos_nivel(struct tipo_no *raiz, int *tamanho_lista) {
    int *contagem_nos_nivel = NULL;
    *tamanho_lista = 0;

    // verificar se a raiz é nula
    if (raiz == NULL) {
        return contagem_nos_nivel;
    }

    // criar fila para percorrer a árvore em largura
    struct tipo_no **fila = malloc(sizeof(struct tipo_no *));
    int inicio_fila = 0;
    int fim_fila = 0;

    // adicionar a raiz à fila
    fila[fim_fila++] = raiz;

    // percorrer a árvore em largura
    while (inicio_fila < fim_fila) {
        // obter o número de nós no nível atual
        int tamanho_nivel = fim_fila - inicio_fila;

        // adicionar o número de nós do nível atual à lista de contagem
        contagem_nos_nivel = realloc(contagem_nos_nivel, (*tamanho_lista + 1) * sizeof(int));
        contagem_nos_nivel[*tamanho_lista] = tamanho_nivel;
        (*tamanho_lista)++;

        // adicionar os nós filhos do nível atual à fila
        for (int i = 0; i < tamanho_nivel; i++) {
            struct tipo_no *no_atual = fila[inicio_fila++];

            if (no_atual->esq != NULL) {
                fila = realloc(fila, (fim_fila + 1) * sizeof(struct tipo_no *));
                fila[fim_fila++] = no_atual->esq;
            }

            if (no_atual->dir != NULL) {
                fila = realloc(fila, (fim_fila + 1) * sizeof(struct tipo_no *));
                fila[fim_fila++] = no_atual->dir;
            }
        }
    }

    // liberar a memória alocada para a fila
    free(fila);

    return contagem_nos_nivel;

}
*/

/*17.Faça um algoritmo que receba um nó e calcule seu fator de balanceamento, levando em
consideração que:
a) Os nós da árvore tem um campo altura, conforme mostrado na struct abaixo, que é
manipulado corretamente por toda inserção e remoção na árvore;
struct tipo_no {
    int altura;
    struct tipo_item dado;
    struct tipo_no *esq, *dir;
}
b) Os nós da árvore não tem um campo altura (é permitido usar a função de calcular altura
implementada previamente nesta lista de exercícios)
struct tipo_no {
    struct tipo_item dado;
    struct tipo_no *esq, *dir;
}
*/
/*int calcular_fator_balanceamento(struct tipo_no *no) {
    if (no == NULL) {
        return 0;
    }
    int altura_esq, altura_dir;
    if (no->esq != NULL) {
        altura_esq = no->esq->altura;
    }else {
        altura_esq = calcula_altura_arvore(no->esq);
    }
    if (no->dir != NULL) {
        altura_dir = no->dir->altura;
    }else {
        altura_dir = calcular_altura_arvore(no->dir);
    }
    return altura_esq - altura_dir;
    a função calcular_altura é utilizada caso o nó não tenha o campo "altura" preenchido. 
    A função calcular_fator_balanceamento recebe um ponteiro para o nó a ser analisado e retorna o seu fator de balanceamento. 
    Se o nó for nulo, o fator de balanceamento também é considerado nulo.
}

/*18.Faça um algoritmo que receba uma ABB e uma chave, e mostre os ancestrais do nó que tem
a chave passada como parâmetro na ordem:
    a) Do ancestral mais próximo até a raiz (ou seja, o primeiro a ser mostrado deve ser o pai,e
o ultimo a raiz);
    b) Da raiz até o ancestral mais próximo (ou seja, o primeiro nó a ser mostrado deve ser a
raiz e o ultimo deve ser o nó pai);

19.Faça um algoritmo que receba uma ABB e verifique se ela é uma árvore AVL.

20.Faça um algoritmo que receba uma lista de elementos e ordene-a de maneira crescente, em
tempo de execução O(n log2 n), no pior caso.
Assuma que não exitem elementos repetidos na lista.*/

int main() {
    struct tipo_no* raiz = NULL;

    raiz = inserir(raiz, 10);
    inserir(raiz, 6);
    inserir(raiz, 20);
    inserir(raiz, 3);
    inserir(raiz, 8);

    printf("Árvore em ordem crescente: ");
    imprimir_em_ordem(raiz);

    return 0;
}

/* Exercício para ser entregue sobre árvores AVL
Faça um programa em C que receba um vetor de números e retorne este
vetor ordenado. É obrigatório que seja usada uma árvore AVL no
processo de ordenação.
OBS: Assuma que o vetor não contém elementos repetidos.*/
#include <stdio.h>
#include <stdlib.h>
// Definindo a estrutura de nó da árvore AVL
struct No {
    int valor;
    struct No* esquerda;
    struct No* direita;
};

// Função que cria um novo nó com um determinado valor
struct No* novoNo(int valor) {
    struct No* no = (struct No*)malloc(sizeof(struct No));
    no->valor = valor;
    no->esquerda = NULL;
    no->direita = NULL;
    return no;
}

// Função que insere um valor em uma árvore AVL e retorna a nova raiz
struct No* inserir(struct No* no, int valor) {
    // Realizando a inserção normal em uma árvore binária de busca
    if (no == NULL)
        return novoNo(valor);

    if (valor < no->valor)
        no->esquerda = inserir(no->esquerda, valor);
    else if (valor > no->valor)
        no->direita = inserir(no->direita, valor);
    else
        return no;

    // Verificando o balanceamento do nó
    int balanceamento = altura(no->esquerda) - altura(no->direita);

    // Realizando as rotações necessárias caso o nó esteja desbalanceado
    if (balanceamento > 1 && valor < no->esquerda->valor)
        return rotacionarDireita(no);

    if (balanceamento < -1 && valor > no->direita->valor)
        return rotacionarEsquerda(no);

    if (balanceamento > 1 && valor > no->esquerda->valor) {
        no->esquerda = rotacionarEsquerda(no->esquerda);
        return rotacionarDireita(no);
    }

    if (balanceamento < -1 && valor < no->direita->valor) {
        no->direita = rotacionarDireita(no->direita);
        return rotacionarEsquerda(no);
    }

    return no;
}

// Função que converte uma árvore AVL em um vetor ordenado
void arvoreParaVetor(struct No* no, int* vetor, int* indice) {
    if (no != NULL) {
        arvoreParaVetor(no->esquerda, vetor, indice);
        vetor[(*indice)++] = no->valor;
        arvoreParaVetor(no->direita, vetor, indice);
    }
}

// Função que ordena um vetor de números usando uma árvore AVL
void avl_ordenar(int* vetor, int n) {
    // Criando uma árvore AVL vazia
    struct No* raiz = NULL;

    // Inserindo todos os elementos do vetor na árvore AVL
    for (int i = 0; i < n; i++) {
        raiz = inserir(raiz, vetor[i]);
    }

    // Convertendo a árvore AVL em um vetor ordenado
    int indice = 0;
    arvoreParaVetor(raiz, vetor, &indice);
}

int main() {
    // Exemplo de uso da função avl_ordenar
    int vetor[] = { 3, 6, 1, 9, 5 };
    int n = sizeof(vetor) / sizeof(vetor[0]);
    avl_ordenar(vetor, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    return 0;

}

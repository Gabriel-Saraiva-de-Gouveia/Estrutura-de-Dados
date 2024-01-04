#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct No {
    char pergunta[100];
    struct No* sim;
    struct No* nao;
};

struct No* criarNo(char* pergunta) {
    struct No* no = (struct No*) malloc(sizeof(struct No));
    strcpy(no->pergunta, pergunta);
    no->sim = NULL;
    no->nao = NULL;
    return no;
}

void fazerPerguntas(struct No* no) {
    char resposta[10];
    printf("%s (s/n): ", no->pergunta);
    scanf("%s", resposta);
    if (strcmp(resposta, "s") == 0) {
        if (no->sim == NULL) {
            printf("Qual animal voce pensou? ");
            char animal[100];
            scanf(" %[^\n]s", animal);
            printf("O que diferencia %s do(a) %s? ", animal, no->pergunta);
            char diferenca[100];
            scanf(" %[^\n]s", diferenca);

            no->sim = criarNo(animal);
            no->nao = criarNo(no->pergunta);
            strcpy(no->pergunta, diferenca);
        }
        fazerPerguntas(no->sim);
    } else {
        if (no->nao == NULL) {
            printf("Qual animal voce pensou? ");
            char animal[100];
            scanf(" %[^\n]s", animal);
            printf("O que diferencia %s do(a) %s? ", animal, no->pergunta);
            char diferenca[100];
            scanf(" %[^\n]s", diferenca);

            no->nao = criarNo(animal);
            no->sim = criarNo(no->pergunta);
            strcpy(no->pergunta, diferenca);
        }
        fazerPerguntas(no->nao);
    }
}

int main() {
    struct No* raiz = criarNo("O animal que voce pensou eh mamifero?");
    fazerPerguntas(raiz);
    return 0;
}

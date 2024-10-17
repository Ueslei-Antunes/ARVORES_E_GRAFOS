#include "ArvoreBinaria.h"

int estritamenteBinariaAux(pNohArvore noh) {
    // Se o nó é NULL, não afeta a estrutura (caso base)
    if (noh == NULL) {
        return 1;
    }

    // Se o nó é uma folha (não tem filhos à esquerda nem à direita)
    if (noh->esquerda == NULL && noh->direita == NULL) {
        return 1;
    }

    // Se o nó tem ambos os filhos
    if (noh->esquerda != NULL && noh->direita != NULL) {
        // Verifica recursivamente se os subárvores também são estritamente binárias
        return estritamenteBinariaAux(noh->esquerda) && estritamenteBinariaAux(noh->direita);
    }

    // Caso contrário, se tiver apenas um filho, não é estritamente binária
    return 0;
}

int estritamenteBinaria(pDArvore arvore) {
    if (arvore == NULL || arvore->raiz == NULL) {
        return 1; // Consideramos uma árvore vazia como estritamente binária
    }
    return estritamenteBinariaAux(arvore->raiz);
}

int main() {
    pDArvore minhaArvore = criarArvore(0);

    // Criando uma árvore estritamente binária
    int valores[] = {10, 5, 15, 3, 7, 12, 18};
    for (int i = 0; i < 7; i++) {
        incluirInfo(minhaArvore, alocaInt(valores[i]), comparaInt);
    }

    // Verificando se a árvore é estritamente binária
    if (estritamenteBinaria(minhaArvore)) {
        printf("A árvore é estritamente binária.\n");
    } else {
        printf("A árvore NÃO é estritamente binária.\n");
    }

    return 0;
}
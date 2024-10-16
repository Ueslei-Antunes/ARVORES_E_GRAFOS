#ifndef EXERCICIO_2_H
#define EXERCICIO_2_H
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


#endif
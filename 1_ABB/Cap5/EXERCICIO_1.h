#ifndef EXERCICIO_1_H
#define EXERCICIO_1_H
#include "ArvoreBinaria.h"
#include "Utils.h"

int iguais(pDArvore arvore1, pDArvore arvore2, FuncaoComparacao fc) {
    // Caso base: se ambas as árvores forem vazias, elas são iguais
    if (arvoreVazia(arvore1) && arvoreVazia(arvore2)) {
        return 1;
    }

    // Caso base: se uma das árvores for vazia e a outra não, elas não são iguais
    if (arvoreVazia(arvore1) || arvoreVazia(arvore2)) {
        return 0;
    }

    // Comparar os nós raiz das duas árvores
    if (fc(arvore1->raiz->info, arvore2->raiz->info) != 0) {
        return 0;
    }

    // Recursivamente comparar as subárvores esquerda e direita
    return iguais(&arvore1->raiz->esquerda, &arvore2->raiz->esquerda, fc) && iguais(&arvore1->raiz->direita, &arvore2->raiz->direita, fc);
}

#endif

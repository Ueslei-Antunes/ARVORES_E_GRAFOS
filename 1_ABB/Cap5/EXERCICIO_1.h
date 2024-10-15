#ifndef EXERCICIO_1_H
#define EXERCICIO_1_H
#include "ArvoreBinaria.h"
#include "Utils.h"

int iguais(pDArvore arvore1, pDArvore arvore2, FuncaoComparacao fc) {
    // Caso ambas as árvores sejam nulas, elas são iguais
    if (arvore1->raiz == NULL && arvore2->raiz == NULL) {
        return 1;
    }
    
    // Se uma das árvores é nula e a outra não, elas são diferentes
    if (arvore1->raiz == NULL || arvore2->raiz == NULL) {
        return 0;
    }
    
    // Comparar as informações dos nós raiz
    if (fc(arvore1->raiz->info, arvore2->raiz->info) != 0) {
        return 0;
    }
    
    // Comparar as subárvores esquerda e direita
    return iguais(arvore1->raiz->esquerda, arvore2->raiz->esquerda, fc) &&
           iguais(arvore1->raiz->direita, arvore2->raiz->direita, fc);
}
#endif

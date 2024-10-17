#include "ArvoreBinaria.h"

int estritamenteBinariaAux(pNohArvore noh) {
    if (noh == NULL) {
        return 1;
    }

    if (noh->esquerda == NULL && noh->direita == NULL) {
        return 1;
    }

    if (noh->esquerda != NULL && noh->direita != NULL) {
        return estritamenteBinariaAux(noh->esquerda) && estritamenteBinariaAux(noh->direita);
    }

    return 0;
}

int estritamenteBinaria(pDArvore arvore) {
    if (arvore == NULL || arvore->raiz == NULL) {
        return 1;
    }
    return estritamenteBinariaAux(arvore->raiz);
}

int main() {
    pDArvore minhaArvore = criarArvore(0);

    int valores[] = {10, 5, 15, 3, 7, 12, 18};
    for (int i = 0; i < 7; i++) {
        incluirInfo(minhaArvore, alocaInt(valores[i]), comparaInt);
    }

    if (estritamenteBinaria(minhaArvore)) {
        printf("A arvore e estritamente binaria.\n");
    } else {
        printf("A arvore NAO e estritamente binaria.\n");
    }
    return 0;
}
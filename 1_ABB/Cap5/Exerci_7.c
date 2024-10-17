#include "ArvoreBinaria.h"

int isBST(pNohArvore no, void *min, void *max, FuncaoComparacao fc) {
    // Caso base: se o nó for NULL, é uma árvore BST válida
    if (no == NULL) {
        return 1;  // Verdadeiro
    }

    // Verifica se o valor do nó atual é maior ou igual ao valor máximo permitido
    if (max != NULL && fc(no->info, max) >= 0) {
        return 0;  // Falso
    }

    // Verifica se o valor do nó atual é menor ou igual ao valor mínimo permitido
    if (min != NULL && fc(no->info, min) <= 0) {
        return 0;  // Falso
    }

    // Recursivamente verifica a subárvore esquerda e direita
    return isBST(no->esquerda, min, no->info, fc) &&  // Verifica subárvore esquerda
           isBST(no->direita, no->info, max, fc);     // Verifica subárvore direita
}

int isBSTWrapper(pDArvore arvore, FuncaoComparacao fc) {
    return isBST(arvore->raiz, NULL, NULL, fc);
}

void* minValue(pNohArvore no) {
    pNohArvore atual = no;
    while (atual->esquerda != NULL) {
        atual = atual->esquerda;
    }
    return atual->info;
}

void* maxValue(pNohArvore no) {
    pNohArvore atual = no;
    while (atual->direita != NULL) {
        atual = atual->direita;
    }
    return atual->info;
}

int main(int argc, char const *argv[])
{
    pDArvore arvore = criarArvore(sizeof(int));

    // Inserindo nós para formar uma BST
    int valores[] = {10, 5, 15, 3, 7, 12, 18};
    for (int i = 0; i < 7; i++) {
        incluirInfo(arvore, &valores[i], comparaInt);
    }

    if (isBSTWrapper(arvore, comparaInt)) {
        printf("A árvore é uma árvore binária de busca.\n");
    } else {
        printf("A árvore NÃO é uma árvore binária de busca.\n");
    }
    return 0;
}

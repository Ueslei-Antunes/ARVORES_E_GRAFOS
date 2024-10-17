#include "ArvoreBinaria.h"

int isBST(pNohArvore no, void *min, void *max, FuncaoComparacao fc) {
    if (no == NULL) {
        return 1;
    }

    if (max != NULL && fc(no->info, max) >= 0) {
        return 0; 
    }

    if (min != NULL && fc(no->info, min) <= 0) {
        return 0; 
    }

    return isBST(no->esquerda, min, no->info, fc) &&  
           isBST(no->direita, no->info, max, fc);     
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

    int valores[] = {10, 5, 15, 3, 7, 12, 18};
    for (int i = 0; i < 7; i++) {
        incluirInfo(arvore, &valores[i], comparaInt);
    }

    if (isBSTWrapper(arvore, comparaInt)) {
        printf("A arvore e uma arvore binaria de busca.\n");
    } else {
        printf("A arvore NAO e uma arvore binaria de busca.\n");
    }
    return 0;
}
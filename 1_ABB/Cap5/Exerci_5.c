#include "ArvoreBinaria.h"

int comprimentoInternoAux(pNohArvore noh, int profundidade) {
    if (noh == NULL) {
        return 0;
    }

    if (noh->esquerda == NULL && noh->direita == NULL) {
        return profundidade;  
    }

    int comprimentoEsquerda = comprimentoInternoAux(noh->esquerda, profundidade + 1);
    int comprimentoDireita = comprimentoInternoAux(noh->direita, profundidade + 1);

    return comprimentoEsquerda + comprimentoDireita;
}

int comprimentoInterno(pDArvore arvore) {
    return comprimentoInternoAux(arvore->raiz, 0);
}

int main(int argc, char const *argv[])
{
    pDArvore arvore = criarArvore(0); 

    int valores[] = {10, 5, 15, 3, 7, 13, 18};
    for (int i = 0; i < 7; i++) {
        incluirInfo(arvore, alocaInt(valores[i]), comparaInt);
    }

    printf("Arvore em ordem: ");
    emOrdem(arvore, imprimeInt);
    printf("\n");

    int comprimento = comprimentoInterno(arvore);
    printf("Comprimento interno da arvore: %d\n", comprimento);
    return 0;
}
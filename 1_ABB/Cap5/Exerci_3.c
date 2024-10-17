#include "ArvoreBinaria.h"

void espelhoAux(pNohArvore noh) {
    if (noh == NULL) {
        return;
    }

    espelhoAux(noh->esquerda);
    espelhoAux(noh->direita);

    pNohArvore temp = noh->esquerda;
    noh->esquerda = noh->direita;
    noh->direita = temp;
}

void espelho(pDArvore arvore) {
    if (arvore == NULL || arvore->raiz == NULL) {
        return;
    }
    espelhoAux(arvore->raiz);
}

int main(int argc, char const *argv[])
{
    pDArvore minhaArvore = criarArvore(0);  

    int valores[] = {50, 30, 70, 20, 40, 60, 80};

    for (int i = 0; i < 7; i++) {
        incluirInfo(minhaArvore, alocaInt(valores[i]), comparaInt);
    }

    printf("Arvore original em ordem:\n");
    emOrdem(minhaArvore, imprimeInt);

    espelho(minhaArvore);

    printf("\nArvore espelhada em ordem:\n");
    emOrdem(minhaArvore, imprimeInt);
    return 0;
}

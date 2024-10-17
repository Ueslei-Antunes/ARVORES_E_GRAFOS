#include "ArvoreBinaria.h"

int alturaBalanceada(pNohArvore noh, char* balanceada) {
    if (noh == NULL) {
        return 0;
    }

    int alturaEsquerda = alturaBalanceada(noh->esquerda, balanceada);
    int alturaDireita  = alturaBalanceada(noh->direita, balanceada);
    
    if (abs(alturaEsquerda - alturaDireita) > 1) {
        *balanceada = 0;
    }

    return 1 + (alturaEsquerda > alturaDireita ? alturaEsquerda : alturaDireita);
}

char balanceada(pDArvore arvore) {
    if (arvore == NULL || arvore->raiz == NULL) {
        return 1;
    }

    char balanceada = 1;
    alturaBalanceada(arvore->raiz, &balanceada);
    return balanceada;
}

int main(int argc, char const *argv[])
{
    pDArvore arvore = criarArvore(sizeof(int));

    int valores[] = {10, 5, 15, 3, 7, 12, 18};
    for (int i = 0; i < 7; i++) {
        incluirInfo(arvore, &valores[i], comparaInt);
    }

    if (balanceada(arvore)) {
        printf("A arvore esta balanceada.\n");
    } else {
        printf("A arvore nao esta balanceada.\n");
    }
  
    //teste
    int valorDesequilibrante = 1;
    incluirInfo(arvore, &valorDesequilibrante, comparaInt);

    if (balanceada(arvore)) {
        printf("A arvore ainda esta balanceada.\n");
    } else {
        printf("A arvore agora esta desequilibrada.\n");
    }
    return 0;
}

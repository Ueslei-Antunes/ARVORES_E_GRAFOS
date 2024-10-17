#include "ArvoreBinaria.h"

int alturaBalanceada(pNohArvore noh, char* balanceada) {
    if (noh == NULL) {
        return 0;  // Altura de árvore vazia é 0
    }

    int alturaEsquerda = alturaBalanceada(noh->esquerda, balanceada);
    int alturaDireita  = alturaBalanceada(noh->direita, balanceada);

    // Se a diferença de altura entre as subárvores for maior que 1, a árvore não é balanceada
    if (abs(alturaEsquerda - alturaDireita) > 1) {
        *balanceada = 0;  // Marca que a árvore não é balanceada
    }

    // Retorna a altura atual da árvore
    return 1 + (alturaEsquerda > alturaDireita ? alturaEsquerda : alturaDireita);
}

char balanceada(pDArvore arvore) {
    if (arvore == NULL || arvore->raiz == NULL) {
        return 1;  // Árvore vazia é considerada balanceada
    }

    char balanceada = 1;  // Inicialmente, assume que a árvore é balanceada
    alturaBalanceada(arvore->raiz, &balanceada);
    return balanceada;
}

int main(int argc, char const *argv[])
{
    // Criar a árvore binária
    pDArvore arvore = criarArvore(sizeof(int));

    // Inserir alguns valores na árvore
    int valores[] = {10, 5, 15, 3, 7, 12, 18}; // Árvore balanceada
    for (int i = 0; i < 7; i++) {
        incluirInfo(arvore, &valores[i], comparaInt);
    }

    // Verificar se a árvore está balanceada
    if (balanceada(arvore)) {
        printf("A árvore está balanceada.\n");
    } else {
        printf("A árvore não está balanceada.\n");
    }

    // Agora, adicionar mais um nó para desequilibrar a árvore
    int valorDesequilibrante = 1;
    incluirInfo(arvore, &valorDesequilibrante, comparaInt);

    // Verificar novamente se a árvore está balanceada
    if (balanceada(arvore)) {
        printf("A árvore ainda está balanceada.\n");
    } else {
        printf("A árvore agora está desequilibrada.\n");
    }
    return 0;
}

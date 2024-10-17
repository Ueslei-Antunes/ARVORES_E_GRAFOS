#include "ArvoreBinaria.h"

int comprimentoInternoAux(pNohArvore noh, int profundidade) {
    // Se o nó for NULL, retorna 0, pois não há mais caminho
    if (noh == NULL) {
        return 0;
    }

    // Se o nó for uma folha (não tem filhos à esquerda e à direita)
    if (noh->esquerda == NULL && noh->direita == NULL) {
        return profundidade;  // Retorna o comprimento do caminho até a folha
    }

    // Caso contrário, calcula recursivamente para os filhos (esquerda e direita)
    int comprimentoEsquerda = comprimentoInternoAux(noh->esquerda, profundidade + 1);
    int comprimentoDireita = comprimentoInternoAux(noh->direita, profundidade + 1);

    // Soma o comprimento dos caminhos à esquerda e à direita
    return comprimentoEsquerda + comprimentoDireita;
}

int comprimentoInterno(pDArvore arvore) {
    // A função principal chama a auxiliar começando da raiz e profundidade 0
    return comprimentoInternoAux(arvore->raiz, 0);
}

int main(int argc, char const *argv[])
{
    // Criar uma árvore binária
    pDArvore arvore = criarArvore(0); // Inicializa a árvore

    // Incluir alguns números na árvore
    int valores[] = {10, 5, 15, 3, 7, 13, 18};
    for (int i = 0; i < 7; i++) {
        // Chamada correta da função incluirInfo
        incluirInfo(arvore, alocaInt(valores[i]), comparaInt);
    }

    // Imprimir a árvore em ordem (opcional, para ver a árvore)
    printf("Arvore em ordem: ");
    emOrdem(arvore, imprimeInt);
    printf("\n");

    // Calcular e imprimir o comprimento interno
    int comprimento = comprimentoInterno(arvore);
    printf("Comprimento interno da árvore: %d\n", comprimento);
    return 0;
}

#ifndef EXERCICIO_1_H
#define EXERCICIO_1_H
#include "ArvoreBinaria.h"

int iguais (pDArvore arvore1, pDArvore arvore2, FuncaoComparacao fc) {
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
    pDArvore subArvoreEsquerda1 = (pDArvore) malloc(sizeof(DArvore));
    pDArvore subArvoreEsquerda2 = (pDArvore) malloc(sizeof(DArvore));
    pDArvore subArvoreDireita1 = (pDArvore) malloc(sizeof(DArvore));
    pDArvore subArvoreDireita2 = (pDArvore) malloc(sizeof(DArvore));
    
    subArvoreEsquerda1->raiz = arvore1->raiz->esquerda;
    subArvoreEsquerda2->raiz = arvore2->raiz->esquerda;
    subArvoreDireita1->raiz = arvore1->raiz->direita;
    subArvoreDireita2->raiz = arvore2->raiz->direita;
    
    int iguaisEsquerda = iguais(subArvoreEsquerda1, subArvoreEsquerda2, fc);
    int iguaisDireita = iguais(subArvoreDireita1, subArvoreDireita2, fc);
    
    free(subArvoreEsquerda1);
    free(subArvoreEsquerda2);
    free(subArvoreDireita1);
    free(subArvoreDireita2);
     
    // As árvores são iguais se ambas as subárvores forem iguais
    return iguaisEsquerda && iguaisDireita;
}

int main(int argc, char const *argv[])
{
    pDArvore arvore1 = criarArvore(0);
    pDArvore arvore2 = criarArvore(0);

    // Incluindo nós nas duas árvores
    int valor1 = 10, valor2 = 5, valor3 = 20;

    incluirInfo(arvore1, alocaInt(valor1), comparaInt);
    incluirInfo(arvore1, alocaInt(valor2), comparaInt);
    incluirInfo(arvore1, alocaInt(valor3), comparaInt);

    incluirInfo(arvore2, alocaInt(valor1), comparaInt);
    incluirInfo(arvore2, alocaInt(valor2), comparaInt);
    incluirInfo(arvore2, alocaInt(valor3), comparaInt);

    // Verificando se as árvores são iguais
    if (iguais(arvore1, arvore2, comparaInt)) {
        printf("As árvores são iguais!\n");
    } else {
        printf("As árvores são diferentes!\n");
    }

    // Alterando uma árvore para fazer o teste com árvores diferentes
    int valorDiferente = 15;
    incluirInfo(arvore2, alocaInt(valorDiferente), comparaInt);

    // Verificando se as árvores são iguais novamente
    if (iguais(arvore1, arvore2, comparaInt)) {
        printf("As árvores são iguais!\n");
    } else {
        printf("As árvores são diferentes!\n");
    }
    return 0;
}



#endif

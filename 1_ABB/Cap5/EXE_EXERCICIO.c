#include <stdio.h>
#include <stdlib.h>
#include "TAD_Arvore.h"
#include "Operacoes/0_struct_Descritor.h"
#include "Operacoes/ArvoreBinaria/0_struct_Arvore.h"
#include "Operacoes/ArvoreBinaria/2_incluirInfo.h"

int iguais(pDArvore arvore1, pDArvore arvore2, FuncaoComparacao fc) {
    // Caso base: se ambas as árvores forem vazias, elas são iguais
    if (arvoreVazia(arvore1) && arvoreVazia(arvore2)) {
        return 1;
    }

    // Caso base: se uma das árvores for vazia e a outra não, elas não são iguais
    if (arvoreVazia(arvore1) || arvoreVazia(arvore2)) {
        return 0;
    }

    // Comparar os nós raiz das duas árvores
    if (fc(arvore1->raiz->info, arvore2->raiz->info) != 0) {
        return 0;
    }

    // Recursivamente comparar as subárvores esquerda e direita
    return iguais(arvore1->raiz->esquerda, arvore2->raiz->esquerda, fc) && iguais(arvore1->raiz->direita, arvore2->raiz->direita, fc);
}

// Função de comparação para inteiros
int compararInteiros(void* a, void* b) {
    int x = *(int*)a;
    int y = *(int*)b;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

int main() {
    // Criar duas árvores
    pDArvore arvore1 = criarArvore(1);
    pDArvore arvore2 = criarArvore(1);

    // Incluir informações nas árvores
    int valor1 = 1, valor2 = 2, valor3 = 3;
    incluirInfo(arvore1, &valor1, compararInteiros);
    incluirInfo(arvore1, &valor2, compararInteiros);
    incluirInfo(arvore1, &valor3, compararInteiros);

    incluirInfo(arvore2, &valor1, compararInteiros);
    incluirInfo(arvore2, &valor2, compararInteiros);
    incluirInfo(arvore2, &valor3, compararInteiros);

    // Testar se as árvores são iguais
    int resultado = iguais(arvore1, arvore2, compararInteiros);
    printf("Árvores são iguais? %d\n", resultado);

    // Modificar uma das árvores para que elas sejam diferentes
    int valorDiferente = 4;
    incluirInfo(arvore2, &valorDiferente, compararInteiros);

    // Testar novamente
    resultado = iguais(arvore1, arvore2, compararInteiros);
    printf("Árvores são iguais? %d\n", resultado);

    return 0;
}
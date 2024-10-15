#include <stdio.h>
#include <stdlib.h>
#include "TAD_Arvore.h"
#include "Utils.h"
#include "Operacoes/0_struct_Descritor.h"
#include "ArvoreBinaria.h"



int iguais(pDArvore arvore1, pDArvore arvore2, FuncaoComparacao fc);
int main() {
    // Criando duas árvores
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
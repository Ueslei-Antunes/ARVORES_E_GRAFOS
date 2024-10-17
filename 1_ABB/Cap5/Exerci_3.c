#include "ArvoreBinaria.h"

void espelhoAux(pNohArvore noh) {
    // Se o nó for NULL, não há nada para espelhar (caso base)
    if (noh == NULL) {
        return;
    }

    // Realiza o espelhamento recursivamente nas subárvores
    espelhoAux(noh->esquerda);
    espelhoAux(noh->direita);

    // Troca os nós esquerdo e direito
    pNohArvore temp = noh->esquerda;
    noh->esquerda = noh->direita;
    noh->direita = temp;
}

void espelho(pDArvore arvore) {
    if (arvore == NULL || arvore->raiz == NULL) {
        return; // Não há nada para espelhar se a árvore for nula ou vazia
    }
    espelhoAux(arvore->raiz);
}

int main(int argc, char const *argv[])
{
    // Criar a árvore
    pDArvore minhaArvore = criarArvore(0);  // Argumento 0 só como placeholder, pode ser alterado dependendo do uso

    // Inserir alguns números na árvore
    int valores[] = {50, 30, 70, 20, 40, 60, 80};  // Valores de exemplo

    for (int i = 0; i < 7; i++) {
        incluirInfo(minhaArvore, alocaInt(valores[i]), comparaInt);  // Funções auxiliares alocaInt e comparaInt
    }

    // Antes do espelhamento, imprimir a árvore
    printf("Árvore original em ordem:\n");
    emOrdem(minhaArvore, imprimeInt);  // Supondo que já tenha a função emOrdem

    // Realizar o espelhamento
    espelho(minhaArvore);

    // Após o espelhamento, imprimir a árvore
    printf("\nÁrvore espelhada em ordem:\n");
    emOrdem(minhaArvore, imprimeInt);
    return 0;
}

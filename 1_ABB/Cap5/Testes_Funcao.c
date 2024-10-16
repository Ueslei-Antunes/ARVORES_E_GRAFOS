#include <stdio.h>
#include <stdlib.h>
#include "TAD_Arvore.h"
#include "Utils.h"
#include "ArvoreBinaria.h"
#include "Operacoes/0_struct_Descritor.h"
#include "Operacoes/1_criarArvore.h"


int iguais(pDArvore arvore1, pDArvore arvore2, FuncaoComparacao fc);

//####### EXERCICIO 3 ###############
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

//######## EXERCICIO 4 ###############
void amplitude(pDArvore arvore, FuncaoImpressao fi) {
    if (arvoreVazia(arvore)) {
        return; // Se a árvore estiver vazia, não faz nada
    }

    pDLista fila = criarLista(); // Cria a lista para armazenar os nós
    incluirInfo(fila, arvore->raiz); // Adiciona a raiz à lista

    while (fila->quantidade > 0) { // Enquanto houver nós na lista
        pNoh nohAtual = (pNoh) fila->primeiro->info; // Pega o primeiro nó
        fi(nohAtual->info); // Aplica a função de impressão ao nó

        // Enfileirar os filhos
        if (nohAtual->esquerda != NULL) {
            incluirInfo(fila, nohAtual->esquerda); // Adiciona o filho esquerdo
        }
        if (nohAtual->direita != NULL) {
            incluirInfo(fila, nohAtual->direita); // Adiciona o filho direito
        }

        // Remove o nó atual da lista
        excluirInfo(fila, nohAtual, comparaInt);
    }

    destruirLista(fila); // Libera a lista após o uso
}

//######## EXERCICIO 5 ###############
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


int main() {
    /* ####### MAIN - EXERCICIO 1 ###############
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
    */

    /*####### MAIN - EXERCICIO 3 ###############
    
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
    */

   /* ####### MAIN - EXERCICIO 4 ###############
   
   // Cria uma árvore binária
    pDArvore arvore = criarArvore(1);

    // Insere nós na árvore
    int valor1 = 10, valor2 = 20, valor3 = 30, valor4 = 40, valor5 = 50;
    incluirInfo(arvore, alocaInt(valor1), comparaInt);
    incluirInfo(arvore, alocaInt(valor2), comparaInt);
    incluirInfo(arvore, alocaInt(valor3), comparaInt);
    incluirInfo(arvore, alocaInt(valor4), comparaInt);
    incluirInfo(arvore, alocaInt(valor5), comparaInt);

    // Chama a função de caminhamento em amplitude
    printf("Caminhamento em Amplitude da Árvore:\n");
    amplitude(arvore, imprimeInt);

    // Libera a memória da árvore (implementar se necessário)
   
   */

    /*####### MAIN - EXERCICIO 5 ###############
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

*/
    return 0;
}
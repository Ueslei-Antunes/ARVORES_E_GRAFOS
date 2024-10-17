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

//####### EXERCICIO 4 ###############
/*void amplitude(pDArvore arv, FuncaoImpressao fi) {
    if (!arv || !arv->raiz) return; // Verifica se a árvore está vazia

    pDLista lista = criarLista(); // Cria a lista para auxiliar no caminhamento
    incluirInfo(lista, arv->raiz); // Adiciona a raiz à lista

    while (lista->quantidade > 0) {
        // Retira o primeiro nó da lista
        pNohArvore nohAtual = (pNohArvore) buscarInfoPos(lista, 0);
        excluirInfo(lista, nohAtual, NULL);

        // Imprime a informação do nó atual
        fi(nohAtual->info);

        // Adiciona os filhos do nó atual à lista
        if (nohAtual->esquerda) {
            incluirInfo(lista, nohAtual->esquerda);
        }
        if (nohAtual->direita) {
            incluirInfo(lista, nohAtual->direita);
        }
    }

    destruirLista(lista); // Limpa a lista auxiliar
}
*/

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


//####### EXERCICIO 6 #############
// Função auxiliar que retorna a altura da árvore e verifica se está balanceada
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


//####### EXERCICIO 7 #############
int isBST(pNohArvore no, void *min, void *max, FuncaoComparacao fc) {
    // Caso base: se o nó for NULL, é uma árvore BST válida
    if (no == NULL) {
        return 1;  // Verdadeiro
    }

    // Verifica se o valor do nó atual é maior ou igual ao valor máximo permitido
    if (max != NULL && fc(no->info, max) >= 0) {
        return 0;  // Falso
    }

    // Verifica se o valor do nó atual é menor ou igual ao valor mínimo permitido
    if (min != NULL && fc(no->info, min) <= 0) {
        return 0;  // Falso
    }

    // Recursivamente verifica a subárvore esquerda e direita
    return isBST(no->esquerda, min, no->info, fc) &&  // Verifica subárvore esquerda
           isBST(no->direita, no->info, max, fc);     // Verifica subárvore direita
}

int isBSTWrapper(pDArvore arvore, FuncaoComparacao fc) {
    return isBST(arvore->raiz, NULL, NULL, fc);
}

void* minValue(pNohArvore no) {
    pNohArvore atual = no;
    while (atual->esquerda != NULL) {
        atual = atual->esquerda;
    }
    return atual->info;
}

void* maxValue(pNohArvore no) {
    pNohArvore atual = no;
    while (atual->direita != NULL) {
        atual = atual->direita;
    }
    return atual->info;
}


int main() {
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
    
    /*####### MAIN - EXERCICIO 6 ###############
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
    */
    
    /* ####### MAIN - EXERCICIO 7 ###############
    pDArvore arvore = criarArvore(sizeof(int));

    // Inserindo nós para formar uma BST
    int valores[] = {10, 5, 15, 3, 7, 12, 18};
    for (int i = 0; i < 7; i++) {
        incluirInfo(arvore, &valores[i], comparaInt);
    }

    if (isBSTWrapper(arvore, comparaInt)) {
        printf("A árvore é uma árvore binária de busca.\n");
    } else {
        printf("A árvore NÃO é uma árvore binária de busca.\n");
    }
    */

    pDArvore minhaArvore = criarArvore(0);

    // Inserindo valores na árvore
    int valores[] = {10, 5, 15, 3, 7, 12, 18};
    for (int i = 0; i < 7; i++) {
        incluirInfo(minhaArvore, alocaInt(valores[i]), comparaInt);
    }

    // Imprimindo a árvore em amplitude
    printf("Caminhamento em amplitude: ");
    amplitude(minhaArvore, imprimeInt);

    return 0;
}
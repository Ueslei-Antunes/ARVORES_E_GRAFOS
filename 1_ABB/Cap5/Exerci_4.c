#include "ArvoreBinaria.h"
#include "Cap3/Lista.h"

void amplitude(pDArvore arv, FuncaoImpressao fi) {
    if (!arv || !arv->raiz) return; 

    pDLista lista = criarLista(); 
    incluirInfo(lista, arv->raiz); 

    while (lista->quantidade > 0) {
        pNohArvore nohAtual = (pNohArvore) buscarInfoPos(lista, 0);
        excluirInfo(lista, nohAtual, NULL);

        fi(nohAtual->info);

        // Adiciona os filhos do nó atual à lista
        if (nohAtual->esquerda) {
            incluirInfo(lista, nohAtual->esquerda);
        }
        if (nohAtual->direita) {
            incluirInfo(lista, nohAtual->direita);
        }
    }
    destruirLista(lista);
}

int main(int argc, char const *argv[])
{
    pDArvore minhaArvore = criarArvore(0);

    int valores[] = {10, 5, 15, 3, 7, 12, 18};
    for (int i = 0; i < 7; i++) {
        incluirInfo(minhaArvore, alocaInt(valores[i]), comparaInt);
    }

    printf("Caminhamento em amplitude: ");
    amplitude(minhaArvore, imprimeInt);
    return 0;
}
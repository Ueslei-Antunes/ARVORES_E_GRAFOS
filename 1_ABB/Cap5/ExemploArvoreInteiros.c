#include <stdio.h>
#include "Utils.h"
#include "ArvoreBinaria.h"

int main(){
    pDArvore pArvoreInt = criarArvore(2);

    /* teste de inclusao */
    incluirInfo(pArvoreInt, alocaInt(5), comparaInt);
    incluirInfo(pArvoreInt, alocaInt(8), comparaInt);
    incluirInfo(pArvoreInt, alocaInt(6), comparaInt);
    incluirInfo(pArvoreInt, alocaInt(3), comparaInt);
    incluirInfo(pArvoreInt, alocaInt(7), comparaInt);

    desenhaArvore(pArvoreInt, imprimeInt);

    printf("\nAltura: %d \n",    altura(pArvoreInt));
    printf("Qtde Folhas: %d \n", quantidadeFolhas(pArvoreInt));
    printf("Qtde Nohs: %d \n",   quantidadeNohs(pArvoreInt));

}

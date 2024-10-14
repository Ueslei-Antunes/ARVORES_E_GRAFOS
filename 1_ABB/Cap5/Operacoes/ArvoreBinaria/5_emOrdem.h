#ifndef EMORDEM_ARVORE_BINARIA_H
#define EMORDEM_ARVORE_BINARIA_H

/* --------------------------*/
void emOrdemRecursiva(pNohArvore raiz, FuncaoImpressao fi){

   if (raiz != NULL){

       emOrdem(raiz->esquerda, fi);
       fi(raiz->info);
       emOrdem(raiz->direita, fi);
   }
}

/* --------------------------*/
void emOrdem(pDArvore arvore, FuncaoImpressao fi){

    // chama a fun��o recursiva
    emOrdemRecursiva(arvore->raiz, fi);

}

#endif

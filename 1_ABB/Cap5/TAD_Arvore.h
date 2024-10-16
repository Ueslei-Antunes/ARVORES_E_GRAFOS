#ifndef ARVORE_TAD_H
#define ARVORE_TAD_H
/*------------------------------------------*/
/* tipos de dados                           */
/*------------------------------------------*/
/* estrutura do noh da arvore */
typedef struct nohArvore  NohArvore;
typedef NohArvore*        pNohArvore;

/* descritor da arvore */
typedef struct dArvore  DArvore;
typedef DArvore*        pDArvore;

/* tipos referentes aos ponteiros para funcao */
typedef int  (*FuncaoComparacao)(void*, void*);
typedef void (*FuncaoImpressao) (void*);

/*------------------------------------------*/
/* operacoes                                */
/*------------------------------------------*/
pDArvore  criarArvore(int);

void       incluirInfo    (pDArvore, void *, FuncaoComparacao);
int        excluirInfo    (pDArvore, void *, FuncaoComparacao);
pNohArvore buscarInfo     (pDArvore, void *, FuncaoComparacao);


/* percursos */
void      emOrdem  (pDArvore, FuncaoImpressao);
void      preOrdem (pDArvore, FuncaoImpressao);
void      posOrdem (pDArvore, FuncaoImpressao);

int       altura          (pDArvore);
int       grau            (pDArvore);
int       nivel           (pDArvore, void *, FuncaoComparacao);
int       quantidadeFolhas(pDArvore);
int       quantidadeNohs  (pDArvore);
int       ehFolha         (pDArvore, void *, FuncaoComparacao);
int       arvoreVazia     (pDArvore);

void desenhaArvore(pDArvore, FuncaoImpressao);

#endif


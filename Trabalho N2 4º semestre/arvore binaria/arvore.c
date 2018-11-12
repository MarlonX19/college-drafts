#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

/* ------------------------------------------------ */
void inicializar (NO **tree) {

    *tree = NULL;

} /* fim de inicializar */


/* ------------------------------------------------ */
int estaVazia (NO *tree) {
    
    if (tree == NULL)
        return 1;

    return 0;

} /* fim de estaVazia */


/* ------------------------------------------------ */
NO* pesquisar (NO* tree, int valor) {

    NO *aux = tree;

    while (aux != NULL) {
        
        if (valor == aux->dado)
            break;
        
        else if (valor < aux->dado)
            aux = aux->esq;
        
        else
            aux = aux->dir;

    } /* fim do while */

    return aux;

} /* fim de pesquisar */


/* ------------------------------------------------ */
int noExiste (NO* tree, int valor) {

	if(pesquisar (tree, valor) == NULL) {
		printf("Noh nao existente na arvore!");
		return 0;
	}	    
	
	return 1;

} /* fim de verificar existencia no */


/* ------------------------------------------------ */
void preOrdem (NO *tree) {

    if (!estaVazia(tree)) {
        printf("%d ", tree->dado);
        preOrdem(tree->esq);
        preOrdem(tree->dir);
    }

} /* fim de preOrdem */


/* ------------------------------------------------ */
void posOrdem (NO *tree) {

    if (!estaVazia(tree)) {
        posOrdem(tree->esq);
        posOrdem(tree->dir);
        printf("%d ", tree->dado);
    }

} /* fim de posOrdem */


/* ------------------------------------------------ */
void emOrdem (NO *tree) {

    if (!estaVazia(tree)) {
        emOrdem(tree->esq);
        printf("%d ", tree->dado);
        emOrdem(tree->dir);
    }

} /* fim de emOrdem */


/* ------------------------------------------------ */
void inserir (NO **tree, int valor) {
    
    NO* aux;
    NO* papai;

    /* alocar novo noh na memoria */
    NO *novo = (NO*) malloc(sizeof(NO));
    novo->dado = valor;
    novo->esq = NULL;
    novo->dir = NULL;
    novo->pai = NULL;
    
    /* se a arvore estiver vazia */
    if (estaVazia(*tree)) {
        *tree = novo;
        return;
    }
    
    /* caso contrario */
    aux = *tree;
    while (aux != NULL) {

        papai = aux;

        if (valor < aux->dado)
            aux = aux->esq;

        else if (valor > aux->dado)
            aux = aux->dir;

        else {
            printf("Nao eh possivel inserir o noh\n");
            return;
        }
    
    } /* fim do while (aux != NULL) */
    
    if (valor < papai->dado)
        papai->esq = novo;
    else
        papai->dir = novo;

    novo->pai = papai;

} /* fim de inserir */


/* -------------------------------------------------------------------- */
NO* achaMaior (NO* arvore) {

    NO* atual = arvore;

    if (!estaVazia(arvore))
        while (atual->dir != NULL)
            atual = atual->dir;

    return atual;

} /* fim de achaMaior */


/* -------------------------------------------------------------------- */
int remover (NO **arvore, int dado) {

    NO* atual;
    NO* maior;
    int valor;

    if (estaVazia(*arvore))
        return 1;

    atual = pesquisar(*arvore, dado);

    /* noh nao encontrado! */
    if (atual == NULL)
        return 0;

    /* ================================================================ */
    /* CASO 1: NOH A SER REMOVIDO EH NOH FOLHA                          */
    /* ================================================================ */
    if ((atual->esq == NULL) && (atual->dir == NULL)) {

        /* noh a ser removido eh noh raiz */
        if (atual->pai == NULL) {
            inicializar(arvore);
            free(atual);
            return 1;
        }
       
        /* noh a ser removido nao eh o noh raiz */
        if (dado < atual->pai->dado)
            atual->pai->esq = NULL;
        else
            atual->pai->dir = NULL;

        free(atual);
        return 1;

    } /* fim do CASO 1 */


    /* ================================================================ */
    /* CASO 2: NOH A SER REMOVIDO TEM APENAS UM FILHO                   */
    /* ================================================================ */
    if (((atual->esq != NULL) && (atual->dir == NULL)) ||
        ((atual->esq == NULL) && (atual->dir != NULL))) {

        /* caso o noh 'atual' for o noh raiz */
        if (atual->pai == NULL) {

            /* se filho do noh atual for o filho da esquerda */
            if (atual->esq != NULL)
                *arvore = atual->esq;

            /* se filho do noh atual for o filho da direita */
            else
                *arvore = atual->dir;
        }

        /* caso o noh 'atual' nao for o noh raiz */
        else {

            /* caso do noh 'atual' ser o filho da esquerda */
            if (atual == atual->pai->esq) {
                
                /* caso do filho do noh 'atual' ser o filho da esquerda */
                if (atual->esq != NULL) {
                    atual->pai->esq = atual->esq;
                    atual->esq->pai = atual->pai;
                }

                /* caso do filho do noh 'atual' ser o filho da direita */
                else {
                    atual->pai->esq = atual->dir;
                    atual->dir->pai = atual->pai;
                }

            } /* fim do if (atual == filho da esquerda) */


            /* caso noh 'atual ser o filho da direita */
            else if (atual == atual->pai->dir) {

                /* caso do filho do noh 'atual' ser o filho da esquerda */
                if (atual->esq != NULL) {
                    atual->pai->dir = atual->esq;
                    atual->esq->pai = atual->pai;
                }

                /* caso do filho do noh 'atual' ser o filho da direita */
                else {
                    atual->pai->dir = atual->dir;
                    atual->dir->pai = atual->pai;
                }

            } /* fim do else (atual == filho da direita) */

        } /* fim do else (atual != raiz) */

        free(atual);
        return 1;

    } /* fim do CASO 2 */

    /* ================================================================ */
    /* CASO 3: NOH A SER REMOVIDO TEM AMBOS OS FILHOS                   */
    /* ================================================================ */
    if ((atual->esq != NULL) && (atual->dir != NULL)) {

        /* acha o noh de maior valor da sub-arvore da esquerda */
        maior = achaMaior(atual->esq);
        
        /* guarda valor do noh encontrado */
        valor = maior->dado;

        /* remove o noh econtrado */
        remover(arvore, maior->dado);

        /* substitui 'atual' pelo noh encontrado */
        atual->dado = valor;

    } /* fim do CASO 3 */

    return 1;

} /* fim de remover */


/* ************************************************ */
int acharNoRaiz(NO *arvore) {
	return arvore->dado;
} /* Fim acharNoRaiz */


/* ************************************************ */
int contarNosFolhas(NO *arvore){
   
   if(arvore == NULL)
        return 0;
   
   if(arvore->esq == NULL && arvore->dir == NULL)
        return 1;
   
   return contarNosFolhas(arvore->esq) + contarNosFolhas(arvore->dir);
} /* Contar NO ramo */


/* ----------------------------------------------- */
int mostrarNosFolhas(NO *arvore) {
	
	if(arvore == NULL)
        return 0;
   	
	if(arvore->esq == NULL && arvore->dir == NULL) {
   		printf("%d  ", arvore->dado);
        return 1;
	}

    return mostrarNosFolhas(arvore->esq) + mostrarNosFolhas(arvore->dir);
} // Fim mostrarNosFolhas


/* ----------------------------------------------- */
int mostrarNosRamos(NO *arvore) {
	
	if(arvore == NULL)
        return 0;
   	
	if(arvore->esq == NULL && arvore->dir == NULL) {
        return 1;
	} else {
		printf("%d  ", arvore->dado);
	}

    return mostrarNosRamos(arvore->esq) + mostrarNosRamos(arvore->dir);
} // fim mostrarNosRamos


/* ----------------------------------------------- */
int maior(int a, int b) {
    if(a > b)
        return a;
    else
        return b;
} // fim maior


/* ----------------------------------------------- */
int alturaDaArvore(NO *arvore) {
   if((arvore == NULL) || (arvore->esq == NULL && arvore->dir == NULL))
       return 0;
   else
       return 1 + maior(alturaDaArvore(arvore->esq), alturaDaArvore(arvore->dir));
} /* Fim altura da arvore */


/* ------------------------------------------------ */
int grauArvore(NO *tree) {	

	int grau = 0, novoGrau = 0;

    if (!estaVazia(tree)) {
    	if(tree->esq != NULL)
	        grau = grauArvore(tree->esq);
        
		if(tree->esq != NULL) novoGrau++;
        if(tree->dir != NULL) novoGrau++;
        
        if(tree->dir != NULL)
			grau = grauArvore(tree->dir);
		
		if(novoGrau > grau)
			return novoGrau;
		else 
			return grau;
    }

} /* fim de grau da arvore */


/* ------------------------------------------------ */
int profundidadeDoNo(NO* tree, int valor) {

    NO *aux = tree;
    int count = 0;

    while (aux != NULL) {
        
        if (valor == aux->dado) {
            break;
    	} else if (valor < aux->dado) {
            aux = aux->esq;
            count++;
    	} else {
            aux = aux->dir;
            count++;
		}
		
    } /* fim do while */

    return count;

} /* fim de profundidadeDaNO */


/* ----------------------------------------------- */
int alturaDoNo(NO *arvore) {
   if((arvore == NULL) || (arvore->esq == NULL && arvore->dir == NULL))
       return 0;
   else
       return 1 + maior(alturaDoNo(arvore->esq), alturaDoNo(arvore->dir));
} /* Fim alturaDoNo */

/* ------------------------------------------------ */
int nivelDoNo(NO* tree, int valor) {
	
	return profundidadeDoNo(tree, valor) + 1;

} /* fim de profundidadeDaNO */


/* ------------------------------------------------ */
void ancestraisDoNo(NO* tree, int valor) {

    NO *aux = tree;

    while (aux != NULL) {
        
        if (valor == aux->dado) {
            break;
    	} else if (valor < aux->dado) {
        	printf("%d  ", aux->dado);
		    aux = aux->esq;
    	} else {
    		printf("%d  ", aux->dado);
            aux = aux->dir;
		}
		
    } /* fim do while */

} /* fim de ancestraisDoNo */

/* ------------------------------------------------ */
void descendentesDoNo(NO *tree, int raiz) {

    if (!estaVazia(tree)) {
        descendentesDoNo(tree->esq, raiz);
        
			printf("%d ", tree->dado);
        
		descendentesDoNo(tree->dir, raiz);
    }

} /* fim de descendentesDoNo */

void representacaoBarra(NO *x, int b) {

    if (x == NULL) {
        return;
    }

    representacaoBarra(x->dir, b+1);    
    printnode(x->dado, b);
    representacaoBarra(x->esq, b+1);    
}

void printnode(int c, int b) {
    int i;
    for (i = 0; i < b; i++) printf("---");
    
    printf("%d\n", c);
}

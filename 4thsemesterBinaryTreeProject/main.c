#include <stdio.h>
#include <stdlib.h>
#include "arvore.c"


int main() {
	
	NO* arvore;
	NO* aux;
	
    inicializar(&arvore);

    /* -------------------------------------------- */
    /* TESTE DE INSERCAO                            */
    /* -------------------------------------------- */

    inserir(&arvore, 50);
    inserir(&arvore, 40);
    inserir(&arvore, 30);
    inserir(&arvore, 60);
    inserir(&arvore, 45);
    inserir(&arvore, 14);
    inserir(&arvore, 65);
    inserir(&arvore, 78);
    inserir(&arvore, 55);
    inserir(&arvore, 52);
	inserir(&arvore, 10);
    /* -------------------------------------------- */
    /* TESTE DE IMPRESSAO ORDENADA                  */
    /* -------------------------------------------- */

    printf("PRE: ");
    preOrdem(arvore);
    printf("\n");

    printf("POS: ");
    posOrdem(arvore);
    printf("\n");
    
    printf(" EM: ");
    emOrdem(arvore);
    printf("\n");
	
	// Mostrar raiz
	printf("\nNo raiz: %d", acharNoRaiz(arvore)); 
	
	// Mostrar nos folhas
	printf("\nNos folhas da arvore: ");
	mostrarNosFolhas(arvore);
	
	// Mostrar nos ramos
	printf("\nNos ramos da arvore: ");
	mostrarNosRamos(arvore);
	
	int prof = alturaDaArvore(arvore);
	
	// Mostrar altura da arvore
	printf("\nAltura da arvore: %d", prof);
	
	// Mostrar profundidade da arvore
	printf("\nProfundidade da arvore: %d", prof);
	
	// Grau da arvore 
	printf("\nGrau da arvore: %d", grauArvore(arvore));
	
	// Mostrar ancestrais de um no
	printf("\nAncestrais do no %d:  ", 14);
	ancestraisDoNo(arvore, 14);
	
	// Mostrar descendentes de um no
	printf("\nDescendentes do no %d:  ", 40);
	descendentesDoNo(pesquisar(arvore, 40), 40);
		
	// Mostrar profundidade de um no
	printf("\nProfundidade do no %d = %d", 40, profundidadeDoNo(arvore, 40));
	
	// Mostrar altura do no
	printf("\nAltura do no %d: %d", 40, alturaDoNo(pesquisar(arvore, 40)));
	
	// Nivel do no
	printf("\nNivel do no %d: %d", 10, nivelDoNo(arvore, 10));
	
	printf("\n\n\n");
	
	representacaoBarra(arvore, 2);
	
	printf("\n");

    return 0;

} /* fim do main */

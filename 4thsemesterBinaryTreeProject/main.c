#include <stdio.h>
#include <stdlib.h>
#include "arvore.c"


int main() {
	
	int op =0;
	int prof =0;
	
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
    
    
       while(op > -1 && op < 18) {
           printf("\n\nSelecione a opcao que deseja!\n");

            printf("<1> Mostrar no raiz\n");
            printf("<2> Mostrar nos ramos\n");
            printf("<3> Mostrar nos folhas\n");
            printf("<4> Mostrar grau da arvore\n");
            printf("<5> Mostrar altura da arvore\n");
            printf("<6> Mostrar profundidade da arvore\n");
            printf("<7> Mostrar ancestrais de um no\n");
            printf("<8> Mostrar descendentes de um no\n");
            printf("<9> Mostrar grau de um no\n");
            printf("<10> Mostrar altura de um no\n");
            printf("<11> Mostrar profundidade de um no\n");
            printf("<12> Mostrar nivel de um no\n");
            printf("<13> Mostrar pre ordem\n");
            printf("<14> Mostrar em ordem\n");
            printf("<15> Mostrar pos ordem\n");
            printf("<16> Mostrar representacao da arvore\n");
            printf("<17> Sair\n");
              scanf("%d", &op);

    switch(op) {
            case 1:
                // Mostrar raiz
				printf("\nNo raiz: %d", acharNoRaiz(arvore)); 
                break;
            case 2:
               // Mostrar nos ramos
			   printf("\nNos ramos da arvore: ");
			   mostrarNosRamos(arvore);
               break;

            case 3:
              	// Mostrar nos folhas
				printf("\nNos folhas da arvore: ");
				mostrarNosFolhas(arvore);
                break;

            case 4:
               // Grau da arvore 
			   printf("\nGrau da arvore: %d", grauArvore(arvore));
               break;

           case 5:
               // Mostrar altura da arvore
                prof = alturaDaArvore(arvore);
			   printf("\nAltura da arvore: %d", prof);
               break;

            case 6:
               	// Mostrar profundidade da arvore
               
				printf("\nProfundidade da arvore: %d", prof);
                break;
               
            case 7:
                // Mostrar ancestrais de um no
				printf("\nAncestrais do no %d:  ", 14);
				ancestraisDoNo(arvore, 14);
            	break;
            
            case 8:
                // Mostrar descendentes de um no
				printf("\nDescendentes do no %d:  ", 40);
				descendentesDoNo(pesquisar(arvore, 40), 40);
            	break;
            	
            case 9:
                // Mostrar descendentes de um no
				printf("\nDescendentes do no %d:  ", 40);
				descendentesDoNo(pesquisar(arvore, 40), 40);
            	break;
            
            case 10:
               	// Mostrar altura do no
				printf("\nAltura do no %d: %d", 40, alturaDoNo(pesquisar(arvore, 40)));
            	break;
            
             case 11:
                // Mostrar profundidade de um no
				printf("\nProfundidade do no %d = %d", 40, profundidadeDoNo(arvore, 40));
            	break;
            	
            case 12:
                // Nivel do no
				printf("\nNivel do no %d: %d", 10, nivelDoNo(arvore, 10));
            	break;
            	
            case 13:
                printf("PRE: ");
			    preOrdem(arvore);
			    printf("\n");
            	break;
            	
            case 14:
                 printf(" EM: ");
			     emOrdem(arvore);
			     printf("\n");
            	 break;
            	 
           case 15:
                 printf("POS: ");
				 posOrdem(arvore);
				 printf("\n");
            	 break;
            	 
            	 
           case 16:
                 printf("\n\n\n");
				 representacaoBarra(arvore, 2);
				
				 printf("\n");
            	 break;
            

            default:
              printf("Opcao invalida!\n");
        }
    }


    return 0;

} /* fim do main */

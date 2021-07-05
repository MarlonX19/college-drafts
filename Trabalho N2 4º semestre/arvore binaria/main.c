#include <stdio.h>
#include <stdlib.h>
#include "arvore.c"

/*
*  @bitbucket 
*
* Matheus Pegoraro @ https://bitbucket.org/MatheusPegoraro/
* Marlon Englemam @ https://bitbucket.org/Marlonx19/
* 
*/

int main() {
	
	int op = 0;
	int prof = 0;
	int no_temp = 0;
	
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

			printf("<0> Insira um no na arvore\n");
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
    	
    		case 0:
    			// Insere no que o usuario desejar
    			printf("Digite um numero inteiro para o no que deseja inserir: ");
    			scanf("%d", &no_temp);
    			inserir(&arvore, no_temp);
    			break;
    			
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
            	printf("Digite o no para mostrar os ancestrais do mesmo: ");
            	scanf("%d", &no_temp);
            	if(!noExiste(arvore, no_temp)) {
            		break;
				}
                // Mostrar ancestrais de um no
				printf("\nAncestrais do no %d:  ", no_temp);
				ancestraisDoNo(arvore, no_temp);
            	break;
            
            case 8:
            	printf("Digite o no para mostrar os descendentes do mesmo: ");
            	scanf("%d", &no_temp);
            	if(!noExiste(arvore, no_temp)) {
            		break;
				}
                // Mostrar descendentes de um no
				printf("\nDescendentes do no %d:  ", no_temp);
				descendentesDoNo(pesquisar(arvore, no_temp), no_temp);
            	break;
            	
            case 9:
            	printf("Digite o no para mostrar o seu respectivo grau: ");
            	scanf("%d", &no_temp);
            	if(!noExiste(arvore, no_temp)) {
            		break;
				}
                // Mostrar descendentes de um no
				printf("\nGrau do no: %d", grauArvore(pesquisar(arvore, no_temp)));
                break;
            
            case 10:
            	printf("Digite o no para mostrar sua respectiva altura: ");
            	scanf("%d", &no_temp);
            	if(!noExiste(arvore, no_temp)) {
            		break;
				}
               	// Mostrar altura do no
				printf("\nAltura do no %d: %d", no_temp, alturaDoNo(pesquisar(arvore, no_temp)));
            	break;
            
             case 11:
             	printf("Digite o no para mostrar sua respectiva profundidade: ");
            	scanf("%d", &no_temp);
            	if(!noExiste(arvore, no_temp)) {
            		break;
				}
                // Mostrar profundidade de um no
				printf("\nProfundidade do no %d = %d", no_temp, profundidadeDoNo(arvore, no_temp));
            	break;
            	
            case 12:
            	printf("Digite o no para mostrar sua respectiva profundidade: ");
            	scanf("%d", &no_temp);
            	if(!noExiste(arvore, no_temp)) {
            		break;
				}
                // Nivel do no
				printf("\nNivel do no %d: %d", no_temp, nivelDoNo(arvore, no_temp));
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
            	 
            case 17:
                printf("Voce esta saindo, tecle qualquer tecla para sair agora!!!\n\n");
                //getchar();  Use this for Linux, instead of the 
                system("pause");
                op = -1;
                break;
            

            default:
              printf("Opcao invalida!\n");
        }
        printf("\n\n");
        system("pause");
        system("cls");
        
    }


    return 0;

} /* fim do main */

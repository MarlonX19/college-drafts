#include "Funcoes_grafo.c"
#include "lista.c"
#include <stdio.h>

int main (){
	
	int op =0;
	int temp =0;
	

/* Este grafo nao eh: simples, completo,
direcionado, valorado, regular, conexo */

	int g[N][N] = {{0,1,1,0,0,0,0},
				   {1,0,1,1,0,1,0},
				   {1,1,0,1,1,0,0},
				   {0,1,1,0,1,1,0},
				   {0,0,1,1,0,0,0},
				   {0,1,0,1,0,0,0},
                   {0,0,0,0,0,0,0}};


    while(op > -1) {
    	
    	printf("*********Digite a opcao desejada***********\n");
	    printf("<1> Imprimir grafo\n");
	    printf("<2> Buscar em largura\n");
	    printf("<3> Busca em profundidade\n");
	    printf("<4> Contar numero de arestas\n");
	    printf("<5> Sair\n\n");
	    scanf("%d", &op);
    	
    	
    	switch(op) {
    		case 1:
    			imprimeGrafo(g);
    			break;
    		case 2:
    			buscaEmLargura(g, 0);
    			break;
    		case 3: 
    		    buscaEmProfundidade(g, 0);
    		    break;
    		case 4:
    			contaAresta(g);
    			break;
    			
    		case 5:
    			printf("Voce está saindo, tecle qualquer tecla pra confirmar!");
    			system("pause");
    			op = -1;
    			
    		default:
    			printf("Opcao invalida!");
    			op = -1;
    		
		}
		 //Limpa a tela a cada lacada do while, a fim de manter o menu principal sempre em evidencia
		 //Usando funcoes de pause e cls do sistema operacional, caso seja rodado em Linux, necessario fazer alteracoes
    	 printf("\n");
		 system("pause");  
		 system("cls");   
    	
   } 

	return 0;
} /* FIM DO MAIN */

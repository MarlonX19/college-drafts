#include <stdio.h>
#include "grafo.h"
#include "lista.h"

void buscaEmLargura (int g[N][N], int x){


NoLista *fila;
int v, w, i;
int visitados[N];

	/* FAZ STATUS DE TODOS OS VERTICES = 'NAO VISITADOS' */
	for(i=0; i<N; i++)
        visitados[i] = 0;

	/* FAZ STATUS DO VERTICE INICIAL = 'VISITADO' */
	visitados[x] = 1;
	printf("BUSCA EM LARGURA: %d ", x);

	/* INCLUI O VERTICE X NA FILA */
	inicializaLista(&fila);
    insereFinal(&fila, x);



    while(!estaVazia(fila)){

        /* REMOVE O VERTICE DA FILA */
        v = removeInicio(&fila);

        /* PARA TODO ADJACENTE NOA VISITADO DE V... */
        for(w=0; w<N; w++){
            if((g[v][w]==1) && (visitados[w]==0)){
                /* FAZ STATUS DE W = VISITADO */
            visitados[w]=1;
            printf("%d ", w);
            /* ADICIONA W NA FILA*/
            insereFinal(&fila, w);
            }
          }
		}/* FIM DO WHILE */

        printf("\n");

	}


 // FIM DA FUNCAO 'BUSCAEMLARGURA'

void buscaEmProfundidade (int g[N][N], int x){

int i;
int visitados[N];

	/* FAZ STATUS DE TODOS OS VERTICES = 'NAO VISITADOS' */
	for(i=0; i<N; i++)
        visitados[i] = 0;

	/* FAZ STATUS DO VERTICE INICIAL = 'VISITADO' */
	printf("BUSCA EM PROFUNDIDADE:");

	buscaP(g, x, visitados);



} /* FIM DA FUN��O 'BUSCAEMPROFUNIDADE */

void buscaP (int g[N][N], int v, int visitados[N]){

	int w;
	/* FAZ STATUS DE V = 'VISITADO' */
	visitados[v] = 1;
	printf("%d ", v);

	/* PARA CADA W NAO VISITADO ADJACENTE A V... */
	for (w = 0; w < N; w++)
		if ((g[v][w] == 1) && (visitados[w] == 0))
			/* FAZ NOVA CHAMADA RECURSIVA */
			buscaP(g, w, visitados);


} /* FIM DA FUN��O 'BUSCAP' */

void imprimeGrafo(int g[N][N]){

	int lin, col;

	printf("MATRIZ DE ADJACENCIA DO GRAFO \n");
	printf("\n");
	for(lin = 0; lin < N; lin++){
		for(col = 0; col < N; col++){
			printf("%d ", g[lin][col]);
		}
		printf("\n");
	}

  printf("\n");
} /* FIM DA FUN��O 'IMPRIME GRAFO' */



// CONTA ARESTAS
void contaAresta(int g[N][N]){

 int lin, col, arestas=0, antes=0, cont=0;
 int col2[N], lin2[N];


 for(lin=0; lin<N; lin++){
    for(col=0; col<N; col++){

     if(g[lin][col]!=0)
        arestas++;
    }
 }

// VERIFICA SE GRAFO EH DIRECIONADO OU NÃO

while(cont<N){


        for(col=0; col<N; col++){
        lin=antes;
        lin2[col] = g[lin][col];
        }


        for(lin=0; lin<N; lin++){
            col=antes;
            col2[lin] = g[lin][col];
            }


         for(lin=0; lin<N; lin++){
             if((lin2[lin]) != (col2[lin])){
                printf("\n GRAFO EH DIRECIONADO \n");
                printf("\n A QUANTIDADE DE ARESTAS EH: %d \n", arestas);
                return;
             }
         }

        antes++;
        cont++;

        if(cont==N){
            printf("\n GRAFO NAO EH DIRECIONADO \n");
            printf("\n A QUANTIDADE DE ARESTAS EH: %d \n", arestas/2);
        }

    }

}




























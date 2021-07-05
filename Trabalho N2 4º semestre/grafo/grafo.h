
#ifndef GRAFO_H
#define GRAFO_H

#define N 7

void buscaEmLargura (int g[N][N], int x);
void buscaEmProfundidade (int g[N][N], int x);
void buscaP (int g[N][N], int x, int visitados[N]);

void imprimeGrafo (int g[N][N]);
void contaAresta(int g[N][N]);

#endif

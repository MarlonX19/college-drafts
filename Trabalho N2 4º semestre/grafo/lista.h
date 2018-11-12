
#ifndef LISTA_H
#define LISTA_H


/* Estrutura do NoLista ----------------------------------------------- */
typedef struct _nolista {
    int id;
    struct _nolista* proximo;
} NoLista;


/* Funcoes de Lista --------------------------------------------------- */

void inicializaLista (NoLista** lista);

void insereInicio (NoLista** lista, int id);
void insereFinal (NoLista** lista, int id);
void insereOrdenado (NoLista** lista, int id);

int removeInicio (NoLista** lista);
int removeFinal (NoLista** lista);
void removeElemento (NoLista** lista, int id);


int pesquisaElemento (NoLista* lista, int id);
int contaNumElementos (NoLista* lista);

int estaVazia (NoLista* lista);
void esvaziaLista (NoLista** lista);

void imprimeLista (NoLista* lista);


#endif

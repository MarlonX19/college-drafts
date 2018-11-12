
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"


/* inicializa a lista ------------------------------------------------- */
void inicializaLista (NoLista** lista) {

    *lista = NULL;

} /* fim de inicializaLista */



/* adiciona um elemento no inicio da lista ---------------------------- */
void insereInicio (NoLista** lista, int id) {

    NoLista* novo;

    novo = (NoLista*) malloc (sizeof(NoLista));
    novo->id = id;

    if (estaVazia(*lista)) {
        novo->proximo = NULL;
        *lista = novo;
        return;
    }

    novo->proximo = *lista;
    *lista = novo;

} /* fim de insereInicio */



/* adiciona um elemento no final da lista ----------------------------- */
void insereFinal (NoLista** lista, int id) {

    NoLista* atual = *lista;
    NoLista* novo;

    novo = (NoLista*) malloc (sizeof(NoLista));
    novo->id = id;

    if (estaVazia(*lista)) {
        *lista = novo;
        novo->proximo = NULL;
        return;
    }

    while (atual->proximo != NULL)
        atual = atual->proximo;

    atual->proximo = novo;
    novo->proximo = NULL;

} /* fim de insereFinal */



/* adiciona elemento de forma ordenada na lista ----------------------- */
void insereOrdenado (NoLista** lista, int id) {

    NoLista* atual = *lista;
    NoLista* anterior = atual;
    NoLista* novo;

    novo = (NoLista*) malloc (sizeof(NoLista));
    novo->id = id;

    if (estaVazia(*lista)) {
        *lista = novo;
        return;
    }

    /* percorre a lista até encontrar a posição correta de inserção */
    while ((atual != NULL) && (atual->id < id)) {
        anterior = atual;
        atual = atual->proximo;
    }

    /*se posição for inicio da lista, então insere no inicio */
    if (atual == *lista)
        insereInicio(lista, id);

    /* se posição for final da lista, então insere no final */
    else if (atual == NULL)
        insereFinal(lista, id);

    /* insere elemento no meio da lista */
    else {
        anterior->proximo = novo;
        novo->proximo = atual;
    }

} /* fim de insereOrdenado */



/* remove o elemento do inicio da lista ------------------------------- */
int removeInicio (NoLista** lista) {

    NoLista* atual = *lista;
    int id;

    if (estaVazia(*lista))
        return -1;

    *lista = atual->proximo;
    id = atual->id;
    free(atual);
    return id;

} /* fim de removeInicio */



/* remove o elemento do final da lista -------------------------------- */
int removeFinal (NoLista** lista) {

    NoLista* atual = *lista;
    NoLista* anterior = atual;
    int id;

    if (estaVazia(*lista))
        return -1;

    /* se a lista contém apenas um elemento */
    if (atual->proximo == NULL) {
        *lista = NULL;
        id = atual->id;
        free(atual);
        return id;
    }

    /* se a lista contém mais de um elemento */
    while (atual->proximo != NULL) {
        anterior = atual;
        atual = atual->proximo;
    }

    anterior->proximo = NULL;
    id = atual->id;
    free(atual);
    return id;

} /* fim de removeFinal */



/* remove um elemento do meio da lista -------------------------------- */
void removeElemento (NoLista** lista, int id) {

    NoLista* atual = *lista;
    NoLista* anterior = atual;

    if (estaVazia(*lista))
        return;

    while ((atual != NULL) && (atual->id != id)) {
        anterior = atual;
        atual = atual->proximo;
    }

    /* se elemento não existe na lista, imprime mensagem e retorna */
    if (atual == NULL) {
        printf(" -> %d nao encontrado!\n", id);
        return;
    }

    /* se elemento for o primeiro da lista, remove do inicio */
    if (atual == *lista)
        removeInicio(lista);

    /* se elemento for o ultimo da lista, remove do final */
    else if (atual->proximo == NULL)
        removeFinal(lista);

    /* remove elemento do meio da lista */
    else {
        anterior->proximo = atual->proximo;
        free(atual);
    }

} /* fim de removeElemento */



/* verifica se a lista esta vazia ------------------------------------- */
int estaVazia (NoLista* lista) {

    return (lista == NULL);

} /* fim de estaVazia */



/* pesquisa por um elemento na lista ---------------------------------- */
int pesquisaElemento (NoLista* lista, int id) {

    NoLista* atual = lista;
    int posicao = 0;

    if (estaVazia(lista))
        return -1;

    while ((atual != NULL) && (atual->id != id)) {
        atual = atual->proximo;
        posicao++;
    }

    if (atual == NULL)
        return -2;

    return (posicao+1);

} /* fim de pesquisaElemento */



/* conta o numero de elementos atuais da lista ------------------------ */
int contaNumElementos (NoLista* lista) {

    NoLista* atual = lista;
    int contador = 0;

    if (!estaVazia(lista)) {

        while (atual != NULL) {
            atual = atual->proximo;
            contador++;
        }

    }

    return contador;

} /* fim de contaNumElementos */



/* esvazia a lista ---------------------------------------------------- */
void esvaziaLista (NoLista** lista) {

    NoLista* atual = *lista;
    NoLista* anterior ;

    if (estaVazia(*lista))
        return;

    while (atual != NULL) {
        anterior = atual;
        atual = atual->proximo;
        free(anterior);
    }

    *lista = NULL;

} /* fim de esvaziaLista */



/* imprime a lista ---------------------------------------------------- */
void imprimeLista (NoLista* lista) {

    NoLista* atual = lista;

    if (estaVazia(lista)) {
        printf("-\n");
        return;
    }

    while (atual != NULL) {
        if (atual == lista)
            printf("%d", atual->id);
        else
            printf(" -> %d", atual->id);
        atual = atual->proximo;
    }

    printf("\n");

} /* fim de imprimeLista */

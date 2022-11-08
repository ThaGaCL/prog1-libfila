#ifndef _LIBfila_t_H
#define _LIBfila_t_H
#include <stdlib.h>
#include <stdio.h>
#include "libfila.h"
struct nodo_f {
    int chave;            /* fila de numeros inteiros */
    struct nodo_f *prox;  /* ponteiro para o proximo  */
};
typedef struct nodo_f nodo_f_t;
 
struct fila {
    nodo_f_t* ini;        /* ponteiro para o inicio da lista */
    nodo_f_t* fim;        /* ponteiro para o fim da lista    */
    int tamanho;          /* numero de elementos na lista    */
};
typedef struct fila fila_t;


/*
 * Cria uma fila vazia e a retorna, se falhar retorna NULL.
*/
fila_t* fila_cria (){
    /*Aloca a memoria para a fila*/
    fila_t* fila = malloc(sizeof(fila_t));
    if(fila == NULL)
        return NULL;

    /*Seta os ponteiros de inicio e fim para NULL (lista vazia)*/
    fila->ini=NULL;
    fila->fim=NULL;

    return fila;
};

/*
 * Remove todos os elementos da fila, libera espaco e devolve NULL.
*/
fila_t* fila_destroi (fila_t* f)
{  
    /*Reseta os ponteiros de inicio e fim para NULL*/
    free(f->ini);
    f->ini=NULL;
    f->fim=NULL;
    f->tamanho=0;    
    /*Libera a memoria alocada para a fila*/
    free(f);
    f=NULL;
    return f;
};

/*
 * Retorna 1 se a fila esta vazia e 0 caso contrario.
*/
int fila_vazia (fila_t* f)
{
    if (f->ini==f->fim||f->tamanho==0)
        return 1;   
    return 0;
};

/*
 * Retorna o tamanho da fila, isto eh, o numero de elementos presentes nela.
*/
int fila_tamanho (fila_t* f)
{
    return f->tamanho;
};

/*
 * Insere o elemento no final da fila (politica FIFO).
 * Retorna 1 se a operacao foi bem sucedida e 0 caso contrario.
*/
int queue (fila_t* f, int elemento)
{
    nodo_f_t* nodo = malloc(sizeof(nodo_f_t));
    if(nodo == NULL)
        return 0;   
    /*Checa se a fila esta vazia*/   
    /*Caso esteja o nodo de inicio recebe o nodo inicializado*/
    /*Caso não esteja o proximo nodo (apos o nodo fim) recebe*/
    if(f->tamanho==0)
    {
        f->ini=nodo;
    }
    else
        f->fim->prox=nodo;
    
    f->fim = nodo;
    f->tamanho++;
    
    /*Como na fila se adiciona elementos no final o proximo sera nulo*/
    /*até a proxima inserção*/
    nodo->prox=NULL;
    nodo->chave=elemento;
    return 1;
};

/*
 * Remove elemento do inicio da fila (politica FIFO) e o retorna.
 * Retorna 1 se a operacao foi bem sucedida e 0 caso contrario.
*/
int dequeue (fila_t* f, int* elemento)
{
    if(f->tamanho==0)
        return 0;

    /*Cria um nodo auxiliar que recebe o inicio, para poder liberar a memoria apos o dequeue*/
    nodo_f_t* endini = f->ini;
    *elemento=f->ini->chave;
    f->ini=f->ini->prox;
    f->tamanho--;
    free(endini);
    endini=NULL;
    return 1;
};

/*
 * Imprime a fila, do inicio ate o fim, este por ultimo, sem espaco no final.
 * Quando a fila estiver vazia, nao imprime nada, nem um \n.
*/
void fila_imprime (fila_t* f)
{
    if((fila_vazia(f)!=1))
    {
        nodo_f_t* aux;
        for(aux=f->ini;aux->prox!=NULL; aux=aux->prox)
        {
            printf("%d ",aux->chave);
        }

        printf("%d\n",aux->chave);
    }
};


#endif
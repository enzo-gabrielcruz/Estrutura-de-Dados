#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int valor;
    struct node *prox;
    struct node *prev;
}node;

inserir_inicio (node ** lista,int num){
    node * new = malloc(sizeof(node));
    new->valor = num;
    if ((*lista) == NULL){
        new->prox = new;
        new->prev = new;
        *lista = new;
    }
    else{
        new->prox = *lista;
        (*lista)->prev = new;
        new->prev = (*lista)->prev;
        *lista = new;
    }
}

inserir_ordenado (node ** lista, int num){
    node * new = malloc (sizeof(node));
    new->valor = num;
    if((*lista) == NULL){
        new->prox = new;
        new->prev = new;
        *lista = new;
        return;
    }

    node *aux = *lista;

    if (num < aux->valor){
        node * ultimo = (*lista)->prev;
        
        new->prev = ultimo;
        new->prox =  *lista;
        ultimo->prox = new;
        (*lista)->prev = new;
        *lista = new;
        return;

    }
    else{  
        while(aux->prox != *lista && aux->prox->valor < num)
            aux = aux->prox;
      
        new->prox = aux->prox;
        aux->prox->prev = new;
        new->prev = aux;
        aux->prox = new;

        if (new->prox == *lista)
            (*lista)->prev = new;  
    }   
}

inserir_fim (node ** lista, int num){
    node * new = malloc (sizeof(node));
    new->valor = num;
    if (*lista == NULL){
        new->prox = new;
        new->prev = new;
        *lista = new;
    }
    else{
        new->prox = *lista;
        new->prev = (*lista)->prev;
        (*lista)->prev->prox = new;
        (*lista)->prev = new;
    }
}
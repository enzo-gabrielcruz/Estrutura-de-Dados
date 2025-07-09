#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    char pessoa[50];
    node * prox;
}node;

void enqueue (node ** fila,char pessoa[]){
    node * novo = malloc(sizeof(node));
    strcpy(novo->pessoa,pessoa);
    if (*fila == NULL){
        novo->prox = novo;
        *fila = novo;
    }
    else{
        node * aux = *fila;
        while (aux->prox != *fila)
            aux = aux->prox;
        novo->prox = *fila;
        aux->prox = novo;
    }
}

void dequeue(node ** fila){
    node * remove = *fila;
    if(*fila == NULL){
        printf("Fila Vazia.\n");
        return;
    }
    if (remove->prox == remove){
        *fila = NULL;
    }
    else{
        node * aux = *fila;
        while (aux->prox != *fila)
            aux = aux->prox;
        aux->prox = remove->prox;
        *fila = remove->prox;
        free(remove);
    }
}

int main(){

}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    char marca[40];
    struct node *proximo;
}node;

void inicializarPilha (node ** pilha){
    *pilha = NULL;
}

void push (node ** pilha, char marca[]){ // operação de empilhar
    node * novo = malloc (sizeof(node));
    strcpy(novo->marca,marca);
    if(*pilha == NULL){
        novo->proximo = NULL;
        *pilha = novo;
    }
    else{
        novo->proximo = *pilha;
        *pilha = novo;
    }
}

void pop (node ** pilha){ //desempilhar
    node * remove;
    if (*pilha == NULL)
        printf("Pilha vazia.\n\n");
    else{
        remove = *pilha;
        *pilha = remove->proximo;
        free(remove);
    }
}

void printer (node * pilha){
    node * aux = pilha;
    if (aux == NULL)
        printf("Pilha vazia.\n\n");
    else{
        while(aux!=NULL){
            printf("%s --> ",aux->marca);
            aux = aux->proximo;
        }
        printf("\n\n");
    }

}


int main(){
    node * pilha;   
    char marca[50];
    int key = 1;
    printf("\t\t\t PILHA DE MARCAS: \n\n");
    inicializarPilha(&pilha);
    
    while(key!=0){
        printf("1 - Empilhar\t\t\t2 - Desempilhar\t\t\t3 - Verificar Pilha\t\t\t0 - Sair. ");
        scanf("%d",&key);
        switch (key){
            case 0:
                break;
            case 1:
                printf("Nome da marca que será empilhada: ");
                scanf(" %s",&marca[50]);
                push(&pilha,&marca[50]);
                break;
            case 2:
                pop(&pilha);
                break;
            case 3:
                printf("Acompanhe o andamento da Pilha:\n");
                printer(pilha);
                break;
            default:
                printf("Opção Inválida!!Tente NOVAMENTE.\n\n");
                break;
        }

    }

}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    char pessoa[30];
    struct node * proximo;
}node;

void inicializarFila (node ** fila){
    *fila = NULL;
}

void inserir (node ** fila, char pessoa[]){
    node * novo = malloc(sizeof(node));
    strcpy(novo->pessoa,pessoa);
    novo->proximo = NULL;

    if((*fila)==NULL)
        *fila = novo;
    else{
        node * aux = *fila;
        while(aux->proximo != NULL)
            aux = aux->proximo;
        aux->proximo = novo;     
    }  
}

void remover(node ** fila){
    node * remove;

    if (*fila ==  NULL)
        printf("\nSem ninguém para ser atendido.\n");
    else{
        printf("%s\n",(*fila)->pessoa);
        remove = *fila;
        *fila = remove->proximo;
        free(remove);
        printf("Pessoa atendida. Fila atualizada.\n\n");
    }

}

void printer(node * fila){
    node * aux = fila;
    int i = 0;
    printf("\n");

    if(aux==NULL)
        printf("Sem Fila.\n\n");
    else{
        while(aux!=NULL){
        printf("%d-%s <--- ",i+1,aux->pessoa);
        aux = aux->proximo;
        i++;
        }
    }

    printf("\n\n");
}



int main(){
    node * fila;
    char pessoa[50];
    int key = 1;
    printf("\t\t\t FILA DE BANCO, ACOMPANHE A ORDEM: \n\n");
    inicializarFila(&fila);
    
    while(key!=0){
        printf("1 - Inserir pessoa na fila\t\t\t2 - Atender Pessoa da fila\t\t\t3 - Verificar a Fila\t\t\t0 - Sair. ");
        scanf("%d",&key);
        switch (key){
            case 0:
                break;
            case 1:
                printf("Nome da pessoa que entrará na fila: ");
                scanf(" %s",&pessoa[50]);
                inserir(&fila,&pessoa[50]);
                break;
            case 2:
                printf("Pessoa a ser atendida: \n");
                remover(&fila);
                break;
            case 3:
                printf("Acompanhe o andamento da Fila:\n");
                printer(fila);
                break;
            default:
                printf("Opção Inválida!!Tente NOVAMENTE.\n\n");
                break;
        }

    }


}
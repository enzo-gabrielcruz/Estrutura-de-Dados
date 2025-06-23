#include <stdio.h>
#include <stdlib.h>
// inserção utilizando ponteiro para ponteiro

typedef struct node{
    int valor;
    struct node *proximo;
}node;



void insercao_inicio (node **lista,int num){
    node *new = malloc(sizeof(node));
    
    new->valor = num;
    new->proximo = *lista;
    *lista = new;
}

void insercao_fim (node **lista, int num){
    node *new = malloc(sizeof(node));
    node *aux = malloc(sizeof(node));

    new->valor = num;
    new->proximo = NULL;
    
    if(*lista == NULL) // verifico se é o primeiro elemento criado
        *lista = new;
    else{
        aux = *lista;
        while (aux->proximo != NULL)
            aux = aux->proximo;
        aux->proximo = new;
    }
}

void insercao_meio(node **lista, int num, int ant){
    node *new = malloc (sizeof(node));
    node *aux = malloc (sizeof(node));

    new->valor = num;

    if(*lista == NULL){
        new->valor = num;
        new->proximo = NULL;
        new = *lista;
    }
    else{
        aux = *lista;
        while(aux->valor != ant && aux->proximo != NULL)
            aux = aux->proximo;
        new->proximo = aux->proximo;
        aux->proximo = new;
    }
}

void inserir_ordenado(node **lista, int num){
    node *new = malloc(sizeof(node));
    node *aux = malloc(sizeof(node));

    new->valor = num;

    if (*lista == NULL){
        new->proximo = NULL;
        *lista = new;
    }
    else if (new->valor < (*lista)->valor){
        new->proximo = *lista;
        *lista = new;
    }
    else{
        aux = *lista;
        while (aux->proximo != NULL && aux->proximo->valor < new->valor){
            aux = aux->proximo;
        }
        new->proximo = aux->proximo;
        aux->proximo = new;
    }
}

void print (node *lista){
    printf("\t Lista:\n\t");
    while(lista){
        printf("%d  ",lista->valor);
        lista = lista->proximo;
    }
    printf("\n\n");
}

int main(){
    node *lista = NULL;
    int ant,num,key = 1;

    printf("\n\tLista: \n");
    
    while(key!=0){
        printf("\t\n0 - Sair\t\n1 - Inserir no Inicio\t\n2 - Inserir no Meio\t\n3 - Inserir no Fim\t\n4 - Inserir Ordenado\t\n5 - Imprimir Lista\t\n");
        scanf("%d",&key);

        switch (key){
            case 1:
                scanf("%d",&num);
                insercao_inicio(&lista,num);
                break;
            case 2: 
                printf("Digite o numero a ser inserido: ");
                scanf("%d",&num);
                printf("Digite a referencia, caso seja o primeiro numero da lista digite qualquer numero: ");
                scanf("%d",&ant);
                insercao_meio(&lista,num,ant);
                break;
            case 3:
                scanf("%d",&num);
                insercao_fim(&lista,num);
                break;
            case 4:
                scanf("%d",&num);
                inserir_ordenado(&lista,num);
                break;
            case 5:
                print(lista); 
                break;
            default:
                if(key == 0) break;
                else printf("Opção Inválida.\n");
                break;
        }
    }


    return 0;
}

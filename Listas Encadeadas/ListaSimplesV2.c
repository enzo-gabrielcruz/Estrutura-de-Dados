#include <stdio.h>
#include <stdlib.h>
// inserção utilizando uma estutura lista

typedef struct node{
    int valor;
    struct node *proximo;
}node;

typedef struct Lista{
    node *inicio;
    int tam;
}Lista;

void iniciar_lista (Lista *Lista){
    Lista->inicio = NULL;
    Lista->tam = 0;
}

void insercao_inicio (Lista *lista,int num){
    node *new = malloc(sizeof(node));
    new->valor = num;
    new->proximo = lista->inicio;
    lista->inicio = new;
    lista->tam++;
}

void insercao_fim (Lista *lista, int num){
    node *new = malloc(sizeof(node));
    node *aux = malloc(sizeof(node));

    new->valor = num;
    new->proximo = NULL;
    
    
    if(lista->inicio == NULL) // verifico se é o primeiro elemento criado
        lista->inicio = new;
    else{
        aux = lista->inicio;
        while (aux->proximo != NULL)
            aux = aux->proximo;
        aux->proximo = new;
    }
    lista->tam++;
}

void insercao_meio(Lista *lista, int num, int ant){
    node *new = malloc (sizeof(node));
    node *aux = malloc (sizeof(node));

    new->valor = num;

    if(lista->inicio == NULL){
        new->proximo = NULL;
        lista->inicio = new;
    }
    else{
        aux = lista->inicio;
        while(aux->valor != ant && aux->proximo != NULL)
            aux = aux->proximo;
        new->proximo = aux->proximo;
        aux->proximo = new;
    }
}

void inserir_ordenado (Lista *lista, int num){
    node *new = malloc (sizeof(node));
    node *aux = malloc (sizeof(node));

    new->valor = num;

    if(lista->inicio == NULL){
        new->proximo = NULL;
        lista->inicio = new;
    }
    else if (new->valor < lista->inicio->valor){
        new->proximo = lista->inicio;
        lista->inicio = new;
    }
    else{
        aux = lista->inicio;
        while(aux->proximo != NULL && aux->proximo->valor < new->valor){
            aux = aux->proximo;
        }
        new->proximo = aux->proximo;
        aux->proximo = new;
    }
    lista->tam++;
}


void Remover (Lista *lista, int num){
    node *remove = NULL;
    node *aux;
    int key  = 1;
    if(lista->inicio->valor == num){
        remove = lista->inicio;
        lista->inicio = remove->proximo;
        key = 0;
        free(remove);
        lista->tam--;
    }
    else{
        aux = lista->inicio;
        while(aux->proximo != NULL && aux->proximo->valor != num)
            aux = aux->proximo;
        if(aux->proximo != NULL){
            remove = aux->proximo;
            aux->proximo = remove->proximo;
            key = 0;
            free(remove);
            lista->tam--;
        }
    }
     
    if(key == 1)
        printf("Elemento inexistente.\n\n");
}

node * Buscar (Lista *lista, int num){
    node *aux;
    aux = lista->inicio;
    if(lista->inicio->valor == num){
        return lista->inicio;
    }
    else{
        while (aux->proximo != NULL && aux->proximo->valor != num){
        aux = aux->proximo;
        }
        if(aux->proximo != NULL)
            return aux->proximo;        
    }

    return NULL;
}

void print (Lista lista){
    node *no = lista.inicio;
    printf("\t Lista de tamanho %d:\n\t",lista.tam);
    while(no){
        printf("%d  ",no->valor);
        no = no->proximo;
    }
    printf("\n\n");
}

int main(){
    int ant,num,key = 1;
    Lista lista;
    node *busca;

    printf("\n\tLista: \n");

    iniciar_lista(&lista);

    while(key!=0){
        printf("\t\n0 - Sair\t\n1 - Inserir no Inicio\t\n2 - Inserir no Meio\t\n3 - Inserir no Fim\t\n4 - Inserir Ordenado\t\n5 - Inserir Ordenado\t\n6 - Buscar Número\t\n7 - Imprimir Lista\t\n");
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
                scanf("%d",&num);
                Remover(&lista,num);
            case 6:
                 printf("Qual numero deseja buscar na lista? ");
                scanf("%d",&num);
                busca = Buscar(&lista,num);
                if (busca){
                    printf("Número encontrado na Lista, número %d.\n\n",busca->valor);
                }
                else
                    printf("Número não encontrado na lista.\n\n");
                break;
            case 7:
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
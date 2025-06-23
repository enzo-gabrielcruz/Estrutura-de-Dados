#include <stdio.h>
#include <stdlib.h>
// inserção utilizando ponteiro para ponteiro
// Lista Duplamente encadeada

typedef struct node{
    int valor;
    struct node *proximo;
    struct node *anterior;
}node;



void insercao_inicio (node **lista,int num){
    node *new = malloc(sizeof(node));
    
    new->valor = num;
    new->proximo = *lista;
    new->anterior = NULL;
    if(new->proximo != NULL){
        (*lista)->anterior = new;
    }
    *lista = new;
}

void insercao_fim (node **lista, int num){
    node *new = malloc(sizeof(node));
    node *aux;

    new->valor = num;
    new->proximo = NULL;
    
    if(*lista == NULL) { // verifico se é o primeiro elemento criado
        new->anterior = NULL;
        *lista = new;
    }
    else{
        aux = *lista;
        while (aux->proximo != NULL)
            aux = aux->proximo;
        aux->proximo = new;
        new->anterior = aux;
    }
}

void insercao_meio(node **lista, int num, int ant){
    node *new = malloc (sizeof(node));
    node *aux;

    new->valor = num;

    if(*lista == NULL){
        new->valor = num;
        new->proximo = NULL;
        new->anterior = NULL;
        *lista = new;
    }
    else{
        aux = *lista;
        while(aux->valor != ant && aux->proximo != NULL)
            aux = aux->proximo;
        new->proximo = aux->proximo;
        new->anterior = aux;

        if(aux->proximo != NULL){
            aux->proximo->anterior = new;
            
        }
        aux->proximo = new;
    }
}

void inserir_ordenado(node **lista, int num){
    node *new = malloc(sizeof(node));
    node *aux = malloc(sizeof(node));

    new->valor = num;

    if (*lista == NULL){
        new->proximo = NULL;
        new->anterior = NULL;
        *lista = new;
    }
    else if (new->valor < (*lista)->valor){
        new->proximo = *lista;
        (*lista)->anterior = new;
        *lista = new;
    }
    else{
        aux = *lista;
        while (aux->proximo != NULL && aux->proximo->valor < new->valor){
            aux = aux->proximo;
        }
        new->proximo = aux->proximo;
        aux->proximo->anterior = new;
        new->anterior = aux;
        aux->proximo = new;
    }
}

void remover (node **lista, int num){
    node *remove = NULL;
    node *aux;
    int key = 1;
    
    if((*lista)->valor == num){
       remove = *lista;
       *lista = remove->proximo;
       if(*lista != NULL)
            (*lista)->anterior = NULL;
       free(remove);
       key = 0;
    }
    else{
        aux = *lista;
        while(aux->proximo != NULL && aux->proximo->valor != num)
            aux = aux->proximo;
        if(aux->proximo != NULL){
            remove = aux->proximo;
            aux->proximo = remove->proximo;
            if(aux->proximo != NULL)
                aux->proximo->anterior = aux;
            free(remove);
            key = 0;
        }
    }

    if(key == 1){
        printf("Elemento inexistente.\n\n");
    }
    
}

// retornando um ponteiro do tipo struct, geralmente será utilizado caso eu precise acessar mais de uma informação (Ex: Cadastro Aluno);
node* Buscar (node **lista,int num){
    node *aux;

    if((*lista)->valor == num){
        return *lista;
    }
    else{
        aux = *lista;
        while(aux->proximo != NULL && aux->proximo->valor != num)
            aux = aux->proximo;
        if(aux->proximo != NULL){
            return aux->proximo;
        }
    }

    return NULL;
}

void print (node *lista){
    printf("\t Lista:\n\t");
    while(lista){
        printf("%d  ",lista->valor);
        lista = lista->proximo;
    }
    printf("\n\n");
}

node * Ultimo (node ** lista){
    node *aux = *lista;
    while (aux->proximo != NULL){
        aux = aux->proximo;
    }
    return aux;
}

void ImprimirContrario (node *lista){
    printf("\t Lista Inversa:\n\t");
    while(lista){
        printf("%d  ",lista->valor);
        lista = lista->anterior;
    }
    printf("\n\n");
}

int main(){
    node *lista = NULL;
    node *busca;
    int ant,num,key = 1;

    printf("\n\tLista: \n");
    
    while(key!=0){
        printf("\t\n0 - Sair\t\n1 - Inserir no Inicio\t\n2 - Inserir no Meio\t\n3 - Inserir no Fim\t\n4 - Inserir Ordenado\t\n5 - Remover Número\t\n6 - Buscar Número\t\n7 - Imprimir Lista\t\n");
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
                printf("Qual numero deseja remover da lista? ");
                scanf("%d",&num);
                remover(&lista,num);
                break;
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
                ImprimirContrario(Ultimo(&lista));
                break;
            default:
                if(key == 0) break;
                else printf("Opção Inválida.\n");
                break;
        }
    }


    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#define T 10


void PreencherVetor (int *lista, int tamanho){
    int i;
    printf("Preencha a lista com números inteiros:\n");
    for(i=0; i < tamanho;i++){
        printf("Posicao %d: ",i+1);
        scanf("%d",&lista[i]);
    }

}

void ListarValores (int *lista, int tamanho){
    int i;
    for(i=0; i < tamanho; i++){
        printf("%d ",lista[i]);
    }
    printf("\n");
}

void InsertionSort (int *lista, int tamanho){
    // BIG NOTAÇÃO:
    // PIOR CASO: O(N²)
    // CASO MÉDIO: O(N²)
    // MELHOR CASO: O(N)
    // Espaço Extra: O(1), por conta da memória Auxiliar para realização das trocas.
    // Insertion: Realiza troca de valores toda vez que identificar a necessiade, ou seja, número atual menor que o anterior, com auxilio de uma variável
    int i,j,aux;
    for(i=0;i < tamanho - 1;i++){
        if(lista[i] > lista[i+1]){
            aux = lista[i];
            lista[i] = lista[i+1];
            lista[i+1] = aux;
            //A partir do momento que é identificado a condição realizamos a troca dos valores por meio do suporte de AUX;
        }
        j = i - 1; // Decremento o valor de J para que possamos comparar se o atual valor presente em i é menor ou maior do que seu anterior
            while(j>=0){ //Decrementando toda vez que o valor trocado for menor do que o anterior
                if(lista[j+1] < lista[j]){
                    aux = lista[j];
                    lista[j] = lista[j+1];
                    lista[j+1] = aux;
                    // Realiza troca se o valor de J+1 for menor que o valor de na posição J
                }
                else{
                    break;
                }
                j--;
            }

    }
}

void SelectionSort (int *lista, int tamanho){
    // PIOR CASO: O(N²)Não importa a ordem dos elementos, o número de comparações é o mesmo.
    // CASO MÉDIO: O(N²)Sempre precisa percorrer o vetor todo para encontrar o menor elemento.
    // MELHOR CASO: O(N²)Mesmo se o vetor já estiver ordenado, ele compara todos os elementos.
    // Espaço Extra: Sempre Seleciona o menor elemento presente na lista de números e compara com os outros
    int i,j,menor,aux;
    for(i=0; i < tamanho - 1;i++){ // não preciso percorrer a última posição já que ela já estará ordenada
        //Primeiro ponto: definir posiçao 0 como o menor valor inicialmente
        menor = i;
        for (j = i + 1; j < tamanho;j++){
            if (lista[menor] > lista[j]){
                menor = j;
                // o segundo laço é justamente para verificar o menor valor existente no vetor para que ocorra ou não a substiuição da posicao MENOR
            }
        }

        if(menor!=i){// significa que houve a troca
        aux = lista[i];
        lista[i] = lista[menor];
        lista[menor] = aux;
        // realiza a troca dos valores, colocando o menor valor na posição correta
        }
        // após finalizar isso o primeiro for incrementa uma posição e deixa definido as posições anteriores que já se encontram ordenadas
    }
}

int Partition_Quick (int* lista, int inicio, int fim){// realiza a partição do vetor em duas partes (a esquerda os menores que o pivo e a direita os maiores)
    int pivo,aux;
    pivo = (lista[inicio] + lista[fim] + lista[(inicio + fim) / 2]) / 3;
    while (inicio < fim){
        while (lista[inicio] < pivo){
            inicio++;
        }
        while (lista[fim] > pivo){
            fim--;
        }
        if(inicio < fim){
            aux = lista[inicio];
            lista[inicio] = lista[fim];
            lista[fim] = aux;
            inicio ++;
            fim --;
       }
    }
    return inicio;
}

void QuickSort (int*lista, int inicio, int fim){
    // Melhor Caso: O(n log n) O pivô divide o vetor em duas partes quase iguais.
    // Caso Médio: O(n log n) Em geral, mesmo com dados aleatórios, a divisão é relativamente balanceada.
    // Pior Caso: O(n²) Ocorre quando o pivô sempre escolhe o maior ou menor elemento (ex: vetor já ordenado).
    // Utiliza a estratégia de divisão por conquista, através de recursividade com auxilio da função partition
    int pivo;
    if (inicio < fim){
        pivo = Partition_Quick(lista,inicio,fim);
        QuickSort(lista,inicio,pivo - 1);
        QuickSort(lista,pivo + 1,fim);
    }
}

void Merge (int *lista, int inicio, int meio, int fim){
    int i = inicio;
    int m = meio + 1;
    int a;
    int *aux = malloc (sizeof(int) * (fim +1));
    a = inicio;

    while (i <= meio && m <= fim){
        if (lista[i] < lista[m]){
            aux[a] = lista[i];
            i++;
        }
        else{
            aux[a] = lista[m];
            m++;
        }
        a++;
    }

    while (i <= meio){
        aux[a] = lista[i];
        i++;
        a++;
    }
    while (m <= fim){
        aux[a] = lista[m];
        m++;
        a++;
    }
    for (i = inicio; i <= fim; i++){
        lista[i] = aux[i];
    }

}

void MergeSort (int *lista, int inicio, int fim){
  
    if (inicio < fim){
        int meio = (inicio + fim)/2;
        MergeSort(lista,inicio,meio);
        MergeSort(lista,meio + 1,fim);
        
        // Intercala os vetores, função para juntar as partes ordenadas
        Merge(lista,inicio,meio,fim);
    
    }
}

int BuscaBinaria (int *lista,int chave,int inicio, int fim){
    int meio;
    if(inicio <= fim){
        meio = (inicio + fim) / 2;
        if (lista[meio] == chave)
            return meio;
        else{
            if(lista[meio] < chave){
                return BuscaBinaria(lista,chave,meio + 1,fim);
            }
            else{
                return BuscaBinaria(lista,chave,inicio, meio - 1);
            }
        }
    }
    return -1;
}


 int main(){
    int TAM = 10;
    int *lista;
    int key = 0;
    int num,resultado;
    lista = malloc(TAM * sizeof(int));

    PreencherVetor(lista,TAM);
    printf("Ordenação Insertion Sort:\n");
    printf("                Valores sem ORDENAÇÃO:\n");
    ListarValores(lista,TAM);

    printf("                Valores ORDENADOS :\n");
    MergeSort(lista,0,TAM - 1);
    ListarValores(lista,TAM);


    printf("\n\n        BUSCA BINÁRIA:\n");

    while (key != 1){
        printf("Qual número você busca: ");
        scanf("%d",&num);
        resultado = BuscaBinaria(lista,num,0,TAM-1);
        if (resultado == -1){
            printf("Número inexistente na lista atual.\n\n");
            
        }
        else{
            printf("O número buscado encontra-se na posição %d da lista atual.\n",resultado + 1);
            
        }

        printf("Você deseja continuar realizando buscas ?\n1 - Sair ------------- 0 - Continuar");
        scanf("%d",&key);

        if (key == 1) break;
        while (key != 0){
            printf("Escolha inválida, digite novamente a opção que deseja: ");
            scanf("%d",&key);
            if (key == 1) break;
        }
     
}
        
 return 0;
}

   


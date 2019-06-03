#include <stdio.h>
#include <limits.h>
#include <iostream>
using namespace std;

typedef struct funcionario{
    long long int id;
    long long int tempo_de_proc;
}Funcionario;

typedef struct heap{
    long long int lenght;
    long long int heap_size;
    Funcionario *vetor;
}Heap;

long long int parent(long long int value){
    return value/2;
}

long long int left(long long int value){
    return value*2;
}

long long int right(long long int value){
    return value*2 + 1;
}

Heap *build(long long int n_funcionarios, long long int *tempo_atendimento, long long int *clientes){
    Heap *h = new Heap;
    h->lenght    = n_funcionarios;
    h->heap_size = 1;
    h->vetor     = new funcionario[n_funcionarios+1];
    for(long long int cont = 1; cont <= n_funcionarios; cont++){//insere os valores
        h->vetor[cont].tempo_de_proc = tempo_atendimento[cont]*clientes[cont];
        h->vetor[cont].id = cont;
    }
    return h;
}

void heap_print(Heap * arv){
    for(long long int cont = 1; cont <= arv->heap_size; cont++){
        cout << "(" << arv->vetor[cont].id << "," << arv->vetor[cont].tempo_de_proc << ") ";
    }
    cout << "| ";
    for(long long int cont = arv->heap_size+1; cont <= arv->lenght; cont++){
        cout << "(" << arv->vetor[cont].id << "," << arv->vetor[cont].tempo_de_proc << ") ";
    }
    cout << endl;
}


void min_heapify(Heap *h, long long int i){
    long long int l = left(i);
    long long int r = right(i);
    long long int smaller = i;
    if (l <= h->heap_size){
        if (h->vetor[l].tempo_de_proc < h->vetor[i].tempo_de_proc)
            smaller = l;
        else if (h->vetor[l].tempo_de_proc == h->vetor[i].tempo_de_proc){
            if((h->vetor[l].id < h->vetor[i].id)){
                smaller = l;
            }
        }
    }
    if (r <= h->heap_size){
        if (h->vetor[r].tempo_de_proc < h->vetor[smaller].tempo_de_proc)
            smaller = r;
        else if (h->vetor[r].tempo_de_proc == h->vetor[smaller].tempo_de_proc){
            if((h->vetor[r].id < h->vetor[smaller].id)){
                smaller = r;
            }
        }
    }
    if (smaller != i){
        Funcionario aux = h->vetor[i];
        h->vetor[i] = h->vetor[smaller];
        h->vetor[smaller] = aux;
        min_heapify(h,smaller);
    }
}

void build_min_heap(Heap *h){
    h->heap_size = h->lenght;
    long long int i;
    for(i = h->lenght/2; i > 0; i--){
        min_heapify(h,i);
    }
}

void heapsort(Heap *h){
    for (long long int i = h->lenght; i >= 2; i--){
        Funcionario aux = h->vetor[1];
        h->vetor[1] = h->vetor[i];
        h->vetor[i] = aux;
        h->heap_size -= 1;
        min_heapify(h,1);
    }
}
/**
 * Reduz o tempo de cada valor com o tempo do topo da Heap
 * @param h
 * @param tempo
 */
void diminua_tempo(Heap * h){
    for(long long cont = h->lenght; cont >= 1; cont--){
        h->vetor[cont].tempo_de_proc -= h->vetor[1].tempo_de_proc;
    }
}

int main(){
    long long int n_funcionarios, n_clientes;
    long long int cliente_da_fila, tempo_total = 0;
    
    scanf("%lld %lld", &n_funcionarios, &n_clientes);
    
    long long int clientes[n_clientes+1];//o vetor comeca no 1
    long long int tempo_atendimento[n_funcionarios+1];//o vetor comeca no 1
    
    for(long long int cont = 1; cont <= n_funcionarios; cont++){//tempo de atendimento
        scanf("%lld", &tempo_atendimento[cont]);
    }
    for(long long int cont = 1; cont <= n_clientes; cont++){//itens do cliente
        scanf("%lld", &clientes[cont]);
    }
    
    Heap * arv = build(n_funcionarios, tempo_atendimento, clientes);
    
    //heap_print(arv);
    build_min_heap(arv);//constroi a arvore
    //heap_print(arv);
    
    for(long long int cont = n_funcionarios + 1; cont <= n_clientes; cont++){
        //acrescenta o tempo do proximo
        arv->vetor[1].tempo_de_proc += tempo_atendimento[arv->vetor[1].id]*clientes[cont];
        min_heapify(arv, 1);
        //heap_print(arv);
    }
    
    heapsort(arv);
    //heap_print(arv);
    printf("%lld\n", arv->vetor[1].tempo_de_proc);//imprime o maior tempo
}
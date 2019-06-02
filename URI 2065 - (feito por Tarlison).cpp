#include <bits/stdc++.h>
using namespace std;

typedef struct Funcionario{
    long int id;
    long int tempo_de_processamento;
}funcionario;

typedef struct Heap{
    long int lenght;
    long int heap_size;
    struct Funcionario *vetor;
}Heap;

Heap *build(long int n_funcionarios, long int *tempo_original);

long int left(long int index);

long int right(long int index);

void inserir_tempo(Heap *h, long int n_funcionarios, long int *tempo_original);

void build_max_heap(Heap *h);

void max_heapify(Heap *h, long int i);

void heapsort(Heap *h);

void build_max_heap_id(Heap *h);

void max_heapify_id(Heap *h, long int i);

void heapsort_id(Heap *h);

int main() {
    long int n_funcionarios, n_clientes, clientes_espera, tempo_total = 0, i;

    cin >> n_funcionarios >> n_clientes;

    clientes_espera = n_clientes;

    long int  clientes[n_clientes+1];
    long int tempo_original[n_funcionarios+1];

    Heap *h = build(n_funcionarios, tempo_original);

    for(int l = 1; l <= n_clientes; l++){ //quantidade de produto dos clientes
        scanf("%ld", &clientes[l]);
    }

    long int aux_qclientes = 1;
    do{
        for(i = 1; i <= n_funcionarios && aux_qclientes <= n_clientes; i++){
            if (h->vetor[i].tempo_de_processamento == 0){
                h->vetor[i].tempo_de_processamento = tempo_original[h->vetor[i].id];
                h->vetor[i].tempo_de_processamento *= clientes[aux_qclientes++];
                clientes_espera--;
            }
        }

        build_max_heap(h);
        heapsort(h);

        long int tira_tempo =  h->vetor[1].tempo_de_processamento; //salva valor para diminuir dos outros

        if(clientes_espera > 0){

            for(long int j = 1; j <= n_funcionarios; j++)
                h->vetor[j].tempo_de_processamento -= tira_tempo;

            tempo_total += tira_tempo; // tempo total de espera é armazenado aqui
        }

        build_max_heap_id(h);
        heapsort_id(h);

    }while(clientes_espera > 0);

    build_max_heap(h);
    heapsort(h);

    tempo_total += h->vetor[n_funcionarios].tempo_de_processamento;
    cout << tempo_total << endl;

    return 0;
}


Heap *build(long int n_funcionarios, long int *tempo_original){
    Heap *h = new Heap;
    h->lenght = n_funcionarios;
    h->heap_size = 0;
    h->vetor = new funcionario[n_funcionarios+1];
    h->vetor[0].id = h->vetor[0].tempo_de_processamento  = INT_MAX;
    inserir_tempo(h, n_funcionarios, tempo_original);
    return h;
}


long int left(long int index){
    return 2*index;
}

long int right(long int index){
    return 2*index + 1;
}

void inserir_tempo(Heap *h, long int n_funcionarios, long int *tempo_original){
    long int tempo_de_processamento;
    for (long int i = 1; i <= n_funcionarios; i++){
        cin >> tempo_de_processamento;
        h->vetor[i].id = i;
        h->vetor[i].tempo_de_processamento = tempo_de_processamento;
        tempo_original[i] = h->vetor[i].tempo_de_processamento;
        h->vetor[i].tempo_de_processamento = 0;
    }
}

void build_max_heap(Heap *h){
    h->heap_size = h->lenght;
    long int i;
    for(i = h->lenght/2; i > 0; i--){
        max_heapify(h,i);
    }
}

void build_max_heap_id(Heap *h){
    h->heap_size = h->lenght;
    long int i;
    for(i = h->lenght/2; i > 0; i--){
        max_heapify_id(h,i);
    }
}

void max_heapify(Heap *h, long int i){
    long int l = left(i);
    long int r = right(i);
    long int largest = i;
    if ((l <= h->heap_size)){
        if (h->vetor[l].tempo_de_processamento > h->vetor[i].tempo_de_processamento)
            largest = l;
        if (h->vetor[l].tempo_de_processamento == h->vetor[i].tempo_de_processamento){
            if((h->vetor[l].id > h->vetor[i].id)){
                largest = l;
            }
        }

    }
    if ((r <= h->heap_size)){
        if (h->vetor[r].tempo_de_processamento > h->vetor[largest].tempo_de_processamento)
            largest = r;
        if (h->vetor[r].tempo_de_processamento == h->vetor[largest].tempo_de_processamento){
            if((h->vetor[largest].id > h->vetor[r].id)){
                largest = r;
            }
        }

    }
    if (largest != i)
    {
        funcionario aux = h->vetor[i];
        h->vetor[i] = h->vetor[largest];
        h->vetor[largest] = aux;
        max_heapify(h,largest);
    }
}

void max_heapify_id(Heap *h, long int i){
    long int l = left(i);
    long int r = right(i);
    long int largest = i;

    if ((l <= h->heap_size)){
        if (h->vetor[l].id > h->vetor[i].id)
            largest = l;
    }

    if ((r <= h->heap_size)){
        if (h->vetor[r].id > h->vetor[largest].id)
            largest = r;
    }

    if (largest != i){
        funcionario aux = h->vetor[i];
        h->vetor[i] = h->vetor[largest];
        h->vetor[largest] = aux;
        max_heapify(h,largest);
    }
}

void heapsort(Heap *h){
    build_max_heap(h);
    for (long int i = h->lenght; i >= 2; i--){
        funcionario aux = h->vetor[1];
        h->vetor[1] = h->vetor[i];
        h->vetor[i] = aux;
        h->heap_size -= 1;
        max_heapify(h,1);
    }
}

void heapsort_id(Heap *h){
    build_max_heap_id(h);
    for (long int i = h->lenght; i >= 2; i--){
        funcionario aux = h->vetor[1];
        h->vetor[1] = h->vetor[i];
        h->vetor[i] = aux;
        h->heap_size -= 1;
        max_heapify_id(h,1);
    }
}
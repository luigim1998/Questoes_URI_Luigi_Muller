#include <bits/stdc++.h>
using namespace std;

typedef struct Funcionario{
    int id;
    int tempo_de_processamento;
}funcionario;

typedef struct Heap{
    int lenght;
    int heap_size;
    struct Funcionario *vetor;
}Heap;

Heap *build(int n_funcionarios);

int left(int index);

int right(int index);

void inserir_tempo(Heap *h, int n_funcionarios);

void build_max_heap(Heap *h);

void max_heapify(Heap *h, int i);

void heapsort(Heap *h);

void build_max_heap_id(Heap *h);

void max_heapify_id(Heap *h, int i);

void heapsort_id(Heap *h);

int main() {
    int n_funcionarios, n_clientes, clientes_espera, tempo_total = 0, i;

    cin >> n_funcionarios >> n_clientes;

    clientes_espera = n_clientes;

    int  clientes[n_clientes+1];

    Heap *h = build(n_funcionarios);

    int tempo_original[n_funcionarios+1];
    for (int w = 1; w <=n_funcionarios; w++){
        tempo_original[w] = h->vetor[w].tempo_de_processamento;
        h->vetor[w].tempo_de_processamento = 0;
    }

    for(int l = 1; l <= n_clientes; l++){ //quantidade de produto dos clientes
        cin >> clientes[l];
    }
    int aux_qclientes = 1;
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

        int tira_tempo =  h->vetor[1].tempo_de_processamento; //salva valor para diminuir dos outros

        if(clientes_espera > 0){
            for(int j = 1; j <= n_funcionarios; j++){
                h->vetor[j].tempo_de_processamento -= tira_tempo;

            }
            tempo_total += tira_tempo; // tempo total de espera é armazenado aqui
//            cout << "TEMPO TOTAL" << tempo_total << endl;

        }

        build_max_heap_id(h);
        heapsort_id(h);

//        for (int k = 1; k <= n_funcionarios; k++){
//            cout << h->vetor[k].id << ";";
//            cout << h->vetor[k].tempo_de_processamento << endl;
//        }



    }while(clientes_espera > 0);

    build_max_heap(h);
    heapsort(h);

//    for (int k = 1; k <= n_funcionarios; k++){
//        cout << h->vetor[k].id << ";";
//        cout << h->vetor[k].tempo_de_processamento << endl;
//    }

    tempo_total += h->vetor[n_funcionarios].tempo_de_processamento;
    cout << tempo_total << endl;

    return 0;
}


Heap *build(int n_funcionarios){
    Heap *h = new Heap;
    h->lenght = n_funcionarios;
    h->heap_size = 0;
    h->vetor = new funcionario[n_funcionarios+1];
    h->vetor[0].id = h->vetor[0].tempo_de_processamento  = INT_MAX;
    inserir_tempo(h, n_funcionarios);
    return h;
}


int left(int index){
    return 2*index;
}

int right(int index){
    return 2*index + 1;
}

void inserir_tempo(Heap *h, int n_funcionarios){
    int time,tempo_de_processamento;
    for (int i = 1; i <= n_funcionarios; i++){
        cin >> tempo_de_processamento;
        h->vetor[i].id = i;
        h->vetor[i].tempo_de_processamento = tempo_de_processamento;
    }
}

void build_max_heap(Heap *h){
    h->heap_size = h->lenght;
    int i;
    for(i = h->lenght/2; i > 0; i--){
        max_heapify(h,i);
    }
}

void build_max_heap_id(Heap *h){
    h->heap_size = h->lenght;
    int i;
    for(i = h->lenght/2; i > 0; i--){
        max_heapify_id(h,i);
    }
}

void max_heapify(Heap *h, int i){
    int l = left(i);
    int r = right(i);
    int largest = i;
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

void max_heapify_id(Heap *h, int i){
    int l = left(i);
    int r = right(i);
    int largest = i;

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
    for (int i = h->lenght; i >= 2; i--){
        funcionario aux = h->vetor[1];
        h->vetor[1] = h->vetor[i];
        h->vetor[i] = aux;
        h->heap_size -= 1;
        max_heapify(h,1);
    }
}

void heapsort_id(Heap *h){
    build_max_heap_id(h);
    for (int i = h->lenght; i >= 2; i--){
        funcionario aux = h->vetor[1];
        h->vetor[1] = h->vetor[i];
        h->vetor[i] = aux;
        h->heap_size -= 1;
        max_heapify_id(h,1);
    }
}
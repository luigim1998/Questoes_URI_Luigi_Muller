#include <stdio.h>
#include <iostream>
#include <limits.h>
using namespace std;

int *join(int *a, int *b){
    int *c = new int[2];
    c[0] = (a[0]<b[0] ? a[0] : b[0]);
    c[1] = (a[1]>b[1] ? a[1] : b[1]);
    return c;
}

void build(int input[], int segtree[][2], int low, int high, int node){//feito
    if(low + 1 == high){
        segtree[node][0] = segtree[node][1] = input[low];
        return;
    }
    int mid = (low + high)/2;
    build(input, segtree, low, mid, 2 * node);
    build(input, segtree, mid, high, 2 * node + 1);
    int * c = join(segtree[2*node], segtree[2*node + 1]);
    segtree[node][0] = c[0];
    segtree[node][1] = c[1];
}

int *search(int segtree[][2], int qlow, int qhigh, int node, int low, int high){//feito
    if(qlow >= high || qhigh <= low){
        int* a = new int[2];
        a[0] = INT_MAX;
        a[1] = INT_MIN;
        return a;
    }
    if(qlow <= low  && qhigh >= high)
        return segtree[node];
    
    int mid = (low+high)/2;
    return join(search(segtree, qlow, qhigh, 2*node, low, mid),
                search(segtree, qlow, qhigh, 2*node+1, mid, high));
}

void update(int input[], int segtree[][2], int pos, int value, int node, int low, int high){//feito
    if(low + 1 == high){
        input[pos] = segtree[node][0] = segtree[node][1] = value;
        return;
    }
    int mid = (low + high)/2;
    if(pos < mid)
        update(input, segtree, pos, value, 2*node, low, mid);
    else
        update(input, segtree, pos, value, 2*node+1, mid, high);
    int * c = join(segtree[2*node], segtree[2*node+1]);
    segtree[node][0] = c[0];
    segtree[node][1] = c[1];
}

int main(){
    long int N, Q, comando, i, t;
    cout << sizeof(0) << "  " << sizeof(0LL) << endl;
    while(scanf("%lld", &N) != EOF){
        long int lojas[N+1];
        *//*O vetor tem o menor e o maior valor respectivamente*//*
        long int segtree[(N+1)*4][2];
        for(long int cont = 0; cont < N; cont++){//recebe os precos
            long int aux;
            scanf("%ld", &aux);
            lojas[cont] = aux;
            update(lojas, segtree, cont, lojas[cont], 1, 0, N);
        }
        //build(lojas, segtree, 0, N, 1);
        scanf("%ld", &Q);
        for(int cont = 0; cont < Q; cont++){//recebe os comandos
            scanf("%ld %ld %ld", &comando, &i, &t);
            if(comando == 1){//alteracao de preco
                update(lojas, segtree, i-1, t, 1, 0, N);
            } else {//consulta
                long int *vetor = search(segtree, i-1, t, 1, 0, N);
                printf("%ld\n", vetor[1] - vetor[0]);
            }
        }
    }
    return 0;
}
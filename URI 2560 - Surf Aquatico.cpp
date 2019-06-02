#include <iostream>
#include <limits.h>
#include <stdio.h>
using namespace std;

int *join(int *a, int *b){
    int *c = new int[3];
    c[0] = (a[0]<b[0] ? a[0] : b[0]);
    c[1] = a[1] + b[1];
    c[2] = (a[2]>b[2] ? a[2] : b[2]);
    return c;
}

void build(int *input, int segtree[][3], int low, int high, int node){
    if(low + 1 == high){
        segtree[node][0] = segtree[node][1] = segtree[node][2] = input[low];
        return;
    }
    int mid = (low + high)/2;
    build(input, segtree, low, mid, 2 * node);
    build(input, segtree, mid, high, 2 * node + 1);
    int * c = join(segtree[2*node], segtree[2*node + 1]);
    segtree[node][0] = c[0];
    segtree[node][1] = c[1];
    segtree[node][2] = c[2];
}

int *search(int segtree[][3], int qlow, int qhigh, int node, int low, int high){
    if(qlow >= high || qhigh <= low){
        int* a = new int[3];
        a[0] = INT_MAX;
        a[1] = 0;
        a[2] = INT_MIN;
        return a;
    }
    if(qlow <= low  && qhigh >= high)
        return segtree[node];
    
    int mid = (low+high)/2;
    return join(search(segtree, qlow, qhigh, 2*node, low, mid),
                search(segtree, qlow, qhigh, 2*node+1, mid, high));
}

int main(){
    int N, B;
    long long int soma;
    while(scanf("%d%d", &N, &B) != EOF){
        int notas[N+1];
        soma = 0;
        /*O vetor tera o menor, soma e maior valor respectivamente*/
        int segtree[(N+1)*4][3];
        for(int cont = 0; cont < N; cont++){
            //int aux;
            cin >> notas[cont];
            /*scanf("%d", &aux);
            notas[cont] = aux;*/
        }
        build(notas, segtree, 0, N, 1);
        for(int cont = 0; cont < N-B+1; cont++){
            int * c = search(segtree, cont, cont+B, 1, 0, N);
            soma += c[1] - c[0] - c[2];
        }
        cout << soma << endl;
    }
    return 0;
}
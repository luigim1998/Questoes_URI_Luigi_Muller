#include <iostream>
#include <limits.h>
#include <stdio.h>
using namespace std;

typedef struct arv{
    long long int menor;
    long long int soma;
    long long int maior;
}Seg;

Seg join(Seg a, Seg b){
    Seg c;
    c.menor = (a.menor < b.menor ? a.menor : b.menor);
    c.soma = a.soma + b.soma;
    c.maior = (a.maior > b.maior ? a.maior : b.maior);
    return c;
}

void build(long long int *input, Seg *segtree, long long int low, long long int high, long long int node){
    if(low + 1 == high){
        segtree[node].maior = segtree[node].soma = segtree[node].menor = input[low];
        return;
    }
    long long int mid = (low + high)/2;
    build(input, segtree, low, mid, 2 * node);
    build(input, segtree, mid, high, 2 * node + 1);
    segtree[node] = join(segtree[2*node], segtree[2*node + 1]);
}

Seg search(Seg *segtree, long long int qlow, long long int qhigh, long long int node, long long int low, long long int high){
    if(qlow >= high || qhigh <= low){
        Seg a;
        a.menor = LONG_LONG_MAX;
        a.soma = 0;
        a.maior = LONG_LONG_MIN;
        return a;
    }
    if(qlow <= low  && qhigh >= high)
        return segtree[node];
    
    long long int mid = (low+high)/2;
    return join(search(segtree, qlow, qhigh, 2*node, low, mid),
                search(segtree, qlow, qhigh, 2*node+1, mid, high));
}

int main(){
    long long int N, B, soma;
    while(scanf("%lld %lld", &N, &B) != EOF){
        long long int * notas = new long long int[N+1];
        soma = 0;
        /*O vetor tera o menor, soma e maior valor respectivamente*/
        Seg *segtree = new Seg[(N + 1) * 4];
        //recebe as notas
        for(long long int cont = 0; cont < N; cont++){
            scanf("%lld", &notas[cont]);
        }
        build(notas, segtree, 0, N, 1);
        //soma as baterias
        for(long long int cont = 0; cont < N-B+1; cont++){
            Seg c = search(segtree, cont, cont+B, 1, 0, N);
            soma += c.soma - c.maior - c.menor;
        }
        printf("%lld\n", soma);
    }
    return 0;
}
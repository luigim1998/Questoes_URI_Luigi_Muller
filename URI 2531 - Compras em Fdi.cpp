#include <stdio.h>
#include <limits.h>

typedef struct arv{
    long long int menor;
    long long int maior;
}Seg;

Seg join(Seg a, Seg b){
    Seg c;
    c.menor = (a.menor<b.menor ? a.menor : b.menor);
    c.maior = (a.maior>b.maior ? a.maior : b.maior);
    return c;
}

void build(long long int *input, Seg * segtree, long long int low, long long int high, long long int node){//feito
    if(low + 1 == high){
        segtree[node].menor = segtree[node].maior = input[low];
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
        a.maior = LONG_LONG_MIN;
        return a;
    }
    if(qlow <= low  && qhigh >= high)
        return segtree[node];
    
    long long int mid = (low+high)/2;
    return join(search(segtree, qlow, qhigh, 2*node, low, mid),
                search(segtree, qlow, qhigh, 2*node+1, mid, high));
}

void update(long long int *input, Seg *segtree, long long int pos, long long int value, long long int node, long long int low, long long int high){
    if(low + 1 == high){
        input[pos] = segtree[node].menor = segtree[node].maior = value;
        return;
    }
    long long int mid = (low + high)/2;
    if(pos < mid)
        update(input, segtree, pos, value, 2*node, low, mid);
    else
        update(input, segtree, pos, value, 2*node+1, mid, high);
    segtree[node] = join(segtree[2*node], segtree[2*node+1]);
}

int main(){
    long long int N, Q, comando, i, t;
    
    while(scanf("%lld", &N) != EOF){
        long long int *lojas = new long long int[N];
        /*A struct tem o menor e o maior valor*/
        Seg *segtree = new Seg[(N+1)*4];
        for(long int cont = 0; cont < N; cont++){//recebe os precos
            scanf("%lld", &lojas[cont]);
        }
        build(lojas, segtree, 0, N, 1);
        scanf("%lld", &Q);
        for(int cont = 0; cont < Q; cont++){//recebe os comandos
            scanf("%lld %lld %lld", &comando, &i, &t);
            if(comando == 1){//alteracao de preco
                update(lojas, segtree, i-1, t, 1, 0, N);
            } else {//consulta
                Seg vetor = search(segtree, i-1, t, 1, 0, N);
                printf("%lld\n", vetor.maior - vetor.menor);
            }
        }
    }
    return 0;
}
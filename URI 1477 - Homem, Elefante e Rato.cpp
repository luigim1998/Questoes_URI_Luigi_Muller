#include <iostream>
#include <limits.h>
#include <stdlib.h>
using namespace std;

/**
 * Retorna a união de dois nos. O retorno muda de acordo com o propósito.
 * @param a
 * @param b
 * @return
 */
int *join(int a[], int b[]){//feito
    int * c = new int[3];
    for(int cont = 0; cont < 3; cont++)
        c[cont] = a[cont] + b[cont];
    return c;
}

void app(int *lazy, int **segtree, int node, int low, int high, int value){//feito
    lazy[node] += value;
    int i = 0;
    int aux = segtree[node][0];
    segtree[node][i] = segtree[node][(i+value)%3];
    i = (i+value)%3;
    segtree[node][i] = segtree[node][(i+value)%3];
    i = (i+value)%3;
    segtree[node][i] = aux;
}

void shift(int *lazy, int **segtree, int node, int low, int high){//feito
    int mid = (low + high)/2;
    if(lazy[node] != 0){
        app(lazy, segtree, 2 * node, low, mid, lazy[node]);
        app(lazy, segtree, 2 * node + 1, mid, high, lazy[node]);
    }
    lazy[node] = 0;
}

void build(int *input, int **segtree, int low, int high, int node){//feito
    if(low + 1 == high){
        segtree[node][0] = 1;
        segtree[node][1] = 0;
        segtree[node][2] = 0;
        return;
    }
    int mid = (low + high)/2;
    build(input, segtree, low, mid, 2 * node);
    build(input, segtree, mid, high, 2 * node + 1);
    segtree[node] = join(segtree[2*node], segtree[2*node + 1]);
}

int *search(int **segtree, int qlow, int qhigh, int low, int high, int pos){//feito
    if(qlow <= low  && qhigh >= high){
        return segtree[pos];
    }
    if(qlow >= high || qhigh <= low){
        int * a = new int[3];
        a[0] = a[1] = a[2] = 0;
        return a;
    }
    int mid = (low+high)/2;
    return join(search(segtree, qlow, qhigh, low, mid, 2*pos),
                search(segtree, qlow, qhigh, mid, high, 2*pos + 1));
}

void update(int *lazy, int **segtree, int value, int qlow, int qhigh, int node, int low, int high){//feito
    if(qlow >= high || qhigh <= low)
        return;
    if(qlow <= low  && qhigh >= high){
        app(lazy, segtree, node, low, high, value);
        return;
    }
    shift(lazy, segtree, node, low, high);
    int mid = (low + high)/2;
    update(lazy, segtree, value, qlow, qhigh, 2 * node, low, mid);
    update(lazy, segtree, value, qlow, qhigh, 2 * node + 1, mid, high);
    segtree[node] = join(segtree[2*node], segtree[2*node+1]);
}

int main(){
    int jogadores, comandos, a, b;
    int **segtree;
    int *lazy;
    
    char aux;
    while(cin >> jogadores >> comandos){
        segtree = new int*[(jogadores+1)*4];
        lazy    = new int[(jogadores+1)*4];
        for(int cont = 0; cont <= jogadores; cont++){ // inicializa o vetor de jogadores
            lazy[cont] = 0;
        }

        for(int cont = 0; cont < comandos; cont++){
            cin >> aux >> a >> b;
            if(aux == 'M'){
                update(lazy, segtree, 1, a, b+1, 1, 0, jogadores);
            } else { // aux == 'C'
                int * vetor = search( segtree, a, b+1, 0, jogadores, 1);
                cout << vetor[0] << " " << vetor[1] << " " << vetor[2] << endl;
            }
        }
        cout << endl;
    }
    return 0;
}
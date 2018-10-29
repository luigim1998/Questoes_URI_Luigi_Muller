#include <stdio.h>
#include <stdlib.h>

typedef struct fib{
    int res[50];
    int calls[50];
    int topo;
}Fibo;

void empilha(Fibo * f){
    f->calls[f->topo] = f->calls[f->topo-1] + f->calls[f->topo-2] + 1; //a função tem contar as chamadas de função e a própria chamada
    f->res[f->topo]   = f->res[f->topo-1]   + f->res[f->topo-2];
    f->topo++;
}

Fibo * iniciar(){
    Fibo * n = malloc(sizeof(Fibo));
    n->calls[0] = n->calls[1] = 1;
    n->res[0] = 0;
    n->res[1] = 1;
    n->topo = 2;
    return n;
}

int main(){
    int cont, casos, amostra;
    Fibo * fibo = iniciar();

    scanf("%d", &casos);

    for( ;casos>0; casos--){
        scanf("%d", &amostra);

        if(amostra >= fibo->topo){
            for(cont = fibo->topo; cont <= amostra; cont++){
                empilha(fibo);
                //printf("fib(%d) = %d calls = %d\n", cont, fibo->res[cont], fibo->calls[cont]);
            }
        }

        printf("fib(%d) = %d calls = %d\n", amostra, fibo->calls[amostra] - 1, fibo->res[amostra]);
    }
    return 0;
}

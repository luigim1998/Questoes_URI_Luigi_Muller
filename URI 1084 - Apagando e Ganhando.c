#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Pilha{
    char vet[100010];
    int topo;
}pilha;

typedef struct Fila{
    char vet[100010];
    int inicio;
    int fim;
}fila;

int main(){
    int N, D, cont, falta;
    pilha saida;
    fila entrada;

    saida.topo = entrada.inicio = 0;

    scanf("%d %d", &N, &D);

    while(N != 0 && D != 0){
        scanf("%s", entrada.vet);

        for(falta = N-D; falta > 0; falta--){
            saida.vet[saida.topo] = entrada.vet[entrada.inicio];
            for(cont = entrada.inicio + 1; cont <= N-falta; cont++){
                if(entrada.vet[cont] > saida.vet[saida.topo]){
                    saida.vet[saida.topo] = entrada.vet[cont];
                    entrada.inicio = cont;
                }
                if(saida.vet[saida.topo] == '9') break;
            }
            saida.topo++;
            entrada.inicio++;
        }
        for(cont = 0; cont < saida.topo; cont++){
            printf("%c", saida.vet[cont]);
        }
        printf("\n");
        scanf("%d %d", &N, &D);
        entrada.inicio = 0;
        saida.topo = 0;
    }
}




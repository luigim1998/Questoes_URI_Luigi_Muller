#include <stdio.h>
#include <stdlib.h>
#define TAM 60

typedef struct fila{
    int inicio;
    int fim;
    int tamanho;
    int vetor[TAM];
}Fila;

Fila * criar_fila(){
    Fila * f = malloc(sizeof(Fila));
    f->inicio = f->fim = f->tamanho = 0;
    return f;
}

int enfileirar(Fila * f, int v){
    if(!estaCheia(f) ){
        f->vetor[f->fim++] = v;
        f->tamanho++;
        if(f->fim == TAM){
                f->fim = 0;
        }
        return 1;
    }
    return 0;
}

int desenfileirar(Fila * f, int * v){
    if(!estaVazia(f) ){
        *v = f->vetor[f->inicio++];
        f->tamanho--;
        if(f->inicio == TAM){
            f->inicio = 0;
        }
        return 1;
    }
    return 0;
}

int estaCheia(Fila * f){
    return f->tamanho == TAM;
}

int estaVazia(Fila *f){
    return f->tamanho == 0;
}

void imprimir(Fila * fila, Fila * descarte){
    int cont;
    printf("Discarded cards:");
    if(descarte->tamanho == 1){
        printf(" %d", descarte->vetor[descarte->inicio]);
    }
    if(descarte->tamanho > 1){
        printf(" %d", descarte->vetor[descarte->inicio]);
        for(cont = descarte->inicio + 1; cont != descarte->fim; cont++){
            if(cont==TAM){
                cont = 0;
            }
            printf(", %d", descarte->vetor[cont]);
        }
    }
    printf("\nRemaining card:");
    if(fila->tamanho == 1){
        printf(" %d", fila->vetor[fila->inicio]);
    }
    if(fila->tamanho > 1){
        printf(" %d", fila->vetor[fila->inicio]);
        for(cont = fila->inicio + 1; cont != fila->fim; cont++){
            if(cont==TAM){
                cont = 0;
            }
            printf(", %d", fila->vetor[cont]);
        }
    }
    printf("\n");
}

int main(){
    int cont, tamanho, aux;
    Fila * fila_c = criar_fila();
    Fila * descarte = criar_fila();

    scanf("%d", &tamanho);

    while(tamanho != 0){
        fila_c->fim = fila_c->inicio = fila_c->tamanho = 0;
        descarte->fim = descarte->inicio = descarte->tamanho = 0;

        for(cont = 0; cont < tamanho; cont++){
            enfileirar(fila_c, cont+1);
        }

        while(fila_c->tamanho > 1){
            desenfileirar(fila_c, &aux);
            enfileirar(descarte, aux);
            desenfileirar(fila_c, &aux);
            enfileirar(fila_c, aux);
        }

        imprimir(fila_c, descarte);
        scanf("%d", &tamanho);
    }

    return 0;
}








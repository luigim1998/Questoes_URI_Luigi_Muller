#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no{
    char info;
    struct no *esq;
    struct no *dir;
}Nodo;

typedef struct arv_bin{
    Nodo * raiz;
}Arv_bin;

void remove_espacos(char * frase) {
    int cont, aux = 0;
    int tamanho = strlen(frase);
    for(cont = 0; cont < tamanho; cont++){
        if(frase[cont] != ' '){
            frase[aux++] = frase[cont];
        }
    }
    frase[aux] = '\0';
}

int main(){
    char entrada[210];
    int tamanho;

    while(scanf("%[\^n]s", entrada) != EOF){
        tamanho = strlen(entrada);
        remove_espacos(entrada);
    }
    return 0;
}


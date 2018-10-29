#include <stdio.h>
#include <string.h>

#define TAM 1010

typedef struct pilha{
    int topo;
    char mina[TAM];
    int total;
}Pilha;

int main(){
    int cont, cont2, tamString;
    char texto[TAM];
    Pilha diamantes;

    scanf("%d", &cont);

    for(; cont>0; cont--){
        diamantes.topo = diamantes.total = 0;

        scanf("%s", texto);
        tamString = strlen(texto);

        for(cont2 = 0; cont2 < tamString; cont2++){
            switch(texto[cont2]){
            case '<':
                diamantes.mina[diamantes.topo++] = '<';
                break;
            case'>':
                if (diamantes.topo != 0){
                    diamantes.topo--;
                    diamantes.total++;
                }
                break;
            }
        }
        printf("%d\n", diamantes.total);
    }
    return 0;
}

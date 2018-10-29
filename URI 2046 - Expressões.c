#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Pilha{
    char vet[100010];
    int topo;
}pilha;

typedef struct Entrada{
    char texto[100010];
    int tamanho;
}entrada;

pilha * criar_pilha(){
    pilha * n = (pilha*) malloc(sizeof(pilha));
    n->topo = 0;
    return n;
}

entrada * criar_entrada(){
    entrada * n = (entrada*) malloc(sizeof(entrada));
    return n;
}

void empilhar(pilha * p, char a){
    p->vet[p->topo++] = a;
}

void desempilhar(pilha * aux){
    aux->topo -= 2;
}

int main(){
    int casos, cont;
    pilha * aux = criar_pilha();
    entrada * ent = criar_entrada();

    scanf("%d", &casos);

    for(;casos > 0; casos--){
        scanf("%s", ent->texto);

        ent->tamanho = strlen(ent->texto);

        for(cont = 0; cont < ent->tamanho; cont++){
            empilhar(aux, ent->texto[cont]);
            if(aux->topo > 1){ //só analisa se tiver mais de dois itens
                if((aux->vet[aux->topo-2] == '(' && aux->vet[aux->topo-1] == ')') ||
                (aux->vet[aux->topo-2] == '[' && aux->vet[aux->topo-1] == ']') ||
                (aux->vet[aux->topo-2] == '{' && aux->vet[aux->topo-1] == '}')) {
                    desempilhar(aux);
                }
            }
            if(aux->topo > 0 && (aux->vet[0] == ')' || aux->vet[0] == ']' || aux->vet[0] == '}')){
            //não há chance de completar um ')', ']', '}' se ele estiver no inicio
                break;
            }
        }
        if(aux->topo > 0){
            printf("N\n");
        } else {
            printf("S\n");
        }
        aux->topo = 0;
    }
    return 0;
}

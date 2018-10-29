#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct texto{
    char str[1010];
    int topo;
}Texto;

Texto * criar_txt(){
    Texto * n = malloc(sizeof(Texto));
    n->topo = 0;
    return n;
}

void empilhar(Texto * aux, char a){
    aux->str[aux->topo++] = a;
}

void desempilhar(Texto * aux){
    aux->topo -= 2;
}

int main(){
    int cont; //1 para certo, 0 para errado
    Texto * tex = criar_txt();
    Texto * aux = criar_txt();

    while(scanf("%s", tex->str) != EOF){

        tex->topo = strlen(tex->str);

        for(cont = 0; tex->str[cont] != '\0'; cont++){

            if(tex->str[cont] == '(' || tex->str[cont] == ')'){

                empilhar(aux, tex->str[cont]); //empilha se for '(' ou ')'

                if(aux->topo > 1){ //só analisa se tiver mais de dois itens
                    if(aux->str[aux->topo-2] == '(' && aux->str[aux->topo-1] == ')'){
                        desempilhar(aux);
                    }
                }

                if(aux->topo > 0 && aux->str[0] == ')'){ //não há chance de completar um ')' se ele estiver no inicio
                    break;
                }
            }
        }
        if(aux->topo > 0){
            printf("incorrect\n");
        } else {
            printf("correct\n");
        }
        aux->topo = 0;
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

/* questão feita colaborativamente com Tarlison Sander Lima Brito
*/

typedef struct Pilha{
    int topo;
    int vet[1100];
}pilha;

pilha * criar_pilha(){
    pilha * n = (pilha*) malloc( sizeof(pilha) );
    n->topo = 0;
    return n;
}

void empilha(pilha * pil, int val){
    pil->vet[pil->topo++] = val;
}

void desempilha(pilha * pil){
    pil->topo--;
}

int main(){
    int cont, quant;
    pilha * estacao = criar_pilha();
    pilha * saida = criar_pilha();

    scanf("%d", &quant); //recebe a quantidade vagões
    while(quant != 0){
        scanf("%d", &saida->vet[0]); //analisa se já encerrou as aquisições daquela quantidade vagões
        while(saida->vet[0] != 0){
            for(cont = 1; cont < quant; cont++){
                scanf("%d", &saida->vet[cont]);
            } //recebe a requisição do primeiro vagao ao ultimo
            for(cont = 1; cont <= quant; cont++){
                if(cont < saida->vet[saida->topo]){ //se for menor então o valor está atrás do vagao atual
                    empilha(estacao, cont);
                } else if (cont == saida->vet[saida->topo]){ //se for igual então é só levar para a saida
                    saida->topo++;
                } else {//se for maior então o numero pode estar na estacao
                    if(estacao->topo > 0 && estacao->vet[estacao->topo-1] == saida->topo){
                        desempilha(estacao);//desempilhar
                        saida->topo++;
                    }
                }
            }
            for(cont = estacao->topo-1; cont >= 0; cont--){//caso sobre vagoes na estacao
                if(estacao->vet[cont] == saida->vet[saida->topo]){
                    saida->topo++;
                    desempilha(estacao);
                } else {
                    break;
                }
            }
            if(estacao->topo > 0){
                printf("No\n");
            } else {
                printf("Yes\n");
            }
            scanf("%d", &saida->vet[0]); //analisa se já encerrou as aquisições daquela quantidade vagões
            estacao->topo = 0;
            saida->topo = 0;
        }
        printf("\n");
        scanf("%d", &quant); //recebe a quantidade vagões
    }
    free(estacao);
    free(saida);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

/* questão feita colaborativamente com Tarlison Sander Lima Brito
*/

typedef struct Pilha{
    int aux;
    char vet[70];
}pilha;

pilha * criar_pilha(){
    pilha * n = (pilha*) malloc( sizeof(pilha) );
    n->aux = 0;
    return n;
}

void inserir(pilha * est, pilha * inst, char val){
    est->vet[est->aux++] = val;
    inst->vet[inst->aux++] = 'I';
}

void remover(pilha * est, pilha * inst, pilha * saida){
    est->aux--;
    saida->aux++;
    inst->vet[inst->aux++] = 'R';
}

void imprimir(pilha * inst, int val){
    int cont;
    for(cont = 0; cont < inst->aux; cont++){
        printf("%c", inst->vet[cont]);
    }
    if(val == 0){ // se for zero é impossivel organizar desse jeito
        printf(" Impossible\n");
    } else {
        printf("\n");
    }
}

int main(){
    int cont, cont2, quant;
    pilha * entrada = criar_pilha();
    pilha * saida = criar_pilha();
    pilha * estacao = criar_pilha();
    pilha * instrucao = criar_pilha();
    scanf("%d", &quant);
    while(quant != 0){
        for(cont = 0; cont < quant; cont++){//recebe a entrada
            scanf("%s", &entrada->vet[cont]);
        }

        for(cont = 0; cont < quant; cont++){//recebe a saida
            scanf("%s", &saida->vet[cont]);
        }

        for(cont = 0; cont < quant; cont++){
            if(entrada->vet[cont] == saida->vet[saida->aux]){//se o vagao da entrada é igual
                inserir(estacao, instrucao, entrada->vet[cont]);
                remover(estacao, instrucao, saida);
            } else {//se não for
                if(estacao->vet[estacao->aux-1] == saida->vet[saida->aux] && estacao->aux > 0){
                    //se o vagao da estação é igual e a estacao tem mais de um vagao
                    remover(estacao, instrucao, saida);
                } else {// se o vagao da estação não for igual
                    inserir(estacao, instrucao, entrada->vet[cont]);
                }
            }
        }
        for(cont = estacao->aux-1; cont >= 0; cont--){//procura os vagoes restantes na estação
            if(estacao->vet[cont] == saida->vet[saida->aux]){
                remover(estacao, instrucao, saida);
            } else {
                break;
            }
        }
        if(estacao->aux > 0){
            imprimir(instrucao, 0);
        } else {
            imprimir(instrucao, 1);
        }
        entrada->aux = 0;
        saida->aux = 0;
        estacao->aux = 0;
        instrucao->aux = 0;
        scanf("%d", &quant);
    }
    free(entrada);
    free(saida);
    free(estacao);
    free(instrucao);
    return 0;
}

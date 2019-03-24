#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reconstruir(char * prefixo, char * infixo, char * posfixo, int tamanho, int * indice){
    int posicao;
    if(tamanho == 0) return; //n�o h� string, ent�o ele n�o executa
    posfixo[*indice] = prefixo[0];
    (*indice)--; //ele decrementa j� que aquela posi��o j� foi preenchida
    if(tamanho == 1) return; //s� h� um caractere, posfixo recebe o valor e para a fun��o
    for(posicao = 0; posicao < tamanho; posicao++){ //busca a posi��o que a raiz est� em infixo
        if(infixo[posicao] == prefixo[0]){
            break;
        }
    }
    /*Ex:           r                      r
                    DBACEGF             ABCDEFG
                        |                   |
    O prefixo recebe esse valor j� que ele est� na frente da raiz e da sae(sub-�rvore esquerda) e o infixo muda porque a raiz est� depois dela*/
    reconstruir(prefixo+posicao+1, infixo+posicao+1, posfixo, tamanho-posicao-1, indice);//sad
    /*Ex:           r                      r
                    DBACEGF             ABCDEFG
                     |                  |
    O prefixo incrementa porque ele pula a raiz e o infixo n�o muda porque a raiz est� depois*/
    reconstruir(prefixo+1, infixo, posfixo, posicao, indice);//sae
}

void chamada(char * prefixo, char * infixo, char * posfixo, int tamanho){
    int * aux = new int;
    *aux = tamanho - 1;
    reconstruir(prefixo, infixo, posfixo, tamanho, aux);
}

int main(){
    char * prefixo = new char[30];
    char * infixo  = new char[30];
    char * posfixo = new char[30];
    char raiz;
    int tamanho;

    while(scanf("%s %s", prefixo, infixo) != EOF){
        tamanho = strlen(prefixo);
        posfixo[tamanho] = '\0';
        chamada(prefixo, infixo, posfixo, tamanho);
        printf("%s\n", posfixo);
    }
}

/*entradas para testar:
DBACEGF ABCDEFG ACBFGED
BCAD CBAD CDAB*/

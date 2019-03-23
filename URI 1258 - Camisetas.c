#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Esse trabalho foi feito por:
    Luigi Muller Sousa Linhares
    Tarlison Sander Lima Brito*/

typedef struct Usuario{
    char nome[50];
    char cor[10];
    char tamanho;
} usuario;

void organiza_nome(int inicio, int fim){
    if((fim - inicio) <= 1){//sai se houver só um ou nenhum elemento
        return;
    }
    int contador, i;
    usuario aux;
    for (contador = inicio + 1; contador < fim; contador++) {
        for (i = inicio; i < fim - 1; i++) {
            if (strcmp(informacoes[i].nome, informacoes[i+1].nome) == 1) {
                aux = informacoes[i];
                informacoes[i] = informacoes[i + 1];
                informacoes[i + 1] = aux;
            }
        }
    }
    /*for(contador = inicio; contador < fim; contador++){
        printf("N.Nome: <%15s> Cor: <%8s> Tam: <%c>\n",informacoes[contador].nome, informacoes[contador].cor, informacoes[contador].tamanho);
    }*/
}

void organiza_tamanho(int inicio, int fim){
    if((fim - inicio) <= 1){//sai se houver só um ou nenhum elemento
        return;
    }

    int cont, inicioP = inicio, inicioM = 0, inicioG = 0;

    for(cont = inicio; cont < fim; cont++){
        if(informacoes[cont].tamanho == 'P') inicioM++;
        else if(informacoes[cont].tamanho == 'M') inicioG++;
    }
    inicioM += inicioP;
    inicioG += inicioM;
    //printf("P: %d M: %d G: %d\n", inicioP, inicioM, inicioG);

    for(cont = inicio; cont < fim; cont++){
        if(informacoes[cont].tamanho == 'P')      auxiliar[inicioP++] = informacoes[cont];
        else if(informacoes[cont].tamanho == 'M') auxiliar[inicioM++] = informacoes[cont];
        else if(informacoes[cont].tamanho == 'G') auxiliar[inicioG++] = informacoes[cont];
    }
    for(cont = inicio; cont < fim; cont++){
        informacoes[cont] = auxiliar[cont];
        //printf("T.Nome: <%15s> Cor: <%8s> Tam: <%c>\n",informacoes[cont].nome, informacoes[cont].cor, informacoes[cont].tamanho);
    }
    organiza_nome(inicio, inicioP);//tamanho P
    organiza_nome(inicioP, inicioM);//tamanho M
    organiza_nome(inicioM, inicioG);//tamanho G
}

void organiza_cor(usuario * informacoes, int tamanho){
    int inicioBranco = 0, inicioVermelho = 0, cont;
    /*inicioBranco e inicioVermelho vão guardar as posições
    iniciais de onde cada cor aparece no vetor ordenado*/

    for(cont = 0; cont < tamanho; cont++){
        if(informacoes[cont].cor[0] == 'b'){//se for b é branco
            inicioVermelho++;
        }
    }
    for(cont = 0; cont < tamanho; cont++){
        if(informacoes[cont].cor[0] == 'b'){//se for b é branco
            auxiliar[inicioBranco++] = informacoes[cont];
        } else {
            auxiliar[inicioVermelho++]   = informacoes[cont];
        }
    }
    //printf("B: %d V: %d\n", inicioBranco, inicioVermelho);
    for(cont = 0; cont < tamanho; cont++){
        informacoes[cont] = auxiliar[cont];
        //printf("C.Nome: <%15s> Cor: <%8s> Tam: <%c>\n",informacoes[cont].nome, informacoes[cont].cor, informacoes[cont].tamanho);
    }
    organiza_tamanho(0, inicioBranco);
    organiza_tamanho(inicioBranco, tamanho);
}

int main(){
    usuario * informacoes = (usuario*) malloc(60*sizeof(usuario));
    int casos, cont;
    char aux[3];

    scanf("%d", &casos);
    setbuf(stdin, NULL);
    while(casos != 0){

        for(cont = 0; cont < casos; cont++){
            scanf("%[^\n]s", informacoes[cont]->nome);
            setbuf(stdin, NULL);
            scanf("%s %s", informacoes[cont]->cor, aux);
            informacoes[cont].tamanho = aux[0];//tive que usar essa gambiarra
            setbuf(stdin, NULL);

            //printf("M.Nome: <%15s> Cor: <%8s> Tam: <%c>\n",informacoes[cont].nome, informacoes[cont].cor, informacoes[cont].tamanho);
        }
        organiza_cor(casos);

        for(cont = 0; cont < casos; cont++){
            printf("%s %c %s\n", informacoes[cont].cor, informacoes[cont].tamanho, informacoes[cont].nome);
        }
        scanf("%d", &casos);
        setbuf(stdin, NULL);
        if(casos != 0){
            printf("\n");
        }
    }
}

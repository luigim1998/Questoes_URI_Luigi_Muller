#include <stdio.h>

int main(){
    int tiras, area, cont, aux;
    int soma = 0; //soma das áreas
    int maior = 0; //guardará o tamanho da maior tira
    int quant_tiras[10010];//guarda a quantidade que uma tira de C tamanho existe
    scanf("%d %d", &tiras, &area);
    while(tiras != 0 && area != 0){
        for(cont = 0; cont < 10010; coont++) quant_tiras[cont] = 0;//zera a lista
        for(cont = 0; cont < tiras; cont++){//recebe os valores
            scanf("%d", &aux);
            quant_tiras[aux]++;//incrementa no vetor na posição comprimento
            if(aux > maior) maior = aux;
        }

        maior = 0;
        soma = 0;
        scanf("%d %d", &tiras, &area);
    }
    return 0;
}

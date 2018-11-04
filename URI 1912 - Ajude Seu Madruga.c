#include <stdio.h>

/*Trablho feito por:
Luigi Muller Sousa Linhares
Tarlison Sander Lima Brito*/

int main(){
    int tiras, area, cont, auxInt;
    int soma = 0; //soma das áreas
    int maior = 0; //guardará o tamanho da maior tira
    int quant_tiras[10010];//guarda a quantidade que uma tira de C tamanho existe
    double auxDouble;
    scanf("%d %d", &tiras, &area);
    while(tiras != 0 && area != 0){
        for(cont = 0; cont < 10010; cont++) quant_tiras[cont] = 0;//zera a lista
        for(cont = 0; cont < tiras; cont++){//recebe os valores
            scanf("%d", &auxInt);
            quant_tiras[auxInt]++;//incrementa no vetor na posição comprimento
            if(auxInt > maior) maior = auxInt;
        }
        //for(cont = 0; cont <= maior; cont++) printf("vet[%d]=%d ",cont, quant_tiras[cont]);//apague depois
        for(cont = maior-1; cont > 0; cont--) quant_tiras[cont] += quant_tiras[cont+1];
        //cada vetor será a quantidade de tiras que há naquela secção horizontal
        //for(cont = 0; cont <= maior; cont++) printf("vet[%d]=%d ",cont, quant_tiras[cont]);//apague depois
        cont = maior;
        while(soma + quant_tiras[cont] <= area && cont > 0){
            soma += quant_tiras[cont];
            cont--;
        }
        //printf("\n corte em %d, soma = %d\n", cont, soma);

        if(soma == area){
                if(cont == 0) printf(":D\n");
                else printf("%.4lf\n", (double) cont);
        } else {
            if(cont == 0){
                printf("-.-\n");
            } else {
                auxDouble = (double) (area - soma)/quant_tiras[cont];
                printf("%.4lf\n",cont - auxDouble);
            }
        }
        maior = 0;
        soma = 0;
        scanf("%d %d", &tiras, &area);
    }
    return 0;
}

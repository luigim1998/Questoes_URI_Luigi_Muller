#include <stdio.h>
#include <stdlib.h>

void radix_sort(int * entrada, int * saida, int tamanho) {
    int i, *b, exp = 1;
    int maior = saida[0];
    b = (int *)calloc(tamanho, sizeof(int));
    for (i = 0; i < tamanho; i++) {
        saida[i] = entrada[i];//insere no vetor saida
        if (entrada[i] > maior)
    	    maior = entrada[i];
    }
    while (maior/exp > 0) {
        int bucket[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    	for (i = 0; i < tamanho; i++)
    	    bucket[(saida[i] / exp) % 10]++;
    	for (i = 1; i < 10; i++)
    	    bucket[i] += bucket[i - 1];
    	for (i = tamanho - 1; i >= 0; i--)
    	    b[--bucket[(saida[i] / exp) % 10]] = saida[i];
    	for (i = 0; i < tamanho; i++)
    	    saida[i] = b[i];
    	exp *= 10;
    }
    free(b);
}

int main(){
    int quant, cont, vetor[1010];
    while(scanf("%d", &quant) != EOF){
        for(cont = 0; cont < quant; cont++){
            scanf("%d", &vetor[cont]);
        }
    }
}

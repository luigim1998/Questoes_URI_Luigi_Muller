#include <stdio.h>

/*Componetes:
    Luigi Muller Sousa Linhares
    Tarlison Sander Lima Brito*/

void radix_sort(int entrada[], int tamanho) {
    int i, b[1010], exp = 1;
    int maior = entrada[0];
    for (i = 0; i < tamanho; i++) {
        if (entrada[i] > maior)
    	    maior = entrada[i];
    }
    while (maior/exp > 0) {
        int bucket[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    	for (i = 0; i < tamanho; i++)
    	    bucket[(entrada[i] / exp) % 10]++;
    	for (i = 1; i < 10; i++)
    	    bucket[i] += bucket[i - 1];
    	for (i = tamanho - 1; i >= 0; i--)
    	    b[--bucket[(entrada[i] / exp) % 10]] = entrada[i];
    	for (i = 0; i < tamanho; i++)
    	    entrada[i] = b[i];
    	exp *= 10;
    }
}

int main(){
    int quant, cont, vetor[1010];
    while(scanf("%d", &quant) != EOF){
        for(cont = 0; cont < quant; cont++){//recebe os valores
            scanf("%d", &vetor[cont]);
        }
        radix_sort(vetor, quant);
        for(cont = 0; cont < quant; cont++){
            printf("%04d\n", vetor[cont]);
        }
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*Trabalho feito por:
    Luigi Muller Sousa Linhares
    Tarlison Sander Lima Brito*/

void bubble_sort(char** entrada, int tamanho){
    int contador, i;
    char * aux;
    for (contador = 0; contador < tamanho; contador++) {
        for (i = 0; i < tamanho - 1; i++) {
            if (strlen(entrada[i]) < strlen(entrada[i+1])) {
                aux = entrada[i];
                entrada[i] = entrada[i + 1];
                entrada[i + 1] = aux;
            }
        }
    }
}

int main(){
    int cont, aux, linha, coluna, casos, tamanhoString;
    char frase[2600];
    char ** matriz = (char**) malloc( 55*sizeof(char*) );

    for(cont = 0; cont < 55; cont++){ //aloca dinamicamente 55 caracteres
        matriz[cont] = (char*) malloc( 55*sizeof(char) );
    }

    scanf("%d", &casos);
    setbuf(stdin, NULL);

    for( ; casos > 0; casos--){

        scanf("%[^\n]s", frase);
        setbuf(stdin, NULL);
        //printf("%s\n", frase);
        tamanhoString = strlen(frase);
        linha = coluna = 0;

        for(cont = 0; cont <= tamanhoString; cont++){
            if(isalnum(frase[cont])){
                matriz[linha][coluna++] = frase[cont];
            } else {
                matriz[linha++][coluna] = '\0';
                coluna = 0;
            }
        }
        /*for(cont = 0;  cont < linha; cont++){
            printf("<%s>\n", matriz[cont]);
        }printf("\n");*/

        bubble_sort(matriz, linha);

        printf("%s", matriz[0]);
        for(cont = 1;  cont < linha; cont++){
            printf(" %s", matriz[cont]);
        }
        printf("\n");
    }
}

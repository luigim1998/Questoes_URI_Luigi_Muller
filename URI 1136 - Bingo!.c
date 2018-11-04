#include <stdio.h>

int main(){
    int N = 1, B = 1, cont, aux;
    char bolas[95], chances[95], encontrado;

    scanf("%d%d", &N, &B);

    while (N != 0 && B != 0){
        chances[0] = 'S';
        bolas[0] = 'N';

        for (cont = 1; cont <= 90; cont++){
            bolas[cont] = 'N';
            chances[cont] = 'N';
        }

        for (cont = 1; cont <= B; cont++){
            scanf("%d", &aux);
            bolas[aux] = 'S';
        }

        for(cont = N; cont > 0; cont--){
            if (chances[cont] != 'S'){
                for ( aux=0; cont+aux <= N && aux<cont; aux++){
                    if(bolas[cont+aux] == 'S' && bolas[aux] == 'S'){
                        chances[cont] = 'S';
                        encontrado = 'S';
                        //printf("%d %d %s\n", cont, aux, chances);
                    }
                }
                if (chances[cont]!='S'){
                    encontrado = 'N';
                    break;
                }
            }
        }
        if (encontrado == 'N'){
            printf("N\n");
        } else {
            printf("Y\n");
        }
        scanf("%d%d", &N, &B);
    }
	return 0;
}

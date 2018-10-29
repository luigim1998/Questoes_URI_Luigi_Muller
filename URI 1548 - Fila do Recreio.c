#include <stdio.h>

int main(){
    int entrada[1000], saida[1000], casos, alunos, cont, cont2, aux, total;
    scanf("%d", &casos);

    for(; casos > 0; casos--){
        total = 0;
        scanf("%d", &alunos);
        for(cont = 0; cont < alunos; cont++){
            scanf("%d", &entrada[cont]);
            saida[cont] = entrada[cont];
        }
        for(cont = 0; cont < alunos - 1; cont++){
            for(cont2 = cont+1; cont2 < alunos; cont2++){
                if(saida[cont] < saida[cont2]){
                    aux = saida[cont];
                    saida[cont] = saida[cont2];
                    saida[cont2] = aux;
                }
            }
        }
        /*for(cont = 0; cont < alunos; cont++){
            printf("[%d][%d]\n",entrada[cont], saida[cont]);
        }*/
        for(cont = 0; cont < alunos; cont++){
            if (saida[cont] == entrada[cont]){
                total++;
            }
        }
        printf("%d\n", total);
    }
    return 0;
}








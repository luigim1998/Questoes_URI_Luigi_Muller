#include <stdio.h>

int main(){
    int cont, time_a, time_b;
    char oitavas[16] = {'A','B','C','D','E',
                        'F','G','H','I','J',
                        'K','L','M','N','O','P'};
    char quartas[8], semifinal[4], jogo_final[2];

    for(cont = 0; cont < 8; cont++){
        scanf("%d%d", &time_a, &time_b);
        if(time_a > time_b){
            quartas[cont] = oitavas[cont*2 + 0];
        } else {
            quartas[cont] = oitavas[cont*2 + 1];
        }
    }
    for(cont = 0; cont < 4; cont++){
        scanf("%d%d", &time_a, &time_b);
        if(time_a > time_b){
            semifinal[cont] = quartas[cont*2 + 0];
        } else {
            semifinal[cont] = quartas[cont*2 + 1];
        }
    }
    for(cont = 0; cont < 2; cont++){
        scanf("%d%d", &time_a, &time_b);
        if(time_a > time_b){
            jogo_final[cont] = semifinal[cont*2 + 0];
        } else {
            jogo_final[cont] = semifinal[cont*2 + 1];
        }
    }
    scanf("%d%d", &time_a, &time_b);
    if(time_a > time_b){
        printf("%c\n", jogo_final[0]);
    } else {
        printf("%c\n", jogo_final[1]);
    }
    return 0;
}

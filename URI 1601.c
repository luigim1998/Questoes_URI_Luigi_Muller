#include <stdio.h>

int main(){
    int diaI, horaI, minutoI, segundoI;
    int diaF, horaF, minutoF, segundoF;
    int dia, hora, minuto, segundo;
    char s[5];
    scanf("%s %d", s, &diaI);
    scanf("%d %s %d %s %d", &horaI, s, &minutoI, s, &segundoI);
    scanf("%s %d", s, &diaF);
    scanf("%d %s %d %s %d", &horaF, s, &minutoF, s, &segundoF);

    printf("%d %d %d %d %d %d %d %d \n", diaI, horaI, minutoI, segundoI, diaF, horaF, minutoF, segundoF);


        if (minutoF < minutoI){
            hora--;
            minuto = minutoF - minutoI + 60;
        } else {
            minuto = minutoF - minutoI;
        }
        if (segundoF < segundoI){
            minuto--;
            segundo = segundoF - segundoI + 60;
        } else {
            segundo = segundoF - segundoI;
        }
    printf("%d %d %d %d", dia, hora, minuto, segundo);
    return 0;
}
//questao 1061

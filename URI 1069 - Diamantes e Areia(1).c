#include <stdio.h>
#include <string.h>

int main(){
    int total = 0, incom = 0, cont, cont2, tamTexto;
    char texto[1010];

    scanf("%d", &cont);
    for(; cont>0; cont--){
        scanf("%s", texto);
        tamTexto = strlen(texto);

        for(cont2 = 0; cont2 < tamTexto; cont2++){
            if(texto[cont2] == '<'){
                incom++;
            }
            if(texto[cont2] == '>'){
                if(incom > 0){
                    incom--;
                    total++;
                }
            }
            //printf("%d\n", total);
        }
        printf("%d\n", total);
        total = incom = 0;
    }
    return 0;
}

#include <stdio.h>

int main(){
    char texto[53], saida[200], ital, neg;
    int cont, cont_s;

    while( scanf("%[^\n]s", texto) != EOF){
        for(cont = 0, cont_s = 0, ital = 'i', neg = 'i'; texto[cont] != '\0'; cont++){
            if(texto[cont] == '_'){
                if(ital == 'i'){
                    saida[cont_s++] = '<';
                    saida[cont_s++] = 'i';
                    saida[cont_s++] = '>';
                } else {
                    saida[cont_s++] = '<';
                    saida[cont_s++] = '/';
                    saida[cont_s++] = 'i';
                    saida[cont_s++] = '>';
                }
                ital = (ital == 'i') ? 'f' : 'i' ;
            } else if (texto[cont] == '*'){
                if(neg == 'i'){
                    saida[cont_s++] = '<';
                    saida[cont_s++] = 'b';
                    saida[cont_s++] = '>';
                } else {
                    saida[cont_s++] = '<';
                    saida[cont_s++] = '/';
                    saida[cont_s++] = 'b';
                    saida[cont_s++] = '>';
                }
                neg = (neg == 'i') ? 'f' : 'i' ;
            } else {
                saida[cont_s++] = texto[cont];
            }
        }
        saida[cont_s] = '\0';
        printf("%s\n", saida);
        }
    return 0;
}

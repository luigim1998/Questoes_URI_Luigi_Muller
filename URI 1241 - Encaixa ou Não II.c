#include <stdio.h>
#include <string.h>

int main(){ //b tem que corrresponder com a
    int n, num_a, num_b, cont;
    char a[1003], b[1003];
    scanf("%d", &n);
    for ( ; n > 0; n--){
        scanf("%s%s", a, b);
        num_a = strlen(a);
        num_b = strlen(b);
        if(num_a < num_b){
            printf("nao encaixa\n");
        } else {
            for(cont = 0; cont < num_b; cont++){
                if (a[num_a-cont] != b[num_b-cont]){
                    printf("nao encaixa\n");
                    break;
                }
            }
            printf("encaixa\n");
        }
    }
    return 0;
}

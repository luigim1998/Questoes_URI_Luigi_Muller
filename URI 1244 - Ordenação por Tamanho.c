#include <stdio.h>
#include <string.h>

int main(){
    int casos, l, c;
    char ord[50][55];
    scanf("%d", &casos); setbuf(stdin, NULL);
    for(casos = casos;casos > 0; casos--){
        c = 0;
        l = 0;
        scanf("%c", ord[l][c]);
        do{
            if(ord[l][c] == ' '){
                ord[l][c] = '\0';
                l++; c = 0;
            } else {
                c++;2
            }
            scanf("%c", ord[l][c]);
        } while(ord[l][c]!='\n');
        ord[l][c] = '\0';
        for (c = 0; c < l; c++){
            printf("%s ", ord[c]);
        }
    }
}

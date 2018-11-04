#include<stdio.h>
int main()
{
    int a,b,c,d,aux,aux2;
    scanf("%d %d %d %d",&a,&b,&c,&d);
    aux=a*b;
    if(aux>c)
    {
        aux2=aux/c;
    }
    else{
        aux2=c/aux;
    }
    if (d%a==0)
    {
        printf("%d\n",aux2+1);
    }
    else{
        printf("-1\n");
    }
    return 0;
}

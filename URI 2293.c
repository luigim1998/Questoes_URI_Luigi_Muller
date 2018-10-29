#include <stdio.h>

int main()
{
    int m,n;
    scanf("%d %d",&n,&m);
    int mat[n][m],i,j,aux=0,aux2=0,vet1[100],vet2[100], maior = 0;
    for (i=0;i<n;i++)
    {
        for (j=0;j<m;j++)
        {
            scanf("%d",&mat[i][j]);
            aux+=mat[i][j];
        }
        if (aux>maior){
            maior = aux;
        }
        aux = 0;
    }
    for (j=0;j<m;j++)
    {
        for(i=0;i<n;i++)
        {
            aux+=mat[i][j];
        }
        if (aux>maior){
            maior = aux;
        }
        aux = 0;
    }
    printf("%d\n",maior);
    return 0;
}

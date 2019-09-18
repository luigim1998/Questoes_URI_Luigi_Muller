#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int dias, soma;
	while(scanf("%d", &dias) != EOF){
		soma = 0;
		int valores[dias];
		int cust_dia;
		int maior_lucro = 0;
		scanf("%d", &cust_dia);
		
		for(int cont = 0; cont < dias; cont++){
			int aux;
			scanf("%d", &aux);
			valores[cont] = aux;
		}
		
		for(int cont = 0; cont < dias; cont++){
			if(valores[cont] <= cust_dia){
				continue;
			}
			
			for(int cont2 = cont; cont2 < dias; cont2++){
				soma += valores[cont2] - cust_dia;
				
				if(soma > maior_lucro){
					maior_lucro = soma;
				}
				//printf("soma = %d, maior = %d\n", soma, maior_lucro);
			}
			soma = 0;
		}
		
		printf("%d\n", maior_lucro);
	}
	return 0;
}

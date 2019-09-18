#include <bits/stdc++.h>

int main() {
	char frase[6000];
	char comp;
	while(scanf(" %[^\n]s", frase) != EOF){
		comp = toupper( frase[0] );
		int tamanho = strlen(frase);
		int k = 1;
		int alits = 0;
		
		for(int i = 0; i < tamanho; i++){
			if(frase[i] == '\0'){
				break;
			} else if(frase[i] == ' '){
				//printf("fodase %d %d\n", toupper(comp) == toupper(frase[i+1]),k);
				
				if( (toupper(comp) == toupper(frase[i+1])) && k == 1){
					//printf("fodase\n");
					alits++;
					k = 0;
				} else {
					if((toupper(comp) != toupper(frase[i+1]))){
						comp = frase[i+1];
						k = 1;
					}
				}
			}
		}
		printf("%d\n", alits);
	}
	return 0;
}

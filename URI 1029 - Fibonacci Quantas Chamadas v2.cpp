#include <stdio.h>

int main(){
	int calls[40];
	int result[40];
	int num_calls;

	calls[0] = calls[1] = 0;
	result[0] = 0; result[1] = 1;
	
	for(int i = 2; i < 40; i++){
		calls[i] = calls[i-1] + calls[i-2] + 2;
		result[i] = result[i-1] + result[i-2];
	}

	scanf("%d", &num_calls);
	for(int i = 0; i < num_calls; i++){
		int entrada;
		scanf("%d", &entrada);
		printf("fib(%d) = %d calls = %d\n", entrada, calls[entrada], result[entrada]);
	}
}
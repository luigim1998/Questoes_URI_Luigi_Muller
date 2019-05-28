#include <iostream>
#include <limits.h>
#include <stdlib.h>
using namespace std;

typedef struct pt{
    int homem;
    int elefante;
    int rato;
}pontos;

int main(){
    int jogadores, comandos, a, b;
    
    char aux;
    while(cin >> jogadores >> comandos){
        
        for(int cont = 0; cont <= jogadores; cont++){ // inicializa o vetor de jogadores
        
        }

        for(int cont = 0; cont < comandos; cont++){
            cin >> aux >> a >> b;
            if(aux == 'M'){

            } else { // aux == 'C'
                
            }
        }
    }
    return 0;
}
#include <iostream>
#include <queue>
using namespace std;

int main(){
    int casos;      // número de casos de teste
    int endereco;   // número de endereços-base que ele terá em cada caso
    int quantidade; // quantidade de valores a ser inseridos no caso
    int aux;
    cin >> casos;
    while(casos > 0){
        cin >> endereco;
        cin >> quantidade;
        // crio um vetor de filas para os inteiros que entrarão na tabela
        queue<int> tabela[endereco];
        // insere os valores na tabela no índice x mod endereco
        for(int cont = 0; cont < quantidade; cont++){
            cin >> aux;
            tabela[aux%endereco].push(aux);
        }
        // imprime cada linha da tabela
        for(int cont = 0; cont < endereco; cont++){
            cout << cont << " -> ";
            while(!tabela[cont].empty()){
                cout << tabela[cont].front() << " -> ";
                tabela[cont].pop();
            }
            cout << "\\" << endl;
        }
        casos--;
        //se não for zero então separa com uma nova linha o caso
        if(casos != 0){
            cout << endl;
        }
    }
    return 0;
}
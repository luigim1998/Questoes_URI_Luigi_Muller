#include <iostream>
#include <string>
using namespace std;

typedef struct no{
    char info;
    struct no *esq;
    struct no *dir;
}Nodo;

typedef struct arv_bin{
    Nodo * raiz;
}Arv_bin;

string remove_espacos(string entrada) {
    string frase;
    int cont, aux = 0;
    int tamanho = entrada.length();
    for(cont = 0; cont < entrada.length(); cont++){
        if(entrada[cont] != ' '){
            frase.push_back(entrada[cont]);
        }
    }
    return frase;
}

Nodo * cria_nodo(string entrada, int inicio, int fim){
    int cont, cont_parent=0, separador;
    char carac = ' ';
    char testinho;
    Nodo * node = new Nodo;
    if(inicio==fim){
        node->dir = node->esq = NULL;
        node->info = entrada[inicio];
    } else {
        if(entrada[inicio] == '(' && entrada[fim] == ')'){
            node = cria_nodo(entrada, inicio+1, fim-1);
        } else {
            for(cont = inicio; cont <= fim; cont++){
                testinho = entrada[cont];
                if(entrada[cont] == '('){
                    cont_parent++;
                } else if(entrada[cont] == ')'){
                    cont_parent--;
                } else if(entrada[cont] == '+' || entrada[cont] == '-'){
                    if(cont_parent == 0){
                        separador = cont;
                        carac = entrada[cont];
                    }
                } else if(entrada[cont] == '/' || entrada[cont] == '*'){
                    if(cont_parent == 0 && (carac != '+' && carac != '-')){
                        separador = cont;
                        carac = entrada[cont];
                    }
                }
            }
            node->info = carac;
            node->esq = cria_nodo(entrada, inicio, separador-1);
            node->dir = cria_nodo(entrada, separador+1, fim);
        }
    }
    return node;
}

int main(){
    string entrada;
    Arv_bin * arv = new Arv_bin;

    getline(cin, entrada);
    do{
        entrada = remove_espacos(entrada);
        cout << entrada << endl;
        arv->raiz = cria_nodo(entrada, 0, entrada.length()-1);
        getline(cin, entrada);
    }while(!cin.eof());
    return 0;
}

/*
4 * a - ( 6 + b ) + 8 / ( 9 - 7 )
a + b
( a + b * c ) * a - 4 * 5 - 6 + 1 + c * 3
*/
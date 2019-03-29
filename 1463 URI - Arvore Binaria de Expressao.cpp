#include <iostream>
#include <string>
#include <queue>
using namespace std;

typedef struct no{
    char info;
    struct no *esq;
    struct no *dir;
}Nodo;

typedef struct arv_bin{
    Nodo * raiz;
}Arv_bin;

/**
 * Recebe uma string e tira os espaços dela.
 * @param entrada
 * @return Retorna a string sem os espaços.
 */
string remove_espacos(string entrada) {
    string frase;
    int cont, aux = 0;
    for(cont = 0; cont < entrada.length(); cont++){
        if(entrada[cont] != ' '){
            frase.push_back(entrada[cont]);
        }
    }
    return frase;
}
/**
 * Recebe uma string da expresão e gera uma árvore de expressão aritmética.
 * @param entrada
 * @param inicio início da string a ser trabalhado.
 * @param fim índice fim da string a ser trabalhado esse valor equivale ao último caractere e será incluído.
 * @return Nodo raiz da árvore.
 */
Nodo * cria_nodo(string entrada, int inicio, int fim){
    int cont = 0, cont_parent=0, separador = 0;
    char carac = ' ';
    Nodo * node = (Nodo *) malloc(sizeof(Nodo));
    if(inicio==fim){
        node->dir = NULL;
        node->esq = NULL;
        node->info = entrada[inicio];
    } else {
        if((entrada[inicio] == '(') && (entrada[fim] == ')')){
            node = cria_nodo(entrada, inicio+1, fim-1);
        } else {
            for(cont = inicio; cont <= fim; cont++){
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

/**
 * Imprime os níveis.
 * @param fila fila com os nodos do nível anterior.
 * @param nivel_atual
 */
void imprime_linha(queue <Nodo*>fila, int nivel_atual){
    queue<Nodo*>aux;
    if(fila.empty()){
        return;
    } else {
        cout << "Nivel " << nivel_atual << ": ";
        while(!fila.empty()){
            cout << fila.front()->info;
            if(fila.front()->esq != NULL){
                aux.push(fila.front()->esq);
            }
            if(fila.front()->dir != NULL){
                aux.push(fila.front()->dir);
            }
            fila.pop();
        }
        cout << endl;
        imprime_linha(aux, nivel_atual+1);
    }
}

/**
 * Imprime a árvore.
 * @param arv Árvore.
 */
void imprime_arv(Arv_bin * arv){
    queue <Nodo*> aux;
    aux.push(arv->raiz);
    imprime_linha(aux, 0);
}

int main(){
    string entrada;
    Arv_bin * arv = new Arv_bin;

    getline(cin, entrada);
    do{
        entrada = remove_espacos(entrada);
        cout << entrada << endl;
        arv->raiz = cria_nodo(entrada, 0, entrada.length()-1);
        imprime_arv(arv);
        getline(cin, entrada);
        if(!cin.eof()) cout << endl;
    }while(!cin.eof());
    return 0;
}

/*
4 * a - ( 6 + b ) + 8 / ( 9 - 7 )
a + b
( a + b * c ) * a - 4 * 5 - 6 + 1 + c * 3
*/
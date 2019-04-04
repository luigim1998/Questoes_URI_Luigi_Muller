#include <string>
#include <iostream>
using namespace std;

typedef struct no{
    char info;
    struct no *esq;
    struct no *dir;
}Nodo;

typedef struct arv_bin{
    Nodo* raiz;
}Arv_bin;

/**
 * Cria um árvore.
 * @return Ponteiro da árvore.
 */
Arv_bin * abb_cria(){
    Arv_bin * arv = new Arv_bin;
    arv->raiz = NULL;
    return arv;
}

Nodo * insere_no(Nodo *raiz, char n){
    if(raiz == NULL){
        raiz = new Nodo;
        raiz->info = n;
        raiz->esq = raiz->dir = NULL;
    } else if (n < raiz->info)
        raiz->esq = insere_no(raiz->esq, n);
    else
        raiz->dir = insere_no(raiz->dir, n);
    return raiz;
}

/**
 * Cria um nodo com n de informação e insere na árvore.
 * @param arv
 * @param n
 */
void abb_insere(Arv_bin *arv, char n){
    arv->raiz = insere_no(arv->raiz, n);
}

void arv_imprime_pre(Nodo * raiz, string * saida){
    if(raiz != NULL){
        saida->push_back(raiz->info);
        arv_imprime_pre(raiz->esq, saida);
        arv_imprime_pre(raiz->dir, saida);
    }
}

void arv_imprime_inf(Nodo * raiz, string * saida){
    if(raiz != NULL){
        arv_imprime_inf(raiz->esq, saida);
        saida->push_back(raiz->info);
        arv_imprime_inf(raiz->dir, saida);
    }
}

void arv_imprime_pos(Nodo * raiz, string * saida){
    if(raiz != NULL){
        arv_imprime_pos(raiz->esq, saida);
        arv_imprime_pos(raiz->dir, saida);
        saida->push_back(raiz->info);
    }
}

/**
 * Imprime a Avr_bin seguindo a opção: 0 - preordem, 1 - inordem, 2 - posordem e nada se não for esses
 * @param arv
 * @param opcao
 */
void arv_imprime(Arv_bin * arv, int opcao){
    string aux;
    int cont;
    if(opcao == 0){
        arv_imprime_pre(arv->raiz, &aux);
    } else if(opcao == 1){
        arv_imprime_inf(arv->raiz, &aux);
    } else if(opcao == 2){
        arv_imprime_pos(arv->raiz, &aux);
    }
    if(!aux.empty()){
        cout << aux[0];
        for(cont = 1; cont < aux.size(); cont++){
            cout << " " << aux[cont];
        }
    }
}

/**
 * Retorna o nodo com a informação de n ou NULL caso contrário.
 * @param raiz
 * @param n
 * @return
 */
Nodo * arv_busca_no(Nodo *raiz, char n){
    if(raiz==NULL || raiz->info == n)
        return raiz;
    if (n < raiz->info)
        return arv_busca_no(raiz->esq, n);
    else
        return arv_busca_no(raiz->dir, n);
}


int main(){
    string entrada;
    Nodo * aux;
    Arv_bin * arv = abb_cria();

    getline(cin, entrada);
    do{
        if(entrada.compare("PREFIXA") == 0){
            arv_imprime(arv, 0);
            cout << endl;
        } else if(entrada.compare("INFIXA") == 0){
            arv_imprime(arv, 1);
            cout << endl;
        } else if(entrada.compare("POSFIXA") == 0){
            arv_imprime(arv, 2);
            cout << endl;
        } else if(entrada[0] == 'I'){
            abb_insere(arv, entrada[2]);
        } else{
            aux = arv_busca_no(arv->raiz, entrada[2]);
            if(aux == NULL){
                cout << entrada[2] << " nao existe" << endl;
            } else {
                cout << entrada[2] << " existe" << endl;
            }
        }
        getline(cin, entrada);
    }while(!cin.eof());
    return 0;
}
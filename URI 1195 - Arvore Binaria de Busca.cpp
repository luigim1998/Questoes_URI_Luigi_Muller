#include <iostream>
#include <queue>
using namespace std;

typedef struct no{
    int info;
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

Nodo * insere_no(Nodo *raiz, int n){
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
void abb_insere(Arv_bin *arv, int n){
    arv->raiz = insere_no(arv->raiz, n);
}

void arv_libera_no(Nodo * raiz){
    if(raiz!=NULL){
        arv_libera_no(raiz->esq);
        arv_libera_no(raiz->dir);
        delete raiz;
    }
}

/**
 * Apaga a árvore liberando espaço.
 * @param arv
 */
void arv_libera(Arv_bin * arv){
    arv_libera_no(arv->raiz);
    delete arv;
}

void arv_imprime_pre(Nodo * raiz){
    if(raiz != NULL){
        cout << " " << raiz->info;
        arv_imprime_pre(raiz->esq);
        arv_imprime_pre(raiz->dir);
    }
}

void arv_imprime_inf(Nodo * raiz){
    if(raiz != NULL){
        arv_imprime_inf(raiz->esq);
        cout << " " << raiz->info;
        arv_imprime_inf(raiz->dir);
    }
}

void arv_imprime_pos(Nodo * raiz){
    if(raiz != NULL){
        arv_imprime_pos(raiz->esq);
        arv_imprime_pos(raiz->dir);
        cout << " " << raiz->info;
    }
}

/**
 * Imprime a árvore.
 * @param arv Árvore a ser impressa.
 */
void arv_imprime(Arv_bin * arv){
    cout << "Pre.:"; arv_imprime_pre(arv->raiz); cout << endl;
    cout << "In..:"; arv_imprime_inf(arv->raiz); cout << endl;
    cout << "Post:"; arv_imprime_pos(arv->raiz); cout << endl;
}

/**
 * Cria um vetor com a quantidade no argumento e insere os valores dentro.
 * @param quantidade
 * @return
 */
int * recebe_valores(int quantidade){
    int cont1;
    int * vetor = new int[quantidade];
    for(cont1 = 0; cont1 < quantidade; cont1++){
        cin >> vetor[cont1];
    }
    return vetor;
}

void insere_valores(Arv_bin *arv, int * vetor, int tamanho){
    int cont;
    for(cont = 0; cont < tamanho; cont ++){
        abb_insere(arv, vetor[cont]);
    }
}

int main(){
    int casos, quantidade;
    int cont1;
    int * vetor;
    Arv_bin * arv;

    cin >> casos;

    for(cont1 = 1; cont1 <= casos; cont1++){
        arv = abb_cria();
        cout << "Case " << cont1 << ":" << endl;
        cin >> quantidade;
        vetor = recebe_valores(quantidade);
        insere_valores(arv, vetor, quantidade);
        arv_imprime(arv);
        cout << endl;
        arv_libera(arv);
    }
}
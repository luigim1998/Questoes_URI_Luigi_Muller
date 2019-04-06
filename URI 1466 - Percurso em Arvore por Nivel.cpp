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

/**
 * Cria um vetor com a quantidade no argumento e insere os valores dentro.
 * @param quantidade
 * @return
 */
int * cria_vetor(int quantidade){
    int cont1;
    int * vetor = new int[quantidade];
    for(cont1 = 0; cont1 < quantidade; cont1++){
        cin >> vetor[cont1];
    }
    return vetor;
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

void insere_valores(Arv_bin *arv, int * vetor, int tamanho){
    int cont;
    for(cont = 0; cont < tamanho; cont++){
        abb_insere(arv, vetor[cont]);
    }
}

void abb_imprime(Arv_bin * arv){
    queue<Nodo *> * entrada = new queue<Nodo *>;
    queue<Nodo *> * aux     = new queue<Nodo *>;
    queue<Nodo *> * saida   = new queue<Nodo *>;

    entrada->push(arv->raiz);

    while(!entrada->empty()) {
        while (!entrada->empty()) {
            saida->push(entrada->front());

            if (entrada->front()->esq != NULL) {
                aux->push(entrada->front()->esq);
            }
            if (entrada->front()->dir != NULL) {
                aux->push(entrada->front()->dir);
            }
            entrada->pop();
        }
        delete entrada;
        entrada = aux;
        aux = new queue<Nodo *>;
    }
    cout << saida->front()->info;
    saida->pop();
    while(!(saida->empty())){
        cout << " " << saida->front()->info;
        saida->pop();
    }
    cout << endl;
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

int main(){
    int casos, quantidade;
    int cont1;
    int * entrada;
    Arv_bin * arv;

    cin >> casos;
    for(cont1 = 1; cont1 <= casos; cont1++){
        arv = abb_cria();
        cout << "Case " << cont1 << ":" << endl;
        cin >> quantidade;
        entrada = cria_vetor(quantidade);
        insere_valores(arv, entrada, quantidade);
        abb_imprime(arv);
        cout << endl;
        delete entrada;
        arv_libera(arv);
    }
    return 0;
}
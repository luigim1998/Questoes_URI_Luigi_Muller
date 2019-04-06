#include <string>
#include <iostream>
using namespace std;

typedef struct no{
    //string nome;
    int quant;
    struct no *esq;
    string nome;
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
 * Cria um novo nodo para o morto com as informações atualizadas ou apenas atualiza.
 * @param raiz Nodo para pesquisa.
 * @param nome nome do morto;
 * @return Nodo com as informações atualizadas dela e das sub-árvores.
 */
Nodo * insere_morto(Nodo *raiz, string nome){
    if(raiz == NULL){
        raiz = new Nodo;
        raiz->nome = nome;
        raiz->quant = -1;
        raiz->esq = raiz->dir = NULL;
    } else if (nome.compare(raiz->nome) < 0)
        raiz->esq = insere_morto(raiz->esq, nome);
    else if (nome.compare(raiz->nome) > 0)
        raiz->dir = insere_morto(raiz->dir, nome);
    else //nome.compare(raiz->nome) == 0
        if(raiz->quant != -1)
            raiz->quant = -1;
    return raiz;
}

/**
 * Cria um novo nodo para o assassino com as informações atualizadas ou apenas atualiza.
 * @param raiz Nodo para pesquisa.
 * @param nome nome do assassino;
 * @return Nodo com as informações atualizadas dela e das sub-árvores.
 */
Nodo * insere_assassino(Nodo *raiz, string nome){
    if(raiz == NULL){
        raiz = new Nodo;
        raiz->nome = nome;
        raiz->quant = 1;
        raiz->esq = raiz->dir = NULL;
    } else if (nome.compare(raiz->nome) < 0)
        raiz->esq = insere_assassino(raiz->esq, nome);
    else if (nome.compare(raiz->nome) > 0)
        raiz->dir = insere_assassino(raiz->dir, nome);
    else //nome.compare(raiz->nome) == 0
        if(raiz->quant != -1)
            (raiz->quant)++;
    return raiz;
}

/**
 * Retorna true caso ele esteja vivo e false caso contrário.
 * @param raiz Nodo para pesquisa;
 * @param nome Nome para pesquisa;
 * @return Retorna true caso ele esteja vivo e false caso contrário.
 */
bool esta_vivo(Nodo * raiz, string nome){
    if(raiz == NULL)
        return true;
    else if (nome.compare(raiz->nome) < 0)
        return esta_vivo(raiz->esq, nome);
    else if (nome.compare(raiz->nome) > 0)
        return esta_vivo(raiz->dir, nome);
    else { //nome.compare(raiz->nome) == 0
        if (raiz->quant == -1) //está morto
            return false;
        else
            return true;
    }
}

 /**
  * Cria um nodo com n de informação e insere na árvore.
  * @param arv Árvore com as informações;
  * @param assassino Nome do assassino;
  * @param morto Nome do morto;
  */
void abb_insere(Arv_bin *arv, string assassino, string morto){
    if(esta_vivo(arv->raiz, assassino) && esta_vivo(arv->raiz, morto)){
        arv->raiz = insere_assassino(arv->raiz, assassino);
        arv->raiz = insere_morto(arv->raiz, morto);
    }
}

/**
 * Função para imprimir as informações dos assassinos.
 * @param raiz Nodo raiz da árvore;
 */
void abb_imprime(Nodo * raiz){
    if(raiz != NULL){
        abb_imprime(raiz->esq);
        if(raiz->quant != -1) cout << raiz->nome << " " << raiz->quant << endl;
        abb_imprime(raiz->dir);
    }
}

int main(){
    Arv_bin * arv = abb_cria();
    string assassino, morto;

    cin >> assassino >> morto;
    do{
        abb_insere(arv, assassino, morto);
        cin >> assassino >> morto;
    }while(!cin.eof());

    cout << "HALL OF MURDERERS" << endl;
    abb_imprime(arv->raiz);
}
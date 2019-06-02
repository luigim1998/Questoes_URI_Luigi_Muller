#include <iostream>
#include <limits.h>
using namespace std;

inline int LEFT(int i){ return 2*i + 1; }
inline int RIGHT(int i){ return 2*i + 2; }
inline int PARENT(int i){ return (i-1)/2; }

typedef struct proc{
    int requisicao;
    int duracao;
}Process;

typedef struct arvore{
    int lenght;             //número de elementos no arranjo;
    int heap_size;          //número de elemento do heap que estão no arranjo;
    Process vector[100000]; //vetor de valores;
}ArvHeap;

/**
 * Função para manter a propriedade da heap.
 * @param A - Ponteiro da árvore;
 * @param indice - índice para atualizar.
 */

void max_heapify(ArvHeap * A, int indice){
    int l = LEFT(indice);
    int r = RIGHT(indice);
    int largest = indice;
    
    //se o filho a esquerda for maior que o pai
    if(l < A->heap_size){
        if(A->vector[l].requisicao > A->vector[indice].requisicao){
            largest = l;
        }//se forem iguais compara o tempo de duracao
        else if(A->vector[l].requisicao == A->vector[indice].requisicao){
            if(A->vector[l].duracao > A->vector[indice].duracao){
                largest = l;
            }
        }
    }
    //se o filho a direita for maior que o maior
    if(r < A->heap_size){
        if(A->vector[r].requisicao > A->vector[largest].requisicao){
            largest = r;
        }//se forem iguais compara o tempo de duracao
        else if(A->vector[r].requisicao == A->vector[largest].requisicao){
            if(A->vector[r].duracao > A->vector[largest].duracao){
                largest = r;
            }
        }
    }
    if(largest != indice){
        //troca o maior
        Process aux = A->vector[indice];
        A->vector[indice] = A->vector[largest];
        A->vector[largest] = aux;
        max_heapify(A, largest);
    }
}

/**
 * Deixa o vetor seguindo a propriedade da Heap Sort.
 * @param A - Ponteiro da árvore.
 */

void build_max_heap(ArvHeap * A){
    A->heap_size = A->lenght;
    int aux;
    for(aux = A->lenght/2 - 1; aux >= 0; aux--){
        max_heapify(A, aux);
    }
}

/**
 * Organiza o vetor utilizando o heapsort.
 * @param A - ponteiro da árvore.
 */

void heapsort(ArvHeap * A){
    int i;
    Process aux;
    for(i = A->lenght - 1; i > 0; i--){
        //troca o maior que está em A[0] pelo último
        aux = A->vector[0];
        A->vector[0] = A->vector[i];
        A->vector[i] = aux;
        //diminui o tamanho da heap já que os últimos estão organizados
        A->heap_size = A->heap_size - 1;
        //ele mantém a propriedade da heap
        max_heapify(A, 0);
    }
}

int main(){
    ArvHeap * arv = new ArvHeap;
    int casos;
    int aux;
    long long int tempo_atual, atraso_total;
    while(cin >> casos){
        tempo_atual = 1;
        atraso_total = 0;
        arv->lenght    = casos;
        arv->heap_size = 0;
        for(int cont = 0; cont < casos; cont++){
            cin >> aux;
            arv->vector[cont].requisicao = aux;
            cin >> aux;
            arv->vector[cont].duracao = aux;
        }
        build_max_heap(arv);
        heapsort(arv);
        for(int cont = 0; cont < casos; cont++){
            if(arv->vector[cont].requisicao < tempo_atual){//esta atrasado
                atraso_total += tempo_atual - arv->vector[cont].requisicao;//atualiza o atraso
                tempo_atual += arv->vector[cont].duracao;//atualiza o tempo
            }else if(arv->vector[cont].requisicao == tempo_atual){//terminou na hora
                tempo_atual += arv->vector[cont].duracao;//atualiza o tempo
            }else{//terminou antes do outro comecar
                tempo_atual = arv->vector[cont].requisicao +
                        arv->vector[cont].duracao;//recebe o tempo mais a execucao
                
            }
        }
        cout << atraso_total << endl;
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <queue>

using namespace std;
//Definição do tipo Grafo
//
typedef struct grafo Grafo;
struct grafo{
    int eh_ponderado;
    int nro_vertices;
    int grau_max;
    int** arestas;
    float** pesos;
    int* grau;
};

Grafo* cria_Grafo(int nro_vertices, int grau_max, int eh_ponderado);

void libera_Grafo(Grafo* gr);

int insereAresta(Grafo* gr, int orig, int dest, int eh_digrafo, float peso);

void buscaLargura_Grafo(Grafo *gr, int ini, int *visitado,int cont);

int main(){
	int n_v,n_a,n,n_case = 1;
	char orig,dest;
	scanf("%d",&n);

	while(n != 0)
	{
		int vis[26] = {0};
		int cont = 1;
		scanf("%d %d", &n_v,&n_a);
		Grafo* g = cria_Grafo(n_v,26,0);
		for (int i = 0; i < n_a; ++i)
		{
			scanf(" %c %c",&orig,&dest);
			insereAresta(g,(char)(orig-97),(char)(dest-97),0,0);
		}
		for (int i = 0; i < g->nro_vertices; ++i)
		{
			if(vis[i]==0){
				buscaLargura_Grafo(g,i,vis,cont);
				cont++;
			}
		}
		printf("Case #%d:\n", n_case++);
		for (int i = 1; i < cont; ++i)
		{
			for (int j = 0; j < g->nro_vertices; ++j)
			{
				if(vis[j] == i)
					printf("%c,",(char)(j+97));
			}
			printf("\n");
		}
		printf("%d connected components\n\n", (cont-1));
		libera_Grafo(g);
		n--;
	}
	return 0;
}

Grafo* cria_Grafo(int nro_vertices, int grau_max, int eh_ponderado){
    Grafo *gr;
    gr = (Grafo*) malloc(sizeof(struct grafo));
    if(gr != NULL){
        int i;
        gr->nro_vertices = nro_vertices;
        gr->grau_max = grau_max;
        gr->eh_ponderado = (eh_ponderado != 0)?1:0;
        gr->grau = (int*) calloc(nro_vertices,sizeof(int));

        gr->arestas = (int**) malloc(nro_vertices * sizeof(int*));
        for(i=0; i<nro_vertices; i++)
            gr->arestas[i] = (int*) malloc(grau_max * sizeof(int));

        if(gr->eh_ponderado){
            gr->pesos = (float**) malloc(nro_vertices * sizeof(float*));
            for(i=0; i<nro_vertices; i++)
                gr->pesos[i] = (float*) malloc(grau_max * sizeof(float));
        }

    }
    return gr;
}

void libera_Grafo(Grafo* gr){
    if(gr != NULL){
        int i;
        for(i=0; i<gr->nro_vertices; i++)
            free(gr->arestas[i]);
        free(gr->arestas);

        if(gr->eh_ponderado){
            for(i=0; i<gr->nro_vertices; i++)
                free(gr->pesos[i]);
            free(gr->pesos);
        }
        free(gr->grau);
        free(gr);
    }
}

int insereAresta(Grafo* gr, int orig, int dest, int eh_digrafo, float peso){
    if(gr == NULL)
        return 0;
    if(orig < 0 || orig >= gr->nro_vertices)
        return 0;
    if(dest < 0 || dest >= gr->nro_vertices)
        return 0;

    gr->arestas[orig][gr->grau[orig]] = dest;
    if(gr->eh_ponderado)
        gr->pesos[orig][gr->grau[orig]] = peso;
    gr->grau[orig]++;

    if(eh_digrafo == 0)
        insereAresta(gr,dest,orig,1,peso);
    return 1;
}

void buscaLargura_Grafo(Grafo *gr, int ini, int *visitado,int cont){
    int i, vert;
    queue<int>fila;
    fila.push(ini);
    visitado[ini] = cont;
    while(!fila.empty()){
        vert = fila.front();
        fila.pop();
        for(i=0; i<gr->grau[vert]; i++){
            if(!visitado[gr->arestas[vert][i]]){
                fila.push(gr->arestas[vert][i]);
                visitado[gr->arestas[vert][i]] = cont;
            }
        }
    }
}

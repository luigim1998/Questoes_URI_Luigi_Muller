#include<bits/stdc++.h>
#include<list> 
using namespace std;

int contador = 0;

class Grafo { //grafo representado por uma lista de adjacencia 
	int N_vertices; // No. of vertices 
	 
	list<int> *adj; // Pointer to an array containing adjacency lists
	
	void DFSUtil(int v, bool visited[]); // A recursive function used by DFS 
public: 
	Grafo(int N_vertices); // Constructor 

	void addEdge(int v, int w); // funcao que adiciona a aresta no grafo

	void DFS(int v); // DFS traversal of the vertices reachable from v 
}; 

Grafo::Grafo(int N_vertices) { 
	this->N_vertices = N_vertices; 
	adj = new list<int>[N_vertices]; 
} 

void Grafo::addEdge(int v, int w) { 
	adj[v].push_back(w); // Add w to v’s list.  
} 

void Grafo::DFSUtil(int v, bool visited[]) { 
	//cout << "consegui chamar a funcao" << endl;
	visited[v] = true; // Marca o nodo atual como visitado

	list<int>::iterator i; // passar por todas as adj das arestas do grafo
	for (i = adj[v].begin(); i != adj[v].end(); ++i){ // o ++i é pq é para mover o ponteiro para o elemento adjacente da lista
		if (visited[*i] == false){
			contador++; //quantidade de arestas pra multiplicar por 2 no final
			//cout << v << "vai para" << *i << endl;
			DFSUtil(*i, visited);
		 
		}
	}
	
} 

void Grafo::DFS(int v) { 

	bool *visited = new bool[N_vertices]; //marca todos os vertices como nao visitados
	for (int i = 0; i < N_vertices; i++) 
		visited[i] = false; 

	/* for (int i = 0; i < N_vertices; i++){
		if (visited[i] == false)
			DFSUtil(i, visited); // Call the recursive helper function to DFS traversal 
	}  */
	DFSUtil(v,visited);
	
} 

int main() { 
	int casos_de_testes, inicio_e_fim, vertices, arestas;
	int aresta1, aresta2;

	scanf("%d",&casos_de_testes);

	while(casos_de_testes--){
		scanf("%d",&inicio_e_fim);
		scanf("%d %d",&vertices, &arestas);
		Grafo labirinto(vertices);
		while(arestas--){
			scanf("%d %d", &aresta1, &aresta2);
			labirinto.addEdge(aresta1, aresta2);
			labirinto.addEdge(aresta2, aresta1);
		}
		labirinto.DFS(inicio_e_fim);
		cout << 2*contador << endl;
		contador = 0;
	}

	return 0; 
} 

// C++ program for Kruskal's algorithm to find Minimum Spanning Tree
// of a given connected, undirected and weighted graph
// Website with code: https://www.geeksforgeeks.org/kruskals-minimum-spanning-tree-algorithm-greedy-algo-2/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

// a structure to represent a weighted edge in graph
struct Edge
{
    long int src, dest, weight;
};

// a structure to represent a connected, undirected
// and weighted graph
struct Graph
{
    // V-> Number of vertices, E-> Number of edges
    long int V, E;
    
    // graph is represented as an array of edges.
    // Since the graph is undirected, the edge
    // from src to dest is also edge from dest
    // to src. Both are counted as 1 edge here.
    struct Edge* edge;
};

// Creates a graph with V vertices and E edges
struct Graph* createGraph(long int V, long int E)
{
    struct Graph* graph = new Graph;
    graph->V = V;
    graph->E = E;
    
    graph->edge = new Edge[E];
    
    return graph;
}

// A structure to represent a subset for union-find
struct subset
{
    long int parent;
    long int rank;
};

// A utility function to find set of an element i
// (uses path compression technique)
long int find(struct subset subsets[], long int i)
{
    // find root and make root as parent of i
    // (path compression)
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    
    return subsets[i].parent;
}

// A function that does union of two sets of x and y
// (uses union by rank)
void Union(struct subset subsets[], long int x, long int y)
{
    long int xroot = find(subsets, x);
    long int yroot = find(subsets, y);
    
    // Attach smaller rank tree under root of high
    // rank tree (Union by Rank)
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
        
        // If ranks are same, then make one as root and
        // increment its rank by one
    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Compare two edges according to their weights.
// Used in qsort() for sorting an array of edges
int myComp(const void* a, const void* b)
{
    struct Edge* a1 = (struct Edge*)a;
    struct Edge* b1 = (struct Edge*)b;
    if ( a1->weight <  b1->weight ) return -1;
    if ( a1->weight == b1->weight ) return 0;
    if ( a1->weight >  b1->weight ) return 1;
}

// The main function to construct MST using Kruskal's algorithm
long int KruskalMST(struct Graph* graph)
{
    long int soma_minima = 0;
    long int V = graph->V;
    struct Edge result[V]; // Tnis will store the resultant MST
    long int e = 0; // An index variable, used for result[]
    long int i = 0; // An index variable, used for sorted edges
    
    // Step 1: Sort all the edges in non-decreasing
    // order of their weight. If we are not allowed to
    // change the given graph, we can create a copy of
    // array of edges
    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp);
    
    // Allocate memory for creating V ssubsets
    struct subset *subsets =
            (struct subset*) malloc( V * sizeof(struct subset) );
    
    // Create V subsets with single elements
    for (long int v = 0; v < V; ++v)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
    
    // Number of edges to be taken is equal to V-1
    while (e < V - 1)
    {
        // Step 2: Pick the smallest edge. And increment
        // the index for next iteration
        struct Edge next_edge = graph->edge[i++];
        
        long int x = find(subsets, next_edge.src);
        long int y = find(subsets, next_edge.dest);
        
        // If including this edge does't cause cycle,
        // include it in result and increment the index
        // of result for next edge
        if (x != y)
        {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
        // Else discard the next_edge
    }
    
    // print the contents of result[] to display the
    // built MST
    //printf("Following are the edges in the constructed MST\n");
    for (i = 0; i < e; ++i) {
        //printf("%ld -- %ld == %ld\n", result[i].src, result[i].dest, result[i].weight);
        soma_minima += result[i].weight;
    }
    
    return soma_minima;
}

// Driver program to test above functions
int main() {
    
    long int V; // Number of vertices in graph
    long int E; // Number of edges in graph
    long int soma_total; // Sum of all weights
    long int soma_minima; // Sum of tree weights
    
    scanf("%ld%ld", &V, &E);
    
    while(V != 0 && E != 0){
    
        soma_total = soma_minima = 0;
        
        struct Graph *graph = createGraph(V, E);
    
        for(long int cont = 0; cont < E; cont++){ // Inserts the edges
            long int a, b, c;
            scanf("%ld%ld%ld", &a, &b, &c);
            if(a > b){ // For security reasons the src will be less than dest
                int aux = a;
                a = b;
                b = aux;
            }
            graph->edge[cont].src = a;
            graph->edge[cont].dest = b;
            graph->edge[cont].weight = c;
            soma_total += c;
        }
        
        soma_minima = KruskalMST(graph);
        
        printf("%ld\n", soma_total - soma_minima);
        
        scanf("%ld%ld", &V, &E);
    }
    return 0;
}

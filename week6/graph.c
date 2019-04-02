#include <stdio.h>
#include <stdlib.h>

typedef struct graphRep *Graph;
typedef int Vertex;

struct graphRep { 
    int nV;
    int nE;
    int **edges;
}; 

// write a function that returns a set of all vertices 
// that can be reached by following a path from the start
Set reachable(Graph g, Vertex v) {
    Set seen = newSet(g->nV);

    return seen;
}

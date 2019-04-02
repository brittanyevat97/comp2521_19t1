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
    Stack s = newStack();
    SetInclude(seen, v);
    StackPush(s, v);
    while(!StackIsEmpty(s)) {
        Vertex x = StackPop(s);
        for (Vertex y = 0; y < g->nV; y++) {
            if (g->edges[x][y] && !SetHasElem(seen, y)) {
                StackPush(s, y);
                SetInclude(seen, y);
            }
        }
    }
    return seen;
}

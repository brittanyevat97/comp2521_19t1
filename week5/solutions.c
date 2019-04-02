#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct graphRep *Graph;
typedef int Vertex;
typedef struct vNode *List;

// representation of a node used in adjacency list representation
struct vNode {
    Vertex v;
    struct vNode *next;
};

// Adjacency matrix graph representation
struct graphRep {
    int nV;         // number of vertices
    int nE;         // number of edges
    int **edges;    // matrix of booleans (0 or 1)
};

// Adjacency list graph representation
struct graphRep {
    int nV;         // number of vertices
    int nE;         // number of edges
    List *edges;    // array of Vertex lists
};

// alter the DFS from the tute so that no vertex is put in the
// stack more than once
void depthFirst(Graph g, Vertex v) {
    int *visited = calloc(g->nV, sizeof(int));
    Stack s = newStack();
    // note that now we mark a vertex as visited when we push
    // it onto the stack (instead of when we pop it)
    StackPush(s, v);
    visited[v] = 1;
    while (!StackIsEmpty (s)) {
        Vertex x = StackPop (s);
        printf ("%d\n", x);
        for (Vertex y = g->nV - 1; y >= 0; y--) {
            if (!g->edges[x][y])
                continue;
            if (!visited[y]) {
                StackPush (s, y);
                visited[y] = 1;
            }
        }
    }
}

void dfsR(Graph g, Vertex v, int *visited) {
    visited[v] = 1;
    printf("%d\n", v);
    for (Vertex w = 0; w < g->nV; w++) {
        // note that we want all the vertices we can reach from v
        // so if v has an edge to w, then we want to visit w and all
        // the vertices we can reach from w
        if (g->edges[v][w] && !visited[w]) 
            dfs(g, w, visited);
    }
}

// implement DFS recursively
// psuedocode:
//      mark v as visited
//      for each w in neighbours of v
//          if w has not been visited
//              dfs(g, w)
void dfs(Graph g, Vertex v) {
    int *visited = calloc(g->nV, sizeof(int));
    // we require a helper function so that we do not overwrite
    // the visited array / allocate memory for it more than once
    dfsR(g, v, visited);
}

int dfsHasPathHelper(Graph g, Vertex from, Vertex to, int *visited) {
    if (from == to) return 1;
    visited[from] = 1;
    for (Vertex w = 0; w < g->nV; w++) {
        if (g->edges[from][w] && !visited[w]) {
            // if there is a path from any neighbour of 'from' to 'to'
            // then we have found a path so return 1
            if (dfsR(g, w, to, visited) == 1) return 1;
        }
    }
    // if we reach here, we have found no path
    return 0;
}


// use a DFS to check if the graph g has a path between the vertices
// 'from' and 'to'
int dfsHasPath(Graph g, Vertex from, Vertex to) {
    int *visited = calloc(g->nV, sizeof(int));
    // similary to above, we require a helper function
    return dfsHasPathHelper(g, from, to, visited);
}


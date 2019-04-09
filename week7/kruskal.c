// Kruskal's algorithm from COMP2521 19T1 Tutorial 7
#include <stdio.h>
#include <stdlib.h>

typedef struct graphRep {
    int nV;
    int nE;
    int **edges;
} GraphRep;

typedef GraphRep *Graph;
typedef Graph MSTree;

typedef struct {
    Vertex v;
    Vertex w;
    int weight;
} Edge;

MSTree kruskalFindMST(Graph g) {
    MSTree mst = newGraph();  // MST initially empty
    Edge eList[g->nV];
    edges(eList, g->nE, g);
    sortEdgeList(eList, g->nE); // consider edges in increasing weight order
    for (int i = 0; mst->nE < g->nV - 1; i++) {
        Edge e = eList[i];
        insertE(mst, e); // add edge to MST
        if (hasCycle(mst))
            removeE(mst, e); // remove edge if it forms a cycle
    }
    return mst;
}


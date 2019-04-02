// Dijkstra's single-source shortest-path algorithm

Dijkstra(Graph g, Vertex s) {
    VertexSet vSet = newSet();
    PQueue pq = newPQueue();
    int dist[g->nV] = {inf};
    dist[s] = 0;
    Vertex pred[g->nV] = {-1};
    
    PQueueJoin(pq, s, dist[s]);

    Vertex v, w;
    while (SetSize(vSet) < g->nV) {
        v = PQueueLeave(pq);
        SetInclude(vSet, v);
        for (each Vertex w adjacent to v) {
            if (isElem(vSet, w)) continue;
            if (dist[v] + weight(v, w) < dist[w]) {
                dist[w] = dist[v] + weight(v, w);
                pred[w] = v;
                PQueueJoin(pq, w, dist[w]);
            }
        }
    }
}

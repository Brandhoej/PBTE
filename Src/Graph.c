#include <stdlib.h>
#include "Graph.h"

void initGraph(graph *g, hub *hubs, unsigned int hubAmount) {
    int e;
    g->hubAmount = hubAmount;
    g->hubs = hubs;
    g->edges = calloc(hubAmount, sizeof(edge*));
    for (e = 0; e < hubAmount; ++e) {
        g->edges[e] = calloc(hubAmount, sizeof(edge));
    }
}

void addEdge(graph *g, int from, int to, edge *edge) {
    g->edges[from][to] = *edge;
    g->edges[to][from] = *edge;
}


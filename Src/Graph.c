#include <stdlib.h>
#include "Graph.h"

void initGraph(graph *graph, hub *hubs, unsigned int hubAmount) {
    int e;
    graph->hubAmount = hubAmount;
    graph->hubs = hubs;
    graph->edges = calloc(hubAmount, sizeof(edge*));
    for (e = 0; e < hubAmount; ++e) {
        graph->edges[e] = calloc(hubAmount, sizeof(edge));
    }
}

void addEdge(graph *graph, edge *edge) {
    graph->edges[edge->u][edge->v] = *edge;
    graph->edges[edge->v][edge->u] = *edge;
}


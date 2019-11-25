#include <stdlib.h>
#include "Graph.h"

void initGraph(graph *g, hub *hubs, unsigned int hubAmount) {
    int e;
    g->hubs = hubs;
    g->edges = calloc(hubAmount, sizeof(hub));
    for (e = 0; e < hubAmount; ++e) {
        g->edges[e] = calloc(hubAmount, sizeof(hub));
    }
}
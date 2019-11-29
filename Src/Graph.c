#include <stdlib.h>
#include <stdio.h>
#include "Graph.h"

int edgeAmount(int n){
    int amount = -1;
    if(n > 0){
        /* This is the gauss sum formula */
        amount = n * (n - 1) / 2;
    }
    return amount;
}

int getEdgeIndex(int u, int v){
    int index = -1;
    if(u != v && u >= 0 && v >= 0){
        int min, max;
        if (u > v){
            min = v;
            max = u;
        }
        else {
            min = u;
            max = v;
        }
        index = edgeAmount(max) + min;
    }
    return index;
}

void initGraph(graph *graph, hub *hubs, unsigned int hubAmount) {
    graph->hubAmount = hubAmount;
    graph->hubs = hubs;
    graph->edges = calloc(edgeAmount(hubAmount), sizeof(edge*));
}

void addEdge(graph *graph, int u, int v, edge *edge) {
    graph->edges[getEdgeIndex(u, v)] = edge;
}

edge *getEdge(graph *graph, int u, int v){
    return graph->edges[getEdgeIndex(u, v)];
}

unsigned int totalAmountBicycle(graph *graph){
    int n;
    unsigned int totalAmount = 0;

    for(n = 0; n < graph->hubAmount; ++n){
        totalAmount += graph->hubs[n].inventory;
    }
    return totalAmount;
}

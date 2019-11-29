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

void initGraph(Graph *graph, Hub *hubs, unsigned int hubAmount) {
    graph->hubAmount = hubAmount;
    graph->hubs = hubs;
    graph->edges = calloc(edgeAmount(hubAmount), sizeof(Edge*));
}

void addEdge(Graph *graph, int u, int v, Edge *edge) {
    graph->edges[getEdgeIndex(u, v)] = edge;
}

Edge *getEdge(Graph *graph, int u, int v){
    return graph->edges[getEdgeIndex(u, v)];
}

unsigned int totalAmountBicycle(Graph *graph){
    int n;
    unsigned int totalAmount = 0;

    for(n = 0; n < graph->hubAmount; ++n){
        totalAmount += graph->hubs[n].inventory;
    }
    return totalAmount;
}

int totalAmountBicycle(graph *graph){
    int n = 0, balance = 0;

    while(balance == 0 && n < graph->hubAmount){
        ++n;
        balance += getBalance(&graph->hubs[n]);
    }

    return balance;
}
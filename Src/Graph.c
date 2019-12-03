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
    int eAmount, i;

    graph->hubAmount = hubAmount;
    graph->hubs = hubs;
    graph->edges = calloc(edgeAmount(hubAmount), sizeof(Edge));
}

void addEdge(Graph *graph, int u, int v, Edge *edge) {
    graph->edges[getEdgeIndex(u, v)].distance = edge->distance;
}

Edge *getEdge(Graph *graph, int u, int v) {
    return &graph->edges[getEdgeIndex(u, v)];
}

int getBestHubIndex(Graph *graph, int from){
    int hIndex, hBestIndex;
    double eBestWeight = -1000.0;
    for(hIndex = 0; hIndex < graph->hubAmount; ++hIndex){
        if(hIndex != from && getEdge(graph, from, hIndex)->weight > eBestWeight){
            hBestIndex = hIndex;
            eBestWeight = getEdge(graph, from, hIndex)->weight;
        }
    }
    return hBestIndex;
}

unsigned int totalAmountBicycle(Graph *graph){
    int n;
    unsigned int totalAmount = 0;

    for(n = 0; n < graph->hubAmount; ++n){
        totalAmount += graph->hubs[n].inventory;
    }
    return totalAmount;
}

int CalcAllBalance(Graph *graph){
    int n = 0, balance = 0;

    do{
        balance = getBalance(&graph->hubs[n]);
        n++;
    }while(balance == 0 && n < graph->hubAmount);
    return balance == 0;
}
#include <stdlib.h>
#include <stdio.h>
#include "Graph.h"

void initGraph(graph *graph, hub *hubs, unsigned int hubAmount) {
  int e = 0;
  graph->hubAmount = hubAmount;
  graph->hubs = hubs;
  printf("%i\n", sizeof(edge));
  /* (HA - 1) * (min - 1) + (max - 1)*/
  
  
  /*
    int e;
    printf("TT1\n");
    graph->hubAmount = hubAmount;
    printf("TT2\n");
    graph->hubs = hubs;
    printf("TT3\n");
    graph->edges = calloc(hubAmount, sizeof(edge*));
    printf("TT4\n");
    printf("%i\n", sizeof(edge));
    printf("TT4\n");
    for (e = 0; e < hubAmount; ++e) {
        graph->edges[e] = calloc(hubAmount, sizeof(edge));
    }
  */
}

void addEdge(graph *graph, int u, int v, edge *edge) {
  /*
    graph->edges[u][v] = *edge;
    graph->edges[v][u] = *edge;
  */
}

void getEdge(graph *graph, int u, int v, edge *edge){
  /*
  edge = &(graph->edges[u][v]);
  */
}

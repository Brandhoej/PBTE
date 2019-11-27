#include <stdlib.h>
#include <stdio.h>
#include "Graph.h"

int edgeAmount(int n){
	return n*(n-1)/2;
}

int getEdgeIndex(int u, int v){
	int min, max;
	if (u > v){
		min = v;
		max = u;
	}
	else {
		min = u;
		max = v;
	}
	return edgeAmount(max)+min;
}


void initGraph(graph *graph, hub *hubs, unsigned int hubAmount) {
  int e = 0;
  graph->hubAmount = hubAmount;
  graph->hubs = hubs;
  graph->edges = calloc(edgeAmount(hubAmount), sizeof(edge));
  printf("hub amount = %i, edge amount = %i\n", hubAmount, edgeAmount(hubAmount));
}

void addEdge(graph *graph, int u, int v, edge *edge) {
	graph->edges[getEdgeIndex(u, v)] = *edge;
}

void getEdge(graph *graph, int u, int v, edge *edge){
	edge = &(graph->edges[getEdgeIndex(u, v)]);
}

#pragma once

#include "Hub.h"
#include "Edge.h"

typedef struct graph {
	unsigned int hubAmount;
	hub *hubs;
	edge **edges;
} graph;

void initGraph(graph *g, hub *hubs, unsigned int hubAmount);
void addEdge(graph *g, int from, int to, edge *edge);
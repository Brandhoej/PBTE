#pragma once

#include "Hub.h"
#include "Edge.h"

typedef struct graph {
	hub *hubs;
	edge **edges;
} graph;

void initGraph(graph *g, hub *hubs, unsigned int hubAmount);

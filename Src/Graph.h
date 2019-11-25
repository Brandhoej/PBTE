#pragma once

#include "Hub.h"
#include "Edge.h"

typedef struct graph {
	hub *h;
	edge **e;
} graph;
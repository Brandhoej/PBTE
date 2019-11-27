#pragma once

#include "Hub.h"
#include "Edge.h"

/**
 * \struct This struct contains the nessecary members to have a functional undirected graph
*/
typedef struct graph {
    /**
     * The amount of hubs in this graph
     * @TODO make more generic
    */
	unsigned int hubAmount;

    /**
     * The hub array. Which is a collection of the verticies in this graph
    */
	hub *hubs;

    /**
    */
	edge **edges;
} graph;

int edgeAmount(int n);
int getEdgeIndex(int u, int v);
/**
 * This function initializes a graph with hubs and creates the adjacency matrix
 * @param g is the graph pointer that will be initialized by this function
 * @param hubs is an array of the hubs this graph should contain
 * @param hubAmount an unsigned amount of hubs in the hubs
*/
void initGraph(graph *graph, hub *hubs, unsigned int hubAmount);

/**
 * Function prototype, adds edge to the graph using parameters
 * @param graph is pointer to a graph, where edge are added
 * @param u is one of the verticies
 * @param v is one of the verticies
 * @param edge struct containing the connections between hubs
 */
void addEdge(graph *graph, int u, int v, edge *edge);

/**
 * Returns the edge connecting these verticies in an undirected graph.
 * @param u is one of the verticies
 * @param v is one of the verticies
 * @param edge output
 */
edge *getEdge(graph *graph, int u, int v);

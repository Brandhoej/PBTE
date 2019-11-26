#pragma once

#include "Hub.h"
#include "Edge.h"

/**
 * \struct This struct contains the nessecary members to have a functional undirected graph
*/
typedef struct {
    /**
     * The amount of hubs in this graph 
     * @TODO make more generic
    */
	unsigned int hubAmount;

    /**
     * The hub array. Which is a colelction of the verticies in this graph
    */
	hub *hubs;

    /**
     * The edges in this graph. This is an adjacency matrix. 
     * Where edges[0] returns an array of size hubAmount with all the edges. 
     * Fx. edges[0][1] is the edge between vertex 0 and vertex 1.
     * 
    */
	edge **edges;
} graph;

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
 * @param edge struct containing the connections between hubs
 */
void addEdge(graph *graph, int from, int to, edge *edge);
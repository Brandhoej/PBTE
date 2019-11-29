#pragma once

#include "Hub.h"
#include "Edge.h"

/**
 * \struct graph
 * this struct contains the nessecary members to have a functional undirected graph
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
     * This is the 1d hub array with hub pointers.
     * The size of this array is equal to hubAmount.
    */
    edge *edges;
} graph;

/**
 * This function calculates the total amount of edges
 * @param n is the number of hubs
*/
int edgeAmount(int n);

/**
 * This function gets the index in the graph array for the edge between two hubs (vertices)
 * @param u is one of the vertices
 * @param v is one of the vertices
*/
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

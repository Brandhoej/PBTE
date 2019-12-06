#pragma once

#include "Hub.h"
#include "Edge.h"

/**
 * \struct graph
 * this struct contains the nessecary members to have a functional undirected graph
*/
typedef struct Graph {
    /**
     * The amount of hubs in this graph
    */
    unsigned int hubAmount;

    /**
     * The hub array. Which is a collection of the verticies in this graph
    */
    Hub *hubs;

    /**
     * This is the 1d hub array.
     * The size of this array is equal to hubAmount.
    */
    Edge *edges;

} Graph;

/**
 * This function initializes a graph with hubs and creates the adjacency matrix
 * @param g is the graph pointer that will be initialized by this function
 * @param hubs is an array of the hubs this graph should contain
 * @param hubAmount an unsigned amount of hubs in the hubs
*/
void initGraph(Graph *graph, Hub *hubs, unsigned int hubAmount);

/**
 * This function calculates the total amount of edges needed for n hubs
 * @param n is the number of hubs
*/
unsigned int getEdgeAmount(unsigned int n);

/**
 * This function gets the index in the graph array for the edge between two hubs (vertices)
 * @param u is one of the vertices
 * @param v is one of the vertices
*/
int getEdgeIndex(unsigned int u, unsigned int v);

/**
 * Function prototype, adds edge to the graph using parameters
 * @param graph is pointer to a graph, where edge are added
 * @param u is one of the verticies
 * @param v is one of the verticies
 * @param edge struct containing the connections between hubs
 */
void addEdge(Graph *graph, int u, int v, Edge *edge);

/**
 * @param u is one of the verticies
 * @param v is one of the verticies
 * @returns the edge connecting these verticies in an undirected graph.
 */
Edge *getEdge(Graph *graph, int u, int v);

/**
 * @param graph is pointer to a graph with the hubs
 * @param index the index of the hub in the graph
 * @returns a hub pointer for the hub at that index. If out of bounds the NULL is returnd
 */
Hub *getHub(Graph *graph, int index);

/**
 * @returns the hub index of the highest weighted hub from a hub index.
 */
unsigned int getBestHubIndex(Graph *graph, unsigned int from);

 /**
 * Returns the total amount of bicycles in the graph
 * @param  graph points to graph where our values for hub and inventory are stored, used to calculate the amount.
 * @return returnes the total amount af bicycles
 */
unsigned int totalAmountBicycle(Graph *graph);

/**
 * Checks the balance for hubs and stops when not balance 
 * @param graph point to the graph to get the values from hubs and the amount of hubs
 * @return returns 1 when balance and 0 when not balance 
*/
int CalcAllBalance(Graph *graph);

/**
 * Frees the allocated memtory of the graph (hubs, edges)
 * @param graph the graph that will be freed
 */
void freeGraph(Graph *graph);
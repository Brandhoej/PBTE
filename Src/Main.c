#include <stdio.h>
#include <stdlib.h>
#include "FileHandler.h"
#include "Vehicle.h"
#include "float.h"

void addEdgeTest(Graph *graph, int u, int v, double distance){
    Edge e = {0, 0};
    e.distance = distance;
    addEdge(graph, u, v, &e);
}

void createGraphTest(Graph *graph){
    Hub *hubs = calloc(9, sizeof(Hub));
    hubs[0].inventory = 4;  hubs[0].capacity = 8;  hubs[0].targetInventory = 4;
    hubs[1].inventory = 1;  hubs[1].capacity = 6;  hubs[1].targetInventory = 3;
    hubs[2].inventory = 0;  hubs[2].capacity = 2;  hubs[2].targetInventory = 1;
    hubs[3].inventory = 8;  hubs[3].capacity = 8;  hubs[3].targetInventory = 4;
    hubs[4].inventory = 2;  hubs[4].capacity = 4;  hubs[4].targetInventory = 2;
    hubs[5].inventory = 10; hubs[5].capacity = 10; hubs[5].targetInventory = 5;
    hubs[6].inventory = 5;  hubs[6].capacity = 6;  hubs[6].targetInventory = 3;
    hubs[7].inventory = 6;  hubs[7].capacity = 6;  hubs[7].targetInventory = 3;
    hubs[8].inventory = 0;  hubs[8].capacity = 18; hubs[8].targetInventory = 9;
    
    initGraph(graph, hubs, 9);

    addEdgeTest(graph, 0, 1, 1);
    addEdgeTest(graph, 0, 2, 2);
    addEdgeTest(graph, 0, 3, 1);
    addEdgeTest(graph, 0, 4, 2);
    addEdgeTest(graph, 0, 5, 3);
    addEdgeTest(graph, 0, 6, 2);
    addEdgeTest(graph, 0, 7, 3);
    addEdgeTest(graph, 0, 8, 4);

    addEdgeTest(graph, 1, 2, 1);
    addEdgeTest(graph, 1, 3, 2);
    addEdgeTest(graph, 1, 4, 1);
    addEdgeTest(graph, 1, 5, 2);
    addEdgeTest(graph, 1, 6, 3);
    addEdgeTest(graph, 1, 7, 2);
    addEdgeTest(graph, 1, 8, 3);

    addEdgeTest(graph, 2, 3, 3);
    addEdgeTest(graph, 2, 4, 2);
    addEdgeTest(graph, 2, 5, 1);
    addEdgeTest(graph, 2, 6, 4);
    addEdgeTest(graph, 2, 7, 3);
    addEdgeTest(graph, 2, 8, 2);

    addEdgeTest(graph, 3, 4, 3);
    addEdgeTest(graph, 3, 5, 2);
    addEdgeTest(graph, 3, 6, 1);
    addEdgeTest(graph, 3, 7, 2);
    addEdgeTest(graph, 3, 8, 3);

    addEdgeTest(graph, 4, 5, 1);
    addEdgeTest(graph, 4, 6, 2);
    addEdgeTest(graph, 4, 7, 1);
    addEdgeTest(graph, 4, 8, 2);

    addEdgeTest(graph, 5, 6, 3);
    addEdgeTest(graph, 5, 7, 2);
    addEdgeTest(graph, 5, 8, 1);

    addEdgeTest(graph, 6, 7, 1);
    addEdgeTest(graph, 6, 8, 2);

    addEdgeTest(graph, 7, 8, 1);
}

int *PBTE412(Graph *graph, Vehicle *vehicle, int startHubIndex);
void calcEdgeWeights(Graph *graph, Vehicle *vehicle, int from);
double CalcEdgeWeight(Graph *graph, Vehicle *vehicle, int from, int to);

int main(void) {
    Graph *graph = malloc(sizeof(Graph));
    createGraphTest(graph);
    
    free(graph->hubs);
    free(&graph);
    return EXIT_SUCCESS;
}

int *PBTE412(Graph *graph, Vehicle *vehicle, int startHubIndex){
    int *seq = calloc(graph->hubAmount, sizeof(int));
    int location = startHubIndex;
    while(CalcAllBalance(graph) == 0){
        /* Weight edges */
        calcEdgeWeights(graph, vehicle, location);
        /* Go to best edge */
        
        /* Add hub index to seq*/
        
    }
    return seq;
}

void calcEdgeWeights(Graph *graph, Vehicle *vehicle, int from){
    int hIndex = 0;
    for(hIndex = 0; hIndex < graph->hubAmount; ++hIndex){
        if(hIndex != from){
            getEdge(graph, from, hIndex)->weight = calcEdgeWeight(graph, vehicle, from, hIndex);
        }
    }
}

double calcEdgeWeight(Graph *graph, Vehicle *vehicle, int from, int to){
    double weight = 0;
    Hub 
        *fromHub = &graph->hubs[from],
        *toHub = &graph->hubs[to];
    Edge *edge = getEdge(graph, from, to);
    
    if(getBalance(toHub) != 0){
        if(availableCapacity(vehicle) == 0){
            if(getBalance(toHub) < 0){
                weight += ((getBalance(toHub) > availableCapacity(vehicle)) ? availableCapacity(vehicle) : getBalance(toHub)) / edge->distance;
                weight += ((getBalance(toHub) <= vehicle->inventory) ? 1 : 0);
            }
            else if(getBalance(toHub) > 0){
                weight = -1000000;
            }
        }
        else if(vehicle->inventory == 0){
            /*
            if(getBalance(toHub) > 0){
                weight += ((getBalance(toHub) < availableCapacity(vehicle)) ? availableCapacity(vehicle) : getBalance(toHub)) / edge->distance;
                weight += ((getBalance(toHub) >= vehicle->inventory) ? 1 : 0);
            }
            else if(getBalance(toHub) < 0){
                weight = -1000000;
            }
            */
        }
        else if(availableCapacity(vehicle) != 0){
            
        }
    }
    else{
        /*FIXME*/
        weight = -1000000;
    }
    
    return weight;
}
#include <stdio.h>
#include <stdlib.h>
#include "FileHandler.h"
#include "Vehicle.h"

int *PBTE412(Graph *graph, Vehicle *vehicle, int startHubIndex, int *seqLength);
void calcEdgeWeights(Graph *graph, Vehicle *vehicle, int from);
double calcEdgeWeight(Graph *graph, Vehicle *vehicle, int from, int to);

int main(void) {
    Graph *graph = malloc(sizeof(Graph));
    Vehicle *vehicles;
    int seqLength = 0;
    int *seq = NULL;
    
    readFile("DB/file.txt", &vehicles, graph);
    
    seq = PBTE412(graph, &vehicles[0], 0, &seqLength);
    printf("seqLen:%i\n", seqLength);
    
    free(graph->hubs);
    free(graph);
    return EXIT_SUCCESS;
}

int *PBTE412(Graph *graph, Vehicle *vehicle, int startHubIndex, int *seqLength){
    int *seq = calloc(1000, sizeof(int));
    int location = startHubIndex, nextLocation;
    int allBalance = 0;
    doVehicleActionAtHub(&graph->hubs[location], vehicle);
    (*seqLength) = 0;
    
    while((allBalance = CalcAllBalance(graph)) == 0){
        /* Weight edges */
        calcEdgeWeights(graph, vehicle, location);
        
        /* Find most optimal hub */
        nextLocation = getBestHubIndex(graph, location);
        
        /* Go to best hub */
        seq[(*seqLength)] = location;
        (*seqLength)++;
        location = nextLocation;
        
        /* Choose action at hub */
        int action = doVehicleActionAtHub(&graph->hubs[location], vehicle);
    }
    
    return seq;
}

void calcEdgeWeights(Graph *graph, Vehicle *vehicle, int from){
    int hIndex = 0;
    for(hIndex = 0; hIndex < graph->hubAmount; ++hIndex){
        getEdge(graph, from, hIndex)->weight = calcEdgeWeight(graph, vehicle, from, hIndex);
    }
}

double calcEdgeWeight(Graph *graph, Vehicle *vehicle, int from, int to){
    double weight = 0;
    Hub 
        *fromHub = &graph->hubs[from],
        *toHub = &graph->hubs[to];
    Edge *edge = getEdge(graph, from, to);
    
    if(from == to){
        weight = 0;
    }
    else{
        if(getBalance(toHub) < 0 && vehicle->inventory + getBalance(toHub) >= 0) {        
            weight += 1;
        }
        else if(getBalance(toHub) > 0 && availableCapacity(vehicle) - getBalance(toHub) >= 0){
            weight += 1;
        }
        else{
            
            weight = 0;
        }
        
        weight /= (edge->distance/10);
        weight /= abs(((double)vehicle->capacity) / 2.0 - (((double)vehicle->inventory) + abs(getBalance(toHub))));        
    }

    return weight;
}
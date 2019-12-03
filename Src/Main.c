#include <stdio.h>
#include <stdlib.h>
#include "FileHandler.h"
#include "Vehicle.h"
#include "VehicleAction.h"

/**
 * This function is ued by the algorithm to calculate all the edge weights.
 * The higher the weight the better.
 * @param graph is the graph the vehicle traverses on the edges
 * @param vehicle is the vehicle used to rebalance the graph network of hubs
 * @param from is the hub index of the current location of the vehicle
 * @param to is the hub index of the vehicle destination it should give a weight for if it goes there.
 * @returns the weight for the vehicle if it goes from -> to
 */
typedef double (getEdgeWeight)(Graph *graph, Vehicle *vehicle, int from, int to);

/**
 * This is the "Probaly Better Than Experience 412" algorithm that returns a sequence of hubs to visit which will create "balance"
 * @param graph is the graph the vehicle traverses on the edges
 * @param vehicle is the vehicle used to rebalance the graph network of hubs
 * @param startHubIndex is the index of the first hub
 * @param seqLength is the length of the sequence returned
 * @param getEdgeWeight is the function used by the algorithm to calculate the edge weights
 * @returns the sequence of hubs to visit with the vehicle
 */
VehicleAction *PBTE412(Graph *graph, Vehicle *vehicle, int startHubIndex, int *seqLength, getEdgeWeight getWedgeWeights);

/**
 * Calculates the weight from a point in a graph to all the neighbours using the getEdgeWeight function.
 * @param graph is the graph the vehicle traverses on the edges
 * @param vehicle is the vehicle used to rebalance the graph network of hubs
 * @param from is the location of the vehicle
 */
void calcEdgeWeights(Graph *graph, Vehicle *vehicle, int from, getEdgeWeight getWedgeWeight);

/* Edge weight calculators */
double calcEdgeWeight1(Graph *graph, Vehicle *vehicle, int from, int to);
double calcEdgeWeight2(Graph *graph, Vehicle *vehicle, int from, int to);

int main(void) {
    /* Allocate for graph and vehicle */
    Graph *graph = malloc(sizeof(Graph));
    Vehicle *vehicles;
    
    /* Make variables fot the sequence returned by the algorithm */
    int seqLength = 0, i;
    VehicleAction *seq = NULL;
    
    /* Read file.txt data */
    readFile("DB/file.txt", &vehicles, graph);
    
    /* Ask user for vehicle type */
    
    /* Get the sequence from the algorithm */
    seq = PBTE412(graph, &vehicles[0], 0, &seqLength, calcEdgeWeight2);
    printVehicleActions(seq, seqLength);
    
    /* Clean up */
    free(graph->hubs);
    free(graph);
    
    return EXIT_SUCCESS;
}

VehicleAction *PBTE412(Graph *graph, Vehicle *vehicle, int startHubIndex, int *seqLength, getEdgeWeight getEdgeWeight){
    VehicleAction *seq = calloc(1000, sizeof(VehicleAction));
    int location = startHubIndex, nextLocation, action;
    (*seqLength) = 1; /* We count the starting location */
    
    while(CalcAllBalance(graph) == 0){
        /* Weight edges */
        calcEdgeWeights(graph, vehicle, location, getEdgeWeight);
        
        /* Find most optimal hub */
        nextLocation = getBestHubIndex(graph, location);
        
        /* Go to best hub */
        location = nextLocation;
        
        /* Choose action at hub */
        action = doVehicleActionAtHub(&graph->hubs[location], vehicle);
        
        /* Save action and location */
        seq[*seqLength].action = action;
        seq[*seqLength].hubIndex = location;
        (*seqLength)++;
    }
    
    return seq;
}

void calcEdgeWeights(Graph *graph, Vehicle *vehicle, int from, getEdgeWeight getEdgeWeight){
    int hIndex = 0;
    for(hIndex = 0; hIndex < graph->hubAmount; ++hIndex){
        getEdge(graph, from, hIndex)->weight = getEdgeWeight(graph, vehicle, from, hIndex);
    }
}

double calcEdgeWeight1(Graph *graph, Vehicle *vehicle, int from, int to){
    double weight = 0;
    Hub 
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
        
        /**
         * Calculates the weight where distance is taking into account
         * Distance is the factor that has the highest impact on the calculation on the weight
         * Distance is divided by 10 which is a factor that has been chosen.
         */
        weight /= (edge->distance/10);
        /**
         * Calculates the weight, but the distance has the highest impact 
         * abs return the absolute value which is always positive 
         * capcacity of the vechicle has been taking into account 
         * inventory of the vechile has been taking into account
         * getBalance which can be negative or positive has been taking into account
         */
        weight /= abs(((double)vehicle->capacity) / 2.0 - (((double)vehicle->inventory) + abs(getBalance(toHub))));        
    }

    return weight;
}

double calcEdgeWeight2(Graph *graph, Vehicle *vehicle, int from, int to){
    int bestActionAtHub = getVehicleActionAtHub(&graph->hubs[to], vehicle);
    double weight = 0;
    /* If zero the hub is either in balance or the vehicle cant perform an action 
     * at the hub such as delivering and picking up inventory */
    if(bestActionAtHub != 0)
    {
        weight = abs(bestActionAtHub);
        /* Value the amount of work per distance unit */
        weight /= getEdge(graph, from, to)->distance;
    }
    return weight;
}
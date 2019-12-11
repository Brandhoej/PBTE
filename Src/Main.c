#include <stdio.h>
#include <stdlib.h>
#include "FileHandler.h"
#include "Vehicle.h"
#include "Sequence.h"
#include "VehicleAction.h"

#define MAX_ACT_SIZE (1000)
#define FILE_PATH "DB/file.txt"

/**
 * This function is ued by the algorithm to calculate all the edge weights.
 * The higher the weight the better.
 * @param graph is the graph the vehicle traverses on the edges
 * @param vehicle is the vehicle used to rebalance the graph network of hubs
 * @param from is the hub index of the current location of the vehicle
 * @param to is the hub index of the vehicle destination it should give a weight for if it goes there.
 * @returns the weight for the vehicle if it goes from -> to. This weght must not be negative.
 */
typedef double (getEdgeWeight)(Graph *graph, Vehicle *vehicle, int from, int to);

/**
 * This is the "Probaly Better Than Experience 412" algorithm that returns a sequence of hubs to visit which will make eveyr hub meets its target inventory if possible.
 * If it is not possible to reach the target inventory of every hub then there are two outcomes.
 * It is possible that there are leftover bicycles but if this amount is lower or equal to the current capacity of the vehicle then the system still van reach balance
 * Else if there are too few bicycles unpredicted behaviour will happen
 * @param graph is the graph the vehicle traverses on the edges. Balance in relation to the hubs target inventory should be achiveable.
 * @param vehicle is the vehicle used to rebalance the graph network of hubs. This vehicle can have leftover in the inventory bicycles when PBTE412 is done.
 * @param startHubIndex is the index of the first hub. Must be a hub in graph.
 * @param getEdgeWeight is the function used by the algorithm to calculate the edge weights.
 * @returns the sequence of hubs to visit with the vehicle which creates balance.
 */
Sequence *PBTE412(Graph *graph, Vehicle *vehicle, int startHubIndex, getEdgeWeight getWedgeWeights);

/**
 * Calculates the weight from a point in a graph to all its connecting hubs using the getEdgeWeight function.
 * @param graph is the graph the vehicle traverses on the edges
 * @param vehicle is the vehicle used to rebalance the graph network of hubs
 * @param from is the location of the vehicle
 */
void calcEdgeWeights(Graph *graph, Vehicle *vehicle, int from, getEdgeWeight getWedgeWeight);

/* Edge weight calculators */
double calcEdgeWeight1(Graph *graph, Vehicle *vehicle, int from, int to);
double calcEdgeWeight2(Graph *graph, Vehicle *vehicle, int from, int to);

int main(void) {
    int vehicleAmount = 0, vehicleIndex = 0, startingHub = 0, i = 0;
    /* Allocate for graph and vehicle */
    Graph *graph = malloc(sizeof(Graph));
    Vehicle *vehicles = NULL;
    
    /* Make variables fot the sequence returned by the algorithm */
    Sequence *sequence = NULL;
    
    /* Read file.txt data */
    readFile(FILE_PATH, &vehicles, graph, &vehicleAmount);
    
    /* Print vehicles and their indicies */
    for(i = 0; i < vehicleAmount; ++i){
        printf("%1i :: %2i/%-2i\n", i, vehicles[i].inventory,  vehicles[i].capacity);
    }
    
    /* Read user vehicle input */
    printf("Which vehicle do you want?> ");
    if(scanf(" %i", &vehicleIndex) == 1){
        printf("At which hub should the vehicle start [%i; %i]?>", 0, graph->hubAmount - 1);
        if(scanf(" %i", &startingHub)){
            /* Get the sequence from the algorithm */
            sequence = PBTE412(graph, &vehicles[vehicleIndex], startingHub, calcEdgeWeight2);
            printSequence(sequence);
        }
    }

    freeGraph(graph);
    free(vehicles);
    
    freeGraph(graph);
    free(vehicles);
    
    return EXIT_SUCCESS;
}

Sequence *PBTE412(Graph *graph, Vehicle *vehicle, int startHubIndex, getEdgeWeight getEdgeWeight){
    Sequence *sequence = malloc(sizeof(Sequence));
    VehicleAction *actions = calloc(MAX_ACT_SIZE, sizeof(VehicleAction)), *temp = NULL;
    Edge *edge = NULL;
    int location = startHubIndex, nextLocation, action;
    int seqLength = 0;
    
    while(calcAllBalance(graph) == 0){
        /* Choose action at hub */
        action = doVehicleActionAtHub(getHub(graph, location), vehicle);

        /* Save action and location */
        actions[seqLength].action = action;
        actions[seqLength].hubIndex = location;
        sequence->totalDistance += (edge == NULL) ? 0 : edge->distance;
        seqLength++;
    
        /* Weight edges */
        calcEdgeWeights(graph, vehicle, location, getEdgeWeight);

        /* Find most optimal hub */
        nextLocation = getBestHubIndex(graph, location);

        /* Store edge */
        edge = getEdge(graph, location, nextLocation);
        
        /* Go to best hub */
        location = nextLocation;
    }
    
    /* Free unused VehicleActions */
    if((temp = realloc(actions, seqLength * sizeof(VehicleAction))) != NULL) {
        actions = temp;
    }
    
    sequence->actions = actions;
    sequence->actionsLength = seqLength;
    
    return sequence;
}

void calcEdgeWeights(Graph *graph, Vehicle *vehicle, int from, getEdgeWeight getEdgeWeight){
    int hIndex = 0;
    for(hIndex = 0; hIndex < graph->hubAmount; ++hIndex){
        getEdge(graph, from, hIndex)->weight = getEdgeWeight(graph, vehicle, from, hIndex);
    }
}

double calcEdgeWeight1(Graph *graph, Vehicle *vehicle, int from, int to){
    double weight = 0;
    Hub *toHub = getHub(graph, to);
    Edge *edge = getEdge(graph, from, to);
    
    if(from == to){
        weight = 0;
    }
    else{
        if(getBalance(toHub) < 0 && vehicle->inventory > 0) { 
            weight = 10;
            if (getBalance(toHub) + vehicle->inventory >= 0) {
                weight += 25;
            }
        }
        else if(getBalance(toHub) > 0 && availableCapacity(vehicle) > 0){
            weight = 10;
            if (availableCapacity(vehicle) - getBalance(toHub) >= 0)
                weight += 25;
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
        weight /= abs(((double)vehicle->capacity) / 2.0 - (((double)vehicle->inventory) + (double)abs(getBalance(toHub))));
    }
    
    return weight;
}

double calcEdgeWeight2(Graph *graph, Vehicle *vehicle, int from, int to){
    /* TODO: Maybe prioritize getting rid of the complete inventory of the vehicle if it is possible near by
     * and to fill the inventory to the capacity if close by higher */
    int bestActionAtHub = getVehicleActionAtHub(getHub(graph, to), vehicle),
        balanceAtDestination = 0;
    double weight = 0;
    /* If zero the hub is either in balance or the vehicle cant perform an action 
     * at the hub such as delivering and picking up inventory. If positive the vehicle picks up inventory */
    if(bestActionAtHub != 0)
    {
        weight += abs(bestActionAtHub);
        balanceAtDestination = getBalance(getHub(graph, to));
        
        /* Best action is to pick up */
        if(bestActionAtHub > 0){
            /* Weight creating balance at the hub higher */
            if(availableCapacity(vehicle) >= abs(balanceAtDestination)){
               weight += abs(bestActionAtHub);
            }
        }
        /* Best action is to deliver */
        else{
            /* Weight creating balance at the hub higher */
            if(vehicle->inventory >= abs(balanceAtDestination)){
               weight += abs(bestActionAtHub);
            }
        }
        weight /= getEdge(graph, from, to)->distance;
    }
    return weight;
}
#include <stdio.h>
#include <stdlib.h>
#include "FileHandler.h"
#include "Vehicle.h"
#include "Sequence.h"
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
Sequence *PBTE412(Graph *graph, Vehicle *vehicle, int startHubIndex, int *seqLength, getEdgeWeight getWedgeWeights);

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
    int vehicleAmount = 0, vehicleIndex = 0, i = 0;
    /* Allocate for graph and vehicle */
    Graph *graph = malloc(sizeof(Graph));
    Vehicle *vehicles = NULL;
    
    /* Make variables fot the sequence returned by the algorithm */
    int sequenceLength = 0;
    Sequence *sequence = NULL;
    
    /* Read file.txt data */
    readFile("DB/file.txt", &vehicles, graph, &vehicleAmount);
    
    /* Ask user for vehicle type */
    /* Print vehicles and their indicies */
    for(i = 0; i < vehicleAmount; ++i){
        printf("%2i :: %2i/%-2i\n", i, vehicles[i].inventory,  vehicles[i].capacity);
    }
    /* Read user vehicle input */
    printf("Which vehicle do you want?> ");
    if(scanf(" %i", &vehicleIndex) == 1){
        /* Get the sequence from the algorithm */
        sequence = PBTE412(graph, &vehicles[vehicleIndex], 0, &sequenceLength, calcEdgeWeight1);
        printSequence(sequence);
    }
    
    /* Clean up */
    freeGraph(graph);
    freeSequence(sequence);
    
    return EXIT_SUCCESS;
}

Sequence *PBTE412(Graph *graph, Vehicle *vehicle, int startHubIndex, int *seqLength, getEdgeWeight getEdgeWeight){
    int currentActionSize = graph->hubAmount;
    Sequence *sequence = malloc(sizeof(Sequence));
    VehicleAction *actions = calloc(currentActionSize, sizeof(VehicleAction));
    Edge *edge = NULL;
    int location = startHubIndex, nextLocation, action;
    (*seqLength) = 0;
    
    /* Do action at start hub */
    action = doVehicleActionAtHub(&graph->hubs[location], vehicle);
    actions[*seqLength].action = action;
    actions[*seqLength].hubIndex = location;
    (*seqLength)++;
        
    while(CalcAllBalance(graph) == 0){
        /* If the sequence length now extends the array then resize */
        if(*seqLength >= currentActionSize){
            currentActionSize = *seqLength + graph->hubAmount;
            actions = realloc(actions, currentActionSize * sizeof(VehicleAction));
        }
        
        /* Weight edges */
        calcEdgeWeights(graph, vehicle, location, getEdgeWeight);

        /* Find most optimal hub */
        nextLocation = getBestHubIndex(graph, location);

        /* Store edge */
        edge = getEdge(graph, location, nextLocation);
        
        /* Go to best hub */
        location = nextLocation;
        
        /* Choose action at hub */
        action = doVehicleActionAtHub(&graph->hubs[location], vehicle);

        /* Save action and location */
        actions[*seqLength].action = action;
        actions[*seqLength].hubIndex = location;
        sequence->totalDistance += edge->distance;
        (*seqLength)++;
    }
    
    if(*seqLength != currentActionSize){
        actions = realloc(actions, *seqLength * sizeof(VehicleAction));
    }
    
    sequence->actions = actions;
    sequence->actionsLength = *seqLength;
    
    return sequence;
}

void calcEdgeWeights(Graph *graph, Vehicle *vehicle, int from, getEdgeWeight getEdgeWeight){
    int hIndex = 0;
    for(hIndex = 0; hIndex < graph->hubAmount; ++hIndex){
        getEdge(graph, from, hIndex)->weight = getEdgeWeight(graph, vehicle, from, hIndex);
        /*printf("Weight for hub %d, is %lf\n", hIndex, getEdgeWeight(graph, vehicle, from, hIndex));*/
    }
}

double calcEdgeWeight1(Graph *graph, Vehicle *vehicle, int from, int to){
    double weight = 0;
    Hub *toHub = &graph->hubs[to];
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
    int bestActionAtHub = getVehicleActionAtHub(&graph->hubs[to], vehicle);
    double weight = 0;
    /* If zero the hub is either in balance or the vehicle cant perform an action 
     * at the hub such as delivering and picking up inventory. If positive the vehicle picks up inventory */
    if(bestActionAtHub != 0)
    {
        weight += abs(bestActionAtHub);
        
        /* Best action is to pick up */
        if(bestActionAtHub > 0){
            /* Weight creating balance at the hub higher */
            if(availableCapacity(vehicle) >= abs(getBalance(&graph->hubs[to]))){
               weight += abs(bestActionAtHub);
            }
        }
        /* Best action is to deliver */
        else{
            /* Weight creating balance at the hub higher */
            if(vehicle->inventory >= abs(getBalance(&graph->hubs[to]))){
               weight += abs(bestActionAtHub);
            }
        }
        weight /= getEdge(graph, from, to)->distance;
    }
    return weight;
}
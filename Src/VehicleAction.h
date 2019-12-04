#include "Vehicle.h"

#pragma once

/**
 * @struct this struct contains data for a vehicle action at a hub on the graph stored by index.
 */
typedef struct VehicleAction
{
    /**
     * This is the action calculated for the vehicle to do at the hub
     */
    int action;
    
    /**
     * The hub index where the action is performed at by the vehicle
     */
    int hubIndex;
} VehicleAction;

void printVehicleActions(VehicleAction *action, int amount);
void printVehicleAction(VehicleAction *action);
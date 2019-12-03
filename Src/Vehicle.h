#pragma once

#include "Hub.h"

/**
 * @struct vehicle
 * This is the data structure for a vehicle which can be used as a rebalancing vehicle
 */
typedef struct Vehicle {
    
    /**
     * The current inventory of the vehicle
     */
    unsigned int inventory;
    
    /**
     * The maximum capacity of the vehicle (inclusive)
     */
    unsigned int capacity;
} Vehicle;

/**
 * calculates the available capcity (free space)
 * @param the vehicle to calculate the available capacity for
 * @return the available capacity for the vehicle
 */
unsigned int availableCapacity(Vehicle *v);

/**
 * Calculates the optimal action to perform at a hub by a vehicle.
 * @returns a negative number if the vehicle must deliver at the hub. If positive the vehicle takes inventory from the hub.
 */
int getVehicleActionAtHub(Hub *hub, Vehicle *vehicle);

/**
 * Performs an action on a hub. This action is calculated with getVehicleActionAtHub.
 * @returns the action performed at the hub. If negative the vehicle delivered inventory. If positive the vehicle gained inventory.
 */
int doVehicleActionAtHub(Hub *hub, Vehicle *vehicle);

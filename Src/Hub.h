#pragma once

#include "CuTest.h"

/**
 * @struct hub 
 * this is a data strcture for a hub used in the HCM
 */
typedef struct hub {
    
    /**
     * This is the current inventory of the hub
     */
    unsigned int inventory;
    
    /**
     * This is the maximum inventory allowed in this hub (inclusive)
     */
    unsigned int capacity;
    
    /**
     * This is the invenory that this hub need to be in balance
     */
    unsigned int targetInventory;
} hub;

/**
 * sets the target inventory of a hub.
 * @param *hub the hub pointer to the hub which needs to have the target inventory calculated and set
 * @TODO this should also depend on the graph and not just the information from the hub
 */
void calcTargetInventory(hub *hub);

/**
 * calculates the balance within the hub.
 * @param *hub points the hub to needed elements for calculating the balance 
 * @return If 0, there is balance in the hub. Negative, too few. Positive, too many bikes.
 */
int getBalance(hub *hub);

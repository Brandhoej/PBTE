/** @file */
#pragma once

/**
 * @struct hub
 * this is a data strcture for a hub used in the HCM
 */
typedef struct Hub {

    /**
     * This is the current inventory of the hub
     */
    unsigned int inventory;
    
    /**
     * This is the maximum inventory allowed in this hub (inclusive)
     */
    unsigned int capacity;

    /**
     * This is the inventory that this hub need to be in balance
     */
    unsigned int targetInventory;
} Hub;

/**
 * sets the target inventory of a hub.
 * @param *hub the hub pointer to the hub which needs to have the target inventory calculated and set
 * @TODO this should also depend on the graph and not just the information from the hub
 */
void calcTargetInventory(Hub *hub);

/**
 * calculates the balance within the hub.
 * @param *hub points the hub to needed elements for calculating the balance
 * @return If 0, there is balance in the hub. Negative, too few. Positive, too many bikes.
 */
int getBalance(Hub *hub);

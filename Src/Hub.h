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
     * If the balance is negative this hub needs that absolute bicycle amount of the balance
     * If the balance is positive this hub needs that many bicycles
     */
    int balance;
} hub;

/**
 * sets the balance amount of a hub.
 * @param *h the hub pointer to the hub which needs to have the balance calculated and set
 * @TODO this should also depend on the graph and not just the information from the hub
 */
void calcBalance(hub *h);
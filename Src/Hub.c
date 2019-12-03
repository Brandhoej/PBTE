#include "Hub.h"

void calcTargetInventory(Hub *hub){
    hub->targetInventory = hub->capacity / 2;
}

int getBalance(Hub *hub){
    return hub->inventory - hub->targetInventory;
}
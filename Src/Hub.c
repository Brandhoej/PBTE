#include "Hub.h"

void calcTargetInventory(hub *hub){
    hub->targetInventory = hub->capacity / 2;
}

int getBalance(hub *hub){
    return hub->inventory - hub->targetInventory;
}

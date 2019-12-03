#include <stdio.h>
#include "VehicleAction.h"

void printVehicleActions(VehicleAction *action, int amount){
    int i = 0;
    for(i = 0; i < amount; ++i){
        printVehicleAction(&action[i]);
    }
}

void printVehicleAction(VehicleAction *action){
    printf("%i (%i)\n", action->hubIndex, action->action);
}
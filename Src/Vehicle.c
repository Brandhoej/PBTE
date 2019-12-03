#include <stdio.h>
#include "Vehicle.h"

unsigned int availableCapacity(Vehicle *vehicle) {
    return vehicle->capacity - vehicle->inventory;
}

int getVehicleActionAtHub(Hub *hub, Vehicle *vehicle){
    int balance = getBalance(hub), action = 0;
    if(balance < 0){
        action = (-balance < vehicle->inventory) ? balance : -vehicle->inventory;
    }
    else if(balance > 0){
        action = (balance < availableCapacity(vehicle)) ? balance : availableCapacity(vehicle);
    }
    return action;
}

int doVehicleActionAtHub(Hub *hub, Vehicle *vehicle){
    int action = getVehicleActionAtHub(hub, vehicle);
    hub->inventory -= action;
    vehicle->inventory += action;
    return action;
}
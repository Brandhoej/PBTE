#include "Vehicle.h"

int availableCapacity(Vehicle *vehicle) {
    return vehicle->capacity - vehicle->inventory;
}
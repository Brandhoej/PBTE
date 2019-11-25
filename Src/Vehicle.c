#include "Vehicle.h"

int availableCapacity(vehicle *vehicle) {
    return vehicle->capacity - vehicle->inventory;
}

#include "Vehicle.h"
#include "CuTest.h"

int availableCapacity(vehicle *vehicle) {
    return vehicle->capacity - vehicle->inventory;
}

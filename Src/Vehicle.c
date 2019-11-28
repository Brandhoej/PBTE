#include "Vehicle.h"
#include "CuTest.h"

unsigned int availableCapacity(vehicle *vehicle) {
    return vehicle->capacity - vehicle->inventory;
}

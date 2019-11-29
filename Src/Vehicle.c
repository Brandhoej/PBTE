#include "Vehicle.h"
#include "CuTest.h"

unsigned int availableCapacity(Vehicle *vehicle) {
    return vehicle->capacity - vehicle->inventory;
}

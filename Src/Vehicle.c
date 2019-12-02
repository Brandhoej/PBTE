#include "Vehicle.h"
#include "CuTest.h"

int availableCapacity(Vehicle *vehicle) {
    return vehicle->capacity - vehicle->inventory;
}

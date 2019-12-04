#include <stdio.h>
#include <stdlib.h>
#include "Sequence.h"
#include "Vehicle.h"

void printSequence(Sequence *sequence){
    printf("Amount of actions:%-2i    Total distance:%-2.1lf\n", sequence->actionsLength, sequence->totalDistance);
    printVehicleActions(sequence->actions, sequence->actionsLength);
}

void freeSequence(Sequence *Sequence){
    free(Sequence->actions);
}
#include "VehicleAction.h"

/**
 * @struct contains information about the sequence calculated by PBTE
 */
typedef struct Sequence{
    
    /**
     * The total distance of the path
     */
    double totalDistance;
    
    /**
     * The amount of actions
     */
    int actionsLength;
    
    /**
     * The actions in sequentiel order where the first element is the first action
     */
    VehicleAction *actions;
} Sequence;

/**
 * Prints the complete sequence
 */
void printSequence(Sequence *sequence);

/**
 * Frees the sequence
 */
void freeSequence(Sequence *Sequence);
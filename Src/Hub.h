#pragma once

#include "CuTest.h"

typedef struct hub {
    unsigned int inventory;
    unsigned int capacity;
    int balance;
    double weight;
} hub;

void calcBalance(hub *h);
/* void calcWeight(CuTest *tc); */


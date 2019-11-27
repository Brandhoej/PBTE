#include "Hub.h"

void calcBalance(hub *hub) {
    hub->balance = hub->capacity/2;
}

void calcWeight(hub *hub, CuTest *tc, int i) {
    int expected = 10;
    CuAssertIntEquals(tc, expected, i);
}

CuSuite *HubSuite(){
    CuSuite *suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, calcWeight);

    return suite;
}
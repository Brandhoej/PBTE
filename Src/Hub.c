#include "Hub.h"
#include "CuTest.h"

void calcBalance(hub *hub) {
    hub->balance = hub->capacity/2;
}

/*void calcWeight(hub *hub, CuTest *tc, int i);*/
void calcWeight(CuTest *tc) {
    int actual = 4;
    int expected = 10;
    CuAssertIntEquals(tc, expected, actual);
}

CuSuite *HubSuite(){
    CuSuite *suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, calcWeight);

    return suite;
}
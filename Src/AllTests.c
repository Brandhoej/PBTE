#include "CuTest.h"
#include "Hub.h"

CuSuite* HubSuite();

/* Runs all the CuTest suites */
void RunAllTests(void);

/* Hubs */
CuSuite *HubSuite();
void hubTestCalcWeight(CuTest *tc);

int main(void)
{
    RunAllTests();
    return 0;
}

void RunAllTests(void)
{
    CuString *output = CuStringNew();
    CuSuite* suite = CuSuiteNew();

    CuSuiteAddSuite(suite, HubSuite());

    CuSuiteRun(suite);
    CuSuiteSummary(suite, output);
    CuSuiteDetails(suite, output);
    printf("%s\n", output->buffer);
}

CuSuite *HubSuite() {
    CuSuite *suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, hubTestCalcWeight);
    return suite;
}

void hubTestCalcWeight(CuTest *tc) {
    unsigned int 
        expected = 5, 
        inventory = 5, 
        capacity = 10;
    hub h = {inventory, capacity, 0};
    calcBalance(&h);
    CuAssertIntEquals(tc, expected, h.balance);
}
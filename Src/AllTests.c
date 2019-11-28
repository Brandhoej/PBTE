#include "CuTest.h"
#include "Hub.h"

CuSuite* HubSuite();

void RunAllTests(void);

void calcWeight(CuTest *tc) ;
CuSuite *HubSuite();

/* Hubs */
void calcWeight(CuTest *tc);
CuSuite *HubSuite();

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

void calcWeight(CuTest *tc) {
    int actual = 4;
    int expected = 10;
    CuAssertIntEquals(tc, expected, actual);
}

CuSuite *HubSuite() {
    CuSuite *suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, calcWeight);

    return suite;
}

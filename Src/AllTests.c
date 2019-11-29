#include <stdlib.h>
#include "CuTest.h"
#include "Hub.h"
#include "Graph.h"

/* Runs all the CuTest suites */
void RunAllTests(void);

/* Hubs */
CuSuite *HubSuite();
void hubTestCalcTargetInventory(CuTest *ct);

/* Graph */
CuSuite *GraphSuite();
void graphTestInitGraph(CuTest *ct);
void graphTestGetEdgeIndex(CuTest *ct);
void graphTestEdgeAmount(CuTest *ct);

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
	CuSuiteAddSuite(suite, GraphSuite());

    CuSuiteRun(suite);
    CuSuiteSummary(suite, output);
    CuSuiteDetails(suite, output);
    printf("%s\n", output->buffer);
}

CuSuite *HubSuite() {
    CuSuite *suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, hubTestCalcTargetInventory);
    return suite;
}

void hubTestCalcTargetInventory(CuTest *ct) {
    unsigned int 
        expected = 5, 
        inventory = 5, 
        capacity = 10;
    hub hub = {0, 0, 0};
    hub.inventory = inventory;
    hub.capacity = capacity;
    calcTargetInventory(&hub);
    CuAssertIntEquals(ct, expected, hub.targetInventory);
}

CuSuite *GraphSuite(){
    CuSuite *suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, graphTestInitGraph);
    SUITE_ADD_TEST(suite, graphTestGetEdgeIndex);
    SUITE_ADD_TEST(suite, graphTestEdgeAmount);
    return suite;
}

void graphTestInitGraph(CuTest *ct){
    graph *graph = malloc(sizeof(graph));
    hub *hubs = calloc(5, sizeof(hub));
    
    hubs[0].inventory = 0; hubs[0].capacity =  0;
    hubs[1].inventory = 1; hubs[1].capacity =  2;
    hubs[2].inventory = 2; hubs[2].capacity =  3;
    hubs[3].inventory = 3; hubs[3].capacity =  9;
    hubs[4].inventory = 4; hubs[4].capacity = 10;
    
    calcTargetInventory(&hubs[8]);
    calcTargetInventory(&hubs[1]);
    calcTargetInventory(&hubs[2]);
    calcTargetInventory(&hubs[3]);
    calcTargetInventory(&hubs[4]); 

    CuAssertIntEquals(ct, 10, edgeAmount(5));
    initGraph(graph, hubs, 5);
    
    CuAssertIntEquals(ct, 0, hubs[0].inventory);
    CuAssertIntEquals(ct, 1, graph->hubs[1].inventory);

    CuAssertIntEquals(ct, 2, graph->hubs[1].capacity);
    CuAssertIntEquals(ct, 10, graph->hubs[4].capacity);

    free(graph);
    free(hubs);
}

void graphTestGetEdgeIndex(CuTest *ct){
    CuAssertIntEquals(ct, -1, getEdgeIndex(-1 ,1));
    CuAssertIntEquals(ct, -1, getEdgeIndex(-1 ,-2));
    CuAssertIntEquals(ct, -1, getEdgeIndex(1 ,1));
    CuAssertIntEquals(ct, 20, getEdgeIndex(6 ,5));
}

void graphTestEdgeAmount(CuTest *ct){
    CuAssertIntEquals(ct, -1, edgeAmount(-5));
    CuAssertIntEquals(ct, -1, edgeAmount(-1));
    CuAssertIntEquals(ct, 0, edgeAmount(1));
    CuAssertIntEquals(ct, 10, edgeAmount(5));
    CuAssertIntEquals(ct, 36, edgeAmount(9));
}
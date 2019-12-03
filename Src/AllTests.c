#include <stdlib.h>
#include "CuTest.h"
#include "Hub.h"
#include "Graph.h"
#include "FileHandler.h"

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
void graphTestTotalAmountBicycle(CuTest *ct);
void graphTestCalcAllBalance(CuTest *ct);

/* FileHandler */
CuSuite *FHSuite();
void FHTestReadFile(CuTest *ct);
void FHTestAmountInCategory(CuTest *ct);
void FHTestValueInCategory(CuTest *ct);

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
    CuSuiteAddSuite(suite, FHSuite());

    CuSuiteRun(suite);
    CuSuiteSummary(suite, output);
    CuSuiteDetails(suite, output);
    printf("%s\n", output->buffer);
}



/* Hubs */
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
    Hub hub = {0, 0, 0};
    hub.inventory = inventory;
    hub.capacity = capacity;
    calcTargetInventory(&hub);
    CuAssertIntEquals(ct, expected, hub.targetInventory);
}



/* Graph */
CuSuite *GraphSuite(){
    CuSuite *suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, graphTestInitGraph);
    SUITE_ADD_TEST(suite, graphTestGetEdgeIndex);
    SUITE_ADD_TEST(suite, graphTestEdgeAmount);
    SUITE_ADD_TEST(suite, graphTestTotalAmountBicycle);
    SUITE_ADD_TEST(suite, graphTestCalcAllBalance);
    return suite;
}

void graphTestInitGraph(CuTest *ct){
    Graph *graph = malloc(sizeof(Graph));
    Hub *hubs = calloc(5, sizeof(Hub));

    hubs[0].inventory = 9; hubs[0].capacity =  5;
    hubs[1].inventory = 1; hubs[1].capacity =  2;
    hubs[2].inventory = 2; hubs[2].capacity =  3;
    hubs[3].inventory = 3; hubs[3].capacity =  9;
    hubs[4].inventory = 4; hubs[4].capacity = 10;
    
    calcTargetInventory(&hubs[0]);
    calcTargetInventory(&hubs[1]);
    calcTargetInventory(&hubs[2]);
    calcTargetInventory(&hubs[3]);
    calcTargetInventory(&hubs[4]); 

    CuAssertIntEquals(ct, 10, edgeAmount(5));
    initGraph(graph, hubs, 5);
    
    CuAssertIntEquals(ct, 9, graph->hubs[0].inventory);
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

void graphTestTotalAmountBicycle(CuTest *ct){
    Graph *graph = malloc(sizeof(Graph));
    Hub *hubs = calloc(5, sizeof(Hub));
    unsigned int expected = 19;

    hubs[0].inventory = 9; hubs[0].capacity =  5;
    hubs[1].inventory = 1; hubs[1].capacity =  2;
    hubs[2].inventory = 2; hubs[2].capacity =  3;
    hubs[3].inventory = 3; hubs[3].capacity =  9;
    hubs[4].inventory = 4; hubs[4].capacity = 10;

    initGraph(graph, hubs, 5);

    CuAssertIntEquals(ct, expected, totalAmountBicycle(graph));

    free(graph);
    free(hubs);
}

void graphTestCalcAllBalance(CuTest *ct){
    Graph *graph = malloc(sizeof(Graph));
    Hub *hubs = calloc(5, sizeof(Hub));
    int expected = 1;

    hubs[0].inventory = 2; hubs[0].capacity =  4;
    hubs[1].inventory = 1; hubs[1].capacity =  2;
    hubs[2].inventory = 6; hubs[2].capacity =  12;
    hubs[3].inventory = 2; hubs[3].capacity =  4;
    hubs[4].inventory = 7; hubs[4].capacity = 14;

    initGraph(graph, hubs, 5);

    calcTargetInventory(&hubs[0]);
    calcTargetInventory(&hubs[1]);
    calcTargetInventory(&hubs[2]);
    calcTargetInventory(&hubs[3]);
    calcTargetInventory(&hubs[4]);

    CuAssertIntEquals(ct, expected, CalcAllBalance(graph));

    free(graph);
    free(hubs);
}


/* FileHandler */
CuSuite *FHSuite() {
    CuSuite *suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, FHTestReadFile);
	SUITE_ADD_TEST(suite, FHTestAmountInCategory);
	SUITE_ADD_TEST(suite, FHTestValueInCategory);
    return suite;
}

void FHTestReadFile(CuTest *ct) {
    int expected = 1,
        readFileSuccessfully;
    Vehicle *vehicles = NULL;
    Graph *graph = malloc(sizeof(Graph));
    
    readFileSuccessfully = readFile("DB/file.txt", &vehicles, graph);
    free(graph);
    CuAssertIntEquals(ct, expected, readFileSuccessfully);
}

void FHTestAmountInCategory(CuTest *ct){
    int expected = 6, getAmountInCategory;
	FILE *DBFile = fopen("DB/file.txt", "r");

	getAmountInCategory = amountInCategory("Edges", DBFile);
	CuAssertIntEquals(ct, expected, getAmountInCategory);
}

void FHTestValueInCategory(CuTest *ct){
	int expected = 1, getValueInCategory;
	Graph *graph = malloc(sizeof(Graph));
	FILE *DBFile = fopen("DB/file.txt", "r");
	int vehicleAmount = amountInCategory("Vehicles", DBFile);
	int hubAmount = amountInCategory("Hubs", DBFile);
	Hub *hubs = calloc(hubAmount, sizeof(Hub));
	Vehicle *vehicles = calloc(vehicleAmount, sizeof(Vehicle));

	initGraph(graph, hubs, hubAmount);
	getValueInCategory = valueInCategory("Edges", DBFile, vehicles, graph);
	free(graph);
	CuAssertIntEquals(ct, expected, getValueInCategory);
}

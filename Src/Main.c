#include <stdio.h>
#include <stdlib.h>
#include "FileHandler.h"

void addEdgeTest(graph *graph, int u, int v, double distance){
	struct edge *e = malloc(8);
	printf("test2 %i\n", 8);
	e->distance = distance;
	printf("test3\n");
	addEdge(graph, u, v, e);
	printf("test4\n");
}

void createGraphTest(graph *graph){
      
    hub *hubs = calloc(9, sizeof(hub));
    hubs[0].balance = 0;
    hubs[1].balance = 2;
    hubs[2].balance = 1;
    hubs[3].balance = -4;
    hubs[4].balance = 0;
    hubs[5].balance = 5;
    hubs[6].balance = 2;
    hubs[7].balance = 3;
    hubs[8].balance = -9;

    initGraph(graph, hubs, 9);

	printf("H1 = %i, H2 = %i, edgeindex = %i\n", 2, 4, getEdgeIndex(2,4));


    addEdgeTest(graph, 0, 1, 1);
    addEdgeTest(graph, 0, 2, 2);
    addEdgeTest(graph, 0, 3, 1);
    addEdgeTest(graph, 0, 4, 2);
    addEdgeTest(graph, 0, 5, 3);
    addEdgeTest(graph, 0, 6, 2);
    addEdgeTest(graph, 0, 7, 3);
    addEdgeTest(graph, 0, 8, 4);
    printf("test\n");
    addEdgeTest(graph, 1, 2, 1);
    addEdgeTest(graph, 1, 3, 2);
    addEdgeTest(graph, 1, 4, 1);
    addEdgeTest(graph, 1, 5, 2);
    addEdgeTest(graph, 1, 6, 3);
    addEdgeTest(graph, 1, 7, 2);
    addEdgeTest(graph, 1, 8, 3);

    addEdgeTest(graph, 2, 3, 3);
    addEdgeTest(graph, 2, 4, 2);
    addEdgeTest(graph, 2, 5, 1);
    addEdgeTest(graph, 2, 6, 4);
    addEdgeTest(graph, 2, 7, 3);
    addEdgeTest(graph, 2, 8, 2);

    addEdgeTest(graph, 3, 4, 3);
    addEdgeTest(graph, 3, 5, 2);
    addEdgeTest(graph, 3, 6, 1);
    addEdgeTest(graph, 3, 7, 2);
    addEdgeTest(graph, 3, 8, 3);

    addEdgeTest(graph, 4, 5, 1);
    addEdgeTest(graph, 4, 6, 2);
    addEdgeTest(graph, 4, 7, 1);
    addEdgeTest(graph, 4, 8, 2);

    addEdgeTest(graph, 5, 6, 3);
    addEdgeTest(graph, 5, 7, 2);
    addEdgeTest(graph, 5, 8, 1);

    addEdgeTest(graph, 6, 7, 1);
    addEdgeTest(graph, 6, 8, 2);

    addEdgeTest(graph, 7, 8, 1);
}

int main(void) {
   /*
    graph *graph = malloc(sizeof(graph));
    hub h1 = { 0,0,0,0 };
    hub h2 = { 1,1,1,1 };
    hub *hs = calloc(2, sizeof(hub));
    edge edge = { 0, 1,  2.69 };
    hs[0] = h1;
    hs[1] = h2;

    initGraph(graph, hs, 2);
    printf("%i\n", graph->hubs[1].balance);
    
    addEdge(graph, &edge);
    printf("0->1:%lf\n", graph->edges[0][1].distance);
    printf("1->0:%lf\n", graph->edges[1][0].distance);
    printf("0->0:%lf\n", graph->edges[0][0].distance);
   */
    graph *graph = malloc(sizeof(graph));
    createGraphTest(graph);
	printf("3\n");
    edge *edge = NULL;
	printf("1\n");
    getEdge(graph, 0, 3, edge);
	printf("2\n");
    printf("%s\n", (edge==NULL)?"NULL":"YEAA");
    printf("From H1->H4 er der %lf\n", edge->distance);
    return EXIT_SUCCESS;
}

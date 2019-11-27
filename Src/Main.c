#include <stdio.h>
#include <stdlib.h>
#include "FileHandler.h"

int main(void) {
    graph *graph = malloc(sizeof(graph));
    hub h1 = { 0,0,0,0 };
    hub h2 = { 1,1,1,1 };
    hub *hs = calloc(2, sizeof(hub));
    edge edge = {0, 1,  2.69 };
    hs[0] = h1;
    hs[1] = h2;

    initGraph(graph, hs, 2);
    printf("%i\n", graph->hubs[1].balance);

    addEdge(graph, &edge);
    printf("0->1:%lf\n", graph->edges[0][1].distance);
    printf("1->0:%lf\n", graph->edges[1][0].distance);
    printf("0->0:%lf\n", graph->edges[0][0].distance);

    writeFile("DB/file.txt", graph);

    return EXIT_SUCCESS;
}

#include <stdio.h>
#include <stdlib.h>
#include "FileHandler.h"

void addEdgeTest(graph *graph, int u, int v, double distance){
    edge e = {0, 0};
    e.distance = distance;
    addEdge(graph, u, v, &e);
}

void createGraphTest(graph *graph){
    hub *hubs = calloc(9, sizeof(hub));
    hubs[0].inventory = 4;  hubs[0].capacity = 8;  hubs[0].targetInventory = 4;
    hubs[1].inventory = 1;  hubs[1].capacity = 6;  hubs[1].targetInventory = 3;
    hubs[2].inventory = 0;  hubs[2].capacity = 2;  hubs[2].targetInventory = 1;
    hubs[3].inventory = 8;  hubs[3].capacity = 8;  hubs[3].targetInventory = 4;
    hubs[4].inventory = 2;  hubs[4].capacity = 4;  hubs[4].targetInventory = 2;
    hubs[5].inventory = 10; hubs[5].capacity = 10; hubs[5].targetInventory = 5;
    hubs[6].inventory = 5;  hubs[6].capacity = 6;  hubs[6].targetInventory = 3;
    hubs[7].inventory = 6;  hubs[7].capacity = 6;  hubs[7].targetInventory = 3;
    hubs[8].inventory = 0;  hubs[8].capacity = 18; hubs[8].targetInventory = 9;
    
    initGraph(graph, hubs, 9);

    addEdgeTest(graph, 0, 1, 1);
    addEdgeTest(graph, 0, 2, 2);
    addEdgeTest(graph, 0, 3, 1);
    addEdgeTest(graph, 0, 4, 2);
    addEdgeTest(graph, 0, 5, 3);
    addEdgeTest(graph, 0, 6, 2);
    addEdgeTest(graph, 0, 7, 3);
    addEdgeTest(graph, 0, 8, 4);

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
    graph *graph = malloc(sizeof(graph));
    
    createGraphTest(graph);
    
    printf("%i %i edge index is %i\n", 0, 0, getEdgeIndex(0 ,0));
    printf("%i %i edge index is %i\n", 0, 1, getEdgeIndex(0 ,1));
    printf("%i %i edge index is %i\n", 0, 2, getEdgeIndex(0 ,2));
    printf("%i %i edge index is %i\n", 0, 3, getEdgeIndex(0 ,3));
    printf("%i %i edge index is %i\n", 2, 1, getEdgeIndex(2 ,1));
    printf("%i %i edge index is %i\n", 2, 4, getEdgeIndex(2 ,4));
    printf("%i %i edge index is %i\n", 1, 1, getEdgeIndex(1 ,1));
    printf("%i %i edge index is %i\n", 2, 2, getEdgeIndex(2 ,2));
    
    free(graph->hubs);
    free(graph);
    return EXIT_SUCCESS;
}

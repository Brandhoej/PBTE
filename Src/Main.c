#include <stdio.h>
#include <stdlib.h>
#include "FileHandler.h"

int main(void) {
    graph *g = malloc(sizeof(graph));
    hub h1 = { 0,0,0,0 };
    hub h2 = { 1,1,1,1 };
    hub *hs = calloc(2, sizeof(hub));
    hs[0] = h1;
    hs[1] = h2;

    initGraph(g, hs, 2);
    printf("%d\n", g->hubs[1].balance);

    return EXIT_SUCCESS;
}
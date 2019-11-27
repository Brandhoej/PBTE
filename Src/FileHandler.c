#include <stdio.h>
#include <stdlib.h>
#include "FileHandler.h"

int readFile(char *fileName) {
    graph graph;
    char *string;
    FILE *DBFile = fopen(fileName, "r");
    if(DBFile == NULL)
        return EXIT_FAILURE;
    fgets(string, 30, DBFile);
<<<<<<< HEAD
    string[0];
=======
>>>>>>> f19c7d32dfcba746742fa53839cecfd90852120e

    fclose(DBFile);
    return EXIT_SUCCESS;
}

int writeFile(char *fileName, graph *graph) {
    FILE *DBFile = fopen(fileName, "w");
    if(DBFile == NULL)
        return EXIT_FAILURE;
    fwrite(graph, sizeof(struct graph), 1, DBFile);
    fclose(DBFile);
    return EXIT_SUCCESS;
}

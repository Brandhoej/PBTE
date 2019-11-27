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
    string[0];

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

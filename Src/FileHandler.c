#include <stdio.h>
#include <stdlib.h>
#include "FileHandler.h"

int readFile(char *fileName) {
    int succes = 0;
    /*graph graph;*/
    FILE *DBFile = fopen(fileName, "r");
    if(DBFile != NULL)
        succes = 1;

    fclose(DBFile);
    return succes;
}
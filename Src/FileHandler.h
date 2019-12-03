#pragma once

#include "Vehicle.h"
#include "Graph.h"

typedef enum Category {VEHICLES,HUBS,EDGES,ERROR} Category;

/**
 * @param path is the path to the file
 * @param vehicles is the array of vehicles read from the file
 * @param graph is the graph containing data from the file
 * @return returns 1 if file is found, otherwise 0
 */
int readFile(char *path, Vehicle **vehicles, Graph *graph);

void analyzeFile(FILE *DBFile, Vehicle **vehicles, Graph *graph);
int amountInCategory(char *category, FILE *DBFile);
int valueInCategory(char *category, FILE *DBFile, Vehicle *vehicles, Graph *graph);
int keepReading(char *lineInFile, FILE *DBFile);
int getLine(char *category, FILE *DBFile);
char* readNextLine(char *lineInFile, FILE *DBFile);

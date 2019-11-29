#pragma once

#include "Vehicle.h"
#include "Graph.h"

typedef enum Category {VEHICLES,HUBS,EDGES,ERROR} Category;

/**
 * Checks if it is possible to read a file.
 * @param path is the path to the file
 * @return returns 0 if failed 1 if succes 
 */
int readFile(char *path, Vehicle *vehicles, Graph *graph);
void analyzeFile(FILE *DBFile, Vehicle *vehicles, Graph *graph);
int amountInCategory(char *category, FILE *DBFile);
int valueInCategory(char *category, FILE *DBFile, Vehicle *vehicles, Graph *graph);
int keepReading(char *lineInFile, FILE *DBFile);
int getLine(char *category, FILE *DBFile);
char* readNextLine(char *lineInFile, FILE *DBFile);
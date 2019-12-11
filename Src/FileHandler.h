#pragma once

#include "Vehicle.h"
#include "Graph.h"

typedef enum List {VEHICLES,HUBS,EDGES,ERROR} List;

/**
 * @param list is the enum which will be converted
 * @returns a string representation of the list enum. 
 */
char *listToStr(List list);

/**
 * @param path is the path to the file
 * @param vehicles is the array of vehicles read from the file
 * @param graph is the graph containing data from the file
 * @param vehicleAmount is an output parameter that will be set to the amount of vehicles by analyzeFile
 * @return returns 1 if file is found, otherwise 0
 */
int readFile(char *path, Vehicle **vehicles, Graph *graph, int *vehicleAmount);

/**
 * @param DBfile the file containing all the graph and vehicle information
 * @param vehicles stores information about the different vehicles
 * @param vehicleAmount is an output parameter that will be set to the amount of vehicles read in the list
 * @param graph stores information about the graph
 */
void analyzeFile(FILE *DBFile, Vehicle **vehicles, Graph *graph, int *vehicleAmount);

/**
 * @param list the list containing information (Vehicles, Hubs, Edges)
 * @param DBFile the file containing all the graph and vehicle information
 * @return returns the amount of lines belonging to @param list
 */
int amountInList(char *list, FILE *DBFile);

/**
 * @param list the list containing information (Vehicles, Hubs, Edges)
 * @param DBFile the file containing all the graph and vehicle information
 * @param vehicles stores information about the different vehicles
 * @param graph stores information about the graph
 * @return returns the amount of lines belonging to @param list
 */
int valueInList(char *list, FILE *DBFile, Vehicle *vehicles, Graph *graph);

/**
 * @param lineInFile the current line that is read from function: getLine
 * @param DBFile the file containing all the graph and vehicle information
 * @return returns 1 if the line belongs to the list, otherwise returns 0
 */
int keepReading(char *lineInFile, FILE *DBFile);

/**
 * @param list the list containing information (Vehicles, Hubs, Edges)
 * @param DBFile the file "cursor" is positioned at where the @param list is
 * @return returns 1 if the @param list was found in the file, otherwise returns 0
 */
int getLine(char *list, FILE *DBFile);

/**
 * @param lineInFile the current line that is read from function: getLine
 * @param DBFile the file containing all the graph and vehicle information
 * @return returns the line that was read
 */
char* readNextLine(char *lineInFile, FILE *DBFile);

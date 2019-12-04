#pragma once

#include "Vehicle.h"
#include "Graph.h"

typedef enum Category {VEHICLES,HUBS,EDGES,ERROR} Category;

/**
 * @param category is the enum which will be converted
 * @returns a string representation of the category enum. 
 */
char *CategoryToStr(Category category);

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
 * @param vehicleAmount is an output parameter that will be set to the amount of vehicles read in the category
 * @param graph stores information about the graph
 */
void analyzeFile(FILE *DBFile, Vehicle **vehicles, Graph *graph, int *vehicleAmount);

/**
 * @param category the category containing information (Vehicles, Hubs, Edges)
 * @param DBFile the file containing all the graph and vehicle information
 * @return returns the amount of lines belonging to @param category
 */
int amountInCategory(char *category, FILE *DBFile);

/**
 * @param category the category containing information (Vehicles, Hubs, Edges)
 * @param DBFile the file containing all the graph and vehicle information
 * @param vehicles stores information about the different vehicles
 * @param graph stores information about the graph
 * @return returns the amount of lines belonging to @param category
 */
int valueInCategory(char *category, FILE *DBFile, Vehicle *vehicles, Graph *graph);

/**
 * @param lineInFile the current line that is read from function: getLine
 * @param DBFile the file containing all the graph and vehicle information
 * @return returns 1 if the line belongs to the category, otherwise returns 0
 */
int keepReading(char *lineInFile, FILE *DBFile);

/**
 * @param category the category containing information (Vehicles, Hubs, Edges)
 * @param DBFile the file "cursor" is positioned at where the @param category is
 * @return returns 1 if the @param category was found in the file, otherwise returns 0
 */
int getLine(char *category, FILE *DBFile);

/**
 * @param lineInFile the current line that is read from function: getLine
 * @param DBFile the file containing all the graph and vehicle information
 * @return returns the line that was read
 */
char* readNextLine(char *lineInFile, FILE *DBFile);

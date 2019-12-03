#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FileHandler.h"

char *CategoryToStr(Category category){
	switch(category){
		case(VEHICLES): return "Vehicles"; break;
		case(HUBS):     return "Hubs"; break;
		case(EDGES):    return "Edges"; break;
		case(ERROR):    return "Errors"; break;
	}
}

int readFile(char *path, Vehicle **vehicles, Graph *graph) {
    int succes = 0;

    FILE *DBFile = fopen(path, "r");
    if(DBFile != NULL) {
		succes = 1;

		analyzeFile(DBFile, vehicles, graph);
	}

    fclose(DBFile);
    return succes;
}

void analyzeFile(FILE *DBFile, Vehicle **vehicles, Graph *graph) {
	int vehicleAmount = amountInCategory(CategoryToStr(VEHICLES), DBFile);
	int hubAmount = amountInCategory(CategoryToStr(HUBS), DBFile);

	Hub *hubs = calloc(hubAmount, sizeof(Hub));
	*vehicles = calloc(vehicleAmount, sizeof(Vehicle));

	initGraph(graph, hubs, hubAmount);
	valueInCategory(CategoryToStr(VEHICLES), DBFile, *vehicles, graph);
	valueInCategory(CategoryToStr(HUBS), DBFile, *vehicles, graph);
	valueInCategory(CategoryToStr(EDGES), DBFile, *vehicles, graph);
}

int amountInCategory(char *category, FILE *DBFile) {
	int amountCount = 0;
	char lineInFile[30];

	if (getLine(category, DBFile)) {
		while (keepReading(&lineInFile[0], DBFile))
			++amountCount;
	}
	else
		amountCount = -1;
	return amountCount;
}

int valueInCategory(char *category, FILE *DBFile, Vehicle *vehicles, Graph *graph) {
	int returnState = 1, indx = 0;
	int hubU, hubV;
	char name[10];
	char lineInFile[30];
	double edgeDistance;
	Category cat = -1;
	Edge edge;
	
	if (strcmp(category, CategoryToStr(VEHICLES)) == 0)
		cat = VEHICLES;
	else if (strcmp(category, CategoryToStr(HUBS)) == 0)
		cat = HUBS;
	else if (strcmp(category, CategoryToStr(EDGES)) == 0)
		cat = EDGES;
	else
		cat = ERROR;

	if (getLine(category, DBFile)) {
		while(keepReading(&lineInFile[0], DBFile)) {
			switch(cat) {
				case VEHICLES:
					sscanf(lineInFile, " %s %u", &name[0], &vehicles[indx].capacity);
					/* Name is not used (Will be added) */
					break;
				case HUBS:
					sscanf(lineInFile, " %s %u %u", &name[0], &graph->hubs[indx].inventory, &graph->hubs[indx].capacity);
					calcTargetInventory(&graph->hubs[indx]);
					/* Name is not used (Will be added) */
					break;
				case EDGES:
					sscanf(lineInFile, " %d %d %lf", &hubU, &hubV, &edgeDistance);
					edge.distance = edgeDistance;
					addEdge(graph, hubU, hubV, &edge);
					break;
				case ERROR:
					printf("ERROR\n");
					break;
			}
			++indx;
		}
	}
	else
		returnState = 0;

	return returnState;
}

int keepReading(char *lineInFile, FILE *DBFile) {
	char firstChar, secondChar;
	int returnState = 1;

	if (readNextLine(lineInFile, DBFile) == NULL)
		returnState = 0;
	else
		sscanf(lineInFile, "%c%c", &firstChar, &secondChar);

	return returnState ? (firstChar == ' ' && secondChar == ' ') : returnState;
}

int getLine(char *category, FILE *DBFile) {
	int returnState = 1;
	char firstString[10];
	char lineInFile[30];

	rewind(DBFile);

	do {
		if (readNextLine(lineInFile, DBFile) == NULL) {
			returnState = 0;
		}
		else {
			sscanf(lineInFile, " %s", firstString);	
		}
	} while (strcmp(firstString, category) != 0 && returnState);

	return returnState;
}

char* readNextLine(char *lineInFile, FILE *DBFile) {
	return fgets(lineInFile, 30, DBFile);
}
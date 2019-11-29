#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FileHandler.h"

int readFile(char *path, Vehicle *vehicles, Graph *graph) {
    int succes = 0;
	
    FILE *DBFile = fopen(path, "r");
    if(DBFile != NULL) {
		succes = 1;

		analyzeFile(DBFile, vehicles, graph);

	}

    fclose(DBFile);
    return succes;
}

void analyzeFile(FILE *DBFile, Vehicle *vehicles, Graph *graph) {
	int vehicleAmount = amountInCategory("Vehicles", DBFile);
	int hubAmount = amountInCategory("Hubs", DBFile);

	vehicles = calloc(vehicleAmount, sizeof(Vehicle));
	graph->edges = calloc(edgeAmount(hubAmount), sizeof(Edge));
	graph->hubs = calloc(hubAmount, sizeof(Hub));
	graph->hubAmount = hubAmount;
	
	valueInCategory("Vehicles", DBFile, vehicles, graph);
	valueInCategory("Hubs", DBFile, vehicles, graph);
	valueInCategory("Edges", DBFile, vehicles, graph);
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
	Edge edge;
	int edgeU, edgeV;
	char name[10];
	char lineInFile[30];
	Category cat = -1;
	
	if (strcmp(category, "Vehicles") == 0)
		cat = VEHICLES;
	else if (strcmp(category, "Hubs") == 0)
		cat = HUBS;
	else if (strcmp(category, "Edges") == 0)
		cat = EDGES;
	else
		cat = ERROR;

	if (getLine(category, DBFile)) {
		while(keepReading(&lineInFile[0], DBFile)) {
			switch(cat) {
				case VEHICLES:
					sscanf(lineInFile, " %s %d", &name[0], vehicles[indx].capacity);
					/* Name is not used (Will be added) */
					break;
				case HUBS:
					sscanf(lineInFile, " %s %d %d", &name[0], graph->hubs[indx].inventory, graph->hubs[indx].capacity);
					/* Name is not used (Will be added) */
					break;
				case EDGES:
					sscanf(lineInFile, " %d %d %d", &edgeU, &edgeV, getEdge(graph, edgeU, edgeV)->distance);

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

	if (readNextLine(lineInFile, DBFile))
		returnState = 0;
	sscanf(lineInFile, "%c%c", &firstChar, &secondChar);

	return returnState ? (firstChar == ' ' && secondChar == ' ') : returnState;
}

int getLine(char *category, FILE *DBFile) {
	int returnState = 1;
	char firstString[10];
	char lineInFile[30];

	rewind(DBFile);

	do {
		if (readNextLine(&lineInFile[0], DBFile) == NULL)
			returnState = 0;
		else
			sscanf(lineInFile, " %s", firstString);	
	} while (strcmp(firstString, category) != 0 && returnState);

	return returnState;
}

char* readNextLine(char *lineInFile, FILE *DBFile) {
	return fgets(&lineInFile[0], 30, DBFile);
}
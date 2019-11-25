
CC=gcc
CFLAGS = -Wall -ansi -pedantic

Main: Main.o Edge Filehandler.o Graph.o Hub.o Vehicle.o
	$(CC) Main.o Src/Edge.h Filehandler.o Graph.o Hub.o Vehicle.o -o Main

Main.o: Src/Main.c
	$(CC) -c Src/Main.c $(CFLAGS)

Edge: Src/Edge.h

Filehandler.o: Src/Filehandler.c
	$(CC) -c Src/Filehandler.c $(CFLAGS)

Graph.o: Src/Graph.c
	$(CC) -c Src/Graph.c $(CFLAGS)

Hub.o: Src/Hub.c
	$(CC) -c Src/Hub.c $(CFLAGS)

Vehicle.o: Src/Vehicle.c
	$(CC) -c Src/Vehicle.c $(CFLAGS)

clean:
	rm *.o Main.exe

#target: dependencies
#	action
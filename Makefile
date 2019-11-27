CC=gcc
DEPS=Src/Edge.h Filehandler.o Graph.o Hub.o Vehicle.o
APPFLAGS=Main.o
TFLAGS=AllTests.o CuTest.o

ifdef WAP
	CFLAGS = -Wall -ansi -pedantic
else
	CFLAGS =
endif

App: $(APPFLAGS) $(DEPS)
	$(CC) $(APPFLAGS) $(DEPS) -o App

Test: $(TFLAGS) $(DEPS)
	$(CC) $(TFLAGS) $(DEPS) -o Test

Main.o: Src/Main.c
	$(CC) -c Src/Main.c $(CFLAGS)

Filehandler.o: Src/Filehandler.c
	$(CC) -c Src/Filehandler.c $(CFLAGS)

Graph.o: Src/Graph.c
	$(CC) -c Src/Graph.c $(CFLAGS)

Hub.o: Src/Hub.c
	$(CC) -c Src/Hub.c $(CFLAGS)

Vehicle.o: Src/Vehicle.c
	$(CC) -c Src/Vehicle.c $(CFLAGS)

AllTests.o: Src/AllTests.c
	$(CC) -c Src/AllTests.c $(CFLAGS)

CuTest.o: Src/CuTest.c
	$(CC) -c Src/CuTest.c $(CFLAGS)

clean:
	rm *.o App.exe Test.exe

#target: dependencies
#	action

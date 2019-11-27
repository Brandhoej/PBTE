
CC=gcc
DEPS=Filehandler.o Graph.o Hub.o Vehicle.o
APPFLAGS=Main.o
TFLAGS=AllTests.o CuTest.o

ifneq ($(WAP), 0)
	CFLAGS = -Wall -ansi -pedantic
endif
CFLAGS += $(OPCFLAGS) #Add optinal input from user

App: $(APPFLAGS) $(DEPS)
	$(CC) $? $(CFLAGS) -o App

Test: $(TFLAGS) $(DEPS)
	$(CC) $? $(CFLAGS) -o Test

All: Test App

Main.o: Src/Main.c
	$(CC) -c $? $(CFLAGS)

Filehandler.o: Src/Filehandler.c
	$(CC) -c $? $(CFLAGS)

Graph.o: Src/Graph.c
	$(CC) -c $? $(CFLAGS)

Hub.o: Src/Hub.c
	$(CC) -c $? $(CFLAGS)

Vehicle.o: Src/Vehicle.c
	$(CC) -c $? $(CFLAGS)

AllTests.o: Src/AllTests.c
	$(CC) -c $? $(CFLAGS)

CuTest.o: Src/CuTest.c
	$(CC) -c $? $(CFLAGS)

clean:
	rm -f *.o Main.exe

#target: dependencies
#	action

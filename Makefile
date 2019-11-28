#How add to this file
#target: dependencies
#	action
#The target can be dependencies at other targets.

#'$?' is the name of the file to be made

#How to use/build the application:

#App
#if you want the release App with WAP then
#"make"
#if you want the relase but without WAP
#"make WAP=0"

#if you want the make the build with CuTest then
#It works like the other but this time you shall specify the make target
#fx. "make Test"

#if you want to add additional compiler flags then add
#"ADDCFLAGS=" and then the flags on the same line as calling make

#Build App example
#"make WAP=0 ADDCFLAGS=-std89"

#Build Test example
#"make Test WAP=0 ADDCFLAGS=-std89"

#These are variables used in the make file
#The way we access their value we use $(VAR). Fx. $(CFALGS)
#If the VAR name is single character it is possible to use $V. 
#For this brackets are not nessecary
CC=gcc
DEPS=Filehandler.o Graph.o Hub.o Vehicle.o
APPFLAGS=Main.o
TFLAGS=AllTests.o CuTest.o

#ifneq because we always want to compile with WAP
ifneq ($(WAP), 0)
	CFLAGS = -Wall -ansi -pedantic
endif

#Here OPCFLAGS is not declared in this makefile
#But in the prompt the user can fx. type "make App ADDCFLAGS=-std89"
CFLAGS += $(ADDCFLAGS) #Add optinal input from user

#Builds (App, Test and All which is both in one)
App: $(APPFLAGS) $(DEPS)
	$(CC) $? $(CFLAGS) -o App

Test: $(TFLAGS) $(DEPS)
	$(CC) $? $(CFLAGS) -o Test

All: Test App


#Compile targets
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
	rm -f *.o *.exe
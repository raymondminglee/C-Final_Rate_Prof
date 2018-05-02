# Definitions for constants
CC=g++
CFLAGS = -I. 

# This will create your final output using .o compiled files
make: main.o check.o create.o linedel.o linewrite.o Rate.o Professor.o
	$(CC) $(CFLAGS) -o main main.o check.o create.o linedel.o linewrite.o Rate.o Professor.o

main.o: main.cpp check.h create.h linedel.h linewrite.h Rate.h Professor.h
	$(CC) $(CFLAGS) -c main.cpp -o main.o

chek.o: check.cpp check.h
	$(CC) $(CFLAGS) -c check.cpp -o check.o 

create.o: create.cpp create.h
	$(CC) $(CFLAGS) -c create.cpp -o create.o


linedel.o: linedel.cpp linedel.h
	$(CC) $(CFLAGS) -c linedel.cpp -o linedel.o

linewrite.o: linewrite.cpp linewrite.h
	$(CC) $(CFLAGS) -c linewrite.cpp -o linewrite.o


Rate.o: Rate.cpp Rate.h
	$(CC) $(CFLAGS) -c Rate.cpp -o Rate.o

Professor.o: Professor.cpp Professor.h
	$(CC) $(CFLAGS) -c Professor.cpp -o Professor.o


# This will clean or remove compiled files so you can start fresh
clean:
	rm -f *.o *.exe getStuff/*.o

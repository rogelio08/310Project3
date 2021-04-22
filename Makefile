EXEC = dijkstra
CC = g++
CFLAGS = -c -Wall


$(EXEC) :main.o util.o graphAlgo.o node.o
	$(CC) -o $(EXEC) main.o util.o graphAlgo.o node.o


main.o:main.cpp 
	$(CC) $(CFLAGS) main.cpp

util.o:util.h util.cpp
	$(CC) $(CFLAGS) util.cpp

graphAlgo.o:graphAlgo.h graphAlgo.cpp
	$(CC) $(CFLAGS) graphAlgo.cpp

node.o:node.h node.cpp
	$(CC) $(CFLAGS) node.cpp

clean:
	rm *.o

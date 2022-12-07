CC = g++
CFLAGS = -Wall -g -w

output: main.o travelGraph.o tests.o utils.o
	$(CC) $(CFLAGS) main.o travelGraph.o tests.o utils.o -o output

test: catchmain.o tests.o travelGraph.o utils.o
	$(CC) $(CFLAGS) catchmain.o tests.o travelGraph.o utils.o -o test

catchmain.o: ./CS_Project/cs225/catch/catchmain.cpp ./CS_Project/cs225/catch/catch.hpp 
	$(CC) $(CFLAGS) -c ./CS_Project/cs225/catch/catchmain.cpp ./CS_Project/cs225/catch/catch.hpp 

tests.o: catchmain.o CS_Project/tests/tests.cpp
	$(CC) $(CFLAGS) -c CS_Project/tests/tests.cpp catchmain.o 

main.o: CS_Project/main.cpp
	$(CC) $(CFLAGS) -c CS_Project/main.cpp

travelGraph.o: CS_Project/travelGraph.cpp CS_Project/travelGraph.h
	$(CC) $(CFLAGS) -c CS_Project/travelGraph.cpp

utils.o: CS_Project/utils.cpp CS_Project/utils.h
	$(CC) $(CFLAGS) -c CS_Project/utils.cpp

clean:
	rm -f core *.o main tests

# edits: CC = clang++
# CFLAGS = -Wall -g -w -std=c++1y -clang
# LDFLAGS = -std=c++1y -stdlib=libc++ -lc++abi

# main: main.o travelGraph.o tests.o utils.o -o out
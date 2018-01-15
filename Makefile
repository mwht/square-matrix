all: main

main: main.cpp SquareMatrix.cpp
	rm -f -- kolo_squarematrix
	g++ -g -Wall -pedantic -o kolo_squarematrix main.cpp SquareMatrix.cpp

.PHONY: clean

clean:
	rm kolo_squarematrix

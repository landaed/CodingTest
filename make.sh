#!/bin/bash

g++ -std=c++11 -Wall -g -c ./src/rectangle2D.cpp -o ./bin/rectangle2D.o
g++ -std=c++11 -Wall -g -c ./src/main.cpp -o ./bin/main.o
g++ -std=c++11 -Wall -g -o build/app.exe ./bin/rectangle2D.o ./bin/main.o



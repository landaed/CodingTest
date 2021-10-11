#!/bin/bash

g++ -std=c++14 -Wall -g -c ./src/rectangle2D.cpp -o ./bin/rectangle2D.o
g++ -std=c++14 -Wall -g -c ./src/bst.cpp -o ./bin/bst.o
g++ -std=c++14 -Wall -g -c ./src/component.cpp -o ./bin/component.o
g++ -std=c++14 -Wall -g -c ./src/entityBuilder.cpp -o ./bin/entityBuilder.o
g++ -std=c++14 -Wall -g -o build/entityApp.exe ./bin/rectangle2D.o ./bin/bst.o ./bin/component.o ./bin/entityBuilder.o



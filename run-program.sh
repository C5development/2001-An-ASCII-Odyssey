#!/bin/bash

g++ -std=c++11 main.cpp -o an-ascii-odyssey.o

rc=$?; if [[ $rc != 0 ]];
then
    exit 1
fi

./an-ascii-odyssey.o

exit 0

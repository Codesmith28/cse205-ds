#!/bin/bash

# Move all files that end with .cpp from current directory to cp directory except run.cpp

for file in *.cpp
do
    if [ $file != "run.cpp" ]
    then
        mv $file cp
    fi
done

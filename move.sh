#!/bin/bash

for file in *.cpp
do
    if [ $file != "run.cpp" ]
    then
        echo "Moving file: $file -> cp directory"
        mv -f $file cp
    fi
done
echo "Done! All files have been moved to cp directory."
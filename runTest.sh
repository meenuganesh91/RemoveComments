#!/bin/bash
rm -f testRemoveComments.o
echo "Compiling removeComments.c"
gcc -o testRemoveComments.o removeComments.c testRemoveComments.c
echo "Running testRemoveComments.o"
./testRemoveComments.o

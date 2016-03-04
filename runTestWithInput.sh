#!/bin/bash
rm -f testRemoveCommentsWithInput.o
echo "Compiling removeComments.c"
gcc -o testRemoveCommentsWithInput.o removeComments.c testRemoveCommentsWithInput.c
echo "Running testRemoveCommentsWithInput.o"
./testRemoveCommentsWithInput.o -t "Hello how are you"
./testRemoveCommentsWithInput.o -t "Hi. Hello!!//Single line comment only.\n This is the first line!"
./testRemoveCommentsWithInput.o -t "Hi. Hello!!/*Multi line comment only.\n */ This is the first line!"
./testRemoveCommentsWithInput.o -t "//Starting with single line!\n/* Finishing with double line.*/"
./testRemoveCommentsWithInput.o -t "//Single line comment/*Multi inside single*/\n Hello!!"
./testRemoveCommentsWithInput.o -t "Hello!!/*Multi line comment//Single inside multi\n*/ Hello!!"

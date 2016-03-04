
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "removeComments.h"

//Function to remove C and C++ comments from an input string.
void removeComments(char *str) {
    int writepos = 0, readpos = 0;
    int isOneLineComment = 0;
    int isMultiLineComment = 0;
    int inString = 0;
    while (readpos<strlen(str)){
        if(writepos != readpos) {
            str[writepos] = str[readpos];
        }
        if(isOneLineComment == 1){
            if (str[readpos] == '\n') {
                isOneLineComment = 0;
            }
            else if(str[readpos] == '\\' && str[readpos+1] == 'n'){
                readpos++;
                isOneLineComment = 0;
            }
        }
        else if (isMultiLineComment == 1){
            if(str[readpos] == '*' && str[readpos+1] == '/'){
                readpos++;
                isMultiLineComment = 0;
            }
        }
        else if(str[readpos] == '/' && str[readpos+1] == '/' && inString == 0){
            isOneLineComment = 1;
        }
        else if(str[readpos] == '/' && str[readpos+1] == '*' && inString == 0){
            isMultiLineComment = 1;
        }
        else {
            if(str[readpos] == '\'' || str[readpos] == '\"') {
                inString = 1 - inString;
            }
            writepos++;
        }
        readpos++;
    }
    str[writepos] = '\0';
}

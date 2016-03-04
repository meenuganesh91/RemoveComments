//Program to remove C and C++ comments from an input string.
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//Function to remove C and C++ comments from an input string.
void removeComments(char *str) {
    int writepos = 0, readpos = 0;
    int isOneLineComment = 0;
    int isMultiLineComment = 0;
    while (readpos<strlen(str)){
        if(writepos != readpos) {
            str[writepos] = str[readpos];
        }
        if(isOneLineComment == 1){
            if (str[readpos] == '\n') {
                //writepos++;
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
        else if(str[readpos] == '/' && str[readpos+1] == '/'){
            isOneLineComment = 1;
        }
        else if(str[readpos] == '/' && str[readpos+1] == '*'){
            isMultiLineComment = 1;
        }
        else {
            writepos++;
        }
        readpos++;
    }
    str[writepos] = '\0';
    //str = (char *) realloc(str, writepos+1);
}

//Function to test removeComments()
void testRemoveComments(int testNum, char *original, char *expected){
    
    printf("Test case %d\n", testNum);
    printf("Original string :\n%s\n", original);
    removeComments(original);
    printf("New string : \n%s\n", original);
    if (strcmp(original, expected) == 0) {
        printf("Test result : Passed\n");
    }
    else{
        printf("Test result : Failed\n");
    }
    printf("------\n");
}


int main(){
    char *str = malloc(100);
    char *expectedString = malloc(100);
    strcpy(str, "Hi. Hello!!//Single line comment only.\n This is fun!");
    strcpy(expectedString, "Hi. Hello!! This is fun!");
    testRemoveComments(1,str, expectedString);
    free(str);
    free(expectedString);
    
    str = (char*)malloc(100);
    expectedString = (char*)malloc(100);
    strcpy(str, "Hi. Hello!!/*Multi line comment only.\n */ This is fun!");
    strcpy(expectedString, "Hi. Hello!! This is fun!");
    testRemoveComments(2,str, expectedString);
    free(str);
    free(expectedString);
    
    str = (char*)malloc(100);
    expectedString = (char*)malloc(100);
    strcpy(str, "//Starting with single line!\n/* Finishing with double line.*/");
    strcpy(expectedString, "");
    testRemoveComments(3,str, expectedString);
    free(str);
    free(expectedString);
    
    str = (char*)malloc(100);
    expectedString = (char*)malloc(100);
    strcpy(str, "//Single line comment/*Multi inside single*/\n Hello!!");
    strcpy(expectedString, " Hello!!");
    testRemoveComments(4,str, expectedString);
    free(str);
    free(expectedString);
    
    str = (char*)malloc(100);
    expectedString = (char*)malloc(100);
    strcpy(str, "Hello!!/*Multi line comment//Single inside multi\n*/ Hello!!");
    strcpy(expectedString, "Hello!! Hello!!");
    testRemoveComments(5,str, expectedString);
    free(str);
    free(expectedString);

    return 0;
}







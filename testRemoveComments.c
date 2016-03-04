#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "removeComments.h"

int testRemoveComments(int testNum, char *original, char *expected){
    
    printf("Test case %d\n", testNum);
    printf("Original string :\n%s\n", original);
    removeComments(original);
    printf("Formatted string : \n%s\n", original);
    if (strcmp(original, expected) == 0) {
        printf("Test result : Passed\n");
        printf("------\n");
        return 1;
    }
    else{
        printf("Test result : Failed\n");
        printf("------\n");
        return 0;
    }
}


int main(){
        int testStatus = 1;
    char *str = malloc(100);
    char *expectedString = malloc(100);
    strcpy(str, "Hi. Hello!!//Single line comment only.\n This is the next line!");
    strcpy(expectedString, "Hi. Hello!! This is the next line!");
    testStatus = testStatus * testRemoveComments(1, str, expectedString);
    free(str);
    free(expectedString);
    
        str = (char*)malloc(500);
    expectedString = (char*)malloc(500);
    strcpy(str, "Hi. Hello!!/*Multi line comment only.\n Next line of multi line comment\nAnother line of comment */ This is a line after comment!");
    strcpy(expectedString, "Hi. Hello!! This is a line after comment!");
    testStatus = testStatus * testRemoveComments(2, str, expectedString);
    free(str);
    free(expectedString);
    
        str = (char*)malloc(100);
    expectedString = (char*)malloc(100);
    strcpy(str, "//Starting with single line!\n/* Finishing with double line.\n Another line comment */");
    strcpy(expectedString, "");
    testStatus = testStatus * testRemoveComments(3, str, expectedString);
    free(str);
    free(expectedString);
    
        str = (char*)malloc(500);
    expectedString = (char*)malloc(500);
    strcpy(str, "//Starting with single line comment!\nThis is the first line.//Followed by a small comment\nThis is the second line.");
    strcpy(expectedString, "This is the first line.This is the second line.");
    testStatus = testStatus * testRemoveComments(4, str, expectedString);
    free(str);
    free(expectedString);
    
        str = (char*)malloc(500);
    expectedString = (char*)malloc(500);
    strcpy(str, "/*Starting with multi line comment\ncontinuing comment*/!\nThis is the first line./*Followed by a multi line comment\n that spans \n three lines*\\ and ends here*/\nThis is the second line.");
    strcpy(expectedString, "!\nThis is the first line.\nThis is the second line.");
    testStatus = testStatus * testRemoveComments(5, str, expectedString);
    free(str);
    free(expectedString);

        str = (char*)malloc(100);
    expectedString = (char*)malloc(100);
    strcpy(str, "//Single line comment/*Multi inside single*/\n Hello!!");
    strcpy(expectedString, " Hello!!");
    testStatus = testStatus * testRemoveComments(6, str, expectedString);
    free(str);
    free(expectedString);

        str = (char*)malloc(100);
    expectedString = (char*)malloc(100);
    strcpy(str, "Hello!!/*Multi line comment//Single inside multi\n*/ Have a great day!!");
    strcpy(expectedString, "Hello!! Have a great day!!");
    testStatus = testStatus * testRemoveComments(7, str, expectedString);
    free(str);
    free(expectedString);
    
        str = (char*)malloc(500);
    expectedString = (char*)malloc(500);
    strcpy(str, "/*Starting with multi line comment\ncontinuing comment*/This is the first line./*Followed by a multi line comment\n that spans \n three lines*\\nThis is the second line.");
    strcpy(expectedString, "This is the first line.");
    testStatus = testStatus * testRemoveComments(8, str, expectedString);
    free(str);
    free(expectedString);

        str = (char*)malloc(500);
    expectedString = (char*)malloc(500);
    strcpy(str, "/*Starting with multi line comment\ncontinuing comment*/This is the first line./*Followed by a multi line comment\n that spans \n three lines*/This is the second line.//Ending with a single line comment");
    strcpy(expectedString, "This is the first line.This is the second line.");
    testStatus = testStatus * testRemoveComments(9, str, expectedString);
    free(str);
    free(expectedString);
    
    if (testStatus == 1) {
        printf("All tests passed\n");
    }
    else{
        printf("There are failures. Please take a look.\n");
    }
    
    int lSize = 1024*1024;
    char *buffer = (char*) malloc (sizeof(char)*lSize);
    FILE *fp = fopen(__FILE__, "r");
    int read = fread(buffer,1,lSize,fp);
    printf("My original program:\n");
    printf("%s\n", buffer);
    
    
    
    removeComments(buffer);
    
    
    
    printf("My program no comment:\n");
    
    printf("%s\n", buffer);
    
    
    
    fclose(fp);
    
    free(buffer);
    


    return 0;
}













//Program to test removeComments(0 function taking input via command line.
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

#include "removeComments.h"

int main(int argc, char **argv){
    char *str;
    int c;
    while((c = getopt(argc,argv, "t:"))!= -1){
        switch (c){
            case 't' :
                str = (char*)malloc(sizeof(optarg)+1);
                strcpy(str,optarg);
                break;
            case '?' :
                if(optopt == 't'){
                    fprintf(stderr, "Text to evaluate not found!\n");
                }
                return 1;
            default:
                fprintf(stderr, "Unknown option!\n");
                return 1;
                abort();
        }
    }
    printf("String before removing comments: \n%s\n", str);
    removeComments(str);
    printf("String after removing comments: \n%s\n\n", str);
    free(str);
    return 0;
}






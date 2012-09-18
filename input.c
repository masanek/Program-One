#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINE 1

void user_input()
{
    char **arryPtr = (char**)malloc(sizeof(char*));
int count = 0;
char curr;
    char* complete = "l";
    char* second = "s";
    char* third = "p";
    /*SHOULD SWITCH THIS TO reALLOC but worry about it later*/
    char* temp = (char*)malloc((strlen(complete)+2) * sizeof(char));
    complete = strcpy(temp, complete);
    complete = strcat(temp,second);

    temp = (char*)malloc((strlen(complete)+2) * sizeof(char));
    complete = strcpy(temp, complete);
    complete = strcat(temp, third);

    printf("%s", complete);
/*This is working to build a string of variable length. . Now we need to add it to our growing array of Char*/
    printf("%i", arryPtr);
    arryPtr = memmove(arryPtr, complete,sizeof(char*));
    printf("%s", *arryPtr);

    while (count < MAXLINE && EOF != curr)
    {
        curr = getchar();
	printf("%i", count);
	curr = getchar(); /*Capture the enter key*/
        count = count + 1;
    }

 }

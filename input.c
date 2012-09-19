#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXLINE 100000
#define BUFFERSIZE 640
#define ARGVSIZE 20
void user_input()
{
    /*Set up the temp buffer while reading in characters*/
    /*Probably could make this a struct?*/
    char* _buffer = (char*)malloc(BUFFERSIZE * sizeof(char));
    int position = 0;
    /*Set up the argv pointer array*/
    char** arryPtr = (char**)malloc(ARGVSIZE * sizeof(char*));
    int arryPtrPos = 0;
    /*Number of characters inputted*/
    int count = 0;
    /*Current character from user*/
    char current = 'a';
    
    /*this needs to be refactored*/
    bool inWord = false;
    /*Main loop - should get put into seperate functions...*/
    while (count < MAXLINE && EOF != current)
    {
        current = getchar();
        if(current != ' ' && !inWord)
        {
            /*TODO:need to check if we have enough here*/
            arryPtr[arryPtrPos] = &_buffer[position];
            inWord = true;
            arryPtrPos++;
        }
        /*now handle the character*/
        if(current != ' ' && inWord) /*TODO:Error Cases*/
        {
           /*Should refactor this to a read word function*/
           _buffer[position] = current;
           position++;
        }
        if(current == ' ' && inWord)
        {
           inWord = false;
           _buffer[position] = '\0';
           position++;
        } 
        count = count + 1;
    }
    /*Need some clean up if like EOF during word. Length check etc*/
printf("\n%s,%i\n", arryPtr[0], arryPtrPos);
printf("\n%s\n", arryPtr[1]);
    printf("\n%s\n", arryPtr[2]);
    /*char* temp = (char*)malloc(6 * sizeof(char));
    char** arryPtr = (char**)malloc(2 * sizeof(char*));
    temp[0] = 't';
    temp[1] = '\0';
    temp[2] = 'a';
    temp[3] = 'p';
    temp[4] = '\0';

    arryPtr[0] = &temp[0];
    arryPtr[1] = &temp[2];
    printf("\n%s\n", arryPtr[1]);
    
    memcpy(temp,"t\0",2);
    memcpy(&temp[2],"ap\0",3);

char **arryPtr = (char**)malloc(sizeof(char*));
    int count = 0;
    char curr;
    char* complete = "l";
    char* second = "s";
    char* third = "p";
    char* temp = (char*)malloc((strlen(complete)+2) * sizeof(char));
    complete = strcpy(temp, complete);
    complete = strcat(temp,second);

    temp = (char*)malloc((strlen(complete)+2) * sizeof(char));
    complete = strcpy(temp, complete);
    complete = strcat(temp, third);

    printf("%s", complete);

    printf("%i", arryPtr);
    arryPtr[0] = complete;
    
    char** temp2 = (char**)realloc(arryPtr,sizeof(char*));
    arryPtr[1] = complete;
    printf("%s", arryPtr[1]);
    while (count < MAXLINE && EOF != curr)
    {
        curr = getchar();
	printf("%i", count);
	curr = getchar(); 
        count = count + 1;
    }*/

 }

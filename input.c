#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "input.h"

#define MAXLINE 100000
#define BUFFERSIZE 640
#define ARGVSIZE 20

void user_input(char*** arrayPointer, bool* endOfFile)
{
    /*Set up the temp buffer while reading in characters*/
    char* _buffer = (char*)malloc(BUFFERSIZE * sizeof(char));
    int position = 0;
    /*Set up the argv pointer array*/
    char** arryPtr = (char**)malloc(ARGVSIZE * sizeof(char*));
    int arryPtrPos = 0;
    /*Number of characters inputted*/
    int count = 0;
    /*Current character from user*/
    char current = 'a';
    /*bool if we are in a word*/
    bool inWord = false;

    /*Main loop - should get put into seperate functions...*/
    while (true)
    {
        current = getchar();
        /*we could make a function for these checks but we react differently so maybe not*/
        if(current == EOF)
        {
            *endOfFile=true;
            /*clean up function*/
            cleanUp(&arryPtr,arryPtrPos,&_buffer, position, inWord);
            break;
        }
        else if (current == '\n')
        {
	    *endOfFile=false;
            /*clean up function*/
            cleanUp(&arryPtr,arryPtrPos,&_buffer, position, inWord);
            break;
        }
        else /* Acceptable characters- Probably need to add more checks*/
        {
		if(current != ' ' && !inWord)
		{
		    arryPtr[arryPtrPos] = &_buffer[position];
		    inWord = true;
		    arryPtrPos++;
		}
                /*The above sets up the arrayPtr and tells below save the char*/
		if(inWord && current != ' ')
		{
		   /*Should refactor this to a read word function*/
		   _buffer[position] = current;
		   position++;
		}
		if(inWord && current == ' ')
		{
		   inWord = false;
		   _buffer[position] = '\0';
		   position++;
		} 
                /*TODO:check if we have no more space on the buffers and allocate more*/
                if(arryPtrPos >= ARGVSIZE)
                {
                }
                if(position >= BUFFERSIZE)
                {
                }
                count = count + 1;
        }
    }
    *arrayPointer = arryPtr;
}
void cleanUp(char*** arrayPointer, int arrayPos, char** bufferPointer, int buffPos, bool stillInWord)
{
    /*This case is for EOF during typing or when the newline was hit*/
    if(stillInWord)
    {
        /*finish off the current word*/
         (*bufferPointer)[buffPos] = '\0';
    }
    (*arrayPointer)[arrayPos] = NULL;
}

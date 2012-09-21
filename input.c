#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "input.h"

#define MAXLINE 100000

void user_input(char*** arrayPointer, bool* endOfFile)
{
	/*not constants because we need to resize*/
	int buffersize = 64;
	int argsize = 10;

    /*Set up the temp buffer while reading in characters*/
    char* buffer = (char*)malloc(buffersize * sizeof(char));
    int bufferPos = 0;
	
    /*Set up the argv pointer array*/
    char** argv = (char**)malloc(argsize * sizeof(char*));
    int argvPos = 0;

    /*Number of characters inputted*/
    int count = 0;

    /*Current character from user*/
	/*Current has to be an int not char, so that EOF can be a non char value*/
    int current = 'a'; 

    /*bool if we are in a word*/
    bool inWord = false;
    
    /*Main loop - should get put into seperate functions...*/
    while (true)
    {
        current = getchar();

        /*we could make a function for these checks but we react differently so maybe not*/
        if (current == EOF)
        {
            *endOfFile = true;
            printf("\n");
            /*clean up function*/
            cleanUp(&argv,argvPos,&buffer, bufferPos, inWord);
            break;
        }

        if (current == '\n' && count != 0)
        {
			*endOfFile = false;
            /*clean up function*/
            cleanUp(&argv,argvPos,&buffer, bufferPos, inWord);
            break;
        }

		/* Acceptable characters- Probably need to add more checks*/
        if (acceptableChar(current)) 
        {
			/* tabs or spaces*/
			if (!inWord && current != ' ' && current != '\t')
			{
			    argv[argvPos] = &buffer[bufferPos];
			    inWord = true;
			    argvPos++;
			}
			
			/*The above sets up the arrayPtr and tells below save the char*/
			if (inWord && current != ' ')
			{
			   /*Should refactor this to a read word function*/
			   buffer[bufferPos] = current;
			   bufferPos++;
			}

			if (inWord && current == ' ')
			{
			   inWord = false;
			   buffer[bufferPos] = '\0';
			   bufferPos++;
			} 

			/*TODO:check if these fail!*/
			if (argvPos >= argsize)
			{
				argsize *= 2;
				argv = (char**)realloc(argv, argsize);
			}

			if (bufferPos >= buffersize)
			{
				buffersize *= 2;
				buffer = (char*)realloc(buffer, buffersize);
			}

			count = count + 1;

        }
    }
    *arrayPointer = argv;
}


bool acceptableChar(char c)
{
if(c != '\n')
   return true;
return false;
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

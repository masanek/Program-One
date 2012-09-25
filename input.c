#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "input.h"

#define MAXLINE 100000

void user_input(char*** arrayPointer, bool* endOfFile, bool* waitForChild)
{
    /*Set up initial correct buffer sizes*/
    int bufferSize = 2;
    int argvSize = 1;
    /*Set up the temp buffer while reading in characters*/
    char* buffer = (char*)malloc(bufferSize * sizeof(char));
    if(buffer == NULL)
    {
    }
    int bufferPos = 0;
    /*We need this incase the buffer gets moved*/
    char* tempBufferPtr;
    /*Set up the argv pointer array*/
    char** argv = (char**)malloc(argvSize * sizeof(char*));

    int argvPos = 0;
    /*Number of characters inputted*/
    int count = 0;
    /*Current character from user*/
    int current = 'a'; /* current has to be an int not char, so that EOF can be a non char value*/
    /*bool if we are in a word*/
    bool inWord = false;

    /*Main loop- Doesnt yet keep scannign to clean out buffer*/
    while (true)
    {
        current = getchar();
        if(count > MAXLINE || '\0' == current)
        {
            printf("\nInvalid Input\n");
	    rejectInput(&argv, &buffer);
            break;
        }
        /*we could make a function for these checks but we react differently so maybe not*/
        if(EOF == current)
        {
            printf("\n");
            *endOfFile=true;
            if(0 != count)
            {
                /*clean up function*/
                cleanUp(&argv,argvPos,&buffer, bufferPos, inWord);
                break;
            }
            else
            {
                free(buffer);
                free(argv);
                argv=NULL;
                break;
            }
        }
        if (current == '\n')
        {
            if(0 != count)
            {
               printf("\n");
	       *endOfFile=false;
               /*clean up function*/
               cleanUp(&argv,argvPos,&buffer, bufferPos, inWord);
               break;
            }
            else
            {
               printf("537sh$ ");
            }
        }
        if(acceptableChar(current)) /* Acceptable characters- Probably need to add more checks*/
        {
		if(!isblank(current) && !inWord)
		{
		    argv[argvPos] = &(buffer[bufferPos]);
		    inWord = true;
		    argvPos++;
                    count = count + 1;
		}
                /*The above sets up the arrayPtr and tells below save the char*/
		if(inWord && !isblank(current))
		{
		   buffer[bufferPos] = current;
		   bufferPos++;
                   count = count + 1;
		}
		if(inWord && isblank(current))
		{
		   inWord = false;
		   buffer[bufferPos] = '\0';
		   bufferPos++;
		} 
                /*TODO:check if these fail!*/
                if(argvPos >= argvSize)
                {
    		    argvSize = argvSize*2;
                    argv = realloc(argv,argvSize * sizeof(char*));
                }
                if(bufferPos >= bufferSize)
                {
                    bufferSize = bufferSize*2;
                    tempBufferPtr = realloc(buffer,bufferSize * sizeof(char));
                    /*Realloc moved our buffer so we need to fix argv*/
                    if(tempBufferPtr != buffer)
                    {
                        updateArgv(&argv, tempBufferPtr, bufferPos);
                    }
                    buffer = tempBufferPtr;
                    tempBufferPtr = NULL;
                }
        }
    }
    if(count ==1)
       printf("%i",buffer[0]);
    *arrayPointer = argv;
}
bool acceptableChar(char c)
{
if(c != '\n' && c!= EOF && c!= '\0' && isprint(c))
   return true;
return false;
}
void rejectInput(char *** argvPtr, char** bufferPtr)
{
   char tempChar;
   /*Free up the memory*/
   free(*argvPtr);
   *argvPtr = NULL;
   free(*bufferPtr);
   
   /*Read out the rest of the buffer*/
   while(true)
   {
      tempChar = getchar();
      if(tempChar == '\n' || EOF == tempChar)
      {
          break;
      }
   }
}
void updateArgv(char*** argvPtr, char* newBufferPtr, int spaces)
{
   int count = 0;
   int argvCounter = 1;
   /*Set the first location*/
   (*argvPtr)[0] = &newBufferPtr[0];
   /*and do the rest */
   while(count < spaces)
   {
      if(newBufferPtr[count] == '\0')
      {
         /*set the next position to the new word. NOTE: it is ok to set the last one wrong. It will get overriden in the callign func*/
         (*argvPtr)[argvCounter] = &newBufferPtr[count+1];
         argvCounter ++;
      }
      count++;
   }
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

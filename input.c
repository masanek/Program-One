#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#include "input.h"

#define MAXLINE 100000

void user_input(char*** arrayPointer, bool* endOfFile, bool* waitForChild)
{
    int buffersize = 100;
    int argsize = 10;

    /*Set up the dynamic string array */
    char* buffer = (char*)malloc(buffersize * sizeof(char));
    int bufferPos = 0;

    /*Set up the argv array, to point at string array*/
    char** argv = (char**)malloc(argsize * sizeof(char*));
    int argvPos = 0;
    
    int i=0;


    /*Number of characters inputted*/
    int count = 0;

    /*Current character from user, int so EOF is valid nonchar value*/
    int current = 'a'; 

    /*bool if we are in a word*/
    bool inWord = false;

    /*Always wait for child process until '&' is specified*/
    *waitForChild = true; 
   /* 
    for (i=0; i < 25; i++) printf("&argv[%d]: %p\n", i, &argv[i]);

    for (i=0; i < 25; i++) printf("argv[%d]: %p\n", i, argv[i]);
*/

    /*Main loop - should get put into seperate functions...*/
    while (true)
    {
        /* eat whitespace */
        while (isblank(current = getchar()))
        {
            if (inWord)
            {
                buffer[bufferPos++] = '\0';                
               // bufferPos++;
            }
            inWord = false;
        }

        if (current == EOF)
        {
            *endOfFile = true;
            printf("\n");
            cleanUp(&argv,argvPos,&buffer, bufferPos, inWord);
            break;
        }

        if (current == '\n')
        {
            *endOfFile = false;
            cleanUp(&argv,argvPos,&buffer, bufferPos, inWord);
            break;
        }
/*
        if (current == '&' && !inWord)
        {
            *waitForChild = false;
            break;
        }   

        if (current == '&' && inWord)
*/
        /* Acceptable characters*/
        if (acceptableChar(current)) 
        {
            if (!inWord)
            {       
                argv[argvPos++] = &buffer[bufferPos];
               // argvPos++;
                inWord = true;
            }

            /*The above sets up the arrayPtr and tells below save the char*/
            if (inWord)
            {
                /*Should refactor this to a read word function*/
                buffer[bufferPos++] = current;
   //             bufferPos++;
            }
        }

        /*TODO:check if these fail!*/
        if (argvPos >= (argsize - 1))
        {
            argsize *= 2;
            argv = (char**)realloc(argv, 100 * sizeof(char*));
            if (argv == NULL) printf("FAILURE");

            /*for (i=0; i < 25; i++) printf("&argv[%d]: %p\n", i, &argv[i]);
    for (i=0; i < 25; i++) printf("argv[%d]: %p\n", i, argv[i]);*/
        }

        if (bufferPos >= (buffersize - 1))
        {
            buffersize *= 2;
            buffer = (char*)realloc(buffer, buffersize * sizeof(char));
        }

        count = count + 1;
    }
    *arrayPointer = argv;
}


bool acceptableChar(char c)
{
if ( isgraph(c))
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

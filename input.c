#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#include "input.h"

#define MAXLINE 100000
#define STRING_START_L 4

/*return 0 ok, -1 error, 1 EOF? */
int user_input(char*** arrayPointer, bool* endOfFile, bool* waitForChild)
{
    int argsize = 10;
    int strSize = STRING_START_L;

    char** argv = (char**)malloc(argsize * sizeof(char*));
    int argvPos = -1;

    int strPos = 0;

    /*Number of characters inputted*/
    int count = 0;

    /*Current character from user, int so EOF is valid nonchar value*/
    int current = 'a'; 

    /*bool if we are in a word*/
    bool inWord = false;

    /*Always wait for child process until '&' is specified*/
    *waitForChild = true; 

    /*Main loop - should get put into seperate functions...*/
    while (true)
    {
        current = getchar();

        /* add count != 0 case */
        if (current == EOF)
        {
            printf("\n");
            if (inWord) 
                argv[argvPos][strPos] = '\0';
            
            argv[++argvPos] = NULL;
            break;
        }

        if (current == '\n')
        {
            if (count != 0)
                argv[argvPos][strPos] = '\0';
            break;
        }
            
        if (current == '&')
        {
            while (isblank(current = getchar()));
            if (current == '\n' || current == EOF)
            {
                if (inWord)  argv[argvPos][strPos] = '\0';
                if (current == EOF) argv[++argvPos] = NULL;
            }
            else
            {
                return -1; /* Invalid to have any other char after & */
            }
                
            *waitForChild = false;
            break;
        }   
    

        /* Acceptable characters*/
        if (acceptableChar(current)) 
        {
            /* char following space */
            if (!isblank(current) && !inWord)
            {
                strSize = STRING_START_L;
                argv[++argvPos] = (char*)malloc(strSize * sizeof(char));
                strPos = 0;
                inWord = true;
            }

            if (!isblank(current) && inWord)
            {
                argv[argvPos][strPos++] = current;
            }

            if (isblank(current) && inWord)
            {
                inWord = false;
                argv[argvPos][strPos] = '\0';
            }
        }

        /*TODO:check if these fail!*/
        if (argvPos >= (argsize - 1))
        {
            argsize *= 2;
            argv = (char**)realloc(argv, argsize * sizeof(char*));
            if (argv == NULL) printf("FAILURE");
        }

        if (strPos >= (strSize - 1))
        {
            strSize *= 2;
            argv[argvPos] = (char*)realloc(argv[argvPos], strSize * sizeof(char));
        }

        if (!isblank(current)) count++;
    }
    *endOfFile = (current == EOF) ? true : false;
    *arrayPointer = argv;
    return 0;
}


bool acceptableChar(char c)
{
if (isprint(c) || '\t')
   return true;
return false;
}


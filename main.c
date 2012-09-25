#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "process.h"
#include "input.h"


int main()
{
    bool stop = false;
    bool waitForChild = true; /*unless we get '&' */
    char ** cmd;

    while(!stop)
    {
        printf("537sh$ ");
        user_input(&cmd, &stop, &waitForChild);
        /*If this happens something went wrong with input*/
        if(cmd != NULL)
        {
            start_process(cmd, waitForChild);
            /*Free up memory. probably need to do a deep free*/
        }
    }
    return 0;
}

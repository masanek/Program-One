#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "process.h"
#include "input.h"

int main()
{
    /* stop is set when EOF is reached*/
    bool stop = false;
    bool waitForChild = true; /*unless we get '&' */
    char **cmd;
    int rv = 0;

    while(!stop)
    {
        printf("537sh$ ");
        rv = user_input(&cmd, &stop, &waitForChild);
        if (!rv)
            start_process(cmd, &waitForChild);
        else
            printf("invalid input");

        /*freemem*/
    }
    return 0;
}

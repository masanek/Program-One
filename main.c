#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "process.h"
#include "input.h"

int main()
{
    bool stop = false;
    char ** cmd;
    while(!stop)
    {
        user_input(&cmd, &stop);
        start_process(cmd);
    }
    return 0;
}

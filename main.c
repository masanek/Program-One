#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "process.h"
#include "input.h"

int main()
{
    /* stop is set when EOF is reached*/
	bool stop = false;
    char **cmd;

    while(!stop)
    {
		printf("537sh$ ");
        user_input(&cmd, &stop);
        start_process(cmd);
    }
    return 0;
}

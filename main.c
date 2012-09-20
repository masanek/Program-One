#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "process.h"
#include "input.h"

int main()
{
    /*TODO: Add outer loop here and continue this process until we get EOF*/
    bool stop = false;
    char ** cmd;
    while(!stop)
    {
        user_input(&cmd, &stop);
        start_process(cmd);
    }
    return 0;
}

    /*char *cmd[3] = {"ls","./",NULL};*/
    /*printf("%s", cmd[1]);
    char * const temp = (char*)malloc(7 * sizeof(char));
    temp[0] = 'l';
    temp[1] = 's';
    temp[2] = '\0';
    temp[3] = '.';
    temp[4] = '/';
    temp[5] = '\0';
    temp[6] = NULL;*/

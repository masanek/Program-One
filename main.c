#include <stdio.h>

#include "process.h"
#include "input.h"

int main()
{
    char *cmd[3] = {"ls","./",NULL}; 
    user_input();
    start_process(cmd);
    return 0;
}

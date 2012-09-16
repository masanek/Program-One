#include <stdio.h>
#include "process.h"

int main()
{
    char *cmd[3] = {"ls","./",NULL};
    start_process(cmd);
    return 0;
}

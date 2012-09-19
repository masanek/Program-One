#include <stdio.h>
#include "process.h"
#include "input.h"

#include <stdlib.h>
int main()
{
    char *cmd[3] = {"ls","./",NULL}; 
    /*printf("%s", cmd[1]);
    char * const temp = (char*)malloc(7 * sizeof(char));
    temp[0] = 'l';
    temp[1] = 's';
    temp[2] = '\0';
    temp[3] = '.';
    temp[4] = '/';
    temp[5] = '\0';
    temp[6] = NULL;*/
    user_input();
    start_process(cmd);
    return 0;
}

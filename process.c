#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void start_process(char** parsedCommand, bool* childWait)
{
     pid_t  pid;
     int status;

     pid = fork();

     /*This will be True if we are the CHILD*/
     if(0 == pid) /* good habits...*/
     {
          execvp(parsedCommand[0], parsedCommand);
          printf("%s: command not found\n", parsedCommand[0]);
          printf("537sh$ ");
          _exit(-1);
     }
     else if (-1 == pid)
        printf("fork failed"); /*fail gracefully*/

     else if (*childWait)
         waitpid(pid, &status, 0);
}

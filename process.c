#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void start_process(char **parsedCommand)
{
     pid_t  pid;
     int status;

     pid = fork();

     /*This will be True if we are the CHILD*/
     if(0 == pid) /* good habits...*/
     {
          execvp(parsedCommand[0], parsedCommand);
          _exit(-1);
     }
     else
     {
         waitpid(pid, &status, 0);
     }

}

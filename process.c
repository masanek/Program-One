#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void start_process(char **parsedCommand, bool waitForChild)
{
     pid_t  pid;
     int status;

     pid = fork();

     /*This will be True if we are the CHILD*/
     if(0 == pid)
     {
          if(parsedCommand[0] != NULL)
          {
          execvp(parsedCommand[0], parsedCommand);
          printf("Command not found\n");
          _exit(-1);
          }
     }
     else if(-1 == pid)
     {
         printf("New Process Could Not Be Started\n"); /*fail gracefully*/
     }
     else if(waitForChild){
         waitpid(pid, &status, 0);
     }
     
}

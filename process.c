#include <sys/types.h>
#include <unistd.h>
#include<stdio.h>

void start_process(char *parsedCommand[])
{
     pid_t  pid;

     pid = fork();
     /*This will be True if we are the CHILD*/
     if(pid == 0)
     {
          execvp(parsedCommand[0], parsedCommand);
     }
}

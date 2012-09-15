#include  <stdio.h>
#include  <string.h>
#include  <sys/types.h>

#define   MAX_COUNT  200
#define   BUF_SIZE   100

void start_process()
{
     pid_t  pid;
     int    i;
     char *cmd[2];
     cmd[0] = "ls";
cmd[1] = "./";
cmd[2] = NULL;
     pid = fork();
   if(pid == 0)
	{

	execvp(cmd[0],cmd);
	 
	}
     
}

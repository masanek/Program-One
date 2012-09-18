#include <stdio.h>
#include <string.h>

#define MAXLINE 10

void user_input()
{
    char curr;
    int count = 0;

    while (count < MAXLINE && EOF != curr)
    {
        curr = getchar();
	printf("%i", count);
	curr = getchar(); /*Capture the enter key*/
        count = count + 1;
    }
}

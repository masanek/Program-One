#include <stdio.h>

#define MAXLINE 10

void user_input()
{
    char curr;
    int count = 0;

    
    do
    {
	curr = getchar();
	printf("%i", count);
        count = count + 1;
    } while (count <= MAXLINE && EOF != curr);
}

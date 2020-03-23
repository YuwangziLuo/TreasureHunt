#include <stdio.h>
#include <stdlib.h>

void wait_and_exit(int exitCode)
{
    printf("Press the enter key to exit...");
    while (getchar() != (int)'\n')
    {
    }
    
    exit(exitCode);
}
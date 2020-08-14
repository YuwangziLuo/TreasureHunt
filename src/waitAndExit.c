#include <stdio.h>
#include <stdlib.h>
#include "../include/TreasureHunt.h"

void waitAndExit(int exitCode)
{
    printf("Press the enter key to exit...");
    while (getchar() != (int)'\n')
    {
    }
    
    exit(exitCode);
}
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <getopt.h>
#include <string.h>
#include "../include/TreasureHunt.h"

#define OPT_PATTERN "hp::rsf:"

int Get_UserOption(
    int argc,
    char **argv,
    User_t *const pUserInfo)
{
    pUserInfo->pMapFileLocation = NULL;
    /* 
    * For safety. 
    * If 'pUserInfo->pMapFileLocation' is not 'NULL' when passed in, 
    * runtime-error may occur at: 
    * 'free(pUserInfo->pMapFileLocation);'
    */

    bool isMapFileLocationSpecified = false;

    int opt;

    while ((opt = getopt(argc, argv, OPT_PATTERN)) != -1)
    {
        switch (opt)
        {
        case 'h':
            printf("\n%s\n", MSG__HELP);

            WaitReturn(0);
            break;
        case 'p':
            if (optarg)
            {
                int temp_int = atoi(optarg);
                if (temp_int > 0)
                {
                    pUserInfo->waitTime = temp_int;
                }
                else
                {
                    Return_WithError(err_optionP);
                }
            }
            //No 'break'.
        case 'r':
            //No 'break'.
        case 's':
            pUserInfo->mode = (signed char)opt;
            break;
        case 'f':
            isMapFileLocationSpecified = true;

            size_t mapFileLocationStrFullLength = strlen(optarg) + 1;

            pUserInfo->pMapFileLocation = realloc(
                pUserInfo->pMapFileLocation,
                mapFileLocationStrFullLength);
            if (!(pUserInfo->pMapFileLocation))
            {
                Return_WithError(err_memAlloc);
            }
            strncpy(
                pUserInfo->pMapFileLocation,
                optarg,
                mapFileLocationStrFullLength);
            break;
        default:
            Return_WithError(err_option);
            break;
        }
    }

    if (!isMapFileLocationSpecified)
    {
        pUserInfo->pMapFileLocation = DEFAULT_MAP_FILE_LOCATION;
    }

    return;
}

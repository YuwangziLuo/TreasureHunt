#include <stdio.h>
#include <stdbool.h>
#include "../include/TreasureHunt.h"
#include "../include/msg.h"

void getMap(
    MapInfo_t *const pMapInfo,
    const User_t *const pUserInfo,
    SearchInfo_t *const pSearchInfo)
{
    //'*row_num_ptr', '*col_num_ptr' and '*treasure_num_ptr' are initialized to 0 before entering this function.
    int cnt = 0;
    char *rawMap = NULL;

    {
        FILE *fp = fopen(
            pUserInfo->pMapFileLocation,
            "r");

        if (!fp)
        {
            Return_WithError(err_fileName);
        }

        for (int ch = fgetc(fp); ch != EOF; ch = fgetc(fp))
        {
            rawMap = (char *)realloc(rawMap, (++cnt) * sizeof(char));
            if (!rawMap)
            {
                Return_WithError(err_memAlloc);
            }

            *(rawMap + cnt - 1) = ch;
        }

        fclose(fp);
    }
    // 'cnt' is now the number of the elements.

    if (cnt == 0)
    {
        fprintf(stderr, "ERROR: Unexpected file contents. File may not be empty. \n");

        WaitReturn(0);
    }

    if ((cnt == 1) && (*rawMap == '\n'))
    {
        fprintf(stderr, "ERROR: Unexpected file contents. File may contain nothing except for newline characters. \n");

        WaitReturn(0);
    }
    /*
    *The two 'if's above are to prevent run-time error later, otherwise: 
    **1. If 'cnt' is 0, run-time error would occur in "if (*(rawMap + cnt - 1) != '\n')" later; 
    **2. If 'cnt' is 1, and the (only) element is '\n', run-time error would occur in "while (*(rawMap + cnt - 2) == '\n')" later; 
    */

    //This 'if-else' is to only keep one '\n' in the tail.
    if (*(rawMap + cnt - 1) != '\n')
    {
        rawMap = (char *)realloc(rawMap, (++cnt) * sizeof(char));
        if (rawMap == NULL)
        {
            fprintf(stderr, "ERROR: Run-time error. Fail to allocate memory. \n");

            WaitReturn(1);
        }
        *(rawMap + cnt - 1) = '\n';
    }
    else
    {
        while (*(rawMap + cnt - 2) == '\n')
        {
            if (cnt == 2) //This means that all characters are '\n', and this can stop the run-time error in the next loop.
            {
                fprintf(stderr, "ERROR: Unexpected file contents. File may contain nothing except for newline characters. \n");

                WaitReturn(0);
            }

            rawMap = (char *)realloc(rawMap, (--cnt) * sizeof(char));
            if (rawMap == NULL)
            {
                fprintf(stderr, "ERROR: Run-time error. Fail to allocate memory. \n");

                WaitReturn(1);
            }
        }
    }

    {
        unsigned distanceChker[2] = {0, 0};
        bool isFirstChk = true, isStartPointFound = false;
        char ch;

        for (unsigned i = 0; i < cnt; ++i)
        {
            ch = *(rawMap + i);

            if ((ch != (int)' ') && (ch != (int)'x') && (ch != (int)'X') && (ch != (int)'t') && (ch != (int)'T') && (ch != (int)'\n') && (ch != (int)'s') && (ch != (int)'S'))
            {
                fprintf(stderr, "ERROR: Unexpected file contents. File may not contain illegal characters. \n");

                WaitReturn(0);
            }

            if ((ch == 's') || (ch == 'S'))
            {
                if (isStartPointFound)
                {
                    fprintf(stderr, "ERROR: Unexpected file contents. A unique starting-point is required. \n");

                    WaitReturn(0);
                }
                else
                {
                    isStartPointFound = true;
                }
            }

            if ((ch == 't') || (ch == 'T'))
            {
                ++(pMapInfo->treasureNum);
            }

            if (ch == '\n')
            {
                if (isFirstChk)
                {
                    distanceChker[1] = i;
                    isFirstChk = false;
                }
                else
                {
                    if ((i + distanceChker[0]) != ((2 * distanceChker[1]) + 1))
                    {
                        fprintf(stderr, "ERROR: Unexpected file contents. Number of characters in each line must be consistent. \n");

                        WaitReturn(0);
                    }

                    distanceChker[0] = (distanceChker[1] + 1);
                    distanceChker[1] = i;
                }
            }
        }
    }
    //File-checking is done.

    //Now copy 'rawMap' to 'map', meanwhile elliminate the '\n' and change certain characters.
    char *map = (char *)NULL;

    {
        char ch;
        unsigned i = 0, j = 0;
        for (; i < cnt; ++i)
        {
            if ((ch = *(rawMap + i)) == '\n')
            {
                ++(pMapInfo->rowNum);
            }
            else
            {
                switch (ch)
                {
                case 'x':
                    ch = 'X';
                    break;
                case 't':
                case 'T':
                    ch = '$';
                    break;
                case 's':
                case 'S':
                    pMapInfo->startPos = j;
                    ch = ' ';
                    break;
                default:
                    break;
                }

                map = (char *)realloc(map, (++j) * sizeof(char));
                if (map == (char *)NULL)
                {
                    fprintf(stderr, "ERROR: Run-time error. Fail to allocate memory. \n");

                    WaitReturn(1);
                }

                *(map + j - 1) = ch;

                if (pMapInfo->rowNum == 0)
                {
                    ++(pMapInfo->columnNum);
                }
            }
        }
    }

    free(rawMap);

    return map;
}
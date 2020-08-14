#include "TreasureHunt.h"

char *get_map(unsigned short *const row_num_ptr, unsigned short *const col_num_ptr, unsigned *const treasure_num_ptr, unsigned *const start_pos_ptr)
{
    //'*row_num_ptr', '*col_num_ptr' and '*treasure_num_ptr' are initialized to 0 before entering this function.
    unsigned cnt = 0;
    char *map_for_chk = (char *)NULL;

    {
        FILE *fp = fopen("./Map.txt", "r");

        if (fp == NULL)
        {
            fprintf(stderr, "ERROR: Fail to open \"Map.txt\", check if the file exists. \n");

            wait_and_exit(1);
        }

        for (int ch = fgetc(fp); ch != EOF; ch = fgetc(fp))
        {
            map_for_chk = (char *)realloc(map_for_chk, (++cnt) * sizeof(char));
            if (map_for_chk == NULL)
            {
                fprintf(stderr, "ERROR: Run-time error. Fail to allocate memory. \n");

                wait_and_exit(1);
            }

            *(map_for_chk + cnt - 1) = ch;
        }

        fclose(fp);
    }
    // 'cnt' is now the number of the elements.

    if (cnt == 0)
    {
        fprintf(stderr, "ERROR: Unexpected file contents. File may not be empty. \n");

        wait_and_exit(0);
    }

    if ((cnt == 1) && (*map_for_chk == '\n'))
    {
        fprintf(stderr, "ERROR: Unexpected file contents. File may contain nothing except for newline characters. \n");

        wait_and_exit(0);
    }
    /*
    *The two 'if's above are to prevent run-time error later, otherwise: 
    **1. If 'cnt' is 0, run-time error would occur in "if (*(map_for_chk + cnt - 1) != '\n')" later; 
    **2. If 'cnt' is 1, and the (only) element is '\n', run-time error would occur in "while (*(map_for_chk + cnt - 2) == '\n')" later; 
    */

    //This 'if-else' is to only keep one '\n' in the tail.
    if (*(map_for_chk + cnt - 1) != '\n')
    {
        map_for_chk = (char *)realloc(map_for_chk, (++cnt) * sizeof(char));
        if (map_for_chk == NULL)
        {
            fprintf(stderr, "ERROR: Run-time error. Fail to allocate memory. \n");

            wait_and_exit(1);
        }
        *(map_for_chk + cnt - 1) = '\n';
    }
    else
    {
        while (*(map_for_chk + cnt - 2) == '\n')
        {
            if (cnt == 2) //This means that all characters are '\n', and this can stop the run-time error in the next loop.
            {
                fprintf(stderr, "ERROR: Unexpected file contents. File may contain nothing except for newline characters. \n");

                wait_and_exit(0);
            }

            map_for_chk = (char *)realloc(map_for_chk, (--cnt) * sizeof(char));
            if (map_for_chk == NULL)
            {
                fprintf(stderr, "ERROR: Run-time error. Fail to allocate memory. \n");

                wait_and_exit(1);
            }
        }
    }

    {
        unsigned distance_ckr[2] = {0, 0};
        bool is_firstChk = true, is_startPoint_found = false;
        char ch;

        for (unsigned i = 0; i < cnt; ++i)
        {
            ch = *(map_for_chk + i);

            if ((ch != (int)' ') && (ch != (int)'x') && (ch != (int)'X') && (ch != (int)'t') && (ch != (int)'T') && (ch != (int)'\n') && (ch != (int)'s') && (ch != (int)'S'))
            {
                fprintf(stderr, "ERROR: Unexpected file contents. File may not contain illegal characters. \n");

                wait_and_exit(0);
            }

            if ((ch == 's') || (ch == 'S'))
            {
                if (is_startPoint_found)
                {
                    fprintf(stderr, "ERROR: Unexpected file contents. A unique starting-point is required. \n");

                    wait_and_exit(0);
                }
                else
                {
                    is_startPoint_found = true;
                }
            }

            if ((ch == 't') || (ch == 'T'))
            {
                ++(*treasure_num_ptr);
            }

            if (ch == '\n')
            {
                if (is_firstChk)
                {
                    distance_ckr[1] = i;
                    is_firstChk = false;
                }
                else
                {
                    if ((i + distance_ckr[0]) != ((2 * distance_ckr[1]) + 1))
                    {
                        fprintf(stderr, "ERROR: Unexpected file contents. Number of characters in each line must be consistent. \n");

                        wait_and_exit(0);
                    }

                    distance_ckr[0] = (distance_ckr[1] + 1);
                    distance_ckr[1] = i;
                }
            }
        }
    }
    //File-checking is done.

    //Now copy 'map_for_chk' to 'map', meanwhile elliminate the '\n' and change certain characters.
    char *map = (char *)NULL;

    {
        char ch;
        unsigned i = 0, j = 0;
        for (; i < cnt; ++i)
        {
            if ((ch = *(map_for_chk + i)) == '\n')
            {
                ++(*row_num_ptr);
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
                    *(start_pos_ptr) = j;
                    ch = ' ';
                    break;
                default:
                    break;
                }

                map = (char *)realloc(map, (++j) * sizeof(char));
                if (map == (char *)NULL)
                {
                    fprintf(stderr, "ERROR: Run-time error. Fail to allocate memory. \n");

                    wait_and_exit(1);
                }

                *(map + j - 1) = ch;

                if ((*row_num_ptr) == 0)
                {
                    ++(*col_num_ptr);
                }
            }
        }
    }

    free(map_for_chk);

    return map;
}

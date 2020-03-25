#include "TreasureHunt.h"

void print_map(const unsigned short row_num, const unsigned short col_num, const char *map, const unsigned crt_pos, const signed char mode, const unsigned long wait_time)
{
    system("cls");

    {
        char *printContent = (char *)malloc((row_num * (col_num + 1)) * sizeof(char));

        if (printContent == NULL)
        {
            fprintf(stderr, "ERROR: Run-time error. Fail to allocate memory. \n");

            wait_and_exit(1);
        }

        bool is_crt_pos_encountered = false;
        for (unsigned i = 0; i < (unsigned)((row_num * (col_num + 1)) - 1); ++i)
        {
            if ((i % (col_num + 1)) == 0)
            {
                *(printContent + i) = '\n';
            }
            else
            {
                if ((!is_crt_pos_encountered) && (i == (crt_pos + (i / (col_num + 1)))))
                {
                    *(printContent + i) = '@';
                    is_crt_pos_encountered = true;
                }
                else
                {
                    *(printContent + i) = (*(map + i - (i / (col_num + 1))));
                }
            }
        }
        *(printContent + (row_num * (col_num + 1)) - 1) = '\n';

        printf("%s", printContent);
    }

    switch (mode)
    {
    case (signed char)'p':
        Sleep((DWORD)wait_time);
        break;
    case (signed char)'s':
        printf("Press the enter key to continue...");
        while (getchar() != (int)'\n')
        {
        }
        break;
    default:
        //'mode' is checked inside 'get_mode(int, char **)'.
        break;
    }

    return;
}

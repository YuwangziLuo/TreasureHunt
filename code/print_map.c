#include "TreasureHunt.h"

void print_map(const unsigned short row_num, const unsigned short col_num, const char *map, const unsigned crt_pos, const signed char mode, const unsigned long wait_time)
{
    system("cls");

    for (unsigned i = 0; i < (row_num * col_num); ++i)
    {
        if ((i % col_num) == 0)
        {
            putchar((int)'\n');
        }

        if (i == crt_pos)
        {
            putchar((int)'@');
        }
        else
        {
            putchar((int)*(map + i));
        }
    }
    putchar((int)'\n');

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

#include "TreasureHunt.h"

void search(const unsigned short row_num, const unsigned short col_num, char *map, const unsigned crt_pos, unsigned *const foundTreasure_num_ptr, const signed char mode, const unsigned long wait_time)
{
    //'*foundTreasure_num_ptr' is initialized to 0 before entering this function.
    if (mode != (signed char)'r')
    {
        print_map(row_num, col_num, (const char *)map, crt_pos, mode, wait_time);
    }

    if (*(map + crt_pos) == '$')
    {
        ++(*foundTreasure_num_ptr);
        *(map + crt_pos) = '#';
    }
    else
    {
        *(map + crt_pos) = '.';
    }

    char ch;

    if ((((crt_pos + 1) % col_num) != 0) && (((ch = *(map + crt_pos + 1)) == ' ') || (ch == '$')))
    {
        search(row_num, col_num, map, (crt_pos + 1), foundTreasure_num_ptr, mode, wait_time);
        if (mode != (signed char)'r')
        {
            print_map(row_num, col_num, (const char *)map, crt_pos, mode, wait_time);
        }
    }

    if ((((signed long)crt_pos - (signed long)col_num) >= 0) && (((ch = *(map + crt_pos - col_num)) == ' ') || (ch == '$')))
    {
        search(row_num, col_num, map, (crt_pos - col_num), foundTreasure_num_ptr, mode, wait_time);
        if (mode != (signed char)'r')
        {
            print_map(row_num, col_num, (const char *)map, crt_pos, mode, wait_time);
        }
    }

    if (((crt_pos % col_num) != 0) && (((ch = *(map + crt_pos - 1)) == ' ') || (ch == '$')))
    {
        search(row_num, col_num, map, (crt_pos - 1), foundTreasure_num_ptr, mode, wait_time);
        if (mode != (signed char)'r')
        {
            print_map(row_num, col_num, (const char *)map, crt_pos, mode, wait_time);
        }
    }

    if ((((crt_pos / col_num) + 1) <= row_num) && (((ch = *(map + crt_pos + col_num)) == ' ') || (ch == '$')))
    {
        search(row_num, col_num, map, (crt_pos + col_num), foundTreasure_num_ptr, mode, wait_time);
        if (mode != (signed char)'r')
        {
            print_map(row_num, col_num, (const char *)map, crt_pos, mode, wait_time);
        }
    }

    return;
}

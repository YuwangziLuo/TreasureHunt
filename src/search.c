#include "../include/TreasureHunt.h"

void search(
    const MapInfo_t *const pMapInfo,
    char *pMap,
    const unsigned crt_pos,
    unsigned *const foundTreasure_num_ptr,
    const char mode,
    const unsigned long wait_time)
{
    //'*foundTreasure_num_ptr' is initialized to 0 before entering this function.
    if (mode != (signed char)'r')
    {
        printMap(row_num, col_num, (const char *)pMap, crt_pos, mode, wait_time);
    }

    if (*(pMap + crt_pos) == '$')
    {
        ++(*foundTreasure_num_ptr);
        *(pMap + crt_pos) = '#';
    }
    else
    {
        *(pMap + crt_pos) = '.';
    }

    char ch;

    if ((((crt_pos + 1) % col_num) != 0) && (((ch = *(pMap + crt_pos + 1)) == ' ') || (ch == '$')))
    {
        search(row_num, col_num, pMap, (crt_pos + 1), foundTreasure_num_ptr, mode, wait_time);
        if (mode != (signed char)'r')
        {
            printMap(row_num, col_num, (const char *)pMap, crt_pos, mode, wait_time);
        }
    }

    if ((((signed long)crt_pos - (signed long)col_num) >= 0) && (((ch = *(pMap + crt_pos - col_num)) == ' ') || (ch == '$')))
    {
        search(row_num, col_num, pMap, (crt_pos - col_num), foundTreasure_num_ptr, mode, wait_time);
        if (mode != (signed char)'r')
        {
            printMap(row_num, col_num, (const char *)pMap, crt_pos, mode, wait_time);
        }
    }

    if (((crt_pos % col_num) != 0) && (((ch = *(pMap + crt_pos - 1)) == ' ') || (ch == '$')))
    {
        search(row_num, col_num, pMap, (crt_pos - 1), foundTreasure_num_ptr, mode, wait_time);
        if (mode != (signed char)'r')
        {
            printMap(row_num, col_num, (const char *)pMap, crt_pos, mode, wait_time);
        }
    }

    if ((((crt_pos / col_num) + 1) <= row_num) && (((ch = *(pMap + crt_pos + col_num)) == ' ') || (ch == '$')))
    {
        search(row_num, col_num, pMap, (crt_pos + col_num), foundTreasure_num_ptr, mode, wait_time);
        if (mode != (signed char)'r')
        {
            printMap(row_num, col_num, (const char *)pMap, crt_pos, mode, wait_time);
        }
    }

    return;
}

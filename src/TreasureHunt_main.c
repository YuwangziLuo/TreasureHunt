#include "../include/TreasureHunt.h"

int main(int argc, char **argv)
{
    unsigned long wait_time = 5UL;
    const signed char mode = get_mode(argc, argv, (unsigned long *const)&wait_time);
    //'mode' is checked inside 'get_mode(int, char **)'.
    unsigned short row_num = 0, col_num = 0;
    unsigned treasure_num = 0, foundTreasure_num = 0, start_pos;

    char *map = get_map(&row_num, &col_num, &treasure_num, &start_pos);

    search(row_num, col_num, map, start_pos, &foundTreasure_num, mode, (const unsigned long)wait_time);

    printf("Result: Treasure-hunt finished. %u treasure found out of %u in the %u x %u map. \n", foundTreasure_num, treasure_num, row_num, col_num);

    printf("Press the enter key to exit...");
    while (getchar() != (int)'\n')
    {
    }

    return 0;
}

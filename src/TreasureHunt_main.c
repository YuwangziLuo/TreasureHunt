#include "../include/TreasureHunt.h"

int main(
    int argc,
    char **argv)
{
    unsigned long waitTime = 5UL;
    const char mode = get_mode(
        argc,
        argv,
        &waitTime);

    //'mode' is checked inside 'get_mode(int, char **)'.

    unsigned rowNum = 0U, colNum = 0U;
    unsigned treasure_num = 0U, foundTreasureNum = 0U, startPos;

    char *map = get_map(
        &rowNum,
        &colNum,
        &treasure_num,
        &startPos);

    search(
        rowNum,
        colNum,
        map,
        startPos,
        &foundTreasureNum,
        mode,
        (const unsigned long)waitTime);

    printf(
        "Result: Treasure-hunt finished. %u treasure found out of %u in the %u x %u map. \n",
        foundTreasureNum,
        treasure_num,
        rowNum,
        colNum);

    printf(
        "Press the enter key to exit...");
    while (getchar() != (int)'\n')
    {
    }

    return 0;
}

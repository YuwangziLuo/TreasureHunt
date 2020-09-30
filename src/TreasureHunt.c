#include <stdio.h>
#include "../include/TreasureHunt.h"

int main(
    int argc,
    char **argv)
{
    User_t searcherInfo = {
        DEFAULT_SEARCH_OPT,
        DEFAULT_WAIT_TIME,
        NULL};

    Get_UserOption(
        argc,
        argv,
        &searcherInfo);

    /* 
    * 'searcherInfo.mode' is checked inside 
    * 'void Get_UserOption(int argc, char **argv, User_t *const pSearcherInfo)'.
    */

    MapInfo_t mapInfo = {0, 0, 0};

    int foundTreasureNum = 0;

    char *const map = getMap(
        &mapInfo);

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
        treasureNum,
        rowNum,
        colNum);

    printf(
        "%s",
        MSG__PRESS_KEY_TO_EXIT);
    while (getchar() != (int)'\n')
    {
    }

    return 0;
}

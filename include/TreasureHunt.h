#ifndef TREASUREHUNT_H
#define TREASUREHUNT_H

#include <windows.h>
#include "./msg.h"
#include "./err.h"

#define DEFAULT_SEARCH_OPT \
    'p'
#define DEFAULT_WAIT_TIME \
    5UL
#define DEFAULT_MAP_FILE_LOCATION \
    "./Map.txt"

struct MapInfo
{
    int rowNum;
    int columnNum;
    int treasureNum;
    int startPos;
};

struct User
{
    signed char mode;
    DWORD waitTime;
    signed char *pMapFileLocation;
};

struct SearchInfo
{
    signed char *p_annotatedMap;
    int crtRow;
    int crtColumn;
};

struct WrappedError
{
    signed char *p_msg;
    int code;
};

typedef struct MapInfo MapInfo_t;
typedef struct User User_t;
typedef struct SearchInfo SearchInfo_t;
typedef struct WrappedError WrappedError_t;

void Get_UserOption(
    int argc,
    char **argv,
    User_t *const pUserInfo);

char *getMap(
    MapInfo_t *const pMapInfo);

void search(
    const MapInfo_t *const pMapInfo,
    char *map,
    const int crt_pos,
    int *const foundTreasue_num_ptr,
    const char mode,
    const long int wait_time);

void printMap(
    const int row_num,
    const int col_num,
    const char *map,
    const int crt_pos,
    const char mode,
    const unsigned long wait_time);

#endif //TREASUREHUNT_H
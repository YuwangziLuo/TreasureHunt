#ifndef __WAIT_RETURN_H__
#define __WAIT_RETURN_H__

#include <stdio.h>

#define WaitReturn(returnCode)                \
    do                                        \
    {                                         \
        printf("%s", MSG__PRESS_KEY_TO_EXIT); \
        while (getchar() != '\n')             \
        {                                     \
        }                                     \
                                              \
        return returnCode;                    \
    } while (0)

#endif //__WAIT_RETURN_H__
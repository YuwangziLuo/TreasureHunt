#ifndef __EXIT_WITH_ERROR_H__
#define __EXIT_WITH_ERROR_H__

#include <stdio.h>
#include "./TreasureHunt.h"

#define Return_WithError(wrappedErr) \
    do                               \
    {                                \
        fprintf(                     \
            stderr,                  \
            "%s%s",                  \
            ERROR_PREFIX,            \
            wrappedErr.p_msg);       \
                                     \
        WaitReturn(wrappedErr.code); \
    } while (0)

#endif //__EXIT_WITH_ERROR_H__
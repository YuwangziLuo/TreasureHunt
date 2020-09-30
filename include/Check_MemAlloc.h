#ifndef __CHECK_MEM_ALLOC_H__
#define __CHECK_MEM_ALLOC_H__

#define Check_MemAlloc(allocatedMem)        \
    do                                      \
    {                                       \
        if (!p_AllocatedMem)                \
        {                                   \
            Return_WithError(err_memAlloc); \
        }                                   \
    } while (0)

#endif //__CHECK_MEM_ALLOC_H__
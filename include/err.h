#ifndef __ERROR_H__
#define __ERROR_H__

#define ERROR_PREFIX \
    "ERROR: "
#define ERROR__OPTION \
    "Invalid option or format."
#define ERROR__OPTION_P \
    "Option '-p' only accepts a positive integer as optional argument."
#define ERROR__FILE_NAME \
    "Fail to open \"Map.txt\", check if the file exists."
#define ERROR__MEM_ALLOC \
    "Fail to allocate memory."

#include "./WaitReturn.h"
#include "./Return_WithError.h"
#include "./Check_MemAlloc.h"

extern const WrappedError_t
    err_option,
    err_optionP,
    err_fileName,
    err_memAlloc;

#endif //__ERROR_H__
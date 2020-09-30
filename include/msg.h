#ifndef __MSG_H__
#define __MSG_H__

#define MSG__HELP                                            \
    "Option\tArgument\tSpecification\n"                      \
    "------\t--------\t-------------\n"                      \
    "-h\tNo\t\tPrint out this help message. \n"              \
    "-p\tOptional\tGet process of treasure-hunt. \n\t\t\t"   \
    "Optional argument must be a positive integer as rough " \
    "interval(millisecond) between two status. \n\t\t\t"     \
    "(Default value: 5) \n"                                  \
    "-r\tNo\t\tGet only result of treasure-hunt. \n"         \
    "-s\tNo\t\tGet step of treasure-hunt. \n"                \
    "(Default mode: '-p')"
#define MSG__PRESS_KEY_TO_EXIT \
    "Press the enter key to exit..."

#endif //__MSG_H__
#include <stdio.h>
#include <windows.h>
#include "getopt.h"
#include "../include/TreasureHunt.h"

char get_mode(int argc, char **argv, unsigned long *const wait_time)
{
    const char *HELP_MESSAGE = "Option\tArgument\tSpecification\n\n"
                               "-h\tNo\t\tPrint out this help message. \n"
                               "-p\tOptional\tGet process of treasure-hunt. \n\t\t\t"
                               "Optional argument must be a positive integer as rough interval(millisecond) between two status. \n\t\t\t"
                               "(Default value: 5) \n"
                               "-r\tNo\t\tGet only result of treasure-hunt. \n"
                               "-s\tNo\t\tGet step of treasure-hunt. \n"
                               "(Default mode: '-p')\n";

    char mode = 'p';

    int opt;
    while ((opt = getopt(argc, argv, "bhp::rs")) != -1)
    {
        switch (opt)
        {
        case (int)'h':
            printf("\n%s\n", HELP_MESSAGE);

            waitAndExit(0);
            break;
        case (int)'p':
            if (optarg != NULL)
            {
                int temp_int = atoi((const char *)optarg);
                if (temp_int > 0)
                {
                    *wait_time = temp_int;
                }
                else
                {
                    fprintf(stderr, "ERROR: Option '-p' only accepts a positive integer as optional argument. \n");

                    waitAndExit(0);
                }
            }
            //No 'break'.
        case (int)'r':
        case (int)'s':
            mode = (signed char)opt;
            break;
        default:
            fprintf(stderr, "ERROR: Invalid option or format. \n");

            waitAndExit(0);
            break;
        }
    }

    if ((mode != (signed char)'p') && (mode != (signed char)'r') && (mode != (signed char)'s'))
    {
        {
            FILE *errlog_fp = fopen("errlog.txt", "a");
            //Ignore possible file-opening error.
            fprintf(errlog_fp, "Unexpected 'mode': %c. Error written to \"./errlog.txt\". \n", mode);
            fclose(errlog_fp);
        }
        fprintf(stderr, "ERROR: Unexpected error. \n");

        waitAndExit(-1);
    }

    return mode;
}

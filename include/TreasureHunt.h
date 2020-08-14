#ifndef TREASUREHUNT_H
#define TREASUREHUNT_H

char get_mode(
    int argc,
    char **argv,
    unsigned long *const wait_time);

char *get_map(
    unsigned *const row_num_ptr,
    unsigned *const col_num_ptr,
    unsigned *const treasure_num_ptr,
    unsigned *const start_pos_ptr);

void search(
    const unsigned row_num,
    const unsigned col_num,
    char *map,
    const unsigned crt_pos,
    unsigned *const foundTreasue_num_ptr,
    const char mode,
    const unsigned long wait_time);

void print_map(
    const unsigned row_num,
    const unsigned col_num,
    const char *map,
    const unsigned crt_pos,
    const char mode,
    const unsigned long wait_time);

void waitAndExit(
    int exitCode);

#endif //TREASUREHUNT_H

#ifndef TREASUREHUNT_H
#define TREASUREHUNT_H


signed char get_mode(int argc, char **argv, unsigned long *const wait_time);

char *get_map(unsigned short *const row_num_ptr, unsigned short *const col_num_ptr, unsigned *const treasure_num_ptr, unsigned *const start_pos_ptr);

void search(const unsigned short row_num, const unsigned short col_num, char *map, const unsigned crt_pos, unsigned *const foundTreasue_num_ptr, const signed char mode, const unsigned long wait_time);

void print_map(const unsigned short row_num, const unsigned short col_num, const char *map, const unsigned crt_pos, const signed char mode, const unsigned long wait_time);

void waitAndExit(int exitCode);

#endif //TREASUREHUNT_H

/*
** EPITECH PROJECT, 2022
** B-CPE-110-LYN-1-1-BSQ-vivien.boitard
** File description:
** header
*/

#ifndef HEADER_H_
    #define HEADER_H_

    #include "../src/lib/my/my.h"
    #include <stdlib.h>
    #include <unistd.h>

typedef struct bsq_s {
    int len_line;
    int file_len;
    char *buff;
    int size;
} bsq_t;

int error_file(char const *filepath);
char *init_buffer(char const *filepath);
void init_map(char const *filepath, bsq_t *bsq);
void line_len(bsq_t *bsq);
void find_bsq(bsq_t *bsq);
void display_map(bsq_t *bsq);
int generate_map(char *nb, char *str, bsq_t *bsq);

#endif /* !HEADER_H_ */

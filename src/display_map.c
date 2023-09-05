/*
** EPITECH PROJECT, 2022
** B-CPE-110-LYN-1-1-BSQ-vivien.boitard
** File description:
** display_map
*/

#include "../include/header.h"

static void len_file(bsq_t *bsq)
{
    char *size = malloc(sizeof(char) * 10);
    int nb;

    for (nb = 0; bsq->buff[nb] != '\n'; nb++)
        size[nb] = bsq->buff[nb];
    size[nb] = '\0';
    bsq->file_len = my_getnbr(size);
}

void line_len(bsq_t *bsq)
{
    int i = 0;
    int len = 0;

    for (i = 0; bsq->buff[i] != '\n'; i++);
    for (i++; bsq->buff[i] != '\n'; i++)
        len++;
    bsq->len_line = len;
}

void display_map(bsq_t *bsq)
{
    int n = 0;

    len_file(bsq);
    for (int nb = bsq->file_len; nb > 0; nb /= 10, n++);
    write(1, bsq->buff + n + 1, bsq->file_len * (bsq->len_line + 1));
}

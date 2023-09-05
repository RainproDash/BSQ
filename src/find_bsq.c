/*
** EPITECH PROJECT, 2022
** B-CPE-110-LYN-1-1-BSQ-vivien.boitard
** File description:
** find_bsq
*/

#include "../include/header.h"

static int check_square(bsq_t *bsq, int i, int size)
{
    for (int j = 0; j < size; j++) {
        if (bsq->buff[i + j] == 'o')
            return 1;
        if (bsq->buff[i + j] == '\n')
            return 1;
        if (bsq->buff[i + j] == '\0')
            return 1;
    }
    return 0;
}

static int is_square(int i, bsq_t *bsq, int size)
{
    for (int n = 0; n < size; n++, i += bsq->len_line + 1)
        if (check_square(bsq, i, size) == 1)
            return 1;
    return 0;
}

static void replace_square(bsq_t *bsq, int cords)
{
    for (int n = 0; n < bsq->size; n++, cords++) {
        for (int j = 0; j < bsq->size; j++, cords++)
            bsq->buff[cords] = 'x';
        cords += bsq->len_line - bsq->size;
    }
}

static void find_square(bsq_t *bsq, int *cords, int size, int i)
{
    for (size = bsq->size; is_square(i, bsq, size + 1) != 1; size++);
    (size > bsq->size) ? (bsq->size = size, *cords = i) : (0);
}

void find_bsq(bsq_t *bsq)
{
    int i = 0;
    int cords = 0;
    int size = 0;

    line_len(bsq);
    for (i = 0; bsq->buff[i] != '\n'; i++);
    cords = i + 1;
    for (i += 1; bsq->buff[i] != '\0'; i++)
        if (bsq->buff[i] == '.')
            find_square(bsq, &cords, size, i);
    replace_square(bsq, cords);
    display_map(bsq);
}

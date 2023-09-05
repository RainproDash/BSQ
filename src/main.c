/*
** EPITECH PROJECT, 2022
** B-CPE-110-LYN-1-1-BSQ-vivien.boitard
** File description:
** main
*/

#include "../include/header.h"

static void init_bsq(bsq_t *bsq)
{
    bsq->len_line = 0;
    bsq->file_len = 0;
    bsq->size = 0;
    bsq->buff = NULL;
}

static void destroy_bsq(bsq_t *bsq)
{
    free(bsq->buff);
    free(bsq);
}

int main(int ac, char **av)
{
    bsq_t *bsq = malloc(sizeof(bsq_t));

    if (ac < 2 || ac > 3)
        return 84;
    init_bsq(bsq);
    if (ac == 2) {
        if (error_file(av[1]) == 84)
            return 84;
        init_map(av[1], bsq);
        destroy_bsq(bsq);
        return 0;
    }
    if (generate_map(av[1], av[2], bsq) == 84)
        return 84;
    destroy_bsq(bsq);
    return 0;
}

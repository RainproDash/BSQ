/*
** EPITECH PROJECT, 2022
** B-CPE-110-LYN-1-1-BSQ-vivien.boitard
** File description:
** generate_map
*/

#include "../include/header.h"

static int check_valid_map_generation(char *nb, char *str, int *len)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] != 'o' && str[i] != '.')
            return 84;
    for (int i = 0; nb[i] != '\0'; i++, len++)
        if (nb[i] < '0' || nb[i] > '9')
            return 84;
    return 0;
}

static void generate_nb(char *nb, int *index, bsq_t *bsq)
{
    for (int i = 0; nb[i] != '\0'; i++, *index += 1)
        bsq->buff[*index] = nb[i];
    bsq->buff[*index] = '\n';
    *index += 1;
}

static void generate_str(char *str, int index, int n, bsq_t *bsq)
{
    for (int j = 0; index < n * (n + 1);) {
        for (int k = 0; k < n; k++, index++, j++) {
            (str[j] == '\0') ? (j = 0) : 0;
            bsq->buff[index] = str[j];
        }
        bsq->buff[index++] = '\n';
    }
    bsq->buff[index] = '\0';
}

int generate_map(char *nb, char *str, bsq_t *bsq)
{
    int n = 0;
    int len_nb = 0;
    int index = 0;

    if (check_valid_map_generation(nb, str, &len_nb) == 84)
        return 84;
    n = my_getnbr(nb);
    if (n == 0)
        return 84;
    bsq->buff = malloc(sizeof(char) * (n * (n + 1) + len_nb + 1) + 1);
    generate_nb(nb, &index, bsq);
    generate_str(str, index, n, bsq);
    find_bsq(bsq);
    return 0;
}

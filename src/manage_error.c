/*
** EPITECH PROJECT, 2022
** B-CPE-110-LYN-1-1-BSQ-vivien.boitard
** File description:
** manage_errro
*/

#include "../include/header.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>

static int same_line_len(char *buff, int i, int *len, int len_ref)
{
    if (buff[i] == '\n') {
        if (*len - 1 != len_ref)
            return 84;
        else
            *len = 0;
    }
    return 0;
}

static int valide_input(char *buff, int nb, int size)
{
    int len_ref;
    int len = 0;
    int nb_n = 1;

    len = len;
    for (len_ref = 0; buff[nb + 1] != '\n'; nb++, len_ref++);
    for (int i = nb + 2, len = 1; buff[i] != '\0'; i++, len++) {
        if (buff[i] != '.' && buff[i] != 'o' && buff[i] != '\n')
            return 84;
        if (same_line_len(buff, i, &len, len_ref) == 84)
            return 84;
        if (buff[i] == '\n')
            nb_n++;
    }
    if (nb_n != size)
        return 84;
    return 0;
}

int error_file(char const *filepath)
{
    char *buff = init_buffer(filepath);
    char *size = malloc(sizeof(char) * 10);
    int nb;

    if (buff == NULL)
        return 84;
    for (nb = 0; buff[nb] != '\n'; nb++) {
        if (buff[nb] < '0' || buff[nb] > '9')
            return 84;
        size[nb] = buff[nb];
    }
    size[nb + 1] = '\0';
    if (valide_input(buff, nb, my_getnbr(size)) == 84)
        return 84;
    free(size);
    free(buff);
    return 0;
}

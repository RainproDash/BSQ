/*
** EPITECH PROJECT, 2022
** B-CPE-110-LYN-1-1-BSQ-vivien.boitard
** File description:
** init_variable
*/

#include "../include/header.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/stat.h>

char *init_buffer(char const *filepath)
{
    struct stat st;
    char *buff;
    int fd = open(filepath, O_RDONLY);

    if (fd == -1)
        return (NULL);
    stat(filepath, &st);
    buff = malloc(sizeof(char) * (st.st_size + 1));
    read(fd, buff, st.st_size);
    close (fd);
    return (buff);
}

void init_map(char const *filepath, bsq_t *bsq)
{
    bsq->buff = init_buffer(filepath);
    if (bsq->buff == NULL)
        return;
    find_bsq(bsq);
}

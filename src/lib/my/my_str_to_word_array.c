/*
** EPITECH PROJECT, 2022
** B-CPE-100-LYN-1-1-cpoolday08-vivien.boitard
** File description:
** my_str_to_word_array
*/

#include "my.h"
#include <stdlib.h>

static int verif_letter(char charac)
{
    if (charac == '.' || charac == 'o')
        return 1;
    if (charac > '0' && charac < '9')
        return 1;
    return 0;
}

static int nb_of_word(char const *str)
{
    int count = 0;
    int pos_str = 0;

    for (int i = pos_str; str[i] != '\0'; i++)
        if (verif_letter(str[i]) == 0 && verif_letter(str[i + 1]) != 0)
            count++;
    return (count);
}

static int word_length(char const *str, int pos)
{
    int count = 0;

    for (int i = pos; str[i] != '\0'; i++, count++)
        if (verif_letter(str[i]) == 0)
            return (count);
    return (count);

}

char **my_str_to_word_array(char const *str)
{
    int nb_word = nb_of_word(str);
    int j;
    int pos_str = 0;
    char **tab = malloc(sizeof(char *) * (nb_word + 1));

    for (int i = 0; i < nb_word; i++, pos_str++) {
        tab[i] = malloc(sizeof(char) * (word_length(str, i) + 1));
        for (; verif_letter(str[pos_str]) == 0; pos_str++);
        for (j = 0; verif_letter(str[pos_str]) == 1; j++, pos_str++)
            tab[i][j] = str[pos_str];
        tab[i][j] = '\0';
    }
    return (tab);
}

/*
** EPITECH PROJECT, 2021
** week_1_synth-pool
** File description:
** error
*/

#include "my.h"

int str_cmp(char *one, char *two)
{
    if (my_strlen(one) != my_strlen(two))
        return (0);
    for (int i = 0; one[i] != '\0'; i++) {
        if (one[i] != two[i])
            return (0);
    }
    return (1);
}

void free_list(pokemon_t ***pokedex)
{
    for (int i = 0; (*pokedex)[i] != NULL; i++) {
        free((*pokedex)[i]->name);
        free((*pokedex)[i]);
    }
    free(*pokedex);
    return;
}

int error1(int res, int res2, int len, char *line)
{
    for (int i = 0; i < len - 1; i++) {
        if (line[i] == ';' && line[i + 1] != ';')
            res++;
    }
    for (int i = 0; i < len; i++) {
        if (line[i] == ';')
            res2++;
    }
    if (res != 4 || res2 != res) {
        return (1);
    }
    return (0);
}

bool error(char *line)
{
    int res = 0;
    int res2 = 0;
    int len = my_strlen(line);
    int a = 0;

    if (error1(res, res2, len, line))
        return (1);
    for (int i = 0; line[i] != '\0' && line[i] != ';'; i++) {
        if ((line[i] < 'a' || line[i] > 'z') && (line[i] < 'A' \
        || line[i] > 'Z')) {
            return (1);
        }
    }
    for (a = 0; line[a] != ';'; a++);
    for (a; line[a] != '\0'; a++) {
        if (line[a] != ';' && (line[a] < '0' || line[a] > '9')) {
            return (1);
        }
    }
    return (0);
}
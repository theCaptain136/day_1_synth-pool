/*
** EPITECH PROJECT, 2021
** week_1_synth-pool
** File description:
** lsit_tool
*/

#include "my.h"

int exists(pokemon_t **pokedex, char *name)
{
    for (int i = 0; pokedex[i] != NULL; i++) {
        if (str_cmp(pokedex[i]->name, name) == 1)
            return (1);
    }
    return (0);
}

char *frankenstein(char *str)
{
    int len_dir = 10;
    int len_file = my_strlen(str);
    char *res = malloc(sizeof(char) * (len_file + len_dir + 1));
    char dir[] = "./pokecfg/";

    if (res == NULL)
        return (NULL);
    for (int i = 0; i < len_dir; i++) {
        res[i] = dir[i];
    }
    for (int i = 0; i < len_file; i++) {
        res[i + len_dir] = str[i];
    }
    res[len_dir + len_file] = '\0';
    return (res);
}

int count(char *path)
{
    FILE *fd = fopen(path, "r");
    char *line = NULL;
    size_t t = 0;
    int res = 0;

    while (getline(&line, &t, fd) != EOF) {
        if (line[0] != '#')
            res++;
        free(line);
        line = NULL;
        t = 0;
    }
    free(line);
    fclose(fd);
    return (res);
}

int count_all(void)
{
    struct dirent *dir = NULL;
    DIR *fd = opendir("./pokecfg");
    char *full_way = NULL;
    int nb = 0;

    while ((dir = readdir(fd)) != NULL) {
        full_way = frankenstein(dir->d_name);
        nb += count(full_way);
        free(full_way);
    }
    closedir(fd);
    return (nb);
}

char *str_cp(char *str)
{
    char *res = NULL;

    res = malloc(sizeof(char) * (my_strlen(str) + 1));
    if (res == NULL)
        return (NULL);
    for (int i = 0; str[i] != '\0'; i++)
        res[i] = str[i];
    res[my_strlen(str)] = '\0';
    return (res);
}
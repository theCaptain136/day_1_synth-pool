/*
** EPITECH PROJECT, 2021
** week_1_synth-pool
** File description:
** main
*/

#include "my.h"

int is_it_new(pokemon_t ***list, char **line)
{
    if (my_len(*list) < 2)
        return (1);
    for (int i = 0; (*list)[i] != NULL; i++) {
        if (str_cmp((*list)[i]->name, line[0])) {
            return (0);
        }
    }
    return (1);
}

void fill_struct(char *line, char **tmp, pokemon_t ***pokedex, int *i)
{
        if (line[my_strlen(line) - 1] == '\n')
            line[my_strlen(line) - 1] = '\0';
        if (line[0] != '#' && error(line) == 0 && is_it_new(pokedex, tmp) \
        == 1) {
            (*pokedex)[*i] = malloc(sizeof(pokemon_t *));
            (*pokedex)[*i]->name = str_cp(tmp[0]);
            (*pokedex)[*i]->atk = my_getnbr(tmp[1]);
            (*pokedex)[*i]->defense = my_getnbr(tmp[2]);
            (*pokedex)[*i]->speed = my_getnbr(tmp[3]);
            (*pokedex)[*i]->health = my_getnbr(tmp[4]);
            *i += 1;
        }
}

void add_pokemon(pokemon_t ***pokedex, char *path)
{
    char *line = NULL;
    size_t t = 0;
    FILE *fd = fopen(path, "r");
    char **tmp = NULL;
    int i = 0;

    while ((*pokedex)[i] != NULL)
        i++;
    while (getline(&line, &t, fd) != EOF) {
        tmp = my_strtok(line, ';');
        fill_struct(line, tmp, pokedex, &i);
        free_all(tmp);
        free(line);
        line = NULL;
    }
    free(line);
    fclose(fd);
}

pokemon_t **init_pokedex(void)
{
    int amount = count_all();
    pokemon_t **pokedex = malloc(sizeof(pokemon_t *) * (amount + 2));
    struct dirent *dir = NULL;
    DIR *fd = opendir("./pokecfg");
    char *full_way = NULL;

    for (int i = 0; i <= amount + 1; i++) {
        pokedex[i] = NULL;
    }
    while ((dir = readdir(fd)) != NULL) {
        full_way = frankenstein(dir->d_name);
        add_pokemon(&pokedex, full_way);
        free(full_way);
    }
    closedir(fd);
    return (pokedex);
}

int main(int ac, char **av)
{
    pokemon_t **pokedex = init_pokedex();
    if (dash_h(ac, av, &pokedex))
        return (0);
    bubble_sort(pokedex);
    print_pokedex(pokedex);
    if (ac_error(ac, &pokedex))
        return (84);
    if (doesnt_exist(&pokedex, av) == 1)
        return (84);
    fight(pokedex, av[1], av[2]);
    free_list(&pokedex);
    return (0);
}
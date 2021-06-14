/*
** EPITECH PROJECT, 2021
** week_1_synth-pool
** File description:
** prints
*/

#include "my.h"

int doesnt_exist(pokemon_t ***pokedex, char **av)
{
    if (!exists(*pokedex, av[1]) || !exists(*pokedex, av[2])) {
        if (!exists(*pokedex, av[1]))
            fprintf(stderr, "Pokemon at av[1] not found\n");
        else
            fprintf(stderr, "Pokemon at av[2] not found\n");
        free_list(pokedex);
        return (1);
    }
    return (0);
}

int ac_error(int ac, pokemon_t ***pokedex)
{
    if (ac < 3) {
        fprintf(stderr, "Choose 2 pokemons from the above!\n");
        fprintf(stderr, "  use -h for more information\n");
        free_list(pokedex);
        return (1);
    }
    else if (ac > 3) {
        fprintf(stderr, "too many arguments. Choose 2 from the above!");
        fprintf(stderr, "\n  use -h for more information\n");
        free_list(pokedex);
        return (1);
    }
    return (0);
}

void print_pokedex(pokemon_t **pokedex)
{
    for (int i = 0; pokedex[i] != NULL; i++) {
        printf("Pokemon %s has %d attack, %d defense", \
        pokedex[i]->name, pokedex[i]->atk, pokedex[i]->defense);
        printf(", %d speed and %d health\n", pokedex[i]->speed, \
        pokedex[i]->health);
    }
}

int dash_h(int ac, char **av, pokemon_t ***pokedex)
{
    if (ac == 2 && my_strlen(av[1]) >= 2) {
        if (str_cmp(av[1], "-h")) {
            printf("USAGE\n\n./pokemon [pokemon one] [pokemon two]\n");
            printf("use no parameter to list all pokemons in the pokedex\n");
            printf("   all the pokemons are stored in the files in the ");
            printf("pokecfg directory\n");
            printf("   to add a pokemon strictly follow this format: name;");
            printf("attack;defense;speed;health\n");
            free_list(pokedex);
            return (1);
        }
    }
    return (0);
}
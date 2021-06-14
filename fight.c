/*
** EPITECH PROJECT, 2021
** week_1_synth-pool
** File description:
** fight
*/

#include "my.h"

int dead(pokemon_t *one, pokemon_t *two)
{
    if (one->health <= 0) {
        printf("%s is KO\n", one->name);
        printf("%s wins the fight!\n", two->name);
        return (1);
    }
    else if (two->health <= 0) {
        printf("%s is KO\n", two->name);
        printf("%s wins the fight!\n", one->name);
        return (1);
    }
    return (0);
}

int battle0(pokemon_t *one, pokemon_t *two)
{
    if (one->atk <= two->defense && two->atk <= one->defense) {
        if (one->health > two->health)
            printf("%s wins by being fatter!\n", one->name);
        else
            printf("%s wins by being fatter!\n", one->name);
        return (1);
    }
    return (0);
}

void until_death(pokemon_t *one, pokemon_t *two)
{
    int who = 1;
    int atk = 0;

    if (one->speed > two->speed)
        who = 1;
    else
        who *= -1;
    while (true) {
        if (battle0(one, two))
            return;
        if (who == 1) {
            battle1(one, two, atk);
        } else {
            battle2(one, two, atk);
        }
        if (dead(one, two) == 1)
            return;
    who *= -1;
    }
}

int fight(pokemon_t **list, char *fighter_one, char *fighter_two)
{
    pokemon_t *one = NULL;
    pokemon_t *two = NULL;

    for (int i = 0; list[i] != NULL; i++) {
        if (str_cmp(list[i]->name, fighter_one))
            one = list[i];
        if (str_cmp(list[i]->name, fighter_two))
            two = list[i];
    }
    until_death(one, two);
    return (0);
}
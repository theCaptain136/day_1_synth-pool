/*
** EPITECH PROJECT, 2021
** week_1_synth-pool
** File description:
** battle
*/

#include "my.h"

void battle1(pokemon_t *one, pokemon_t *two, int atk)
{
    atk = rand() % one->atk + 1;
    printf("%s attacks for %i damage\n", one->name, atk);
    printf("%s blocks %i damage\n", two->name, two->defense);
    atk -= two->defense;
    if (atk < 0)
        atk = 0;
    two->health -= atk;
    if (two->health < 0)
        two->health = 0;
    printf("%s loses %i health (%i left)\n", two->name, atk, two->health);
}

void battle2(pokemon_t *one, pokemon_t *two, int atk)
{
    atk = rand() % two->atk + 1;
    printf("%s attacks for %i damage\n", two->name, atk);
    printf("%s blocks %i damage\n", one->name, one->defense);
    atk -= one->defense;
    if (atk < 0)
        atk = 0;
    one->health -= atk;
    if (one->health < 0)
        one->health = 0;
    printf("%s loses %i health (%i left)\n", one->name, atk, one->health);
}
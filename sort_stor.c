/*
** EPITECH PROJECT, 2021
** week_1_synth-pool
** File description:
** sort_stor
*/

#include "my.h"

void swap1(sort t)
{
    *t.o = t.arr[t.i]->name[*t.a];
    *t.t = t.arr[t.i + 1]->name[*t.a];
    while (*t.o != '\0' && *t.o == *t.t) {
        *t.a += 1;
        *t.o = t.arr[t.i]->name[*t.a];
        *t.t = t.arr[t.i + 1]->name[*t.a];
    }
    if (*t.o == '\0') {
        *t.a -= 1;
        *t.o = t.arr[t.i]->name[*t.a];
        *t.t = t.arr[t.i + 1]->name[*t.a];
    }
}

void swap2(char *o, char *t)
{
    if (*o >= 'A' && *o <= 'Z')
        *o -= 32;
    if (*t >= 'A' && *t <= 'Z')
        *t += 32;
}

void struct_swap2(pokemon_t **arr, int i, pokemon_t *tmp)
{
    arr[i]->atk = tmp->atk;
    arr[i]->defense = tmp->defense;
    arr[i]->speed = tmp->speed;
    arr[i]->health = tmp->health;
}

void struct_swap3(pokemon_t **arr, int i, pokemon_t *tmp)
{
    arr[i + 1]->atk = arr[i]->atk;
    arr[i + 1]->defense = arr[i]->defense;
    arr[i + 1]->speed = arr[i]->speed;
    arr[i + 1]->health = arr[i]->health;
    free(arr[i]->name);
    arr[i]->name = str_cp(tmp->name);
}
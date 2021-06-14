/*
** EPITECH PROJECT, 2021
** week_1_synth-pool
** File description:
** sort
*/

#include "my.h"

int my_len(pokemon_t **str)
{
    int i = 0;

    while (str[i] != NULL) {
        i++;
    }
    return (i);
}

int big_brother(pokemon_t **arr)
{
    int a = 0;
    char o = 0;
    char t = 0;

    for (int i = 0; i < my_len(arr) - 1; i++) {
        swap1((sort){&o, &t, arr, i, &a});
        if (o >= 'A' && o <= 'Z')
            o -= 32;
        if (t >= 'A' && t <= 'Z')
            t += 32;
        if (o > t) {
            return (0);
        }
        a = 0;
    }
    return (1);
}

void struct_swap(pokemon_t *tmp, pokemon_t **arr, int i)
{
    tmp->name = str_cp(arr[i + 1]->name);
    tmp->atk = arr[i + 1]->atk;
    tmp->defense = arr[i + 1]->defense;
    tmp->speed = arr[i + 1]->speed;
    tmp->health = arr[i + 1]->health;
    free(arr[i + 1]->name);
    arr[i + 1]->name = str_cp(arr[i]->name);
    arr[i + 1]->atk = arr[i]->atk;
    arr[i + 1]->defense = arr[i]->defense;
    arr[i + 1]->speed = arr[i]->speed;
    arr[i + 1]->health = arr[i]->health;
    free(arr[i]->name);
    arr[i]->name = str_cp(tmp->name);
    arr[i]->atk = tmp->atk;
    arr[i]->defense = tmp->defense;
    arr[i]->speed = tmp->speed;
    arr[i]->health = tmp->health;
}

void swap(pokemon_t **arr)
{
    int a = 0;
    char o = 0;
    char t = 0;
    pokemon_t *tmp = malloc(sizeof(pokemon_t));

    for (int i = 0; i < my_len(arr) - 1; i++) {
        swap1((sort){&o, &t, arr, i, &a});
        if (o >= 'A' && o <= 'Z')
            o -= 32;
        if (t >= 'A' && t <= 'Z')
            t += 32;
        if (o > t) {
            struct_swap(tmp, arr, i);
            free(tmp->name);
        }
        a = 0;
    }
    free(tmp);
}

void bubble_sort(pokemon_t **arr)
{
    while (big_brother(arr) == 0) {
        swap(arr);
    }
}
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
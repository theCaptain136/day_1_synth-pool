/*
** EPITECH PROJECT, 2020
** a
** File description:
** a
*/

#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <dirent.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdbool.h>

typedef struct pokmon {
    char *name;
    int atk;
    int defense;
    int speed;
    int health;
} pokemon_t;

typedef struct sort {
    char *o;
    char *t;
    pokemon_t **arr;
    int i;
    int *a;
} sort;

typedef struct str_tok {
    char **res;
    int end;
    int start;
    int *i;
    char *str;
    int *cell;
} str_tok;

void my_putchar(char c);
char *my_strstr(char *, char const);
int my_isneg(int);
int my_strcmp(char const *, char const *);
int my_put_nbr(int);
int my_strncmp(char const *, char const *, int);
void my_swap(int *, int *);
char *my_strupcase(char *);
int my_putstr(char const *);
char *my_strlowcase(char *);
int my_strlen(char *);
char *my_strcapitalize(char *);
int my_getnbr(char const *);
int my_str_isalpha(char const *);
void my_sort_int_array(int *, int);
int my_str_isnum(char const *);
int my_compute_power_rec(int, int);
int my_str_islower(char const *);
int my_compute_square_root(int);
int my_str_isupper(char const *);
int my_is_prime(int);
int my_str_isprintable(char const *);
int my_find_prime_sup(int);
int my_showstr(char const *);
char *my_strcpy(char *, char const *);
int my_showmem(char const *, int);
char *my_strncpy(char *, char const *, int);
char *my_strcat(char *, char const *);
char *my_revstr(char *);
char *my_strncat(char *, char const *, int);
char **my_str_to_word_array(char *);
char *my_strdup(char const *);
char **result(char const *, char **, int, int);
int wordnum(char const *);
int is_alpha(char);
int my_numnum(char *);
int calculate_plus(char *, char *);
int calculate_minus(char **, char *, char *);
int my_strstrlen(char **str);
char **my_arr_cpy(char **str, char ***dest);
char **arr_cpy(char **arr);
void free_all(char **str);
int sign(char const *str);
char **my_strtok(char *str, char delim);
int count_delim(char *str, char delim);
char *str_cp(char *str);
bool error(char *line);
int add_pokemon(pokemon_t ***pokedex, char *path);
int count_all();
int count(char *path);
char *frankenstein(char *str);
int bubble_sort(pokemon_t **arr);
int my_len(pokemon_t **str);
int str_cmp(char *one, char *two);
int fight(pokemon_t **list, char *fighter_one, char *fighter_two);
int exists(pokemon_t **pokedex, char *name);
int doesnt_exist(pokemon_t ***pokedex, char **av);
int ac_error(int ac, pokemon_t ***pokedex);
void print_pokedex(pokemon_t **pokedex);
int dash_h(int ac, char **av, pokemon_t ***pokedex);
void battle1(pokemon_t *one, pokemon_t *two, int atk);
void battle2(pokemon_t *one, pokemon_t *two, int atk);
void free_list(pokemon_t ***pokedex);
void swap1(sort t);
int malloc_error(pokemon_t **pokedex);
int param_error(pokemon_t ***pokedex, int ac, char **av);
void swap2(char *o, char *t);
void struct_swap2(pokemon_t **arr, int i, pokemon_t *tmp);
void struct_swap3(pokemon_t **arr, int i, pokemon_t *tmp);
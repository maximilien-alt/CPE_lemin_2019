/*
** EPITECH PROJECT, 2019
** CPE_lemin_2019
** File description:
** storage.c
*/

#include "../include/my.h"

/*void print_value(storage_t *ret)
{
    my_printf("Nombres de nodes: %i\n", ret->nb_nodes);
    my_printf("Nombres de ants: %i\n", ret->nb_ants);
    my_printf("Start: %i %i %i\n", ret->start->index, \
    ret->start->x, ret->start->y);
    my_printf("End: %i %i %i\n", ret->end->index, ret->end->x, ret->end->y);
    print_list(ret->nodes);
    for (int i = 0; i < ret->nb_nodes; i++) {
        for (int j = 0; j < ret->nb_nodes; j++)
            my_printf("%d ", ret->links[i][j]);
        my_printf("\n");
    }
}*/

void fill_links(storage_t *ret, char *str)
{
    static int init = 0;
    char **arr = my_str_to_word_array(str, "-");

    if (!init++) {
        ret->links = my_malloc(sizeof(int *) * ret->nb_nodes);
        for (int i = 0; i < ret->nb_nodes; i++) {
            ret->links[i] = my_malloc(sizeof(int) * ret->nb_nodes);
            for (int j = 0; j < ret->nb_nodes; j++)
                ret->links[i][j] = 0;
        }
    }
    ret->links[my_getnbr(arr[0])][my_getnbr(arr[1])] = 1;
    ret->links[my_getnbr(arr[1])][my_getnbr(arr[0])] = 1;
}

void change_state(char **arr, int *state)
{
    if (!my_strcmp(arr[0], "##end")) {
        *state = 3;
        return;
    }
    if (!my_strcmp(arr[0], "##start")) {
        *state = 2;
        return;
    }
    for (int i = 0; arr[0][i]; i++) {
        if (arr[0][i] == '-') {
            *state = 4;
            return;
        }
    }
    return;
}

int create_storage_bis(storage_t *ret, char **arr, char *buffer, int state)
{
    if (state == 0) {
        ret->nb_ants = my_getnbr(arr[0]);
        state = 1;
        return (state);
    }
    change_state(arr, &state);
    if ((state == 1 || state == 2 || state == 3) && arr[0][0] != '#') {
        fill_nodes(ret, arr, state);
        ret->nb_nodes += 1;
        state = 1;
    }
    (state == 4) ? fill_links(ret, buffer) : 0;
    return (state);
}

storage_t *create_storage(char *buffer, char **arr, size_t sizet)
{
    storage_t *ret = my_malloc(sizeof(storage_t));
    int state = 0;

    ret->nb_nodes = 0;
    ret->nodes = NULL;
    ret->end = NULL;
    ret->start = NULL;
    while (getline(&buffer, &sizet, stdin) != -1) {
        arr = clean_array(my_str_to_word_array(buffer, "\n \t"));
        if (!arr || !arr[0])
            continue;
        if (error_handling(arr, state) == 84)
            return (NULL);
        state = create_storage_bis(ret, arr, buffer, state);
    }
    free(buffer);
    return (ret);
}
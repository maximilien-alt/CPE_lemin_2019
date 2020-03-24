/*
** EPITECH PROJECT, 2019
** CPE_lemin_2019
** File description:
** storage_next.c
*/

#include "../include/my.h"

char **clean_array(char **arr)
{
    for (int i = 0; arr[i]; i++) {
        if (arr[i][0] != '\0' && (arr[i][0] == '#' && arr[i][1] != '#')) {
            arr[i] = NULL;
            return (arr);
        }
    }
    return (arr);
}

cell_t *init_cell(int index, int x, int y)
{
    cell_t *ret = my_malloc(sizeof(cell_t));

    ret->index = index;
    ret->x = x;
    ret->y = y;
    return (ret);
}

void fill_nodes(storage_t *ret, char **arr, int state)
{
    int index = my_getnbr(arr[0]);
    int x = my_getnbr(arr[1]);
    int y = my_getnbr(arr[2]);

    if (state == 2)
        ret->start = init_cell(index, x, y);
    if (state == 3)
        ret->end = init_cell(index, x, y);
    add_node_back(&ret->nodes, x, y, index);
}

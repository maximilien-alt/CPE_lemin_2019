/*
** EPITECH PROJECT, 2019
** CPE_lemin_2019
** File description:
** nodes.c
*/

#include "../include/my.h"

void print_list(nodes_t *nodes)
{
    for (nodes_t *copy = nodes; copy; copy = copy->next)
        my_printf("%d %d %d\n", copy->cellule.index, \
        copy->cellule.x, copy->cellule.y);
}

void add_node_back(nodes_t **nodes, int x, int y, int index)
{
    nodes_t *new_node = my_malloc(sizeof(nodes_t));
    nodes_t *save = *nodes;

    new_node->cellule.x = x;
    new_node->cellule.y = y;
    new_node->cellule.index = index;
    new_node->next = NULL;
    if (!*nodes) {
        new_node->previous = NULL;
        *nodes = new_node;
        return;
    }
    while (save->next)
        save = save->next;
    save->next = new_node;
    new_node->previous = save;
}

nodes_t *init_nodes(void)
{
    nodes_t *nodes = NULL;

    for (int index = 0; index < 100; index += 1)
        add_node_back(&nodes, index, index, index);
    return (nodes);
}
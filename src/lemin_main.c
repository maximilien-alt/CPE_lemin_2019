/*
** EPITECH PROJECT, 2019
** CPE_lemin_2019
** File description:
** main.c
*/

#include "../include/my.h"

int main(int ac, char *av[])
{
    storage_t *storage = NULL;
    (void)av;

    if (ac != 1)
        return (84);
    storage = create_storage(NULL, NULL, 100);
    if (!storage)
        return (84);
}
/*
** EPITECH PROJECT, 2023
** main
** File description:
** main.c
*/

#include "my.h"
#include "my_rpg.h"

int my_rpg_general(void)
{
    main_s data;
    data.window = malloc(sizeof(window_s));
    if (!init_window(&data))
        return (84);
    display_window(&data);
    free_all(&data);
    return (0);
}

int main(int argc, char **argv, char **env)
{
    if (argv[0][0] != '.')
        return 84;
    if (!env || !env[0])
        return (84);
    if (argc > 3)
        return (84);
    if (verif_file() == -1)
        return 84;
    if (my_rpg_general() == 84)
        return (84);
    return (0);
}

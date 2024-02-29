/*
** EPITECH PROJECT, 2023
** periph_vehicule
** File description:
** function : periph_vehicule.c
*/

#include "my.h"
#include "my_rpg.h"

int periph_vehicule(main_s *game_s)
{
    if (game_s->where_vehicule == 1)
        periph_pickup(game_s);
    if (game_s->where_vehicule == 2)
        periph_tractor(game_s);
    if (game_s->where_vehicule == 3)
        periph_harvest(game_s);
    return 0;
}

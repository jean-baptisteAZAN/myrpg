/*
** EPITECH PROJECT, 2023
** init_collision.c
** File description:
** function : init_collision
*/

#include "my.h"
#include "my_rpg.h"

void init_collision(main_s *data)
{
    data->collis_s->map_collis =
        sfImage_createFromFile("./ressources/res/game/map_collision.png");
    data->collis_s->sprite_map_collis =
        init_fond("./ressources/res/game/map_collision.png");
    data->collis_s->is_good =
        sfImage_getPixel(data->collis_s->map_collis, 930, 805);
    data->collis_s->pickup = malloc(sizeof(int) * 4);
    get_collision_pickup(data);
    data->collis_s->tractor = malloc(sizeof(int) * 4);
    get_collision_tractor(data);
    data->collis_s->tractor = malloc(sizeof(int) * 4);
    get_collision_tractor(data);
    data->collis_s->harvest = malloc(sizeof(int) * 4);
    get_collision_harvest(data);
}

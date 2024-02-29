/*
** EPITECH PROJECT, 2023
** collision_pickup.c
** File description:
** function : collision_pickup
*/

#include "my.h"
#include "my_rpg.h"

int collision_pickup_map(main_s *data, int y, int x)
{
    data->ress_s.color_tmp = sfImage_getPixel(data->collis_s->map_collis, y, x);
    if (data->ress_s.color_tmp.r != data->collis_s->is_good.r ||
        data->ress_s.color_tmp.g != data->collis_s->is_good.g ||
        data->ress_s.color_tmp.b != data->collis_s->is_good.b)
        return 1;
    return 0;
}

int verif_collision_pickup_vehicule(main_s *data, int y, int x)
{
    if (((y - data->tractor_s->pos_x) < 50 &&
        (y - data->tractor_s->pos_x) > -50) &&
        ((x - data->tractor_s->pos_y) < 50 &&
        (x - data->tractor_s->pos_y) > -50))
        return 1;
    if (((y - data->harvest_s->pos_x) < 50 &&
        (y - data->harvest_s->pos_x) > -50) &&
        ((x - data->harvest_s->pos_y) < 50 &&
        (x - data->harvest_s->pos_y) > -50))
        return 1;
    return 0;
}

int collision_pickup(main_s *data, int y, int x)
{
    if (y <= 0 || x <= 0)
        return 0;
    if (collision_pickup_map(data, (y - 25), (x - 25)) == 1)
        return 1;
    if (collision_pickup_map(data, (y + 25), (x + 25)) == 1)
        return 1;
    if (collision_pickup_map(data, (y - 25), (x + 25)) == 1)
        return 1;
    if (collision_pickup_map(data, (y + 25), (x - 25)) == 1)
        return 1;

    if (verif_collision_pickup_vehicule(data, y, x) == 1)
        return 1;
    return 0;
}

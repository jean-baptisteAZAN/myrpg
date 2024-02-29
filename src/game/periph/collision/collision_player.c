/*
** EPITECH PROJECT, 2023
** collision_player.c
** File description:
** function : collision_player
*/

#include "my.h"
#include "my_rpg.h"

int collision_player_map(main_s *data, int y, int x)
{
    data->ress_s.color_tmp = sfImage_getPixel(data->collis_s->map_collis, y, x);
    if (data->ress_s.color_tmp.r != data->collis_s->is_good.r ||
        data->ress_s.color_tmp.g != data->collis_s->is_good.g ||
        data->ress_s.color_tmp.b != data->collis_s->is_good.b)
        return 1;
    if (verif_zone_point(get_collision_pickup(data), y, x) == 1)
        return 1;
    if (verif_zone_point(get_collision_tractor(data), y, x) == 1)
        return 1;
    if (verif_zone_point(get_collision_harvest(data), y, x) == 1)
        return 1;
    return 0;
}

int collision_player(main_s *data, int y, int x)
{
    if (y <= 0 || x <= 0)
        return 0;
    if (collision_player_map(data, (y - 2), (x - 2)) == 1)
        return 1;
    if (collision_player_map(data, (y + 2), (x + 2)) == 1)
        return 1;
    if (collision_player_map(data, (y - 2), (x + 2)) == 1)
        return 1;
    if (collision_player_map(data, (y + 2), (x - 2)) == 1)
        return 1;
    return 0;
}

/*
** EPITECH PROJECT, 2023
** collision_player.c
** File description:
** function : collision_player
*/

#include "my.h"
#include "my_rpg.h"

int *get_collision_pickup(main_s *data)
{
    if ((data->pickup_s.sens == 1) || (data->pickup_s.sens == 3) ||
        (data->pickup_s.sens == 5) || (data->pickup_s.sens == 7)) {
        data->collis_s->pickup[0] = data->pickup_s.pos_x - 22;
        data->collis_s->pickup[1] = data->pickup_s.pos_x + 22;
        data->collis_s->pickup[2] = data->pickup_s.pos_y - 25;
        data->collis_s->pickup[3] = data->pickup_s.pos_y + 24;
    }
    if ((data->pickup_s.sens == 0) || (data->pickup_s.sens == 4)) {
        data->collis_s->pickup[0] = data->pickup_s.pos_x - 12;
        data->collis_s->pickup[1] = data->pickup_s.pos_x + 12;
        data->collis_s->pickup[2] = data->pickup_s.pos_y - 25;
        data->collis_s->pickup[3] = data->pickup_s.pos_y + 25;
    }
    if ((data->pickup_s.sens == 2) || (data->pickup_s.sens == 6)) {
        data->collis_s->pickup[0] = data->pickup_s.pos_x - 24;
        data->collis_s->pickup[1] = data->pickup_s.pos_x + 24;
        data->collis_s->pickup[2] = data->pickup_s.pos_y - 15;
        data->collis_s->pickup[3] = data->pickup_s.pos_y + 12;
    }
    return data->collis_s->pickup;
}

int *get_collision_tractor(main_s *data)
{
    if ((data->tractor_s->sens == 0) || (data->tractor_s->sens == 4)) {
        data->collis_s->tractor[0] = data->tractor_s->pos_x - 16;
        data->collis_s->tractor[1] = data->tractor_s->pos_x + 16;
        data->collis_s->tractor[2] = data->tractor_s->pos_y - 27;
        data->collis_s->tractor[3] = data->tractor_s->pos_y + 19;
    } else {
        data->collis_s->tractor[0] = data->tractor_s->pos_x - 22;
        data->collis_s->tractor[1] = data->tractor_s->pos_x + 22;
        data->collis_s->tractor[2] = data->tractor_s->pos_y - 21;
        data->collis_s->tractor[3] = data->tractor_s->pos_y + 16;
    }
    return data->collis_s->tractor;
}

int *get_collision_harvest(main_s *data)
{
    if ((data->harvest_s->sens == 0) || (data->harvest_s->sens == 4)) {
        data->collis_s->harvest[0] = data->harvest_s->pos_x - 16;
        data->collis_s->harvest[1] = data->harvest_s->pos_x + 16;
        data->collis_s->harvest[2] = data->harvest_s->pos_y - 27;
        data->collis_s->harvest[3] = data->harvest_s->pos_y + 17;
    } else {
        data->collis_s->harvest[0] = data->harvest_s->pos_x - 22;
        data->collis_s->harvest[1] = data->harvest_s->pos_x + 22;
        data->collis_s->harvest[2] = data->harvest_s->pos_y - 21;
        data->collis_s->harvest[3] = data->harvest_s->pos_y + 16;
    }
    return data->collis_s->harvest;
}

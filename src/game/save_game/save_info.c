/*
** EPITECH PROJECT, 2023
** save_info.c
** File description:
** function : *
*/

#include "my.h"
#include "my_rpg.h"

char *sub_get_information_player(main_s *data, int line)
{
    if (line == 1)
        return int_to_char((int)data->where_vehicule);
    if (line == 2)
        return data->player_s->name;
    if (line == 3)
        return int_to_char((int)data->player_s->exp);
    if (line == 4)
        return int_to_char((int)data->player_s->money);
    if (line == 5)
        return int_to_char((int)data->player_s->gun_xp);
    return "Error";
}

char *get_information_player(main_s *data, int line)
{
    if (line >= 1 && line <= 5)
        return sub_get_information_player(data, line);
    if (line == 6)
        return int_to_char((int)data->player_s->pos_p_x);
    if (line == 7)
        return int_to_char((int)data->player_s->pos_p_y);
    if (line == 8)
        return int_to_char((int)data->inv_s.nb_recolted);
    if (line == 9)
        return int_to_char((int)data->player_s->gun_xp);
    if (line == 10)
        return int_to_char((int)data->inv_s.gun->find);
    return "Error";
}

char *get_information_pickup(main_s *data, int line)
{
    if (line == 11)
        return int_to_char((int)data->pickup_s.pos_x);
    if (line == 12)
        return int_to_char((int)data->pickup_s.pos_y);
    else
        return int_to_char((int)data->pickup_s.sens);
}

char *get_information_tractor(main_s *data, int line)
{
    if (line == 17)
        return int_to_char((int)data->tractor_s->pos_x);
    if (line == 18)
        return int_to_char((int)data->tractor_s->pos_y);
    else
        return int_to_char((int)data->tractor_s->sens);
}

char *get_information_save(main_s *data, int line)
{
    if (line >= 0 && line <= 10)
        return get_information_player(data, line);
    if (line >= 11 && line <= 13)
        return get_information_pickup(data, line);
    if (line >= 14 && line <= 16)
        return get_information_harvest(data, line);
    else
        return get_information_tractor(data, line);
    return "ERROR_LOAD";
}

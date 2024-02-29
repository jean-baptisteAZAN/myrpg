/*
** EPITECH PROJECT, 2023
** sub
** File description:
** sub
*/

#include "my.h"
#include "my_rpg.h"

int suite_verif_info_where_name(char *str)
{
    for (int n = 0; str[n] != '\0'; n++) {
        if (str[n] < 'a' || str[n] > 'z')
            return -1;
    }
    return 0;
}

int verif_position_load(main_s *data)
{
    if (collision_pickup(data, (data->pickup_s.pos_x),
        (data->pickup_s.pos_y)) == 1)
            return -1;
    if (collision_tractor(data, (data->tractor_s->pos_x),
        (data->tractor_s->pos_y)) == 1)
            return -1;
    if (collision_harvest(data, (data->harvest_s->pos_x),
        (data->harvest_s->pos_y)) == 1)
            return -1;
    return 0;
}

int load_the_game(main_s *data)
{
    if (verif_file_is_good() == -1)
        return -1;
    if (load_map(data) == -1)
        return -1;
    if (load_info(data) == -1)
        return -1;
    if (verif_position_load(data) == -1)
        return -1;
    data->ress_s.load = 1;
    return 0;
}

int sub_verif_info_in_load(char *str, int n)
{
    if (n == 8) {
        if (my_strlen(str) == 1 && (str[0] != '1' || str[0] != '2' ||
            str[0] != '3'))
            return 0;
        else
            return -1;
    }
    if (n == 9) {
        if (my_strlen(str) == 1 && (str[0] != '0' || str[0] != '1'))
            return 0;
        else
            return -1;
    }
    return 0;
}

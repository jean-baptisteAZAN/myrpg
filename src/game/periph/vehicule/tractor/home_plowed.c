/*
** EPITECH PROJECT, 2023
** home_plowed.c
** File description:
** function : home_plowed
*/


#include "my.h"
#include "my_rpg.h"

void plowed_tractor(main_s *data, int x, int y)
{
    data->ress_s.color_tmp = sfImage_getPixel(data->ress_s.img_map_01, x, y);
    if (data->ress_s.color_tmp.r == 208 && data->ress_s.color_tmp.g == 167 &&
        data->ress_s.color_tmp.b == 2) {
        sfImage_setPixel(data->ress_s.img_map_01, x, y, data->ress_s.harvest_f);
        data->tuto->recolt = true;
        if (data->inv_s.nb_recolted >= 50000) {
            data->inv_s.recolted_is_max = 1;
            sfClock_restart(data->inv_s.time_recolted_max);
        } else {
            data->inv_s.nb_recolted++;
        }
    }
}

void home_plowed(main_s *data)
{
    if (data->tractor_s->sens == 0)
        plowed_0(data);
    if (data->tractor_s->sens == 2)
        plowed_2(data);
    if (data->tractor_s->sens == 4)
        plowed_4(data);
    if (data->tractor_s->sens == 6)
        plowed_6(data);
}

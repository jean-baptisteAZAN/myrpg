/*
** EPITECH PROJECT, 2023
** home_plowed.c
** File description:
** function : home_plowed
*/


#include "my.h"
#include "my_rpg.h"

void harved_harvest(main_s *data, int x, int y)
{
    data->ress_s.color_tmp = sfImage_getPixel(data->ress_s.img_map_01, x, y);
    if ((data->ress_s.color_tmp.r == 139 && data->ress_s.color_tmp.g == 69 &&
        data->ress_s.color_tmp.b == 19) ||
        (data->ress_s.color_tmp.r == 11 && data->ress_s.color_tmp.g == 182 &&
        data->ress_s.color_tmp.b == 4) ||
        (data->ress_s.color_tmp.r == 208 && data->ress_s.color_tmp.g == 167 &&
        data->ress_s.color_tmp.b == 2) ||
        (data->ress_s.color_tmp.r == 121 && data->ress_s.color_tmp.g == 85 &&
        data->ress_s.color_tmp.b == 72)) {
        sfImage_setPixel(data->ress_s.img_map_01, x, y, data->ress_s.plowed);
        data->tuto->plant = true;
    }
}

void home_harved(main_s *data)
{
    if (data->harvest_s->sens == 0)
        harved_0(data);
    if (data->harvest_s->sens == 2)
        harved_2(data);
    if (data->harvest_s->sens == 4)
        harved_4(data);
    if (data->harvest_s->sens == 6)
        harved_6(data);
}

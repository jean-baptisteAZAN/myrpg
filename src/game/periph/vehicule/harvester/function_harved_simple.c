/*
** EPITECH PROJECT, 2023
** function_harved_simple.c
** File description:
** function : *
*/

#include "my.h"
#include "my_rpg.h"

void harved_0(main_s *data)
{
    if (data->harvest_s->speed < 0)
        return;
    int x_start = data->harvest_s->pos_x - 12;
    int x_end = data->harvest_s->pos_x + 12;
    int y_start_default = data->harvest_s->pos_y + 18;
    int y_start = data->harvest_s->pos_y + 18;
    int y_end = data->harvest_s->pos_y + 21;
    for (; x_start <= x_end; x_start++) {
        for (y_start = y_start_default; y_start <= y_end; y_start++)
            harved_harvest(data, x_start, y_start);
    }
    sfTexture_destroy(data->ress_s.textu_map_01);
    data->ress_s.textu_map_01 =
        sfTexture_createFromImage(data->ress_s.img_map_01, NULL);
    sfSprite_setTexture(data->ress_s.map_01,
        data->ress_s.textu_map_01, sfFalse);
}

void harved_2(main_s *data)
{
    if (data->harvest_s->speed < 0)
        return;
    int x_start = data->harvest_s->pos_x - 22;
    int x_end = data->harvest_s->pos_x - 19;
    int y_start_default = data->harvest_s->pos_y - 9;
    int y_start = data->harvest_s->pos_y - 9;
    int y_end = data->harvest_s->pos_y + 15;
    for (; x_start <= x_end; x_start++) {
        for (y_start = y_start_default; y_start <= y_end; y_start++)
            harved_harvest(data, x_start, y_start);
    }
    sfTexture_destroy(data->ress_s.textu_map_01);
    data->ress_s.textu_map_01 =
        sfTexture_createFromImage(data->ress_s.img_map_01, NULL);
    sfSprite_setTexture(data->ress_s.map_01,
        data->ress_s.textu_map_01, sfFalse);
}

void harved_4(main_s *data)
{
    if (data->harvest_s->speed < 0)
        return;
    int x_start = data->harvest_s->pos_x - 12;
    int x_end = data->harvest_s->pos_x + 12;
    int y_start_default = data->harvest_s->pos_y - 20;
    int y_start = data->harvest_s->pos_y - 20;
    int y_end = data->harvest_s->pos_y - 17;
    for (; x_start <= x_end; x_start++) {
        for (y_start = y_start_default; y_start <= y_end; y_start++)
            harved_harvest(data, x_start, y_start);
    }
    sfTexture_destroy(data->ress_s.textu_map_01);
    data->ress_s.textu_map_01 =
        sfTexture_createFromImage(data->ress_s.img_map_01, NULL);
    sfSprite_setTexture(data->ress_s.map_01,
        data->ress_s.textu_map_01, sfFalse);
}

void harved_6(main_s *data)
{
    if (data->harvest_s->speed < 0)
        return;
    int x_start = data->harvest_s->pos_x + 17;
    int x_end = data->harvest_s->pos_x + 20;
    int y_start_default = data->harvest_s->pos_y - 9;
    int y_start = data->harvest_s->pos_y - 9;
    int y_end = data->harvest_s->pos_y + 15;
    for (; x_start <= x_end; x_start++) {
        for (y_start = y_start_default; y_start <= y_end; y_start++)
            harved_harvest(data, x_start, y_start);
    }
    sfTexture_destroy(data->ress_s.textu_map_01);
    data->ress_s.textu_map_01 =
        sfTexture_createFromImage(data->ress_s.img_map_01, NULL);
    sfSprite_setTexture(data->ress_s.map_01,
        data->ress_s.textu_map_01, sfFalse);
}

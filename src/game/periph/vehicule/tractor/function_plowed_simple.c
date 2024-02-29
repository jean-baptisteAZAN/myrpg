/*
** EPITECH PROJECT, 2023
** function_plowed_simple.c
** File description:
** function : *
*/

#include "my.h"
#include "my_rpg.h"

void plowed_0(main_s *data)
{
    if (data->tractor_s->speed < 0)
        return;
    int x_start = data->tractor_s->pos_x - 12;
    int x_end = data->tractor_s->pos_x + 12;
    int y_start_default = data->tractor_s->pos_y - 23;
    int y_start = data->tractor_s->pos_y - 23;
    int y_end = data->tractor_s->pos_y - 20;
    for (; x_start <= x_end; x_start++) {
        for (y_start = y_start_default; y_start <= y_end; y_start++)
            plowed_tractor(data, x_start, y_start);
    }
    sfTexture_destroy(data->ress_s.textu_map_01);
    data->ress_s.textu_map_01 =
        sfTexture_createFromImage(data->ress_s.img_map_01, NULL);
    sfSprite_setTexture(data->ress_s.map_01,
        data->ress_s.textu_map_01, sfFalse);
}

void plowed_2(main_s *data)
{
    if (data->tractor_s->speed < 0)
        return;
    int x_start = data->tractor_s->pos_x + 18;
    int x_end = data->tractor_s->pos_x + 21;
    int y_start_default = data->tractor_s->pos_y - 6;
    int y_start = data->tractor_s->pos_y - 6;
    int y_end = data->tractor_s->pos_y + 18;
    for (; x_start <= x_end; x_start++) {
        for (y_start = y_start_default; y_start <= y_end; y_start++)
            plowed_tractor(data, x_start, y_start);
    }
    sfTexture_destroy(data->ress_s.textu_map_01);
    data->ress_s.textu_map_01 =
        sfTexture_createFromImage(data->ress_s.img_map_01, NULL);
    sfSprite_setTexture(data->ress_s.map_01,
        data->ress_s.textu_map_01, sfFalse);
}

void plowed_4(main_s *data)
{
    if (data->tractor_s->speed < 0)
        return;
    int x_start = data->tractor_s->pos_x - 12;
    int x_end = data->tractor_s->pos_x + 12;
    int y_start_default = data->tractor_s->pos_y + 18;
    int y_start = data->tractor_s->pos_y + 18;
    int y_end = data->tractor_s->pos_y + 21;
    for (; x_start <= x_end; x_start++) {
        for (y_start = y_start_default; y_start <= y_end; y_start++)
            plowed_tractor(data, x_start, y_start);
    }
    sfTexture_destroy(data->ress_s.textu_map_01);
    data->ress_s.textu_map_01 =
        sfTexture_createFromImage(data->ress_s.img_map_01, NULL);
    sfSprite_setTexture(data->ress_s.map_01,
        data->ress_s.textu_map_01, sfFalse);
}

void plowed_6(main_s *data)
{
    if (data->tractor_s->speed < 0)
        return;
    int x_start = data->tractor_s->pos_x - 22;
    int x_end = data->tractor_s->pos_x - 19;
    int y_start_default = data->tractor_s->pos_y - 9;
    int y_start = data->tractor_s->pos_y - 9;
    int y_end = data->tractor_s->pos_y + 15;
    for (; x_start <= x_end; x_start++) {
        for (y_start = y_start_default; y_start <= y_end; y_start++)
            plowed_tractor(data, x_start, y_start);
    }
    sfTexture_destroy(data->ress_s.textu_map_01);
    data->ress_s.textu_map_01 =
        sfTexture_createFromImage(data->ress_s.img_map_01, NULL);
    sfSprite_setTexture(data->ress_s.map_01,
        data->ress_s.textu_map_01, sfFalse);
}

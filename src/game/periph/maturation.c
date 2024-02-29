/*
** EPITECH PROJECT, 2023
** maturation.c
** File description:
** function : *
*/

#include "my.h"
#include "my_rpg.h"

void pass_maturation(main_s *data, int x, int y)
{
    data->ress_s.color_tmp = sfImage_getPixel(data->ress_s.img_map_01, x, y);
    if (data->ress_s.color_tmp.r == 59 && data->ress_s.color_tmp.g == 94 &&
        data->ress_s.color_tmp.b == 6) {
        sfImage_setPixel(data->ress_s.img_map_01, x, y, data->ress_s.harvest);
        data->tuto->ready = true;
    }
    if (data->ress_s.color_tmp.r == 97 && data->ress_s.color_tmp.g == 84 &&
        data->ress_s.color_tmp.b == 2)
        sfImage_setPixel(data->ress_s.img_map_01, x, y, data->ress_s.plowed_p);
}

void muration(main_s *data)
{
    if ((sfClock_getElapsedTime(data->ress_s.saison).microseconds
        < data->ress_s.time_saison))
        return;
    int y = 0;
    for (int x = 0; x < 1920; x++) {
        for (y = 0; y < 1080; y++) {
            pass_maturation(data, x, y);
        }
    }
    sfTexture_destroy(data->ress_s.textu_map_01);
    data->ress_s.textu_map_01 =
        sfTexture_createFromImage(data->ress_s.img_map_01, NULL);
    sfSprite_setTexture(data->ress_s.map_01,
        data->ress_s.textu_map_01, sfFalse);
    sfClock_restart(data->ress_s.saison);
}

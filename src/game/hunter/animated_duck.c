/*
** EPITECH PROJECT, 2023
** my_farmer
** File description:
** function : animate duck
*/

#include "my.h"
#include "my_rpg.h"

void sub_anime_duck(main_s *data)
{
    if (data->hun->frame_duck == 2) {
        sfIntRect textureRect = {111, 29, 109, 65};
        sfSprite_setTextureRect(data->hun->bird, textureRect);
        sfSprite_setOrigin(data->hun->bird, (sfVector2f){55, 47});
    }
    if (data->hun->frame_duck == 3) {
        sfIntRect textureRect = {221, 29, 110, 78};
        sfSprite_setTextureRect(data->hun->bird, textureRect);
        sfSprite_setOrigin(data->hun->bird, (sfVector2f){55, 47});
    }
}

void anime_duck(main_s *data)
{
    if (sfClock_getElapsedTime(data->hun->animate_clock)
    .microseconds > 200000) {
        data->hun->frame_duck++;
        sfClock_restart(data->hun->animate_clock);
    }
    if (data->hun->frame_duck == 4)
        data->hun->frame_duck = 1;
    if (data->hun->frame_duck == 1) {
        sfIntRect textureRect = {0, 1, 110, 93};
        sfSprite_setTextureRect(data->hun->bird, textureRect);
        sfSprite_setOrigin(data->hun->bird, (sfVector2f){55, 47});
    }
    sub_anime_duck(data);
}

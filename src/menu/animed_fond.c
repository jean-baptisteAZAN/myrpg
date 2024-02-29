/*
** EPITECH PROJECT, 2023
** animed_fond.c
** File description:
** function : animed_fond
*/

#include "my.h"
#include "my_rpg.h"

void init_animed_fond(main_s *data)
{
    data->menu->fond_animed = init_fond("./ressources/animed_fond.png");
    sfIntRect textureRect = {0, 0, 700, 500};
    sfSprite_setTextureRect(data->menu->fond_animed, textureRect);
    sfSprite_setPosition(data->menu->fond_animed, (sfVector2f){0, 0});
    sfSprite_setScale(data->menu->fond_animed, (sfVector2f){2.8, 2.8});
    data->menu->pos_fond_animed = 0;
    data->menu->time_fond_animed = sfClock_create();
}

void sub_pass_frame_animed_fond(main_s *data)
{
    if (data->menu->pos_fond_animed == 2) {
        sfIntRect textureRect = {1400, 0, 700, 500};
        sfSprite_setTextureRect(data->menu->fond_animed, textureRect);
    }
    if (data->menu->pos_fond_animed == 3) {
        sfIntRect textureRect = {2100, 0, 700, 500};
        sfSprite_setTextureRect(data->menu->fond_animed, textureRect);
    }
    if (data->menu->pos_fond_animed == 4) {
        sfIntRect textureRect = {2800, 0, 700, 500};
        sfSprite_setTextureRect(data->menu->fond_animed, textureRect);
    }
}

void pass_frame_animed_fond(main_s *data)
{
    data->menu->pos_fond_animed++;
    if (data->menu->pos_fond_animed == 5)
        data->menu->pos_fond_animed = 0;
    if (data->menu->pos_fond_animed == 0) {
        sfIntRect textureRect = {0, 0, 700, 500};
        sfSprite_setTextureRect(data->menu->fond_animed, textureRect);
    }
    if (data->menu->pos_fond_animed == 1) {
        sfIntRect textureRect = {700, 0, 700, 500};
        sfSprite_setTextureRect(data->menu->fond_animed, textureRect);
    }
    sub_pass_frame_animed_fond(data);
}

void draw_frame_animed_fond(main_s *data)
{
    sfRenderWindow_drawSprite(data->window->game_window,
        data->menu->fond_animed, NULL);
    if (sfClock_getElapsedTime(data->menu->time_fond_animed).microseconds
        > 200000) {
        pass_frame_animed_fond(data);
        sfClock_restart(data->menu->time_fond_animed);
    }
}

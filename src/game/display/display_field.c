/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** function : display_all
*/

#include "my.h"
#include "my_rpg.h"

void display_field(main_s *data)
{
    for (int i = 0; i < data->ress_s.nb_fields; i++) {
        sfRenderWindow_drawSprite(data->window->game_window,
        data->ress_s.noise[i], NULL);
    }
}

void display_max_recolted(main_s *data)
{
    if (data->inv_s.verif == true)
        return;
    if (data->inv_s.recolted_is_max == 1 &&
        sfClock_getElapsedTime(data->inv_s.time_recolted_max).microseconds <
            500000) {
        sfVector2f pos = sfView_getCenter(data->ress_s.view_p);
        sfText_setPosition(data->inv_s.recolted_max,
            (sfVector2f){pos.x - 141, pos.y - 68});
        sfRenderWindow_drawText(data->window->game_window,
            data->inv_s.recolted_max, NULL);
    }
}

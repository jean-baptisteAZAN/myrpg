/*
** EPITECH PROJECT, 2023
** my_farmer
** File description:
** display_end_game
*/

#include "my.h"
#include "my_rpg.h"

void happy_end(main_s *data)
{
    sfRenderWindow_drawSprite(data->window->game_window,
    data->cinematic->sp_dialogue, NULL);
    sfRenderWindow_drawText(data->window->game_window,
    data->cinematic->dialo, NULL);
    sfRenderWindow_drawSprite(data->window->game_window,
    data->cinematic->button_next, NULL);
}

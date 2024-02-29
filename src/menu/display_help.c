/*
** EPITECH PROJECT, 2023
** help
** File description:
** help
*/

#include "my.h"
#include "my_rpg.h"

void display_help(main_s *data)
{
    sfRenderWindow_drawSprite(data->window->game_window,
    data->menu->help->sprite_back, NULL);
    sfRenderWindow_drawSprite(data->window->game_window,
    data->menu->help->back_button, NULL);
    sfRenderWindow_drawText(data->window->game_window,
    data->menu->help->txt_back, NULL);
}

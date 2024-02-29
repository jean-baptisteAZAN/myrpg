/*
** EPITECH PROJECT, 2023
** hanl
** File description:
** dhna
*/

#include "my.h"
#include "my_rpg.h"

void update_mouse_position(main_s *data)
{
    data->mouse_pos = (sfVector2f) {sfMouse_getPositionRenderWindow(
    data->window->game_window).x,
    sfMouse_getPositionRenderWindow(data->window->game_window).y};
    sfFloatRect zone_play = sfSprite_getGlobalBounds(data->menu->but->settings);
    if (sfFloatRect_contains(&zone_play, data->mouse_pos.x,
    data->mouse_pos.y))
        data->menu->but->sett_state = 1;
}

void handle_pressed(main_s *data)
{
    if (data->menu->but->sett_state == 1)
        data->menu->but->sett_state = 2;
}

void handle_released(main_s *data)
{
    if (data->window->event.type == sfEvtKeyReleased &&
    data->window->event.key.code == sfKeyEscape && data->where == 3)
        data->where = 6;
    else if (data->window->event.type == sfEvtKeyReleased &&
    data->window->event.key.code == sfKeyEscape && data->where == 6)
        data->where = 3;
}

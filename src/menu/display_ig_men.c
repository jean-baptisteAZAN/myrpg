/*
** EPITECH PROJECT, 2023
** ig
** File description:
** ig
*/

#include "my.h"
#include "my_rpg.h"

void sub_display_menu_ig(main_s *data)
{
    sfRenderWindow_drawText(data->window->game_window,
    data->menu_ig->txt_load, NULL);
    sfRenderWindow_drawSprite(data->window->game_window,
    data->menu_ig->button_settings, NULL);
    sfRenderWindow_drawText(data->window->game_window,
    data->menu_ig->txt_settings, NULL);
    sfRenderWindow_drawSprite(data->window->game_window,
    data->menu_ig->money_slot, NULL);
    sfRenderWindow_drawSprite(data->window->game_window,
    data->menu_ig->piece_spr, NULL);
    sfRenderWindow_drawText(data->window->game_window,
    data->menu_ig->money_compt, NULL);
    sfRenderWindow_drawSprite(data->window->game_window,
    data->menu_ig->exit_but, NULL);
    sfRenderWindow_drawText(data->window->game_window,
    data->menu->but->quit, NULL);
}

void display_ig_menu(main_s *data)
{
    data->verif_ig = 1;
    if (data->window->resolution_state == 2)
        sfRenderWindow_setView(data->window->game_window,
        data->ress_s.view_resize);
    else
        sfRenderWindow_setView(data->window->game_window,
        data->ress_s.view_map);
    sfRenderWindow_drawSprite(data->window->game_window,
    data->menu_ig->ig_menu_spr, NULL);
    sfRenderWindow_drawSprite(data->window->game_window,
    data->menu_ig->button_sav, NULL);
    sfRenderWindow_drawText(data->window->game_window,
    data->menu_ig->txt_sav, NULL);
    sfRenderWindow_drawSprite(data->window->game_window,
    data->menu_ig->button_load, NULL);
    sub_display_menu_ig(data);
}

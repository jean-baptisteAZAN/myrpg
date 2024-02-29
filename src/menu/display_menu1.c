/*
** EPITECH PROJECT, 2023
** menu
** File description:
** menu
*/

#include "my.h"
#include "my_rpg.h"

void display_sounds_sett(main_s *data)
{
    sfRenderWindow_drawRectangleShape(data->window->game_window,
    data->menu->settings->sound_bar, NULL);
    sfRenderWindow_drawSprite(data->window->game_window,
    data->menu->settings->plus_button, NULL);
    sfRenderWindow_drawSprite(data->window->game_window,
    data->menu->settings->minus_button, NULL);
    sfRenderWindow_drawText(data->window->game_window,
    data->menu->settings->volume_nb, NULL);
}

void display_frame_sett(main_s *data)
{
    sfRenderWindow_drawRectangleShape(data->window->game_window,
    data->menu->settings->framerate_bar, NULL);
    sfRenderWindow_drawSprite(data->window->game_window,
    data->menu->settings->plus_button_frame, NULL);
    sfRenderWindow_drawSprite(data->window->game_window,
    data->menu->settings->minus_button_frame, NULL);
    sfRenderWindow_drawText(data->window->game_window,
    data->menu->settings->nb_fps_txt, NULL);
}

void display_settings(main_s *data)
{
    sfRenderWindow_drawSprite(data->window->game_window,
    data->menu->sprite_menu, NULL);
    display_sounds_sett(data);
    display_frame_sett(data);
    sfRenderWindow_drawSprite(data->window->game_window,
    data->menu->settings->resume_button, NULL);
    sfRenderWindow_drawRectangleShape(data->window->game_window,
    data->menu->settings->command_but, NULL);
    sfRenderWindow_drawRectangleShape(data->window->game_window,
    data->menu->settings->rect_res, NULL);
    sfRenderWindow_drawSprite(data->window->game_window,
    data->menu->settings->min_res, NULL);
    sfRenderWindow_drawText(data->window->game_window,
    data->menu->settings->res_txt, NULL);
}

void display_buttons_status(main_s *data)
{
    sfRenderWindow_drawSprite(data->window->game_window, data->menu->but->play,
    NULL);
    sfRenderWindow_drawText(data->window->game_window,
    data->menu->but->play_txt, NULL);
    sfRenderWindow_drawSprite(data->window->game_window,
    data->menu->but->resume, NULL);
    sfRenderWindow_drawText(data->window->game_window,
    data->menu->but->resume_txt, NULL);
    sfRenderWindow_drawSprite(data->window->game_window,
    data->menu->but->settings, NULL);
    sfRenderWindow_drawText(data->window->game_window,
    data->menu->but->settings_txt, NULL);
    sfRenderWindow_drawSprite(data->window->game_window,
    data->menu->but->exit, NULL);
    sfRenderWindow_drawText(data->window->game_window,
    data->menu->but->quit, NULL);
    sfRenderWindow_drawSprite(data->window->game_window,
    data->menu->but->button_help, NULL);
    sfRenderWindow_drawText(data->window->game_window,
    data->menu->but->help_txt, NULL);
}

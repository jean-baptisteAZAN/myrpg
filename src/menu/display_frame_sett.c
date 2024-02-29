/*
** EPITECH PROJECT, 2023
** displ
** File description:
** displa
*/

#include "my.h"
#include "my_rpg.h"


void min_button_fps(main_s *data)
{
    sfFloatRect min_fps =
    sfSprite_getGlobalBounds(data->menu->settings->minus_button_frame);
    if (sfFloatRect_contains(&min_fps,
    data->mouse_pos.x, data->mouse_pos.y)) {
        sfSprite_setTexture(data->menu->settings->minus_button_frame,
        data->menu->settings->min_select, sfFalse);
        if (data->window->event.type == sfEvtMouseButtonReleased &&
            data->window->event.mouseButton.button == sfMouseLeft &&
            data->menu->settings->nb_fps > 30) {
            data->menu->settings->nb_fps -= 10.0f;
            sfRenderWindow_setFramerateLimit(data->window->game_window,
            data->menu->settings->nb_fps);
            sfText_setString(data->menu->settings->nb_fps_txt,
            my_put_nbr(data->menu->settings->nb_fps));
        }
    } else
        sfSprite_setTexture(data->menu->settings->minus_button_frame,
        sfTexture_createFromFile("ressources/bouton_moins.png", NULL), sfFalse);
}

void plus_button_frame(main_s *data)
{
    sfFloatRect max_pfps =
    sfSprite_getGlobalBounds(data->menu->settings->plus_button_frame);
    if (sfFloatRect_contains(&max_pfps,
    data->mouse_pos.x, data->mouse_pos.y)) {
        sfSprite_setTexture(data->menu->settings->plus_button_frame,
        data->menu->settings->plus_select, sfFalse);
        if (data->window->event.type == sfEvtMouseButtonReleased &&
            data->window->event.mouseButton.button == sfMouseLeft &&
            data->menu->settings->nb_fps < 70) {
            data->menu->settings->nb_fps += 10.0f;
            sfRenderWindow_setFramerateLimit(data->window->game_window,
            data->menu->settings->nb_fps);
            sfText_setString(data->menu->settings->nb_fps_txt,
            my_put_nbr(data->menu->settings->nb_fps));
        }
    } else
        sfSprite_setTexture(data->menu->settings->plus_button_frame,
        sfTexture_createFromFile("ressources/bouton_plus.png", NULL), sfFalse);
}

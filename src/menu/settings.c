/*
** EPITECH PROJECT, 2023
** sett
** File description:
** sett
*/

#include "my.h"
#include "my_rpg.h"

void switch_reso(main_s *data)
{
    switch (data->window->resolution_state) {
    case 0:
        sfText_setString(data->menu->settings->res_txt, "Fullscreen");
        data->window->game_window =
        sfRenderWindow_create(sfVideoMode_getDesktopMode(),
        "My_Farmer", sfFullscreen | sfResize | sfClose, NULL); break;
    case 1:
        sfText_setString(data->menu->settings->res_txt, "Windowed");
        data->window->game_window =
        sfRenderWindow_create(sfVideoMode_getDesktopMode(),
        "My_Farmer", sfClose, NULL); break;
    case 2:
        sfText_setString(data->menu->settings->res_txt, "1920 x 1000");
        data->window->game_window =
        sfRenderWindow_create((sfVideoMode){1920, 1000, 32},
        "My_Farmer", sfClose, NULL); break;
    default:
        break;
    }
}

void change_display_window(main_s *data)
{
    sfFloatRect zone_right =
        sfSprite_getGlobalBounds(data->menu->settings->min_res);
    if (sfMouse_isButtonPressed(sfMouseLeft) &&
        sfFloatRect_contains(&zone_right,
        data->mouse_pos.x, data->mouse_pos.y)) {
        data->window->resolution_state =
        (data->window->resolution_state + 1) % 3;
        sfRenderWindow_destroy(data->window->game_window);
        switch_reso(data);
    }
}

void min_button_sound(main_s *data)
{
    sfFloatRect min_sound =
    sfSprite_getGlobalBounds(data->menu->settings->minus_button);
    if (sfFloatRect_contains(&min_sound,
    data->mouse_pos.x, data->mouse_pos.y)) {
        sfSprite_setTexture(data->menu->settings->minus_button,
        data->menu->settings->min_select, sfFalse);
        if (data->window->event.type == sfEvtMouseButtonReleased &&
            data->window->event.mouseButton.button == sfMouseLeft &&
            data->volume > 0) {
            data->volume -= 10.0f;
            sfMusic_setVolume(data->music, data->volume);
            sfText_setString(data->menu->settings->volume_nb,
            my_put_nbr(data->volume));
        }
    } else
        sfSprite_setTexture(data->menu->settings->minus_button,
        sfTexture_createFromFile("ressources/bouton_moins.png", NULL), sfFalse);
}

void is_in_settings(main_s *data)
{
    sfFloatRect resume =
    sfSprite_getGlobalBounds(data->menu->settings->resume_button);
    sfSprite_setTexture(data->menu->sprite_menu,
    data->menu->settings_texture, sfFalse);
    plus_button_sound(data);
    min_button_sound(data);
    min_button_fps(data);
    plus_button_frame(data);
    button_command(data);
    if (sfFloatRect_contains(&resume, data->mouse_pos.x, data->mouse_pos.y)
    && data->window->event.type == sfEvtMouseButtonReleased &&
    data->window->event.mouseButton.button == sfMouseLeft
    && data->verif_ig == 0)
        data->where = 0;
    else if (sfFloatRect_contains(&resume, data->mouse_pos.x, data->mouse_pos.y)
    && data->window->event.type == sfEvtMouseButtonReleased &&
    data->window->event.mouseButton.button == sfMouseLeft
    && data->verif_ig == 1)
        data->where = 6;
    change_display_window(data);
}

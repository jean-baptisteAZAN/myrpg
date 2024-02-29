/*
** EPITECH PROJECT, 2023
** load
** File description:
** kiad
*/

#include "my.h"
#include "my_rpg.h"

void exit_but_ig(main_s *data)
{
    sfVector2i mouse_pos =
    sfMouse_getPositionRenderWindow(data->window->game_window);
    sfFloatRect exit_zone = sfSprite_getGlobalBounds(data->menu_ig->exit_but);
    if (data->where == 6 &&
    sfFloatRect_contains(&exit_zone, mouse_pos.x, mouse_pos.y) == true) {
        sfSprite_setTexture(data->menu_ig->exit_but,
        data->menu->but->texture_hover, sfTrue);
        if (sfMouse_isButtonPressed(sfMouseLeft))
            sfSprite_setTexture(data->menu_ig->exit_but,
            data->menu->but->texture_hover, sfFalse);
        if (data->window->event.type == sfEvtMouseButtonReleased &&
            data->window->event.mouseButton.button == sfMouseLeft){
                sfRenderWindow_close(data->window->game_window);
            }
    } else
        sfSprite_setTexture(data->menu_ig->exit_but,
        data->menu->but->texture_play, sfFalse);
}

void save_game_but(main_s *data)
{
    int a = 0;
    sfFloatRect save_game = sfSprite_getGlobalBounds(data->menu_ig->button_sav);
    if (data->where == 6 && sfFloatRect_contains(&save_game, data->mouse_pos.x,
    data->mouse_pos.y)) {
        sfSprite_setTexture(data->menu_ig->button_sav,
        data->menu->but->texture_hover, sfFalse);
        if (sfMouse_isButtonPressed(sfMouseLeft))
            a = save_the_game(data);
        if (a == 1)
            data->verif_loading = 1;
    } else
        sfSprite_setTexture(data->menu_ig->button_sav,
        data->menu->but->texture_play, sfFalse);
    if (data->verif_loading == 1 && (data->where == 6 || data->where == 0)) {
        if (data->check_load == 1 &&
        sfClock_getElapsedTime(data->clock_error_load).microseconds < 500000)
            sfRenderWindow_drawText(data->window->game_window,
                data->error_message, NULL);
    }
}

void load_game_but(main_s *data)
{
    int a = 0;
    sfFloatRect load = sfSprite_getGlobalBounds(data->menu_ig->button_load);
    if (data->where == 6 && sfFloatRect_contains(&load, data->mouse_pos.x,
    data->mouse_pos.y)) {
        sfSprite_setTexture(data->menu_ig->button_load,
        data->menu->but->texture_hover, sfFalse);
        if (sfMouse_isButtonPressed(sfMouseLeft))
            a = load_the_game(data);
        if (a == -1) {
            sfClock_restart(data->clock_error_load);
            data->check_load = 1; data->verif_loading = 1;
        }
    } else
        sfSprite_setTexture(data->menu_ig->button_load,
        data->menu->but->texture_play, sfFalse);
    if (data->verif_loading == 1 && (data->where == 6 || data->where == 0) &&
        data->check_load == 1 &&
        sfClock_getElapsedTime(data->clock_error_load).microseconds < 500000)
        sfRenderWindow_drawText(data->window->game_window,
        data->error_message, NULL);
}

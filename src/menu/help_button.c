/*
** EPITECH PROJECT, 2023
** B-MUL-200-LIL-2-1-myrpg-romain.collignon
** File description:
** help
*/

#include "my.h"
#include "my_rpg.h"

void is_in_help_one(main_s *data)
{
    sfFloatRect zone_back =
    sfSprite_getGlobalBounds(data->menu->help->back_button);
    if (sfFloatRect_contains(&zone_back,
    data->mouse_pos.x, data->mouse_pos.y)) {
        sfSprite_setTexture(data->menu->help->back_button,
        data->menu->but->texture_pressed, sfFalse);
        if (data->window->event.type == sfEvtMouseButtonReleased &&
            data->window->event.mouseButton.button == sfMouseLeft )
                data->where = 0;
    } else
        sfSprite_setTexture(data->menu->help->back_button,
        data->menu->but->texture_play, sfFalse);
}

void help_button(main_s *data)
{
    sfFloatRect zone_help =
    sfSprite_getGlobalBounds(data->menu->but->button_help);
    if (sfFloatRect_contains(&zone_help,
    data->mouse_pos.x, data->mouse_pos.y)) {
        sfSprite_setTexture(data->menu->but->button_help,
        data->menu->but->texture_pressed, sfFalse);
        if (sfMouse_isButtonPressed(sfMouseLeft))
            sfSprite_setTexture(data->menu->but->button_help,
            data->menu->but->texture_hover, sfFalse);
        if (data->window->event.type == sfEvtMouseButtonReleased &&
            data->window->event.mouseButton.button == sfMouseLeft )
                data->where = 4;
    } else
        sfSprite_setTexture(data->menu->but->button_help,
            data->menu->but->texture_play, sfFalse);
}

void sub_resume_but(main_s *data)
{
    int a = 0;
    a = load_the_game(data);
    if (a == -1) {
        data->verif_loading = 1;
        sfClock_restart(data->clock_error_load);
        data->check_load = 1;
    } else {
        data->where = 3;
        data->loaded = 1;
    }
}

void resume_but_rect(main_s *data)
{
    sfFloatRect zone_resume = sfSprite_getGlobalBounds(data->menu->but->resume);
    if (sfFloatRect_contains(&zone_resume,
    data->mouse_pos.x, data->mouse_pos.y)) {
        sfSprite_setTexture(data->menu->but->resume,
        data->menu->but->texture_pressed, sfFalse);
        if (sfMouse_isButtonPressed(sfMouseLeft))
            sfSprite_setTexture(data->menu->but->resume,
            data->menu->but->texture_hover, sfFalse);
        if (data->window->event.type == sfEvtMouseButtonReleased &&
            data->window->event.mouseButton.button == sfMouseLeft)
                sub_resume_but(data);
    } else
        sfSprite_setTexture(data->menu->but->resume,
        data->menu->but->texture_play, sfFalse);
    if (data->verif_loading == 1 && (data->where == 6 || data->where == 0) &&
        data->check_load == 1 &&
        sfClock_getElapsedTime(data->clock_error_load).microseconds < 500000)
        sfRenderWindow_drawText(data->window->game_window,
            data->error_message, NULL);
}

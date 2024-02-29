/*
** EPITECH PROJECT, 2023
** B-MUL-200-LIL-2-1-myrpg-romain.collignon
** File description:
** come
*/

#include "my.h"
#include "my_rpg.h"

void command_menu(main_s *data)
{
    sfRenderWindow_drawSprite(data->window->game_window,
    data->menu->sprite_cmd, NULL);
    sfRenderWindow_drawSprite(data->window->game_window,
    data->menu->back_button, NULL);
    sfRenderWindow_drawText(data->window->game_window,
    data->menu->txt_back, NULL);
}

void ig_menu_but(main_s *data)
{
    sfFloatRect zone_play =
    sfSprite_getGlobalBounds(data->menu_ig->button_settings);
    if (data->where == 6 &&
    sfFloatRect_contains(&zone_play, data->mouse_pos.x,
    data->mouse_pos.y)) {
        sfSprite_setTexture(data->menu_ig->button_settings,
        data->menu->but->texture_pressed, sfFalse);
        if (sfMouse_isButtonPressed(sfMouseLeft))
            sfSprite_setTexture(data->menu_ig->button_settings,
            data->menu->but->texture_hover, sfFalse);
        if (sfMouse_isButtonPressed(sfMouseLeft) &&
        sfFloatRect_contains(&zone_play, data->mouse_pos.x, data->mouse_pos.y))
            data->where = 1;
    } else
        sfSprite_setTexture(data->menu_ig->button_settings,
            data->menu->but->texture_play, sfFalse);
    exit_but_ig(data);
    save_game_but(data);
    load_game_but(data);
}

void cmd_but(main_s *data)
{
    sfFloatRect back = sfSprite_getGlobalBounds(data->menu->back_button);
    if (sfFloatRect_contains(&back,
    data->mouse_pos.x, data->mouse_pos.y)) {
        sfSprite_setTexture(data->menu->back_button,
        data->menu->but->texture_pressed, sfFalse);
        if (sfMouse_isButtonPressed(sfMouseLeft))
            sfSprite_setTexture(data->menu->back_button,
            data->menu->but->texture_hover, sfFalse);
        if (data->window->event.type == sfEvtMouseButtonReleased &&
            data->window->event.mouseButton.button == sfMouseLeft)
                data->where = 1;
    } else {
        sfSprite_setTexture(data->menu->back_button,
            data->menu->but->texture_play, sfFalse);
    }
}

/*
** EPITECH PROJECT, 2023
** update
** File description:
** up
*/

#include "my.h"
#include "my_rpg.h"

void button_settings(main_s *data)
{
    sfFloatRect zone_play = sfSprite_getGlobalBounds(data->menu->but->settings);
    if (sfFloatRect_contains(&zone_play, data->mouse_pos.x,
    data->mouse_pos.y)) {
        sfSprite_setTexture(data->menu->but->settings,
        data->menu->but->texture_pressed, sfFalse);
        if (sfMouse_isButtonPressed(sfMouseLeft))
            sfSprite_setTexture(data->menu->but->settings,
            data->menu->but->texture_hover, sfFalse);
        if (sfMouse_isButtonPressed(sfMouseLeft) &&
        sfFloatRect_contains(&zone_play, data->mouse_pos.x, data->mouse_pos.y))
            data->where = 1;
    } else
        sfSprite_setTexture(data->menu->but->settings,
        data->menu->but->texture_play, sfFalse);
    sfSprite_setTexture(data->menu->sprite_menu, data->menu->texture_menu,
    sfFalse);
}

void start_game_button(main_s *data)
{
    sfFloatRect zone_play = sfSprite_getGlobalBounds(data->menu->but->play);
    if (sfFloatRect_contains(&zone_play,
    data->mouse_pos.x, data->mouse_pos.y)) {
        sfSprite_setTexture(data->menu->but->play,
        data->menu->but->texture_pressed, sfFalse);
        if (sfMouse_isButtonPressed(sfMouseLeft))
            sfSprite_setTexture(data->menu->but->play,
            data->menu->but->texture_hover, sfFalse);
        if (data->window->event.type == sfEvtMouseButtonReleased &&
            data->window->event.mouseButton.button == sfMouseLeft )
                data->where = 2;
    } else
        sfSprite_setTexture(data->menu->but->play,
        data->menu->but->texture_play, sfFalse);
}

void is_in_first_menu(main_s *data)
{
    sfFloatRect exit_zone = sfSprite_getLocalBounds(data->menu->but->exit);
    if (sfFloatRect_contains(&exit_zone,
    data->mouse_pos.x, data->mouse_pos.y)) {
        sfSprite_setTexture(data->menu->but->exit,
        data->menu->but->texture_pressed, sfFalse);
        if (sfMouse_isButtonPressed(sfMouseLeft))
            sfSprite_setTexture(data->menu->but->exit,
            data->menu->but->texture_hover, sfFalse);
        if (data->window->event.type == sfEvtMouseButtonReleased &&
            data->window->event.mouseButton.button == sfMouseLeft)
                sfRenderWindow_close(data->window->game_window);
    } else
        sfSprite_setTexture(data->menu->but->exit,
        data->menu->but->texture_play, sfFalse);
    button_settings(data);
    start_game_button(data);
    help_button(data);
    resume_but_rect(data);
}

void check_menu_ig(main_s *data)
{
    if (data->cinematic->display_cine == 1)
        update_dialo(data);
    sfFloatRect zone_gun = sfSprite_getGlobalBounds(data->inv_s.gun->gun);
    if (data->window->event.type == sfEvtKeyReleased &&
    data->window->event.key.code == sfKeyEscape && data->where == 3)
        data->where = 6;
    else if (data->window->event.type == sfEvtKeyReleased &&
    data->window->event.key.code == sfKeyEscape && data->where == 6)
        data->where = 3;
    ig_menu_but(data);
    sfText_setPosition(data->menu->but->quit, (sfVector2f) {1575, 20});
    if (sfFloatRect_contains(&zone_gun, data->mouse_pos.x, data->mouse_pos.y) &&
    data->window->event.type == sfEvtMouseButtonReleased &&
    data->window->event.mouseButton.button == sfMouseLeft)
        data->inv_s.print_desc = !data->inv_s.print_desc;
    check_coin_press_inv(data);
}

void update_window(main_s *data)
{
    void (*ptr[10])(main_s *) = {is_in_first_menu, is_in_settings,
    is_in_start, check_menu_ig, is_in_help_one, is_in_hunter, check_menu_ig,
    cmd_but, update_end};
    data->mouse_pos = (sfVector2f) {sfMouse_getPositionRenderWindow(
    data->window->game_window).x,
    sfMouse_getPositionRenderWindow(data->window->game_window).y};
    if (ptr[data->where] != NULL)
        ptr[data->where](data);
}

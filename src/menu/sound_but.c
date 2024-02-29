/*
** EPITECH PROJECT, 2023
** sound
** File description:
** sound
*/

#include "my.h"
#include "my_rpg.h"

void plus_button_sound(main_s *data)
{
    sfFloatRect plus_sound =
    sfSprite_getGlobalBounds(data->menu->settings->plus_button);
    if (sfFloatRect_contains(&plus_sound,
    data->mouse_pos.x, data->mouse_pos.y)) {
        sfSprite_setTexture(data->menu->settings->plus_button,
        data->menu->settings->plus_select, sfFalse);
        if (data->window->event.type == sfEvtMouseButtonReleased &&
            data->window->event.mouseButton.button == sfMouseLeft &&
            data->volume < 100.0f) {
            data->volume += 10.0f;
            sfMusic_setVolume(data->music, data->volume);
            sfText_setString(data->menu->settings->volume_nb,
            my_put_nbr(data->volume));
        }
    } else
        sfSprite_setTexture(data->menu->settings->plus_button,
        sfTexture_createFromFile("ressources/bouton_plus.png", NULL), sfFalse);
}

void button_command(main_s *data)
{
    sfFloatRect command =
    sfRectangleShape_getGlobalBounds(data->menu->settings->command_but);
    if (sfFloatRect_contains(&command, data->mouse_pos.x, data->mouse_pos.y)) {
        sfRectangleShape_setFillColor(data->menu->settings->command_but,
        sfColor_fromRGBA(98, 106, 144, 127));
        if (data->window->event.type == sfEvtMouseButtonReleased &&
            data->window->event.mouseButton.button == sfMouseLeft)
                data->where = 7;
    } else
        sfRectangleShape_setFillColor(data->menu->settings->command_but,
        sfColor_fromRGBA(255, 255, 255, 128));
}

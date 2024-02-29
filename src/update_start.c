/*
** EPITECH PROJECT, 2023
** up
** File description:
** ip
*/

#include "my.h"
#include "my_rpg.h"

bool isan(char c)
{
    if ((c >= 'a' && c <= 'z') || c == ' ')
        return (true);
    return (false);
}

void get_name(main_s *data)
{
    static char str[1024] = "quenting";
    static int i = 8;
    static char c;
    int a = 0;
    data->player_s->name = my_strdup(str);
    if (data->window->event.type == sfEvtTextEntered)
        c = data->window->event.key.code;
    if (data->window->event.type == sfEvtKeyReleased) {
        if (c == 8 && i > 0) {
            str[--i] = '\0';
            a = 1;
        } if (isan(c) == true && a == 0 && (my_strlen(str) < 11)) {
            str[i++] = c;
            str[i] = '\0';
        } sfText_setString(data->menu->perso->text_zone, str);
        data->player_s->name = my_strdup(str);
        sfText_setString(data->cinematic->dialo,
        my_strcat(data->player_s->name, txt_dialo[data->i]));
        return;
    }
}

void button_start(main_s *data)
{
    sfFloatRect start =
    sfSprite_getGlobalBounds(data->menu->perso->button_start);
    if (sfFloatRect_contains(&start,
    data->mouse_pos.x, data->mouse_pos.y))
        sfSprite_setTexture(data->menu->perso->button_start,
        data->menu->but->texture_pressed, sfFalse);
    else
        sfSprite_setTexture(data->menu->perso->button_start,
        data->menu->but->texture_play, sfFalse);
    if (sfMouse_isButtonPressed(sfMouseLeft) && sfFloatRect_contains(&start,
    data->mouse_pos.x, data->mouse_pos.y)) {
        data->cinematic->display_cine = 1;
        data->where = 3;
    }
}

void button_back(main_s *data)
{
    sfFloatRect back = sfSprite_getGlobalBounds(data->menu->perso->button_back);
    if (sfFloatRect_contains(&back, data->mouse_pos.x, data->mouse_pos.y))
        sfSprite_setTexture(data->menu->perso->button_back,
        data->menu->but->texture_pressed, sfFalse);
    else {
        sfSprite_setTexture(data->menu->perso->button_back,
        data->menu->but->texture_play, sfFalse);
    } if (data->window->event.type == sfEvtMouseButtonReleased &&
        data->window->event.mouseButton.button == sfMouseLeft &&
        sfFloatRect_contains(&back, data->mouse_pos.x, data->mouse_pos.y))
        data->where = 0;
}

void is_in_start(main_s *data)
{
    get_name(data);
    button_start(data);
    button_back(data);
    if (data->cinematic->display_cine == 1) {
        sfText_setString(data->cinematic->dialo,
        my_strcat(data->player_s->name, txt_dialo[0]));
        update_dialo(data);
    }
}

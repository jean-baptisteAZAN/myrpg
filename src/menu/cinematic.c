/*
** EPITECH PROJECT, 2023
** cine
** File description:
** cine
*/

#include "my.h"
#include "my_rpg.h"

void init_but_next(main_s *data)
{
    data->cinematic->button_next = my_sprite((sprite_create) {
        .color = sfWhite,
        .texture =
        sfTexture_createFromFile("ressources/fleche_droite.png", NULL),
        .scale = (sfVector2f) {2, 2},
        .position = (sfVector2f) {1750, 870},
    });
}

char *get_information_harvest(main_s *data, int line)
{
    if (line == 14)
        return int_to_char((int)data->harvest_s->pos_x);
    if (line == 15)
        return int_to_char((int)data->harvest_s->pos_y);
    else
        return int_to_char((int)data->harvest_s->sens);
}

void update_dialo(main_s *data)
{
    int a = 0;
    sfFloatRect zone_next =
    sfSprite_getGlobalBounds(data->cinematic->button_next);
    if (sfFloatRect_contains(&zone_next, data->mouse_pos.x, data->mouse_pos.y)
    && data->window->event.type == sfEvtMouseButtonReleased &&
    data->window->event.mouseButton.button == sfMouseLeft) {
        if (data->i == 4) {
            data->cinematic->display_cine = 2;
        } else {
            data->i++;
            a = 1;
        }
    }
    if (a != 0) {
        sfText_setString(data->cinematic->dialo, txt_dialo[data->i]);
        sfText_setCharacterSize(data->cinematic->dialo, 50);
        if (data->i > 1)
            sfText_setString(data->cinematic->dialo,
            my_strcat(data->player_s->name, txt_dialo[data->i]));
    }
}

void display_cinematic(main_s *data)
{
    sfRenderWindow_drawSprite(data->window->game_window,
    data->cinematic->sp_dialogue, NULL);
    sfRenderWindow_drawText(data->window->game_window,
    data->cinematic->dialo, NULL);
    sfRenderWindow_drawSprite(data->window->game_window,
    data->cinematic->button_next, NULL);
}

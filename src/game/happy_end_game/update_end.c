/*
** EPITECH PROJECT, 2023
** my_farmer
** File description:
** update_end
*/

#include "my.h"
#include "my_rpg.h"

void sub_display_msg(main_s *data)
{
    sfSprite_setScale(data->npc_s.bloc_msg_voisin,
        (sfVector2f){0.08, 0.08});
    sfRenderWindow_drawSprite(data->window->game_window,
        data->npc_s.bloc_msg_voisin, NULL);
    sfRenderWindow_drawText(data->window->game_window,
        data->npc_s.msg_voisin, NULL);
}

void update_end(main_s *data)
{
    static bool init = false;
    if (init == false) {
        data->i = 5;
        init = true;
    }
    int a = 0;
    sfFloatRect zone_next =
    sfSprite_getGlobalBounds(data->cinematic->button_next);
    if (sfFloatRect_contains(&zone_next, data->mouse_pos.x, data->mouse_pos.y)
    && data->window->event.type == sfEvtMouseButtonReleased &&
    data->window->event.mouseButton.button == sfMouseLeft) {
        if (data->i == 7)
            sfRenderWindow_close(data->window->game_window);
        else
            data->i++;
    }
    if (a == 0) {
        sfText_setString(data->cinematic->dialo, txt_dialo[data->i]);
        sfText_setCharacterSize(data->cinematic->dialo, 50);
    }
}

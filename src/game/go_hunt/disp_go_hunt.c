/*
** EPITECH PROJECT, 2023
** go
** File description:
** go
*/

#include "my.h"
#include "my_rpg.h"

void display_press_e(main_s *data)
{
    if (data->inv_s.verif == false)
        sfRenderWindow_drawSprite(data->window->game_window,
        data->go_hunt->presse, NULL);
}

void status_button_no(main_s *data)
{
    sfSprite_setTexture(data->go_hunt->button_no,
    data->menu->but->texture_pressed, sfFalse);
    if (data->window->event.type == sfEvtMouseButtonReleased &&
        data->window->event.mouseButton.button == sfMouseLeft ) {
        data->go_hunt->chat_go_hunt = false;
    }
}

void status_button_yes(main_s *data)
{
    sfSprite_setTexture(data->go_hunt->button_yes,
    data->menu->but->texture_pressed, sfFalse);
    if (data->window->event.type == sfEvtMouseButtonReleased &&
    data->window->event.mouseButton.button == sfMouseLeft ) {
        sfClock_restart(data->hun->text_clock);
        data->go_hunt->print_text = true;
        if (data->inv_s.gun->find == true) {
            sfClock_restart(data->hun->y_clock);
            data->where = 5;
            return;
        }
    }
}

void display_chat_hunt(main_s *data)
{
    if (data->go_hunt->chat_go_hunt == true) {
        if (data->window->resolution_state == 2)
            sfRenderWindow_setView(data->window->game_window,
            data->ress_s.view_resize);
        else
            sfRenderWindow_setView(data->window->game_window,
            data->ress_s.view_map);
        sub_display_chat_hunt(data);
    } else
        data->go_hunt->print_text = false;
    if (data->go_hunt->print_text == true)
        sfRenderWindow_drawText(data->window->game_window,
        data->go_hunt->need_gun, NULL);
}

void disp_go_hun(main_s *data)
{
    if (data->inv_s.verif == false)
        sfRenderWindow_drawSprite(data->window->game_window,
        data->go_hunt->perso, NULL);
    sfVector2f pos = sfSprite_getPosition(data->player_s->player);
    if ((pos.x > 320 && pos.x < 360) && (pos.y > 85 && pos.y < 120)) {
        display_press_e(data);
        if (data->window->event.type == sfEvtKeyReleased &&
            data->window->event.key.code == sfKeyF)
            data->go_hunt->chat_go_hunt = true;
    }
    display_chat_hunt(data);
}

/*
** EPITECH PROJECT, 2023
** coin
** File description:
** coin
*/

#include "my.h"
#include "my_rpg.h"

void check_plus_but(main_s *data)
{
    sfFloatRect zone_plus = sfSprite_getGlobalBounds(data->inv_s.button_boost);
    if (sfFloatRect_contains(&zone_plus,
    data->mouse_pos.x, data->mouse_pos.y)) {
        sfSprite_setTexture(data->inv_s.button_boost,
        data->menu->settings->plus_select_frame, sfFalse);
        if (data->window->event.type == sfEvtMouseButtonReleased &&
        data->window->event.mouseButton.button == sfMouseLeft) {
            data->player_s->gun_xp++;
            sfText_setString(data->inv_s.nb_lvl_riffle, my_strcat("Niveau \
du fusil ", my_put_nbr_int(data->player_s->gun_xp)));
        }
    } else {
        sfSprite_setTexture(data->inv_s.button_boost,
        sfTexture_createFromFile("ressources/bouton_plus.png", NULL), sfFalse);
    }
}

void verif_inven(main_s *data)
{
    update_inv(data);
    sfVector2f pos = sfSprite_getPosition(data->player_s->player);
    sfVector2f pos2 = sfSprite_getPosition(data->inv_s.gun->gun);
    if ((pos.x < pos2.x + 50 && pos.x > pos2.x - 50)
    && (pos.y < pos2.y + 50 && pos.y > pos2.y - 50))
        take_gun(data);
    if (data->window->event.type == sfEvtKeyReleased &&
    data->window->event.key.code == sfKeyI)
        data->inv_s.verif = !data->inv_s.verif;
    if (data->inv_s.verif == true && data->inv_s.print_desc &&
    data->player_s->money >= 20000) {
        check_plus_but(data);
    }
}

void check_coin_press_inv(main_s *data)
{
    sfFloatRect zone_coin = sfSprite_getGlobalBounds(data->inv_s.coin);
    sfFloatRect zone_ble = sfSprite_getGlobalBounds(data->inv_s.sprite_ble);
    if (sfFloatRect_contains(&zone_coin, data->mouse_pos.x,
    data->mouse_pos.y) &&
    data->window->event.type == sfEvtMouseButtonReleased &&
    data->window->event.mouseButton.button == sfMouseLeft)
        data->inv_s.print_coin_dsc = !data->inv_s.print_coin_dsc;
    if (sfFloatRect_contains(&zone_ble, data->mouse_pos.x, data->mouse_pos.y) &&
        data->window->event.type == sfEvtMouseButtonReleased &&
            data->window->event.mouseButton.button == sfMouseLeft)
        data->inv_s.prin_ble = !data->inv_s.prin_ble;
}
